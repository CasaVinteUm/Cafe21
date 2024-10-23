#include <Arduino.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include "wManager.h"

#ifndef ESP32_NODISPLAY
#include "display.h"
#include "ui.h"

#endif
uint8_t delay_lvgl = 0;

#ifdef USE_I2C
#include <Wire.h>
// #include "I2CScanner.h"
// I2CScanner scanner;
#define VCC_PIN 18 // At display, those pins are in the same connector as the I2C; 17 is unused and 18 is used by the touch circuit for the interrupt signal, but let's try using it to power the I2C.
#define GND_PIN 17
CoffeeMachineController coffeeController;
// I2C Pins on display 19 SDA 20 SCL
#else
#ifndef ESP32C3
#define TX_PIN 13 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 12 // Receive pin:  ESP32 RX <- Coffee Machine TX
#else
#define TX_PIN 21 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 20 // Receive pin:  ESP32 RX <- Coffee Machine TX
#endif
HardwareSerial CoffeeSerial(1);
CoffeeMachineController coffeeController(CoffeeSerial);
// CoffeeMachineController coffeeController(Serial1);
#endif

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 0;
#else
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 1;
#endif

MessageLogger logger;
CoffeeMachineMessage currentMessage;

void readAndProcessMessages();
void runController(void *name);

#ifndef ESP32_NODISPLAY
void UIController(void *name);
#endif

void setup()
{
#ifdef DEBUG_SERIAL
  Serial.begin(115200);
  // while (!Serial)
  // {
  //   ; // Wait for Serial Monitor to initialize
  // }
#ifndef ESP32_NODISPLAY
  display_init();
  delay(100);

  ui_init();
  lv_timer_handler();
  vTaskDelay(500 / portTICK_PERIOD_MS);
#else
  Wire.begin(19, 20);
#endif

#ifdef USE_I2C
  /* pinMode(VCC_PIN, OUTPUT);
  pinMode(GND_PIN, INPUT);
  digitalWrite(VCC_PIN, HIGH);
  digitalWrite(GND_PIN, LOW); */
  Wire.begin();
  // scanner.Init(); // Use to check connection
  // scanner.Scan();
#else
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  // Initialize UART communication with the coffee machine
  Serial.println("UART communication with coffee machine initialized.");
#endif

  init_WifiManager();

  while (!Serial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  Serial.println("ESP32 Coffee Machine Logger Starting...");
#endif // DEBUG_SERIAL

  // Initialize UART communication with the coffee machine
  Serial1.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
#ifdef DEBUG_SERIAL
  while (!Serial1)
  {
    ; // Wait for Serial Monitor to initialize
  }
  Serial.println("UART communication with coffee machine initialized.");
#endif // DEBUG_SERIAL

#ifdef HASDISPLAY
  display_init();
  delay(100);

  ui_init();
  lv_timer_handler();
  vTaskDelay(500 / portTICK_PERIOD_MS);
#endif // HASDISPLAY

#ifdef DEBUG_SERIAL
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
  BaseType_t res1 = xTaskCreatePinnedToCore(runController, "Controller", 10000, (void *)name, 1, NULL, app_cpu1);

#ifdef HASDISPLAY
  // Task to deal with the UI, CPU 1
  char *nameui = (char *)malloc(32);
  sprintf(nameui, "(%s)", "UIController");
  BaseType_t res2 = xTaskCreatePinnedToCore(UIController, "UIController", 10000, (void *)nameui, 1, NULL, app_cpu1);
  delay(100);
#endif // HASDISPLAY

  // Wait for a bit and start the On procedure
  delay(1000);
  coffeeController.sendOnCommand();
}

void runController(void *name)
{
#ifdef DEBUG_SERIAL
  Serial.println("Coffe Machine Controller started");
#endif // DEBUG_SERIAL

  while (true)
  {
    readAndProcessMessages();

#ifdef DEBUG_SERIAL
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

#ifdef HASDISPLAY
void UIController(void *name)
{
  // UI
  Serial.println("UI Controller started");
  while (true)
  {
    switch (ui_action)
    {
    case ui_command::Expresso:
      coffeeController.sendCommand(CoffeeMachineCommand::Espresso, 0);
      ui_action = 0;
      break;
    case ui_command::Coffe:
      coffeeController.sendCommand(CoffeeMachineCommand::Coffee, 0);
      Serial.printf("pedindo um café!");
      ui_action = 0;
      break;
    case ui_command::StartStop:
      coffeeController.sendCommand(CoffeeMachineCommand::StartStop, 0);
      ui_action = 0;
      break;
    case ui_command::Cancel:
      coffeeController.sendCommand(CoffeeMachineCommand::StartStop, 0);
      ui_action = 0;
      break;
    default:
      break;
    }
    // Handle UI state
    switch (coffeeController.getCurrentState())
    {
    case CoffeeMachineState::Loading:
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_primaryButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_subtitulo, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_erroIcon, &ui_img_warningsmall_png);
      lv_label_set_text(ui_errorMessage, "Maquina aquecendo...");
      lv_label_set_text(ui_errorDescription, "Aguarde uns instantes.\n");
      break;
    case CoffeeMachineState::Ready:
      lv_obj_clear_flag(ui_primaryButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_subtitulo, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      break;
    case CoffeeMachineState::Error:
      lv_obj_add_flag(ui_primaryButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_subtitulo, LV_OBJ_FLAG_HIDDEN);
      if (currentMessage.noWater)
      {
        lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_erroIcon, &ui_img_watersmall_png);
        lv_label_set_text(ui_errorMessage, "Ops! O reservatório está vazio");
        lv_label_set_text(ui_errorDescription, "Por favor, adicione água para que possamos preparar o seu café");
      }
      if (currentMessage.cleanTrash)
      {
        lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_erroIcon, &ui_img_trashsmall_png);
        lv_label_set_text(ui_errorMessage, "Hora de uma limpeza!");
        lv_label_set_text(ui_errorDescription, "A borra de café precisa ser esvaziada para preparar seu pedido.");
      }
      if (currentMessage.generalWarning)
      {
        lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_erroIcon, &ui_img_warningsmall_png);
        lv_label_set_text(ui_errorMessage, "Ops! Estamos com problemas!");
        lv_label_set_text(ui_errorDescription, "Verifique se a bandeja está cheia ou se o café está no final.");
      }
      break;
    default:
      lv_obj_clear_flag(ui_primaryButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_subtitulo, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      break;
    }

    delay_lvgl = lv_timer_handler();
    vTaskDelay(delay_lvgl + 1 / portTICK_PERIOD_MS);
  }
}
#endif // HASDISPLAY

void loop()
{
  delay(10); // Stabilize loop
}

void readAndProcessMessages()
{
  static uint8_t messageBuffer[19];
  static size_t messageIndex = 0;

#ifdef USE_I2C
  uint8_t bytesReceived = Wire.requestFrom(COFFEMACHINE_I2C_ADDR, 19);
  vTaskDelay(500 / portTICK_PERIOD_MS);
  Serial.printf("requestFrom: %u\n", bytesReceived);
  uint8_t temp[20] = {0};
  if ((bool)bytesReceived)
  { // If received more than zero bytes
    Wire.readBytes(temp, bytesReceived);
    // log_print_buf(temp, bytesReceived);
  }
  if (bytesReceived > 0)
    // while (Wire.available())
    for (int i = 0; i < bytesReceived; i++)
    {
      uint8_t incomingByte = temp[i]; // Wire.read();
      if (incomingByte == 0xFF)
      {
        continue;
      } // else Serial.print(incomingByte, HEX);
#else
  while (CoffeeSerial.available())
  {
    uint8_t incomingByte = CoffeeSerial.read();
#endif
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

        CoffeeMachineState currState = coffeeController.getCurrentState();

        switch (currState)
        {
        case CoffeeMachineState::Error:
          break;
        case CoffeeMachineState::Loading:
          break;
        case CoffeeMachineState::Selected:
          break;
        case CoffeeMachineState::WaitingForOn:
        case CoffeeMachineState::TurningOn:
          break;
        case CoffeeMachineState::Ready:
          break;
        case CoffeeMachineState::Brewing:
          break;
        case CoffeeMachineState::Off:
        default:
          break;
        }

        logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);
        messageIndex = 0;
      }
    }
  // delay(100);
}