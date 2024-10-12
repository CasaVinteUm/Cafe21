#ifndef COFFEEMACHINEMESSAGE_H
#define COFFEEMACHINEMESSAGE_H

#include <Arduino.h>

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