#include "CoffeeMachineStateMachine.h"

CoffeeMachineStateMachine::CoffeeMachineStateMachine() : currentState(CoffeeMachineState::Off)
{
}

bool CoffeeMachineStateMachine::updateState(const CoffeeMachineMessage &message)
{
    if (currentMessage == message)
        return false;

    lastMessage = currentMessage;
    currentMessage = message;

    if (isWaitingForOnState(message))
    {
        currentState = CoffeeMachineState::WaitingForOn;
    }
    else if (isTurningOnState(message))
    {
        currentState = CoffeeMachineState::TurningOn;
    }
    else if (isErrorState(message))
    {
        currentState = CoffeeMachineState::Error;
    }
    else if (isBrewingState(message, lastMessage))
    {
        currentState = CoffeeMachineState::Brewing;
    }
    else if (isReadyState(message))
    {
        currentState = CoffeeMachineState::Ready;
    }
    else if (isSelectedState(message, lastMessage))
    {
        currentState = CoffeeMachineState::Selected;

        if (message.ledCoffee != 0x00)
        {
            coffeeOptions.type = CoffeeType::COFFEE;
            coffeeOptions.quantity = message.ledCoffee;
        }
        else if (message.ledEspresso != 0x00)
        {
            coffeeOptions.type = CoffeeType::ESPRESSO;
            coffeeOptions.quantity = message.ledEspresso;
        }
        else if (message.ledHotWater)
        {
            coffeeOptions.type = CoffeeType::NONE;
        }
        else if (message.ledSteam)
        {
            coffeeOptions.type = CoffeeType::NONE;
        }

        if (message.ledCoffee != 0x00 || message.ledEspresso != 0x00 || message.ledHotWater)
        {
            switch (message.quantity)
            {
            case 1:
                coffeeOptions.size = SizeLevel::SMALL;
                break;
            case 2:
                coffeeOptions.size = SizeLevel::MEDIUM;
                break;
            case 3:
                coffeeOptions.size = SizeLevel::LARGE;
                break;
            default:
                break;
            }
        }

        if (message.ledCoffee != 0x00 || message.ledEspresso != 0x00)
        {
            switch (message.coffeeStrength)
            {
            case 1:
                coffeeOptions.strength = StrengthLevel::MILD;
                break;
            case 2:
                coffeeOptions.strength = StrengthLevel::MEDIUM;
                break;
            case 3:
                coffeeOptions.strength = StrengthLevel::STRONG;
                break;
            }
        }
    }
    else if (isLoadingState(message))
    {
        currentState = CoffeeMachineState::Loading;
    }
    else
    {
        log_d("State is unknown, setting Loading.");
        // Default to Loading if no state matches
        currentState = CoffeeMachineState::Loading;
    }

    return true;
}

CoffeeMachineError CoffeeMachineStateMachine::GetCurrentError() const
{
    if (currentMessage.generalWarning)
    {
        return CoffeeMachineError::GENERAL;
    }

    if (currentMessage.noWater)
    {
        return CoffeeMachineError::NOWATER;
    }

    if (currentMessage.cleanTrash)
    {
        return CoffeeMachineError::TRASH;
    }

    return CoffeeMachineError::NONE;
}

bool CoffeeMachineStateMachine::canSendCommand(CoffeeMachineCommand command) const
{
    if (command == CoffeeMachineCommand::On)
        return true;

    switch (currentState)
    {
    case CoffeeMachineState::Off:
        return command == CoffeeMachineCommand::Beep;
    case CoffeeMachineState::WaitingForOn:
        return command == CoffeeMachineCommand::On;
    case CoffeeMachineState::TurningOn:
    case CoffeeMachineState::Loading:
        return command == CoffeeMachineCommand::Status;
    case CoffeeMachineState::Ready:
        // Can send Espresso, Coffee, HotWater, Steam commands
        return command == CoffeeMachineCommand::Espresso ||
               command == CoffeeMachineCommand::Coffee ||
               command == CoffeeMachineCommand::HotWater ||
               command == CoffeeMachineCommand::Steam ||
               command == CoffeeMachineCommand::Status;
    case CoffeeMachineState::Selected:
        // Can send Start, Strength, Quantity, or selection commands
        if (command == CoffeeMachineCommand::StartStop ||
            command == CoffeeMachineCommand::Espresso ||
            command == CoffeeMachineCommand::Coffee ||
            command == CoffeeMachineCommand::HotWater ||
            command == CoffeeMachineCommand::Steam ||
            command == CoffeeMachineCommand::Status)
        {
            return true;
        }
        else
        {
            if (lastMessage.ledHotWater)
            {
                return command == CoffeeMachineCommand::Quantity;
            }
            else if (coffeeOptions.type == CoffeeType::COFFEE || coffeeOptions.type == CoffeeType::ESPRESSO)
            {
                return command == CoffeeMachineCommand::Quantity || command == CoffeeMachineCommand::Strength;
            }
            else if (lastMessage.ledSteam)
                return false;
        }
    case CoffeeMachineState::Brewing:
        return command == CoffeeMachineCommand::StartStop ||
               command == CoffeeMachineCommand::Status;
    case CoffeeMachineState::Error:
        return command == CoffeeMachineCommand::Status;
    default:
        return false;
    }
}

CoffeeMachineState CoffeeMachineStateMachine::getCurrentState() const
{
    return currentState;
}

CoffeeOptions CoffeeMachineStateMachine::getCurrentOptions() const
{
    return coffeeOptions;
}

bool CoffeeMachineStateMachine::isWaitingForOnState(const CoffeeMachineMessage &message) const
{
    return message.messageType == 0x01 && message.cleanTrash == 0x00 && message.coffeeStrength == 0x00 && message.generalWarning == 0x00 && message.ledCoffee == 0x00 && message.ledEspresso == 0x00 && message.ledHotWater == 0x00 && message.ledSteam == 0x00 && message.noWater == 0x00 && message.play == 0x00;
}

bool CoffeeMachineStateMachine::isTurningOnState(const CoffeeMachineMessage &message) const
{
    return message.messageType == 0x00 && message.cleanTrash == 0x00 && message.coffeeStrength == 0x00 && message.generalWarning == 0x00 && message.ledCoffee == 0x00 && message.ledEspresso == 0x00 && message.ledHotWater == 0x00 && message.ledSteam == 0x00 && message.noWater == 0x00 && message.play == 0x00;
}

bool CoffeeMachineStateMachine::isLoadingState(const CoffeeMachineMessage &message) const
{
    return message.loading;
}

bool CoffeeMachineStateMachine::isReadyState(const CoffeeMachineMessage &message) const
{
    return message.ledEspresso == 0x01 && message.ledCoffee == 0x01 &&
           message.ledHotWater && message.ledSteam;
}

bool CoffeeMachineStateMachine::isSelectedState(const CoffeeMachineMessage &message, const CoffeeMachineMessage &lastMessage) const
{
    // Check if any selection is made
    bool selectionMade = (message.ledEspresso == 1 || message.ledEspresso == 2 ||
                          message.ledCoffee == 1 || message.ledCoffee == 2 ||
                          message.ledHotWater || message.ledSteam);
    bool sizeAndStrength = (message.coffeeStrength != 0 || message.quantity != 0);
    bool isPlayBlinking = message.play != lastMessage.play;
    return selectionMade && (isPlayBlinking || sizeAndStrength);
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