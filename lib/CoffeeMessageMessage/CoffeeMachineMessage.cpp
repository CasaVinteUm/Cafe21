#include "CoffeeMachineMessage.h"

CoffeeMachineMessage::CoffeeMachineMessage()
{
    messageType = 0;
    ledEspresso = 0;
    ledCoffee = 0;
    ledHotWater = false;
    ledSteam = false;
    coffeeStrength = 0;
    quantity = 0;
    noWater = false;
    cleanTrash = false;
    generalWarning = false;
    play = false;
    loading = false;
}

CoffeeMachineMessage::CoffeeMachineMessage(const uint8_t *message, size_t length)
{
    if (length < 19)
    {
        // Handle error: message too short
        return;
    }
    // Parse the message
    // Bytes 0-1: Header (0xD5 0x55), check if correct and discard
    if (message[0] != 0xD5 || message[1] != 0x55)
    {
        // Handle error: invalid header
        return;
    }

    // Byte 2: Message type
    messageType = message[2];

    // Bytes 3-6: LED status
    switch (message[3])
    {
    case 0x07:
        ledEspresso = 1;
        break;
    case 0x38:
        ledEspresso = 2;
        break;
    case 0x00:
    default:
        ledEspresso = 0;
        break;
    }

    ledHotWater = message[4] == 0x07;

    switch (message[5])
    {
    case 0x07:
        ledCoffee = 1;
        break;
    case 0x38:
        ledCoffee = 2;
        break;
    case 0x00:
    default:
        ledCoffee = 0;
        break;
    }

    ledSteam = message[6] == 0x07;

    // Byte 7: Unknown (skip)

    // Bytes 8-9: Coffee Strength
    switch (message[8])
    {
    case 0x00:
        coffeeStrength = message[9] == 0x07 ? 1 : 0;
        break;
    case 0x38:
        coffeeStrength = 2;
        break;
    case 0x3F:
        coffeeStrength = 3;
        break;
    default:
        coffeeStrength = 0; // Unknown
        break;
    }

    // Bytes 10-11: Quantity
    switch (message[10])
    {
    case 0x00:
        quantity = message[11] == 0x07 ? 1 : 0;
        break;
    case 0x38:
        quantity = 2;
        break;
    case 0x3F:
        quantity = 3;
        break;
    default:
        quantity = 0; // Unknown
        break;
    }

    // Byte 12: Unknown (skip)

    // Byte 13: No Water indicator
    noWater = (message[13] == 0x38);

    // Byte 14: Clean Trash indicator
    cleanTrash = (message[14] == 0x38);

    // Byte 15: General Warning
    generalWarning = (message[15] == 0x38);

    // Byte 16: Play button status
    play = (message[16] == 0x07);

    if ((message[3] == 0x03 || message[4] == 0x03 || message[5] == 0x03 || message[6] == 0x03) && (message[3] == 0x07 || message[4] == 0x07 || message[5] == 0x07 || message[6] == 0x07))
    {
        loading = true;
    }
}

bool CoffeeMachineMessage::operator==(const CoffeeMachineMessage &other) const
{
    return messageType == other.messageType &&
           ledEspresso == other.ledEspresso &&
           ledCoffee == other.ledCoffee &&
           ledHotWater == other.ledHotWater &&
           ledSteam == other.ledSteam &&
           coffeeStrength == other.coffeeStrength &&
           quantity == other.quantity &&
           noWater == other.noWater &&
           cleanTrash == other.cleanTrash &&
           generalWarning == other.generalWarning &&
           play == other.play;
}