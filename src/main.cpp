#include <Arduino.h>
#include <HardwareSerial.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>

// HardwareSerial CoffeeSerial(1);
#ifndef ESP32_NODISPLAY
  #include "display.h"
  #include "ui.h"
#endif

#ifdef USE_I2C
  #include <Wire.h>
  #include "I2CScanner.h"
  I2CScanner scanner;
  #define VCC_PIN 18 // At display, those pins are in the same connector as the I2C; 17 is unused and 18 is used by the touch circuit for the interrupt signal, but let's try using it to power the I2C.
  #define GND_PIN 17
  CoffeeMachineController coffeeController;
  // I2C Pins on display 19 SDA 20 SCL

  // function that executes whenever data is received from display
  void receiveEvent(int howMany)
  {
    Serial.println("Wire:");
    while(Wire.available()) // loop through last data
        {        
          Serial.print(Wire.read(), HEX); // send byte to the MB
        }
  }
#else
  HardwareSerial CoffeeSerial(1);
  #define TX_PIN 13 // Transmit pin: ESP32 TX -> Coffee Machine RX
  #define RX_PIN 12 // Receive pin:  ESP32 RX <- Coffee Machine TX
  CoffeeMachineController coffeeController(CoffeeSerial);
#endif

#ifndef ESP32C3
uint8_t delay_lvgl = 0;
#else
#define TX_PIN 21 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 20 // Receive pin:  ESP32 RX <- Coffee Machine TX
#endif

#define MAX_MESSAGE_LENGTH 256

#if CONFIG_FREERTOS_UNICORE
  static const BaseType_t app_cpu0 = 0;
  static const BaseType_t app_cpu1 = 0;
#else
  static const BaseType_t app_cpu0 = 0;
  static const BaseType_t app_cpu1 = 1;
#endif

CoffeeMachineController coffeeController(Serial1);
MessageLogger logger;
CoffeeMachineMessage currentMessage;

void readAndProcessMessages();
void runController(void *name);

#ifndef ESP32_NODISPLAY
void UIController(void *name);
#endif

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; // Wait for Serial Monitor to initialize
  }
 #ifndef ESP32_NODISPLAY
  display_init();
  delay(100);

  ui_init();
  lv_timer_handler();
  vTaskDelay(500 / portTICK_PERIOD_MS);
 #else
  Wire.begin(19,20);
 #endif

 #ifdef USE_I2C
   pinMode(VCC_PIN, OUTPUT);
   pinMode(GND_PIN, INPUT);
   digitalWrite(VCC_PIN, HIGH);
   digitalWrite(GND_PIN, LOW);
  // Wire.begin();
   scanner.Init();
   scanner.Scan();
   //Wire.onReceive(receiveEvent);
  #else
   CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
   // Initialize UART communication with the coffee machine
   Serial.println("UART communication with coffee machine initialized.");
  #endif
  Serial.println("ESP32 Coffee Machine Logger Starting...");

  // Initialize UART communication with the coffee machine
  Serial1.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial.println("UART communication with coffee machine initialized.");

  delay(1000);

  Serial.println("ESP32 Coffee Machine Controller Starting...");
  Serial.println("Enter commands to control the coffee machine:");
  Serial.println("'o' - Turn On");
  Serial.println("'e' - Select Espresso");
  Serial.println("'c' - Select Coffee");
  Serial.println("'h' - Select Hot Water");
  Serial.println("'s' - Select Steam");
  Serial.println("'r' - Start Brewing");
  Serial.println("'x' - Stop Brewing");
  Serial.println("'t' - Set Strength");
  Serial.println("'q' - Set Quantity");

   // Task to deal with the CoffeMachine Controller, CPU 0
  char *name = (char*) malloc(32);
  sprintf(name, "(%s)", "Controller");
  BaseType_t res1 = xTaskCreatePinnedToCore(runController, "Controller", 10000, (void*)name, 1, NULL, app_cpu1);

 #ifndef ESP32_NODISPLAY
  // Task to deal with the UI, CPU 1
  char *nameui = (char*) malloc(32);
  sprintf(nameui, "(%s)", "UIController");
  BaseType_t res2 = xTaskCreatePinnedToCore(UIController, "UIController", 10000, (void*)nameui, 1, NULL, app_cpu1);
  delay(100);
 #endif 
  // Power on  the machine at start
  coffeeController.sendCommand(CoffeeMachineCommand::Start, 3);

}

void runController(void *name){
  Serial.println("Coffe Machine Controller started");
  while (true)
  {        
    readAndProcessMessages();
    // Check for user input from the Serial Monitor
    if (Serial.available())
    {
      String input = Serial.readStringUntil('\n'); // Read until newline character
      input.trim();                               // Remove any leading/trailing whitespace
      input.toLowerCase();                        // Convert to lowercase for easy comparison

      // Map input to commands
      if (input == "o")
    {
      coffeeController.sendOnCommand();
    }
    else if (input == "e")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Espresso, 0);
      }
      else if (input == "c")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Coffee, 0);
      }
      else if (input == "h")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::HotWater, 0);
      }
      else if (input == "s")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Steam, 0);
      }
      else if (input == "r")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Start, 0);
      }
      else if (input == "x")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Stop, 0);
      }
      else if (input == "t")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Strength, 0);
      }
      else if (input == "q")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Quantity, 0);
      }
      else if (input == "power" || input == "p")
      {
        coffeeController.sendCommand(CoffeeMachineCommand::Start, 3);
      }
      else if (input == "status" || input == "d")
      {
        currentMessage.print();
        Serial.printf("Current Status:%d\n", coffeeController.getCurrentState());
      }
      else
      {
        Serial.println("Unknown command. Please enter a valid command.");
      }
    }
  } // Loop controller
}

#ifndef ESP32_NODISPLAY
void UIController(void *name){
  // UI
  Serial.println("UI Controller started");
  while(true){    
    //Serial.print(".");
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
      coffeeController.sendCommand(CoffeeMachineCommand::Start, 0);
      ui_action = 0;
      break;
    case ui_command::Cancel:
      coffeeController.sendCommand(CoffeeMachineCommand::Stop, 0);
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
    case CoffeeMachineState::Error:     
      lv_obj_add_flag(ui_primaryButton, LV_OBJ_FLAG_HIDDEN);
      lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
      lv_obj_add_flag(ui_subtitulo, LV_OBJ_FLAG_HIDDEN);
      if ( currentMessage.noWater) {
        lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);
        lv_img_set_src(ui_erroIcon, &ui_img_watersmall_png); 
        lv_label_set_text(ui_errorMessage, "Ops! O reservatório está vazio");
        lv_label_set_text(ui_errorDescription, "Por favor, adicione água para que possamos preparar o seu café");
      }
      if ( currentMessage.cleanTrash) {
        lv_obj_clear_flag(ui_errorPanel, LV_OBJ_FLAG_HIDDEN);        
        lv_img_set_src(ui_erroIcon, &ui_img_trashsmall_png); 
        lv_label_set_text(ui_errorMessage, "Hora de uma limpeza!");
        lv_label_set_text(ui_errorDescription, "A borra de café precisa ser esvaziada para preparar seu pedido.");
      }
      if ( currentMessage.generalWarning) {
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
    vTaskDelay(delay_lvgl+1 / portTICK_PERIOD_MS); 
  }
}
#endif

void loop()
{    
 //Serial.print("l");   
  else
  {
    coffeeController.sendCommand(CoffeeMachineCommand::Status);
  }

  delay(10);
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
    if (incomingByte == 0xFF) {
      continue;
    } // else Serial.print(incomingByte, HEX);
#else
  while (Serial1.available())
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
      logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);
      messageIndex = 0;
    }
  }
}