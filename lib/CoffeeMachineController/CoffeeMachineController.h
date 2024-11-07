#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H
#include <HardwareSerial.h>
#include "esp_log.h"

#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"
#include "CoffeeOptions.h"
#include "MessageLogger.h"

class CoffeeMachineController
{
public:
    CoffeeMachineController(HardwareSerial &serial, MessageLogger &logger);

    void updateState(const CoffeeMachineMessage &message);
    bool sendOnCommand();
    bool sendCommand(CoffeeMachineCommand command);
    void selectCoffee(CoffeeType type);
    void startOrder();
    CoffeeMachineError getCurrentError() { return stateMachine.GetCurrentError(); }

    void loop();

    CoffeeType getSelectedCoffee() { return selectedType; }
    CoffeeMachineState getCurrentState() const;

private:
    HardwareSerial &serialPort;
    MessageLogger &logger;
    CoffeeMachineStateMachine stateMachine;
    bool waitingForOnState;
    byte onStateCounter;
    CoffeeType selectedType = CoffeeType::NONE;
    bool isSelectingOrder;

    void sendCommandMessage(CoffeeMachineCommand command);
    const char *coffeeMachineStateString(CoffeeMachineState state);
    const char *coffeeMachineCommandString(CoffeeMachineCommand command);
    const char *coffeeTypeString(CoffeeType type);
    const char *coffeeSizeLevelString(SizeLevel size);
    const char *coffeeStrengthLevelString(StrengthLevel strength);
};

#endif // COFFEEMACHINECONTROLLER_H