#include "CoffeeMachineStateMachine.h"

CoffeeMachineStateMachine::CoffeeMachineStateMachine()
    : currentState(CoffeeMachineState::Loading)
{
}

void CoffeeMachineStateMachine::updateState(const CoffeeMachineMessage &message)
{
    if (currentMessage == message)
        return;

    lastMessage = currentMessage;
    currentMessage = message;

    Serial.print("Current State: ");

    if (isErrorState(message))
    {
        currentState = CoffeeMachineState::Error;
        Serial.println("Error");
    }
    else if (isBrewingState(message, lastMessage))
    {
        currentState = CoffeeMachineState::Brewing;
        Serial.println("Brewing");
    }
    else if (isReadyState(message))
    {
        currentState = CoffeeMachineState::Ready;
        Serial.println("Ready");
    }
    else if (isSelectedState(message, lastMessage))
    {
        currentState = CoffeeMachineState::Selected;
        Serial.println("Selected");
    }
    else if (isLoadingState(message))
    {
        currentState = CoffeeMachineState::Loading;
        Serial.println("Loading");
    }
    else
    {
        // Default to Loading if no state matches
        currentState = CoffeeMachineState::Loading;
        Serial.println("State Unknown");
    }
}

bool CoffeeMachineStateMachine::canSendCommand(CoffeeMachineCommand command) const
{
    switch (currentState)
    {
    case CoffeeMachineState::Loading:
        // No commands can be sent during loading
        return false;
    case CoffeeMachineState::Ready:
        // Can send Espresso, Coffee, HotWater, Steam commands
        return command == CoffeeMachineCommand::Espresso ||
               command == CoffeeMachineCommand::Coffee ||
               command == CoffeeMachineCommand::HotWater ||
               command == CoffeeMachineCommand::Steam;
    case CoffeeMachineState::Selected:
        // Can send Start, Strength, Quantity, or selection commands
        if (command == CoffeeMachineCommand::Start ||
            command == CoffeeMachineCommand::Espresso ||
            command == CoffeeMachineCommand::Coffee ||
            command == CoffeeMachineCommand::HotWater ||
            command == CoffeeMachineCommand::Steam)
        {
            return true;
        }
        else
        {
            if (lastMessage.ledHotWater)
            {
                return command == CoffeeMachineCommand::Quantity;
            }
            else if (lastMessage.ledSteam)
                return false;
        }
    case CoffeeMachineState::Brewing:
        // Only Stop command can be sent
        return command == CoffeeMachineCommand::Stop;
    case CoffeeMachineState::Error:
        // No commands can be sent during error state
        return false;
    default:
        return false;
    }
}

CoffeeMachineState CoffeeMachineStateMachine::getCurrentState() const
{
    return currentState;
}

CoffeeMachineMessage CoffeeMachineStateMachine::getCurrentMessage() const
{
    return currentMessage;
}

bool CoffeeMachineStateMachine::isLoadingState(const CoffeeMachineMessage &message) const
{
    // Define the loading patterns
    const uint8_t pattern1[4] = {0x07, 0x00, 0x03, 0x07};
    const uint8_t pattern2[4] = {0x07, 0x07, 0x00, 0x03};
    const uint8_t pattern3[4] = {0x03, 0x07, 0x07, 0x00};
    const uint8_t pattern4[4] = {0x00, 0x03, 0x07, 0x07};

    // Get the current LED statuses in the order 3, 5, 6, 4
    uint8_t currentPattern[4] = {
        message.ledEspresso, // LED 3
        message.ledHotWater, // LED 5
        message.ledSteam,    // LED 6
        message.ledCoffee    // LED 4
    };

    // Check if currentPattern matches any of the loading patterns
    if ((memcmp(currentPattern, pattern1, 4) == 0) ||
        (memcmp(currentPattern, pattern2, 4) == 0) ||
        (memcmp(currentPattern, pattern3, 4) == 0) ||
        (memcmp(currentPattern, pattern4, 4) == 0))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool CoffeeMachineStateMachine::isReadyState(const CoffeeMachineMessage &message) const
{
    return message.ledEspresso == 0x01 && message.ledCoffee == 0x01 &&
           message.ledHotWater && message.ledSteam;
}

bool CoffeeMachineStateMachine::isSelectedState(const CoffeeMachineMessage &message, const CoffeeMachineMessage &lastMessage) const
{
    // Check if any selection is made
    bool selectionMade = (message.ledEspresso == 0x01 || message.ledEspresso == 0x02 ||
                          message.ledCoffee == 0x01 || message.ledCoffee == 0x02 ||
                          message.ledHotWater || message.ledSteam);
    bool isPlayBlinking = message.play != lastMessage.play;
    return selectionMade && isPlayBlinking;
}

bool CoffeeMachineStateMachine::isBrewingState(const CoffeeMachineMessage &message, const CoffeeMachineMessage &lastMessage) const
{
    // Check for blinking in selection LEDs
    int blinkingCount = 0;

    bool espressoBlinking = isBlinkingLED(message.ledEspresso, lastMessage.ledEspresso);
    bool coffeeBlinking = isBlinkingLED(message.ledCoffee, lastMessage.ledCoffee);
    bool hotWaterBlinking = isBlinkingLED(message.ledHotWater, lastMessage.ledHotWater);
    bool steamBlinking = isBlinkingLED(message.ledSteam, lastMessage.ledSteam);

    if (espressoBlinking)
        blinkingCount++;
    if (coffeeBlinking)
        blinkingCount++;
    if (hotWaterBlinking)
        blinkingCount++;
    if (steamBlinking)
        blinkingCount++;

    // Check if exactly one selection LED is blinking
    if (blinkingCount == 1 && message.play)
    {
        // Brewing state detected
        return true;
    }
    else
    {
        return false;
    }
}

bool CoffeeMachineStateMachine::isErrorState(const CoffeeMachineMessage &message) const
{
    return message.noWater || message.cleanTrash || message.generalWarning;
}

bool CoffeeMachineStateMachine::isLEDOn(uint8_t ledValue) const
{
    return ledValue != 0x00;
}

bool CoffeeMachineStateMachine::isBlinkingLED(uint8_t currentLED, uint8_t lastLED) const
{
    bool currentOn = isLEDOn(currentLED);
    bool lastOn = isLEDOn(lastLED);
    return currentOn != lastOn;
}