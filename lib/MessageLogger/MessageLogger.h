#ifndef MESSAGELOGGER_H
#define MESSAGELOGGER_H

#include <Arduino.h>

// Enum for sender types
enum class Sender
{
    CoffeeMachine,
    Panel
};

class MessageLogger
{
public:
    MessageLogger();
    void logMessage(Sender sender, const uint8_t *message, size_t length, bool logOnlyIfNotRepeated = true);

    static const void hexDump(const uint8_t *data, size_t length, char *buffer, size_t bufferSize);

private:
    uint8_t lastMessage[256];
    size_t lastMessageLength;
    Sender lastSender;
    bool hasLastMessage;
    const char *senderString(Sender sender);
};

#endif // MESSAGELOGGER_H