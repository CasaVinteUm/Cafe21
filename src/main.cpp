#include <Arduino.h>
#include <HardwareSerial.h>
#include <MessageLogger.h>

HardwareSerial CoffeeSerial(1);

#define TX_PIN 18 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 17 // Receive pin:  ESP32 RX <- Coffee Machine TX

#define MAX_MESSAGE_LENGTH 256

// Create an instance of the MessageLogger
MessageLogger logger;

void readAndLogMessages();

void setup()
{
  Serial.begin(115200);
  while (!Serial)
  {
    ; // Wait for Serial Monitor to initialize
  }
  Serial.println("ESP32 Coffee Machine Logger Starting...");

  // Initialize UART communication with the coffee machine
  CoffeeSerial.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
  Serial.println("UART communication with coffee machine initialized.");
}

void loop()
{
  readAndLogMessages();
}

// Function to read and log messages from the coffee machine
void readAndLogMessages()
{
  static uint8_t messageBuffer[MAX_MESSAGE_LENGTH];
  static size_t messageIndex = 0;

  while (CoffeeSerial.available())
  {
    uint8_t incomingByte = CoffeeSerial.read();

    // Look for the header
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
        // Invalid header, reset
        messageIndex = 0;
        continue;
      }
    }

    // Check if we have received at least the minimum message length
    if (messageIndex >= 4)
    {
      // For simplicity, assume messages are fixed length
      // Adjust this as necessary based on your message structure
      size_t messageLength = 19; // Example message length from your logs
      if (messageIndex >= messageLength)
      {
        // Use the logger to log the message
        logger.logMessage(Sender::CoffeeMachine, messageBuffer, messageLength);

        // Reset the buffer for the next message
        messageIndex = 0;
      }
    }
  }
}