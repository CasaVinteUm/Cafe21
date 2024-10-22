#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H
#include <HardwareSerial.h>

#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"

class CoffeeMachineController
{
public:
#ifdef USE_I2C
    CoffeeMachineController();
#else
    CoffeeMachineController(HardwareSerial &serial);
#endif
    void updateState(const CoffeeMachineMessage &message);
    bool sendOnCommand();
    bool sendCommand(CoffeeMachineCommand command, byte destinationS);

    CoffeeMachineState getCurrentState() const;

private:
    HardwareSerial &serialPort;
    CoffeeMachineStateMachine stateMachine;
    bool waitingForOnState;
    byte onStateCounter;

    void sendCommandMessage(CoffeeMachineCommand command);
    std::string coffeeMachineStateString(CoffeeMachineState state);
    std::string coffeeMachineCommandString(CoffeeMachineCommand command);
};

#endif // COFFEEMACHINECONTROLLER_H