#include "main.h"

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 0;
#else
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 1;
#endif

MessageLogger logger;
CoffeeMachineMessage currentMessage;

uint8_t delay_lvgl = 0;
lv_coord_t qrCodeSize = QRCODE_INITIAL_SIZE;

#ifdef ARDUINO_ESP32_DEV
HardwareSerial CoffeeSerial(0);
CoffeeMachineController coffeeController(Serial, logger);
#else
HardwareSerial CoffeeSerial(1);
CoffeeMachineController coffeeController(CoffeeSerial, logger);
#endif

void readAndProcessMessages();
void runController(void *name);

#ifdef DISPLAY_WIDTH
LightningController Lightning;
#endif // DISPLAY_WIDTH

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

#ifdef ARDUINO_ESP32_DEV
  Serial.begin(115200, SERIAL_8N1);
#else
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  while (!CoffeeSerial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  log_i("UART communication with coffee machine initialized.");
#endif

#ifdef DISPLAY_WIDTH
  // Initialize SmartDisplay
  smartdisplay_init();

  // Get Default Display
  __attribute__((unused)) auto disp = lv_disp_get_default();

  // Set Rotation as needed
  if (DISPLAY_HEIGHT > DISPLAY_WIDTH)
  {
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
  }

  // Initialiez UI
  ui_init();

  lv_timer_handler();
  vTaskDelay(500 / portTICK_PERIOD_MS);
#endif // DISPLAY_WIDTH

  log_i("ESP32 Coffee Machine Controller Starting...");
  log_i("Enter commands to control the coffee machine:");
  log_i("'o' - Turn On");
  log_i("'e' - Select Espresso");
  log_i("'c' - Select Coffee");
  log_i("'h' - Select Hot Water");
  log_i("'s' - Select Steam");
  log_i("'x' - Start/Stop Brewing");
  log_i("'t' - Set Strength");
  log_i("'q' - Set Quantity");

  // Task to deal with the CoffeMachine Controller, CPU 0
  char *name = (char *)malloc(32);
  sprintf(name, "(%s)", "Controller");
  xTaskCreatePinnedToCore(runController, "Controller", 10000, (void *)name, 1, NULL, app_cpu1);

#ifdef DISPLAY_WIDTH
  // Task to deal with the UI, CPU 1
  char *nameui = (char *)malloc(32);
  sprintf(nameui, "(%s)", "UIController");
  xTaskCreatePinnedToCore(UIController, "UIController", 10000, (void *)nameui, 1, NULL, app_cpu1);
  delay(100);
#endif // DISPLAY_WIDTH

  init_WifiManager();

  log_i("WiFi connected.");

  Lightning.setOnInvoicePaid(onInvoicePaid);
  Lightning.websocketInit();

  // Wait for a bit and start the On procedure
  delay(1000);
}

void runController(void *name)
{
  log_i("Coffe Machine Controller started");

  while (true)
  {
    readAndProcessMessages();

#ifndef NO_DEBUG_SERIAL
    if (Serial.available())
    {
      String input = Serial.readStringUntil('\n'); // Read until newline character
      input.trim();                                // Remove any leading/trailing whitespace
      input.toLowerCase();                         // Convert to lowercase for easy comparison

      // Map input to commands
      if (input == "o")
      {
        coffeeController.sendOnCommand();
      }
      else if (input == "e")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Espresso);
      }
      else if (input == "c")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Coffee);
      }
      else if (input == "h")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::HotWater);
      }
      else if (input == "s")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Steam);
      }
      else if (input == "x")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::StartStop);
      }
      else if (input == "t")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Strength);
      }
      else if (input == "q")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Quantity);
      }
      else
      {
        log_e("Unknown command. Please enter a valid command.");
      }
    }
#endif // DEBUG_SERIAL

    // Allways send the Status Command...
    coffeeController.sendCommand(CoffeeMachineCommand::Status);

    delay(100); // Stabilize loop
  }
}

#ifdef DISPLAY_WIDTH
void UIController(void *name)
{
  // UI
  log_i("UI Controller started");

  while (true)
  {
    if (Lightning.getIsConnected())
    {
      // Handle UI state
      switch (coffeeController.getCurrentState())
      {
      case CoffeeMachineState::Off:
        coffeeController.sendOnCommand();
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_homeErrorIcon, &ui_img_warning_png);
        lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
        lv_label_set_text(ui_homeErrorSubTitle, "Aguarde...\n");
        break;
      case CoffeeMachineState::WaitingForOn:
      case CoffeeMachineState::TurningOn:
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
        lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
        lv_label_set_text(ui_homeErrorSubTitle, "Aguarde uns instantes.\n");
        break;
      case CoffeeMachineState::Loading:
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
        lv_label_set_text(ui_homeErrorTitle, "Maquina aquecendo...");
        lv_label_set_text(ui_homeErrorSubTitle, "Aguarde uns instantes.\n");
        break;
      case CoffeeMachineState::Ready:
        lv_obj_clear_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        break;
      case CoffeeMachineState::Error:
        lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
        if (currentMessage.noWater)
        {
          lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
          lv_img_set_src(ui_homeErrorIcon, &ui_img_water_png);
          lv_label_set_text(ui_homeErrorTitle, "Ops! O reservatório está vazio");
          lv_label_set_text(ui_homeErrorSubTitle, "Por favor, adicione água para que possamos preparar o seu café");
        }
        if (currentMessage.cleanTrash)
        {
          lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
          lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
          lv_label_set_text(ui_homeErrorTitle, "Hora de uma limpeza!");
          lv_label_set_text(ui_homeErrorSubTitle, "A borra de café precisa ser esvaziada para preparar seu pedido.");
        }
        if (currentMessage.generalWarning)
        {
          lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
          lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
          lv_label_set_text(ui_homeErrorTitle, "Ops! Estamos com problemas!");
          lv_label_set_text(ui_homeErrorSubTitle, "Verifique se a bandeja está cheia ou se o café está no final.");
        }
        break;
      default:
        lv_obj_clear_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_homeErrorSubTitle, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        break;
      }
    }
    else
    {
      lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_homeErrorIcon, &ui_img_wifi_png);
      lv_label_set_text(ui_homeErrorTitle, "Conectando ao WiFi e LNBits...");
      lv_label_set_text(ui_homeErrorSubTitle, "Aguarde...\n");
    }

    delay_lvgl = lv_timer_handler();
    vTaskDelay(delay_lvgl + 1 / portTICK_PERIOD_MS);
  }
}
#endif // DISPLAY_WIDTH

void loop()
{
  Lightning.websocketLoop();
  vTaskDelay(delay_lvgl + 1 / portTICK_PERIOD_MS);
}

void readAndProcessMessages()
{
  static uint8_t messageBuffer[19];
  static size_t messageIndex = 0;

  while (CoffeeSerial.available())
  {
    uint8_t incomingByte = CoffeeSerial.read();
    // Assemble the message as before
    if (messageIndex == 0 && incomingByte != 0xD5)
    {
      continue;
    }

    // If we get a init header anywhere else, reset the buffer and fill up the message again
    if (messageIndex != 0 && incomingByte == 0xD5)
    {
      messageIndex = 0;
    }

    messageBuffer[messageIndex++] = incomingByte;

    // Check for header completion
    if (messageIndex == 2)
    {
      if (messageBuffer[1] != 0x55)
      {
        messageIndex = 0;
        continue;
      }
    }

    // Assuming fixed message length of 19 bytes
    if (messageIndex >= 19)
    {
      logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);

      CoffeeMachineMessage message(messageBuffer, 19);
      currentMessage = message;
      coffeeController.updateState(message);

      messageIndex = 0;
    }
  }
}

void showQrCode(uint8_t buttonNumber, lv_coord_t size)
{
  // Create and update QR code
  auto ui_qrcode = lv_qrcode_create(ui_qrCodeContainer, size ? size : QRCODE_INITIAL_SIZE, lv_color_black(), lv_color_white());
  String qrData = buttonNumber == 1 ? Lightning.button1Lnurl : Lightning.button2Lnurl;
  lv_qrcode_update(ui_qrcode, qrData.c_str(), qrData.length());
  lv_obj_center(ui_qrcode);
}

void generateQrCode(uint8_t buttonNumber)
{
  if (qrCodeSize <= QRCODE_INITIAL_SIZE)
  {
    static uint32_t startTime;
    static uint8_t timerButtonNumber;

    // Allocate and initialize timer data
    startTime = millis();
    timerButtonNumber = buttonNumber;

    // Create a one-shot timer that will generate the QR code after the screen is loaded
    // Create timer that will generate the QR code after the screen is loaded
    __attribute__((unused)) lv_timer_t *timer = lv_timer_create([](lv_timer_t *timer)
                                                                {            
            qrCodeSize = lv_obj_get_content_width(ui_qrCodeContainer) - 5;
            
            if (qrCodeSize > QRCODE_INITIAL_SIZE) {
                showQrCode(timerButtonNumber, qrCodeSize);
                lv_timer_del(timer);
            } else {
                if (millis() - startTime >= 2000) {  // 2 second timeout
                    lv_timer_del(timer);
                    qrCodeSize = QRCODE_INITIAL_SIZE;
                }
            } }, 100, NULL); // 100ms interval
  }
  else
  {
    showQrCode(buttonNumber, qrCodeSize);
  }
}

void chooseButton1Clicked(lv_event_t *e)
{
  isWaitingPayment = 1;
  coffeeController.selectCoffee(CoffeeType::ESPRESSO);
  _ui_screen_change(&ui_payment, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_payment_screen_init);

  lv_timer_create([](lv_timer_t *timer)
                  {
                    generateQrCode(1);
                    lv_timer_del(timer); // Delete the timer after use
                  },
                  100, nullptr); // 100ms delay
}

void chooseButton2Clicked(lv_event_t *e)
{
  isWaitingPayment = 2;
  coffeeController.selectCoffee(CoffeeType::COFFEE);
  _ui_screen_change(&ui_payment, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_payment_screen_init);

  lv_timer_create([](lv_timer_t *timer)
                  {
                    generateQrCode(2);
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
  clearQrCode();
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

void clearQrCode()
{
  lv_timer_create([](lv_timer_t *timer)
                  {
                    lv_obj_clean(ui_qrCodeContainer);
                    lv_timer_del(timer); // Delete the timer after use
                  },
                  500, nullptr); // 500ms delay
}

void onInvoicePaid(uint8_t type)
{
  if (isWaitingPayment == type)
  {
    isWaitingPayment = 0;
    _ui_screen_change(&ui_preparing, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_preparing_screen_init);
    clearQrCode();
    coffeeController.startOrder();
  }
  else
  {
    log_i("Invoice paid for: %d", type);
    return;
  }
}