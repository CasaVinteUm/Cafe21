#include <Arduino.h>
#include <HardwareSerial.h>
#include <CoffeeMachineMessage.h>

HardwareSerial CoffeeSerial(1);

#define TX_PIN 18 // Transmit pin: ESP32 TX -> Coffee Machine RX
#define RX_PIN 17 // Receive pin:  ESP32 RX <- Coffee Machine TX

#define MAX_MESSAGE_LENGTH 256

void readAndProcessMessages();
void handleNewCoffeeMachineMessage(const CoffeeMachineMessage &message);
uint16_t computeCRC16(const uint8_t *data, size_t length);

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
  readAndProcessMessages();
}

// Function to read and process messages from the coffee machine
void readAndProcessMessages()
{
  static uint8_t messageBuffer[MAX_MESSAGE_LENGTH];
  static size_t messageIndex = 0;
  static CoffeeMachineMessage lastMessage;
  static bool hasLastMessage = false;

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
    if (messageIndex >= 19)
    {
      // For simplicity, assume messages are fixed length
      // Adjust this as necessary based on your message structure
      size_t messageLength = 19; // Message length including checksum
      if (messageIndex >= messageLength)
      {
        // Verify checksum
        // uint16_t receivedChecksum = (messageBuffer[messageLength - 2] << 8) | messageBuffer[messageLength - 1];
        // uint16_t calculatedChecksum = computeCRC16(messageBuffer, messageLength - 2);

        // if (receivedChecksum != calculatedChecksum)
        // {
        //   Serial.println("Checksum mismatch, ignoring message.");
        // }
        // else
        // {
        // Parse the message
        CoffeeMachineMessage currentMessage(messageBuffer, messageLength);

        // Compare with the last message
        if (!hasLastMessage || currentMessage != lastMessage)
        {
          // New message detected, handle it
          handleNewCoffeeMachineMessage(currentMessage);

          // Update the last message
          lastMessage = currentMessage;
          hasLastMessage = true;
        }
        // }

        // Reset the buffer for the next message
        messageIndex = 0;
      }
    }
  }
}

// Function to handle new messages from the coffee machine
void handleNewCoffeeMachineMessage(const CoffeeMachineMessage &message)
{
  Serial.println("New message from coffee machine:");
  message.print();

  // Here you can add code to handle the new message, e.g.,
  // update display, trigger actions, etc.
}

// Function to compute CRC16-CCITT checksum
uint16_t computeCRC16(const uint8_t *data, size_t length)
{
  uint16_t crc = 0; // Initial value
  for (size_t i = 2; i < length - 2; i++)
  {
    crc += data[i];
  }
  return crc;
}