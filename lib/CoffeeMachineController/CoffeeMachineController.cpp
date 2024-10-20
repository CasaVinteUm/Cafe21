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
        sendCommandMessage(CoffeeMachineCommand::Beep);
        return false;
    }
    else
    {
        if (currState == CoffeeMachineState::WaitingForOn)
        {
            sendCommandMessage(CoffeeMachineCommand::On);
            return false;
        }
        else if (currState == CoffeeMachineState::TurningOn)
        {
            Serial.println("Setting waitingForOnState = false");
            onStateCounter = 0;
            waitingForOnState = false;
            return true;
        }
        else
        {
            Serial.println("Unknown state while turning on");
            return false;
        }
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
                Serial.println("Command sent successfully.");
            }
            return true;
        }
        else
        {
            CoffeeMachineState currState = stateMachine.getCurrentState();
            if (currState != CoffeeMachineState::Off)
            {
                Serial.println("Command not allowed in the current state");
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
    message[3] = 0x01; // Commonly 0x01
    message[4] = 0x00; // May vary for Start command
    message[5] = 0x00; // Always 0x00
    message[6] = 0x02; // Always 0x02
    message[7] = 0x00; // Varies based on command
    message[8] = 0x00; // Always 0x00
    message[9] = 0x00; // May vary for Start command

    // Set command-specific bytes
    switch (command)
    {
    case CoffeeMachineCommand::Beep:
        message[2] = 0x0A;
        message[4] = 0x02;
        message[6] = 0x09;
        message[10] = 0x09;
        message[11] = 0x15;
        break;
    case CoffeeMachineCommand::On:
        message[2] = 0x01;
        message[4] = 0x02;
        message[6] = 0x09;
        message[10] = 0x22;
        message[11] = 0x20;
        break;
    case CoffeeMachineCommand::Status:
        message[4] = 0x02;
        message[6] = 0x09;
        message[10] = 0x16;
        message[11] = 0x31;
        break;
    case CoffeeMachineCommand::Espresso:
        message[7] = 0x02; // Select Espresso
        message[10] = 0x19;
        message[11] = 0x0F;
        break;
    case CoffeeMachineCommand::Coffee:
        message[7] = 0x08; // Select Coffee
        message[10] = 0x29;
        message[11] = 0x3E;
        break;
    case CoffeeMachineCommand::HotWater:
        message[7] = 0x04; // Select Hot Water
        message[10] = 0x31;
        message[11] = 0x23;
        break;
    case CoffeeMachineCommand::Steam:
        message[7] = 0x10; // Select Steam
        message[10] = 0x19;
        message[11] = 0x04;
        break;
    case CoffeeMachineCommand::Start:
        message[4] = 0x02; // Start command indicator
        message[9] = 0x01; // Additional byte for Start
        message[10] = 0x19;
        message[11] = 0x32;
        break;
    case CoffeeMachineCommand::Stop:
        // Assuming Stop uses the same as Start but with different indicator
        message[4] = 0x02; // Stop command indicator
        message[9] = 0x00; // Differentiate from Start
        message[10] = 0x19;
        message[11] = 0x32;
        break;
    case CoffeeMachineCommand::Strength:
        // Set the appropriate byte for Strength if known
        break;
    case CoffeeMachineCommand::Quantity:
        // Set the appropriate byte for Quantity if known
        break;
    default:
        break;
    }

    // Send the message
    serialPort.write(message, 12);
}