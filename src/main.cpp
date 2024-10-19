#include <Arduino.h>
#include <HardwareSerial.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include "display.h"
#include "ui.h"

#ifdef USE_I2C
 #include <Wire.h>
#endif

HardwareSerial CoffeeSerial(1);

#define TX_PIN 18 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 17 // Receive pin:  ESP32 RX <- Coffee Machine TX

uint8_t delay_lvgl = 0;

#define MAX_MESSAGE_LENGTH 256

CoffeeMachineController coffeeController(CoffeeSerial);
MessageLogger logger;
CoffeeMachineMessage currentMessage;

void readAndProcessMessages();

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; // Wait for Serial Monitor to initialize
  }

  #ifdef USE_I2C
   Wire.begin();
  #endif

  display_init();
  ui_init();
  
  Serial.println("ESP32 Coffee Machine Logger Starting...");

  // Initialize UART communication with the coffee machine
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial.println("UART communication with coffee machine initialized.");

  delay(1000);

  Serial.println("ESP32 Coffee Machine Controller Starting...");
  Serial.println("Enter commands to control the coffee machine:");
  Serial.println("'e' or 'espresso' - Select Espresso");
  Serial.println("'c' or 'coffee'   - Select Coffee");
  Serial.println("'h' or 'hotwater' - Select Hot Water");
  Serial.println("'s' or 'steam'    - Select Steam");
  Serial.println("'start'           - Start Brewing");
  Serial.println("'stop' or 'x'     - Stop Brewing");
  Serial.println("'t' or 'strength' - Set Strength");
  Serial.println("'q' or 'quantity' - Set Quantity");
}

void loop()
{
  readAndProcessMessages();
  // Check for user input from the Serial Monitor
  if (Serial.available())
  {
    String input = Serial.readStringUntil('\n'); // Read until newline character
    input.trim();                                // Remove any leading/trailing whitespace
    input.toLowerCase();                         // Convert to lowercase for easy comparison

    // Map input to commands
    if (input == "e" || input == "espresso")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Espresso);
    }
    else if (input == "c" || input == "coffee")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Coffee);
    }
    else if (input == "h" || input == "hotwater")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::HotWater);
    }
    else if (input == "s" || input == "steam")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Steam);
    }
    else if (input == "start" || input == "r")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Start);
    }
    else if (input == "stop" || input == "x")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Stop);
    }
    else if (input == "t" || input == "strength")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Strength);
    }
    else if (input == "q" || input == "quantity")
    {
      coffeeController.sendCommand(CoffeeMachineCommand::Quantity);
    }
    else
    {
      Serial.println("Unknown command. Please enter a valid command.");
    }
  }
  delay_lvgl = lv_timer_handler(); 
  vTaskDelay(delay_lvgl+1 / portTICK_PERIOD_MS);
  
  // UI
  switch (ui_action)
  {
  case ui_command::Expresso:
    coffeeController.sendCommand(CoffeeMachineCommand::Espresso);
    ui_action = 0;    
    break;
  case ui_command::Coffe:
    coffeeController.sendCommand(CoffeeMachineCommand::Coffee);
    ui_action = 0;
    break;
  case ui_command::StartStop:
    coffeeController.sendCommand(CoffeeMachineCommand::Start);
    ui_action = 0;
    break;
  case ui_command::Cancel:
    coffeeController.sendCommand(CoffeeMachineCommand::Stop);
    ui_action = 0;
    break;
  default:
    break;
  }

  if (coffeeController.getCurrentState() == CoffeeMachineState::Error) {
    if ( currentMessage.noWater) {
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_erroIcon, &ui_img_watersmall_png); 
      lv_label_set_text(ui_errorMessage, "Ops! O reservatório está vazio");
      lv_label_set_text(ui_errorDescription, "Por favor, adicione água para que possamos preparar seu café");
    }
    if ( currentMessage.cleanTrash) {
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_erroIcon, &ui_img_trashsmall_png); 
      lv_label_set_text(ui_errorMessage, "Hora de uma limpeza!");
      lv_label_set_text(ui_errorDescription, "A borra de café precisa ser esvaziada para preparar o próximo pedido.");
    }
    if ( currentMessage.generalWarning) {
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_img_set_src(ui_erroIcon, &ui_img_watersmall_png); 
      lv_label_set_text(ui_errorMessage, "Ops! Estamos com problemas!");
      lv_label_set_text(ui_errorDescription, "Verifique se a bandeja está cheia ou o café está no final.");
    }
  } else{
    lv_obj_add_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
  }
}

void readAndProcessMessages()
{
  static uint8_t messageBuffer[256];
  static size_t messageIndex = 0;

#ifdef USE_I2C
  Wire.requestFrom(COFFEMACHINE_I2C_ADDR, 19);
  while (Wire.available())
  {
    uint8_t incomingByte = Wire.read();
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
      logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);

      messageIndex = 0;
    }
  }
}