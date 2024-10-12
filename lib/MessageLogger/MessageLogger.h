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

private:
    uint8_t lastMessage[256];
    size_t lastMessageLength;
    Sender lastSender;
    bool hasLastMessage;
};

#endif // MESSAGELOGGER_H