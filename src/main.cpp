#include <Arduino.h>
#include <HardwareSerial.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>

// HardwareSerial CoffeeSerial(1);

#ifndef ESP32C3
#define TX_PIN 18 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 17 // Receive pin:  ESP32 RX <- Coffee Machine TX
#else
#define TX_PIN 21 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 20 // Receive pin:  ESP32 RX <- Coffee Machine TX
#endif

#define MAX_MESSAGE_LENGTH 256

CoffeeMachineController coffeeController(Serial1);
MessageLogger logger;

void readAndProcessMessages();

void setup()
{
  Serial.begin(115200);
  // while (!Serial)
  // {
  //   ; // Wait for Serial Monitor to initialize
  // }
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
  Serial.println("'x' - Start/Stop Brewing");
  Serial.println("'t' - Set Strength");
  Serial.println("'q' - Set Quantity");
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
      logger.logMessage(Sender::CoffeeMachine, messageBuffer, 19);

      messageIndex = 0;
    }
  }
}