#include "MessageLogger.h"

MessageLogger::MessageLogger() : lastMessageLength(0), hasLastMessage(false)
{
}

void MessageLogger::logMessage(Sender sender, const uint8_t *message, size_t length, bool logOnlyIfNotRepeated)
{
#if ARDUHAL_LOG_LEVEL >= ARDUHAL_LOG_LEVEL_VERBOSE
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
        char hexString[length * 5 + 1];
        hexDump(message, length, hexString, sizeof(hexString));

        log_v("Message from %s: %s", senderString(sender), hexString);

        // Store the message for future comparison
        if (logOnlyIfNotRepeated)
        {
            memcpy(lastMessage, message, length);
            lastMessageLength = length;
            lastSender = sender;
            hasLastMessage = true;
        }
    }
#endif
}

// Function to convert byte array to hex string
const void MessageLogger::hexDump(const uint8_t *data, size_t length, char *buffer, size_t bufferSize)
{
    int written = 0;
    for (size_t i = 0; i < length && written < bufferSize - 4; i++)
    { // -4 for safety
        written += snprintf(buffer + written, bufferSize - written,
                            "%s0x%02X", i > 0 ? " " : "", data[i]);
    }
}

const char *MessageLogger::senderString(Sender sender)
{
    switch (sender)
    {
    case Sender::CoffeeMachine:
        return "Coffee Machine";
        break;
    case Sender::Panel:
        return "Panel";
        break;
    default:
        return "Unknown Sender";
        break;
    }
}