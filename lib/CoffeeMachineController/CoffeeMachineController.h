#ifndef COFFEEMACHINECONTROLLER_H
#define COFFEEMACHINECONTROLLER_H
#ifdef USE_I2C
 #include <Wire.h>
#else
 #include <HardwareSerial.h>
#endif

#include "CoffeeMachineStateMachine.h"
#include "CoffeeMachineCommand.h"

class CoffeeMachineController
{
public:  
#ifdef USE_I2C       
    CoffeeMachineController();
#else
    CoffeeMachineController(HardwareSerial &serial);
#endif    
    void updateState(const CoffeeMachineMessage &message);
    bool sendCommand(CoffeeMachineCommand command,  byte destinationS);

    CoffeeMachineState getCurrentState() const;

private:
  
#ifndef USE_I2C 
    // HardwareSerial &serialPort;
    HardwareSerial &serialPort;
#endif
    CoffeeMachineStateMachine stateMachine;

    void sendCommandMessage(CoffeeMachineCommand command, byte destination);
    uint16_t computeChecksum(const uint8_t *data, size_t length);
};

#endif // COFFEEMACHINECONTROLLER_H