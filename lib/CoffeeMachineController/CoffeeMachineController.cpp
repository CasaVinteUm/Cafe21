#include "CoffeeMachineController.h"

CoffeeMachineController::CoffeeMachineController(HardwareSerial &serial)
    : serialPort(serial), waitingForOnState(false), onStateCounter(0)
{
}

void CoffeeMachineController::updateState(const CoffeeMachineMessage &message)
{
    stateMachine.updateState(message);
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
        sendCommandMessage(CoffeeMachineCommand::Beep, 0);
        return false;
    }
    else if (currState == CoffeeMachineState::WaitingForOn)
    {
        sendCommandMessage(CoffeeMachineCommand::On, 0);
        return false;
    }
    else // if (currState == CoffeeMachineState::TurningOn || currState == CoffeeMachineState::Ready)
    {
        onStateCounter = 0;
        waitingForOnState = false;
        return true;
    }
}

bool CoffeeMachineController::sendCommand(CoffeeMachineCommand command, byte destination)
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
                Serial.printf("Command: %s sent successfully.", coffeeMachineCommandString(command).c_str());
                Serial.println();
            }
            return true;
        }
        else
        {
            CoffeeMachineState currState = stateMachine.getCurrentState();
            if (currState != CoffeeMachineState::Off)
            {
                Serial.printf("Command: %s not allowed in the current state: %s",
                              coffeeMachineCommandString(command).c_str(),
                              coffeeMachineStateString(currState).c_str());
                Serial.println();
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