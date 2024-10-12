#ifndef COFFEEMACHINESTATEMACHINE_H
#define COFFEEMACHINESTATEMACHINE_H

#include "CoffeeMachineState.h"
#include "CoffeeMachineCommand.h"
#include "CoffeeMachineMessage.h"

class CoffeeMachineStateMachine
{
public:
    CoffeeMachineStateMachine();

    void updateState(const CoffeeMachineMessage &message);
    bool canSendCommand(CoffeeMachineCommand command) const;
    CoffeeMachineState getCurrentState() const;
    CoffeeMachineMessage getCurrentMessage() const;

private:
    CoffeeMachineState currentState;
    CoffeeMachineMessage currentMessage;
    CoffeeMachineMessage lastMessage;

    // Helper functions
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