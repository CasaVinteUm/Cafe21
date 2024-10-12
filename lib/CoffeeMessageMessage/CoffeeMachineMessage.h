#ifndef COFFEEMACHINEMESSAGE_H
#define COFFEEMACHINEMESSAGE_H

#include <Arduino.h>

/// @brief Bytes:
/// 0-1: Header
/// 2: Message type (as you noted before.
/// 3-6: Led status for Expresso x1, Cofee x1, Hot Water, Steam
/// 7: Unknown
/// 8-9: Coffee Strength, 8 -> 0x00 (1 led), 0x38 (2 leds), 0x3f (3 leds). 9 -> 0x07
/// 10-11: Quantity, 10 -> 0x00 (1 led), 0x38 (2 leds), 0x3f (3 leds). 11 -> 0x07
/// 12: Unknown
/// 13: No Water -> 0x38
/// 14: Clean Trash -> 0x38
/// 15: General Warning -> 0x38
/// 16: Play -> ON = 0x07, Off = 0x00
/// 17-18: CRC
class CoffeeMachineMessage
{
public:
    uint8_t messageType;
    uint8_t ledEspresso;
    uint8_t ledCoffee;
    bool ledHotWater;
    bool ledSteam;
    uint8_t coffeeStrength; // 1-3 corresponding to the number of LEDs lit
    uint8_t quantity;       // 1-3 corresponding to the number of LEDs lit
    bool noWater;
    bool cleanTrash;
    bool generalWarning;
    bool play;

    // Default constructor
    CoffeeMachineMessage();

    // Constructor to parse from raw message
    CoffeeMachineMessage(const uint8_t *message, size_t length);

    // Equality operator to compare messages
    bool operator==(const CoffeeMachineMessage &other) const;
    bool operator!=(const CoffeeMachineMessage &other) const { return !(*this == other); }

    // For debugging: print the message
    void print() const;
};

#endif // COFFEEMACHINEMESSAGE_H