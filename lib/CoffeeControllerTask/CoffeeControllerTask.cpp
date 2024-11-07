#include "CoffeeControllerTask.h"

CoffeeControllerTask::CoffeeControllerTask(CoffeeMachineController &controller)
    : coffeeController(controller) {}

void CoffeeControllerTask::begin()
{
    xTaskCreatePinnedToCore(task, "CoffeeController", 10000, this, 1, NULL, 0);
}

void CoffeeControllerTask::task(void *pvParameters)
{
    static_cast<CoffeeControllerTask *>(pvParameters)->run();
}

void CoffeeControllerTask::run()
{
    log_i("Coffe Machine Controller started");

    while (true)
    {
        coffeeController.loop();

#ifndef NO_DEBUG_SERIAL
        if (Serial.available())
        {
            String input = Serial.readStringUntil('\n'); // Read until newline character
            input.trim();                                // Remove any leading/trailing whitespace
            input.toLowerCase();                         // Convert to lowercase for easy comparison

            // Map input to commands
            if (input == "o")
            {
                coffeeController.sendOnCommand();
            }
            else if (input == "e")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::Espresso);
            }
            else if (input == "c")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::Coffee);
            }
            else if (input == "h")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::HotWater);
            }
            else if (input == "s")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::Steam);
            }
            else if (input == "x")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::StartStop);
            }
            else if (input == "t")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::Strength);
            }
            else if (input == "q")
            {
                coffeeController.sendCommand(CoffeeMachineCommand::Quantity);
            }
            else
            {
                log_e("Unknown command. Please enter a valid command.");
            }
        }
#endif // DEBUG_SERIAL

        // Allways send the Status Command...
        coffeeController.sendCommand(CoffeeMachineCommand::Status);

        delay(100); // Stabilize loop
    }
}