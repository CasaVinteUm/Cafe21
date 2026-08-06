#include "main.h"

void setup()
{
#if ARDUINO_USB_CDC_ON_BOOT == 1
  delay(5000);
#endif

#ifndef NO_DEBUG_SERIAL
  Serial.begin(115200);
  while (!Serial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  log_i("Connected!");
#endif // NO_DEBUG_SERIAL

#ifdef ESP32C3
  Serial.begin(115200, SERIAL_8N1);
#else
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  while (!CoffeeSerial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  log_i("UART communication with coffee machine initialized.");

  log_i("Enter commands to control the coffee machine:");
  log_i("'o' - Turn On");
  log_i("'e' - Select Espresso");
  log_i("'c' - Select Coffee");
  log_i("'h' - Select Hot Water");
  log_i("'s' - Select Steam");
  log_i("'x' - Start/Stop Brewing");
  log_i("'t' - Set Strength");
  log_i("'q' - Set Quantity");
#endif

  uiController.begin();

  if (!configManager.begin())
  {
    log_e("Failed to initialize config manager");
    delay(3000);
    ESP.restart();
  }

  if (!wifiManager.begin())
  {
    log_e("Failed to initialize WiFi manager");
    delay(3000);
    ESP.restart();
  }

  initialized = true;
  uiController.setIsInitialized(true);

  log_i("WiFi connected.");

  lightningController.websocketInit();

  coffeeTask.begin();
}

void loop()
{
  if (!initialized)
    return;

  wifiManager.process();

  lightningController.websocketLoop();
  vTaskDelay(uiController.getDelayLvgl() + 1 / portTICK_PERIOD_MS);
}

/// -------------------------------------
///             UI EVENTS
/// -------------------------------------

void chooseButton1Clicked(lv_event_t *e)
{
  uiController.setWaitingPaymentFor(1);
  coffeeController.selectCoffee(CoffeeType::ESPRESSO);
  _ui_screen_change(&ui_payment, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_payment_screen_init);

  lv_timer_create([](lv_timer_t *timer)
                  {
                    uiController.generateQrCode(1);
                    lv_timer_del(timer); // Delete the timer after use
                  },
                  100, nullptr); // 100ms delay
}

void chooseButton2Clicked(lv_event_t *e)
{
  uiController.setWaitingPaymentFor(2);
  coffeeController.selectCoffee(CoffeeType::COFFEE);
  _ui_screen_change(&ui_payment, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_payment_screen_init);

  lv_timer_create([](lv_timer_t *timer)
                  {
                    uiController.generateQrCode(2);
                    lv_timer_del(timer); // Delete the timer after use
                  },
                  100, nullptr); // 100ms delay
}

void chooseBackButtonClicked(lv_event_t *e)
{
  coffeeController.selectCoffee(CoffeeType::NONE);
  _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}

void paymentBackButtonClicked(lv_event_t *e)
{
  coffeeController.selectCoffee(CoffeeType::NONE);
  _ui_screen_change(&ui_choose, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_choose_screen_init);
  uiController.clearQrCode();
}

void preparingCancelButtonClicked(lv_event_t *e)
{
  coffeeController.selectCoffee(CoffeeType::NONE);
  coffeeController.sendCommand(CoffeeMachineCommand::StartStop);

  _ui_screen_change(&ui_choose, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_choose_screen_init);
}

void successPanelButtonClicked(lv_event_t *e)
{
  _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}

void homeConfigClicked(lv_event_t *e)
{
  lv_obj_add_flag(ui_configPanel, LV_OBJ_FLAG_HIDDEN);
  lv_obj_clear_flag(ui_configPasswordPanel, LV_OBJ_FLAG_HIDDEN);

  _ui_screen_change(&ui_config, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_config_screen_init);
}

void configButtonEspressoClicked(lv_event_t *e)
{
  uiController.setWaitingPaymentFor(1);
  coffeeController.selectCoffee(CoffeeType::ESPRESSO);
  uiController.onInvoicePaid(1);
}

void configButtonCoffeeClicked(lv_event_t *e)
{
  uiController.setWaitingPaymentFor(2);
  coffeeController.selectCoffee(CoffeeType::COFFEE);
  uiController.onInvoicePaid(2);
}

void configButtonRestartClicked(lv_event_t *e)
{
  ESP.restart();
}

void configButtonResetClicked(lv_event_t *e)
{
  configManager.reset();
  wifiManager.reset();

  delay(5000);

  ESP.restart();
}

void configButtonBackClicked(lv_event_t *e)
{
  _ui_screen_change(&ui_home, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_home_screen_init);
}

void configPasswordKeyboardValueChanged(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);
  lv_obj_t *obj = lv_event_get_target(e);

  if (code == LV_EVENT_VALUE_CHANGED)
  {
    uint16_t key = lv_keyboard_get_selected_btn(obj);
    const char *txt = lv_btnmatrix_get_btn_text(obj, key);

    if (txt != NULL && strcmp(txt, LV_SYMBOL_OK) == 0)
    {
      // Enter key was pressed
      const char *entered_text = lv_textarea_get_text(ui_configPasswordText);
      if (strcmp(entered_text, String(CONFIG_PASSWORD).c_str()) == 0)
      {
        // Password correct - show config panel
        lv_obj_clear_flag(ui_configPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_configPasswordPanel, LV_OBJ_FLAG_HIDDEN);

        // Clear password
        lv_textarea_set_text(ui_configPasswordText, "");
      }
      else
      {
        // Password incorrect - show error message
        lv_textarea_set_text(ui_configPasswordText, "");

        // Show error message label
        // lv_label_set_text(ui_configPasswordLabel, "Invalid Password");
        lv_obj_clear_flag(ui_configPasswordLabel, LV_OBJ_FLAG_HIDDEN);

        // Hide error message after 2 seconds
        __attribute__((unused)) lv_timer_t *timer = lv_timer_create([](lv_timer_t *t)
                                                                    {
            lv_obj_add_flag(ui_configPasswordLabel, LV_OBJ_FLAG_HIDDEN);
            lv_timer_del(t); }, 2000, NULL);
      }
    }
  }
}