#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H

#include <HardwareSerial.h>
#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"
#ifdef USE_I2C
 #include <Wire.h>
#endif 
class CoffeeMachineController
{
public:
    CoffeeMachineController(HardwareSerial &serial);

    void updateState(const CoffeeMachineMessage &message);
    bool sendCommand(CoffeeMachineCommand command);

    CoffeeMachineState getCurrentState() const;

private:
    HardwareSerial &serialPort;
    CoffeeMachineStateMachine stateMachine;

    void sendCommandMessage(CoffeeMachineCommand command);
    uint16_t computeChecksum(const uint8_t *data, size_t length);
};

#endif // COFFEEMACHINECONTROLLER_H