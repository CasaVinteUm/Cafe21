#include <Arduino.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include "main.h"

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 0;
#else
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 1;
#endif

#ifdef HASDISPLAY
uint8_t delay_lvgl = 0;
#endif // HASDISPLAY

CoffeeMachineController coffeeController(Serial1);
MessageLogger logger;

void readAndProcessMessages();

void setup()
{
#ifdef DEBUG_SERIAL
  Serial.begin(115200);
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

  while (Serial1.available())
  {
    uint8_t incomingByte = Serial1.read();

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
}