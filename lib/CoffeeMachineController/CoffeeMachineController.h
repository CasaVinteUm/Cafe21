#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H

#include <HardwareSerial.h>
#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"

class CoffeeMachineController
{
public:
    CoffeeMachineController(HardwareSerial &serial);

    bool sendCommand(CoffeeMachineCommand command);

    CoffeeMachineState getCurrentState() const;

    // New method to be called when a new message is received
    void handleReceivedMessage(const CoffeeMachineMessage &message);

private:
    HardwareSerial &serialPort;
    CoffeeMachineStateMachine stateMachine;

    // Command confirmation variables
    CoffeeMachineCommand lastCommandSent;
    bool awaitingConfirmation;
    int retryCount;
    const int maxRetries = 5; // Maximum number of retries
    unsigned long lastRetryTime;
    const unsigned long retryInterval = 400; // Retry every 200 milliseconds

    uint8_t beverageQty = 0;

    void sendCommandMessage(CoffeeMachineCommand command);
    uint16_t computeChecksum(const uint8_t *data, size_t length);

    // Helper method to check if the command was applied
    bool isCommandApplied(const CoffeeMachineMessage &message) const;
};

#endif // COFFEEMACHINECONTROLLER_H