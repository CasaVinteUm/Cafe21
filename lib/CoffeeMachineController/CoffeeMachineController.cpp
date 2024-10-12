#include "CoffeeMachineController.h"

CoffeeMachineController::CoffeeMachineController(HardwareSerial &serial)
    : serialPort(serial)
{
}

void CoffeeMachineController::updateState(const CoffeeMachineMessage &message)
{
    stateMachine.updateState(message);
}

bool CoffeeMachineController::sendCommand(CoffeeMachineCommand command)
{
    if (stateMachine.canSendCommand(command))
    {
        sendCommandMessage(command);
        Serial.println("Command sent successfully.");
        return true;
    }
    else
    {
        Serial.println("Command not allowed in the current state.");
        return false;
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

    // // Compute checksum for bytes 0-9
    // uint16_t checksum = computeChecksum(message, 10);

    // // Insert checksum (big-endian)
    // message[10] = (checksum >> 8) & 0xFF;
    // message[11] = checksum & 0xFF;

    // Send the message
    serialPort.write(message, 12);
}

uint16_t CoffeeMachineController::computeChecksum(const uint8_t *data, size_t length)
{
    // Implement the correct checksum calculation based on the coffee machine's protocol
    uint16_t sum = 0;
    for (size_t i = 0; i < length; i++)
    {
        sum += data[i];
    }
    return sum;
}