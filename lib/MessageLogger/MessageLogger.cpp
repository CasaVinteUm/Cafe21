#include "MessageLogger.h"

MessageLogger::MessageLogger() : lastMessageLength(0), hasLastMessage(false)
{
}

void MessageLogger::logMessage(Sender sender, const uint8_t *message, size_t length, bool logOnlyIfNotRepeated)
{
    bool isRepeated = false;

    if (logOnlyIfNotRepeated && hasLastMessage)
    {
        if (sender == lastSender && length == lastMessageLength && memcmp(message, lastMessage, length) == 0)
        {
            isRepeated = true;
        }
    }

    if (!isRepeated)
    {
        // Log the message
        Serial.print("Received from ");
        switch (sender)
        {
        case Sender::CoffeeMachine:
            Serial.print("Coffee Machine: ");
            break;
        case Sender::Panel:
            Serial.print("Panel: ");
            break;
        default:
            Serial.print("Unknown Sender: ");
            break;
        }

        for (size_t i = 0; i < length; i++)
        {
            Serial.print("0x");
            if (message[i] < 0x10)
                Serial.print("0");
            Serial.print(message[i], HEX);
            Serial.print(" ");
        }
        Serial.println();

        // Store the message for future comparison
        if (logOnlyIfNotRepeated)
        {
            memcpy(lastMessage, message, length);
            lastMessageLength = length;
            lastSender = sender;
            hasLastMessage = true;
        }
    }
}