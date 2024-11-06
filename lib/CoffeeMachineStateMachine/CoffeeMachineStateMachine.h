#ifndef COFFEEMACHINESTATEMACHINE_H
#define COFFEEMACHINESTATEMACHINE_H

#include "CoffeeMachineState.h"
#include "CoffeeMachineCommand.h"
#include "CoffeeMachineMessage.h"
#include "CoffeeOptions.h"

class CoffeeMachineStateMachine
{
public:
    CoffeeMachineStateMachine();

    bool updateState(const CoffeeMachineMessage &message);
    bool canSendCommand(CoffeeMachineCommand command) const;
    CoffeeMachineState getCurrentState() const;
    CoffeeOptions getCurrentOptions() const;

private:
    CoffeeMachineState currentState;
    CoffeeMachineMessage currentMessage;
    CoffeeMachineMessage lastMessage;
    CoffeeOptions coffeeOptions;

    // Helper functions
    bool isWaitingForOnState(const CoffeeMachineMessage &message) const;
    bool isTurningOnState(const CoffeeMachineMessage &message) const;
    bool isLoadingState(const CoffeeMachineMessage &message) const;
    bool isReadyState(const CoffeeMachineMessage &message) const;
    bool isSelectedState(const CoffeeMachineMessage &message, const CoffeeMachineMessage &lastMessage) const;
    bool isBrewingState(const CoffeeMachineMessage &message, const CoffeeMachineMessage &lastMessage) const;
    bool isErrorState(const CoffeeMachineMessage &message) const;

    // Helper functions for LED state
    bool isLEDOn(uint8_t ledValue) const;
    bool isBlinkingLED(uint8_t currentLED, uint8_t lastLED) const;
};

#endif // COFFEEMACHINESTATEMACHINE_H