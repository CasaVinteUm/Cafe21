#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H
#include <HardwareSerial.h>

#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"
#include "CoffeeOptions.h"

class CoffeeMachineController
{
public:
    CoffeeMachineController(HardwareSerial &serial);

    void updateState(const CoffeeMachineMessage &message);
    bool sendOnCommand();
    bool sendCommand(CoffeeMachineCommand command);
    void selectCoffee(CoffeeType type);
    void startOrder();

    CoffeeMachineState getCurrentState() const;

private:
    HardwareSerial &serialPort;
    CoffeeMachineStateMachine stateMachine;
    bool waitingForOnState;
    byte onStateCounter;
    CoffeeType selectedType = CoffeeType::NONE;
    bool isSelectingOrder;

    void sendCommandMessage(CoffeeMachineCommand command);
    std::string coffeeMachineStateString(CoffeeMachineState state);
    std::string coffeeMachineCommandString(CoffeeMachineCommand command);
};

#endif // COFFEEMACHINECONTROLLER_H