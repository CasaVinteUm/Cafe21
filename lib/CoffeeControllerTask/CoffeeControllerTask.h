#ifndef COFFEECONTROLLERTASK_H
#define COFFEECONTROLLERTASK_H

#include "CoffeeMachineController.h"

class CoffeeControllerTask
{
public:
    CoffeeControllerTask(CoffeeMachineController &coffeeController);
    void begin();
    static void task(void *pvParameters);

private:
    CoffeeMachineController &coffeeController;

    void run();
    void readAndProcessMessages();
};

#endif // COFFEECONTROLLERTASK_H