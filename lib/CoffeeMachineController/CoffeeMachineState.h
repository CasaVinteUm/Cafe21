#ifndef COFFEEMACHINESTATE_H
#define COFFEEMACHINESTATE_H

enum class CoffeeMachineState
{
    Off,
    WaitingForOn,
    TurningOn,
    Loading,
    Ready,
    Selected,
    Brewing,
    Error
};

#endif // COFFEEMACHINESTATE_H