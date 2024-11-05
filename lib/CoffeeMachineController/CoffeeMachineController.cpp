#include "CoffeeMachineController.h"

CoffeeMachineController::CoffeeMachineController(HardwareSerial &serial)
    : serialPort(serial), waitingForOnState(false), onStateCounter(0)
{
}

void CoffeeMachineController::updateState(const CoffeeMachineMessage &message)
{
    stateMachine.updateState(message);

#ifndef NO_DEBUG_SERIAL
    CoffeeMachineState currState = stateMachine.getCurrentState();
    Serial.printf("Current State: %s ->", coffeeMachineStateString(currState).c_str());

    if (currState == CoffeeMachineState::Selected)
    {
        if (message.ledCoffee != 0x00)
        {
            Serial.printf(" %d Cafe - ", message.ledCoffee);
        }
        else if (message.ledEspresso != 0x00)
        {
            Serial.printf(" %d Espresso - ", message.ledEspresso);
        }
        else if (message.ledHotWater)
        {
            Serial.print("Cha - ");
        }
        else if (message.ledSteam)
        {
            Serial.print("Vapor");
        }

        if (message.ledCoffee != 0x00 || message.ledEspresso != 0x00 || message.ledHotWater)
        {
            Serial.printf("%d ", message.quantity);
        }

        if (message.ledCoffee != 0x00 || message.ledEspresso != 0x00)
        {
            switch (message.coffeeStrength)
            {
            case 1:
                Serial.print("fraco");
                break;
            case 2:
                Serial.print("médio");
                break;
            case 3:
                Serial.print("forte");
                break;
            }
        }
    }

    Serial.println();
#endif // DEBUG_SERIAL
}

bool CoffeeMachineController::sendOnCommand()
{
    if (!waitingForOnState)
    {
        waitingForOnState = true;
    }
    CoffeeMachineState currState = stateMachine.getCurrentState();

    if (onStateCounter < 10 && currState == CoffeeMachineState::Off)
    {
        onStateCounter++;
        sendCommandMessage(CoffeeMachineCommand::Beep);
        return false;
    }
    else if (currState == CoffeeMachineState::WaitingForOn)
    {
        sendCommandMessage(CoffeeMachineCommand::On);
        return false;
    }
    else
    {
        onStateCounter = 0;
        waitingForOnState = false;
        return true;
    }
}

bool CoffeeMachineController::sendCommand(CoffeeMachineCommand command)
{
    if (waitingForOnState)
    {
        return sendOnCommand();
    }
    else
    {
        if (stateMachine.canSendCommand(command))
        {
            sendCommandMessage(command);
            if (command != CoffeeMachineCommand::Status)
            {
#ifndef NO_DEBUG_SERIAL
                Serial.printf("Command: %s sent successfully.", coffeeMachineCommandString(command).c_str());
                Serial.println();
#endif // DEBUG_SERIAL
            }
            return true;
        }
        else
        {
            CoffeeMachineState currState = stateMachine.getCurrentState();
            if (currState != CoffeeMachineState::Off)
            {
#ifndef NO_DEBUG_SERIAL
                Serial.printf("Command: %s not allowed in the current state: %s",
                              coffeeMachineCommandString(command).c_str(),
                              coffeeMachineStateString(currState).c_str());
                Serial.println();
#endif // DEBUG_SERIAL
            }
            return false;
        }
    }
}

CoffeeMachineState CoffeeMachineController::getCurrentState() const
{
    return stateMachine.getCurrentState();
}

void CoffeeMachineController::sendCommandMessage(CoffeeMachineCommand command)
{
    uint8_t message[12] = {0};

    // Header
    message[0] = 0xD5;
    message[1] = 0x55;

    // Message Type
    message[2] = 0x00;

    // Common bytes based on tested commands
    message[3] = 0x01;
    message[4] = 0x02;
    message[5] = 0x00;
    message[6] = 0x09;
    message[7] = 0x00;
    message[8] = 0x00;
    message[9] = 0x00;
    message[10] = 0x16;
    message[11] = 0x31;

    // Set command-specific bytes
    switch (command)
    {
    case CoffeeMachineCommand::Status:
        break;
    case CoffeeMachineCommand::Beep:
        message[2] = 0x0A;
        message[10] = 0x09;
        message[11] = 0x15;
        break;
    case CoffeeMachineCommand::On:
        message[2] = 0x01;
        message[10] = 0x22;
        message[11] = 0x20;
        break;
    case CoffeeMachineCommand::Espresso:
        message[7] = 0x02;
        message[10] = 0x0E;
        message[11] = 0x2A;
        break;
    case CoffeeMachineCommand::Coffee:
        message[7] = 0x08;
        message[10] = 0x3E;
        message[11] = 0x1B;
        break;
    case CoffeeMachineCommand::HotWater:
        message[7] = 0x04;
        message[10] = 0x26;
        message[11] = 0x06;
        break;
    case CoffeeMachineCommand::Steam:
        message[7] = 0x10;
        message[10] = 0x0E;
        message[11] = 0x21;
        break;
    case CoffeeMachineCommand::StartStop:
        message[9] = 0x01;
        message[10] = 0x1E;
        message[11] = 0x35;
        break;
    case CoffeeMachineCommand::Strength:
        message[8] = 0x02;
        message[10] = 0x0E;
        message[11] = 0x28;
        break;
    case CoffeeMachineCommand::Quantity:
        message[8] = 0x04;
        message[10] = 0x27;
        message[11] = 0x02;
        break;
    default:
        break;
    }

    // Send the message
    serialPort.write(message, 12);
}

void CoffeeMachineController::selectCoffee(CoffeeType type)
{
    selectedType = type;
}

void CoffeeMachineController::startOrder()
{
    // Send command to select the right type of coffee
    if (!sendCommand(selectedType == CoffeeType::COFFEE ? CoffeeMachineCommand::Coffee : CoffeeMachineCommand::Espresso))
    {
#ifndef NO_DEBUG_SERIAL
        Serial.println("Error sending command");
#endif // DEBUG_SERIAL
        return;
    }

    // Check if 1 coffee type is selected
    CoffeeOptions options = stateMachine.getCurrentOptions();
    while (stateMachine.getCurrentState() != CoffeeMachineState::Selected || options.type != selectedType || options.quantity != 1)
    {
        if (!sendCommand(CoffeeMachineCommand::Coffee))
        {
#ifndef NO_DEBUG_SERIAL
            Serial.println("Error sending Coffee command");
#endif // DEBUG_SERIAL
            return;
        }
        options = stateMachine.getCurrentOptions();

        yield();
    }

    // check if strength is right
    options = stateMachine.getCurrentOptions();
    while (options.strength != StrengthLevel::STRONG)
    {
        if (!sendCommand(CoffeeMachineCommand::Strength))
        {
#ifndef NO_DEBUG_SERIAL
            Serial.println("Error sending strength command");
#endif // DEBUG_SERIAL
            return;
        }

        options = stateMachine.getCurrentOptions();
    }

    // check if size is right
    options = stateMachine.getCurrentOptions();
    while (options.size != SizeLevel::MEDIUM)
    {
        if (!sendCommand(CoffeeMachineCommand::Quantity))
        {
#ifndef NO_DEBUG_SERIAL
            Serial.println("Error sending size command");
#endif // DEBUG_SERIAL
            return;
        }

        options = stateMachine.getCurrentOptions();
    }

    if (!sendCommand(CoffeeMachineCommand::StartStop))
    {
#ifndef NO_DEBUG_SERIAL
        Serial.println("Error sending start command");
#endif // DEBUG_SERIAL
        return;
    }
}

std::string CoffeeMachineController::coffeeMachineStateString(CoffeeMachineState state)
{
    switch (state)
    {
    case CoffeeMachineState::Brewing:
        return "Brewing";
    case CoffeeMachineState::Error:
        return "Error";
    case CoffeeMachineState::Loading:
        return "Loading";
    case CoffeeMachineState::Ready:
        return "Ready";
    case CoffeeMachineState::Selected:
        return "Selected";
    case CoffeeMachineState::TurningOn:
        return "TurningOn";
    case CoffeeMachineState::WaitingForOn:
        return "WaitingForOn";
    default:
        return "Unknown";
    }
}

std::string CoffeeMachineController::coffeeMachineCommandString(CoffeeMachineCommand command)
{
    switch (command)
    {
    case CoffeeMachineCommand::Beep:
        return "Beep";
    case CoffeeMachineCommand::On:
        return "On";
    case CoffeeMachineCommand::Espresso:
        return "Espresso";
    case CoffeeMachineCommand::Coffee:
        return "Coffee";
    case CoffeeMachineCommand::HotWater:
        return "HotWater";
    case CoffeeMachineCommand::Steam:
        return "Steam";
    case CoffeeMachineCommand::StartStop:
        return "StartStop";
    case CoffeeMachineCommand::Strength:
        return "Strength";
    case CoffeeMachineCommand::Quantity:
        return "Quantity";
    case CoffeeMachineCommand::Status:
        return "Status";
    default:
        return "Unknown";
    }
}