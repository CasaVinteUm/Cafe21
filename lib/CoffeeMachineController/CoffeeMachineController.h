#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H

#include <HardwareSerial.h>
#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"

class CoffeeMachineController
{
public:
    CoffeeMachineController(HardwareSerial &serial);

    void updateState(const CoffeeMachineMessage &message);
    bool sendOnCommand();
    bool sendCommand(CoffeeMachineCommand command);

    CoffeeMachineState getCurrentState() const;

private:
    HardwareSerial &serialPort;
    CoffeeMachineStateMachine stateMachine;
    bool waitingForOnState;
    byte onStateCounter;

    void sendCommandMessage(CoffeeMachineCommand command);
};

#endif // COFFEEMACHINECONTROLLER_H