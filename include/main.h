#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include <ConfigManager.h>
#include <WiFiManagerWrapper.h>
#include <CoffeeControllerTask.h>

// Remove all kinds of logging to serial if we only have one UART
#ifdef NO_DEBUG_SERIAL
#ifdef CORE_DEBUG_LEVEL
#undef CORE_DEBUG_LEVEL
#endif // CORE_DEBUG_LEVEL
#define CORE_DEBUG_LEVEL = ARDUHAL_LOG_LEVEL_NONE
#endif // NO_DEBUG_SERIAL

#ifdef DISPLAY_WIDTH

#include <ui.h>
#include <LightningController.h>
#include <UIController.h>

#endif // DISPLAY_WIDTH

MessageLogger logger;
CoffeeMachineMessage currentMessage;

ConfigManager configManager;
WiFiManagerWrapper wifiManager(configManager);
bool initialized;

#ifdef DISPLAY_WIDTH
LightningController lightningController(configManager);
#endif // DISPLAY_WIDTH

#ifdef ESP32C3
#define TX_PIN 21
#define RX_PIN 20
#else
#define TX_PIN 13
#define RX_PIN 12
#endif // ESP32C3

#ifdef ARDUINO_ESP32_DEV
HardwareSerial CoffeeSerial(0);
CoffeeMachineController coffeeController(Serial, logger);
#else
HardwareSerial CoffeeSerial(1);
CoffeeMachineController coffeeController(CoffeeSerial, logger);
#endif

CoffeeControllerTask coffeeTask(coffeeController);

#ifdef DISPLAY_WIDTH
UIController uiController(coffeeController, lightningController);
#endif // DISPLAY_WIDTH

#endif // MAIN_H