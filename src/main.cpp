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

#ifdef ESP32_3248S035C
HardwareSerial CoffeeSerial(0);
CoffeeMachineController coffeeController(Serial);
#else
HardwareSerial CoffeeSerial(1);
CoffeeMachineController coffeeController(CoffeeSerial);
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
  Serial.println("ESP32 Coffee Machine Logger Starting...");
#endif // NO_DEBUG_SERIAL

#ifdef ESP32_3248S035C
  Serial.begin(115200, SERIAL_8N1);
#else
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  while (!CoffeeSerial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  Serial.println("UART communication with coffee machine initialized.");
#endif

#ifdef DISPLAY_WIDTH
  // Initialize SmartDisplay
  smartdisplay_init();

  // Get Default Display
  __attribute__((unused)) auto disp = lv_disp_get_default();

  // Set Rotation as needed
  // lv_display_set_rotation(disp, LV_DISPLAY_ROTATION_90);

  // Initialiez UI
  ui_init();

  lv_timer_handler();
  vTaskDelay(500 / portTICK_PERIOD_MS);
#endif // DISPLAY_WIDTH

#ifndef NO_DEBUG_SERIAL
  Serial.println("ESP32 Coffee Machine Controller Starting...");
  Serial.println("Enter commands to control the coffee machine:");
  Serial.println("'o' - Turn On");
  Serial.println("'e' - Select Espresso");
  Serial.println("'c' - Select Coffee");
  Serial.println("'h' - Select Hot Water");
  Serial.println("'s' - Select Steam");
  Serial.println("'x' - Start/Stop Brewing");
  Serial.println("'t' - Set Strength");
  Serial.println("'q' - Set Quantity");
#endif // DEBUG_SERIAL

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

#ifndef NO_DEBUG_SERIAL
  Serial.println("WiFi connected.");
#endif // DEBUG_SERIAL

  Lightning.setOnInvoicePaid(onInvoicePaid);
  Lightning.websocketInit();

  // Wait for a bit and start the On procedure
  delay(1000);
}

void runController(void *name)
{
#ifndef NO_DEBUG_SERIAL
  Serial.println("Coffe Machine Controller started");
#endif // DEBUG_SERIAL

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
        Serial.println("Unknown command. Please enter a valid command.");
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
#ifndef NO_DEBUG_SERIAL
  Serial.println("UI Controller started");
#endif // DEBUG_SERIAL

  while (true)
  {
    // Handle UI state
    switch (CoffeeMachineState::Ready) //(coffeeController.getCurrentState())
    {
    case CoffeeMachineState::Off:
      coffeeController.sendOnCommand();
      lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_homeErrorIcon, &ui_img_warnsmall_png);
      lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
      lv_label_set_text(ui_homeErrorSubTitle, "Aguarde...\n");
      break;
    case CoffeeMachineState::WaitingForOn:
    case CoffeeMachineState::TurningOn:
      lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_homeErrorIcon, &ui_img_trashsmall_png);
      lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
      lv_label_set_text(ui_homeErrorSubTitle, "Aguarde uns instantes.\n");
      break;
    case CoffeeMachineState::Loading:
      lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_homeErrorIcon, &ui_img_trashsmall_png);
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
        lv_img_set_src(ui_homeErrorIcon, &ui_img_watersmall_png);
        lv_label_set_text(ui_homeErrorTitle, "Ops! O reservatório está vazio");
        lv_label_set_text(ui_homeErrorSubTitle, "Por favor, adicione água para que possamos preparar o seu café");
      }
      if (currentMessage.cleanTrash)
      {
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_homeErrorIcon, &ui_img_trashsmall_png);
        lv_label_set_text(ui_homeErrorTitle, "Hora de uma limpeza!");
        lv_label_set_text(ui_homeErrorSubTitle, "A borra de café precisa ser esvaziada para preparar seu pedido.");
      }
      if (currentMessage.generalWarning)
      {
        lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_homeErrorIcon, &ui_img_trashsmall_png);
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
      CoffeeMachineMessage message(messageBuffer, 19);
      currentMessage = message;
      coffeeController.updateState(message);

      // CoffeeMachineState currState = coffeeController.getCurrentState();

      // switch (currState)
      // {
      // case CoffeeMachineState::Error:
      //   break;
      // case CoffeeMachineState::Loading:
      //   break;
      // case CoffeeMachineState::Selected:
      //   break;
      // case CoffeeMachineState::WaitingForOn:
      // case CoffeeMachineState::TurningOn:
      //   break;
      // case CoffeeMachineState::Ready:
      //   break;
      // case CoffeeMachineState::Brewing:
      //   break;
      // case CoffeeMachineState::Off:
      // default:
      //   break;
      // }

      // logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);
      messageIndex = 0;
    }
  }
}

void generateQrCode(uint8_t buttonNumber)
{
  auto ui_qrcode = lv_qrcode_create(ui_qrCodeContainer, 256, lv_color_black(), lv_color_white());
  String qrData = buttonNumber == 1 ? Lightning.button1Lnurl : Lightning.button2Lnurl;
  lv_qrcode_update(ui_qrcode, qrData.c_str(), qrData.length());
  lv_obj_center(ui_qrcode);
}

void chooseButton1Clicked(lv_event_t *e)
{
  isWaitingPayment = 1;
  coffeeController.selectCoffee(CoffeeType::ESPRESSO);
  generateQrCode(1);
}

void chooseButton2Clicked(lv_event_t *e)
{
  isWaitingPayment = 2;
  coffeeController.selectCoffee(CoffeeType::COFFEE);
  generateQrCode(2);
}

void chooseBackButtonClicked(lv_event_t *e)
{
  coffeeController.selectCoffee(CoffeeType::NONE);
}

void paymentBackButtonClicked(lv_event_t *e)
{
  lv_obj_clean(ui_qrCodeContainer);
  coffeeController.selectCoffee(CoffeeType::NONE);
}

void preparingCancelButtonClicked(lv_event_t *e)
{
  coffeeController.selectCoffee(CoffeeType::NONE);
}

void paidcallback(lv_event_t *e)
{
  onInvoicePaid(1);
}

void onInvoicePaid(uint8_t type)
{
  if (isWaitingPayment == type)
  {
    isWaitingPayment = 0;
    lv_scr_load(ui_preparing);
    lv_obj_clean(ui_qrCodeContainer);
    coffeeController.startOrder();
  }
  else
  {
#ifndef NO_DEBUG_SERIAL
    Serial.printf("Invoice paid for: %d\n", type);
#endif // DEBUG_SERIAL
    return;
  }
}