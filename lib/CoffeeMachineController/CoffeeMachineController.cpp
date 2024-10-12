#include "CoffeeMachineController.h"

CoffeeMachineController::CoffeeMachineController(HardwareSerial &serial)
    : serialPort(serial), awaitingConfirmation(false), retryCount(0)
{
}

bool CoffeeMachineController::sendCommand(CoffeeMachineCommand command)
{
    if (!stateMachine.canSendCommand(command))
    {
        Serial.println("Command not allowed in the current state.");
        return false;
    }

    lastCommandSent = command;
    retryCount = 0;
    awaitingConfirmation = true;

    sendCommandMessage(command);
    return true;
}

void CoffeeMachineController::sendCommandMessage(CoffeeMachineCommand command)
{
    uint8_t message[12] = {0};

    // Header
    message[0] = 0xD5;
    message[1] = 0x55;

    // Message Type
    message[2] = 0x00;

    // Common bytes
    message[3] = 0x01;
    message[4] = 0x00;
    message[5] = 0x00;
    message[6] = 0x02;
    message[7] = 0x00;
    message[8] = 0x00;
    message[9] = 0x00;

    // Command-specific bytes
    switch (command)
    {
    case CoffeeMachineCommand::Espresso:
        message[7] = 0x02; // Select Espresso
        message[10] = 0x19;
        message[11] = 0x0F;
        beverageQty = stateMachine.getCurrentMessage().ledEspresso;
        break;
    case CoffeeMachineCommand::Coffee:
        message[7] = 0x08; // Select Coffee
        message[10] = 0x29;
        message[11] = 0x3E;
        beverageQty = stateMachine.getCurrentMessage().ledCoffee;
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
    Serial.println("Command sent, waiting for response...");

    serialPort.write(message, 12);
}

void CoffeeMachineController::handleReceivedMessage(const CoffeeMachineMessage &message)
{
    // Update the state machine with the new message
    stateMachine.updateState(message);

    // If we are awaiting confirmation, check if the command was applied
    if (awaitingConfirmation)
    {
        if (isCommandApplied(message))
        {
            Serial.println("Command applied successfully.");
            awaitingConfirmation = false;
            retryCount = 0;
            beverageQty = 0;
        }
        else
        {
            unsigned long currentTime = millis();
            if (currentTime - lastRetryTime >= retryInterval * retryCount)
            {
                // Retry sending the command if maximum retries not reached
                retryCount++;
                if (retryCount <= maxRetries)
                {
                    Serial.println("Command not applied, retrying...");
                    sendCommandMessage(lastCommandSent);
                    lastRetryTime = currentTime;
                }
                else
                {
                    Serial.println("Failed to apply command after maximum retries.");
                    awaitingConfirmation = false;
                    retryCount = 0;
                }
            }
            else
            {
                Serial.println("Easy, cowboy...");
            }
        }
    }
}

bool CoffeeMachineController::isCommandApplied(const CoffeeMachineMessage &message) const
{
    switch (lastCommandSent)
    {
    case CoffeeMachineCommand::Espresso:
        return stateMachine.getCurrentState() == CoffeeMachineState::Selected && (message.ledEspresso != beverageQty);
    case CoffeeMachineCommand::Coffee:
        return stateMachine.getCurrentState() == CoffeeMachineState::Selected && (message.ledCoffee != beverageQty);
    case CoffeeMachineCommand::HotWater:
        return stateMachine.getCurrentState() == CoffeeMachineState::Selected && message.ledHotWater;
    case CoffeeMachineCommand::Steam:
        return stateMachine.getCurrentState() == CoffeeMachineState::Selected && message.ledSteam;
    case CoffeeMachineCommand::Start:
        // Check if brewing has started
        return stateMachine.getCurrentState() == CoffeeMachineState::Brewing;
    case CoffeeMachineCommand::Stop:
        // Check if brewing has stopped
        return stateMachine.getCurrentState() != CoffeeMachineState::Brewing;
    default:
        return false;
    }
}

CoffeeMachineState CoffeeMachineController::getCurrentState() const
{
    return stateMachine.getCurrentState();
}