#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include <ConfigManager.h>
#include <WiFiManagerWrapper.h>

// Remove all kinds of logging to serial if we only have one UART
#ifdef NO_DEBUG_SERIAL
#ifdef CORE_DEBUG_LEVEL
#undef CORE_DEBUG_LEVEL
#endif // CORE_DEBUG_LEVEL
#define CORE_DEBUG_LEVEL = ARDUHAL_LOG_LEVEL_NONE
#endif // NO_DEBUG_SERIAL

#ifdef DISPLAY_WIDTH
#define QRCODE_INITIAL_SIZE 200

#include <esp32_smartdisplay.h>
#include <ui.h>
#include <LightningController.h>

void UIController(void *name);
void showQrCode(uint8_t buttonNumber, lv_coord_t size);
void generateQrCode(uint8_t buttonNumber);
void clearQrCode();
void onInvoicePaid(uint8_t type);
#endif // DISPLAY_WIDTH

void runController(void *name);
void readAndProcessMessages();

uint8_t waitingPaymentFor = 0;
uint8_t delay_lvgl = 0;
lv_coord_t qrCodeSize = QRCODE_INITIAL_SIZE;

MessageLogger logger;
CoffeeMachineMessage currentMessage;

ConfigManager configManager;
WiFiManagerWrapper wifiManager(configManager);
bool initialized;

#ifdef DISPLAY_WIDTH
LightningController Lightning(configManager);
#endif // DISPLAY_WIDTH

#ifdef ESP32C3
#define TX_PIN 21
#define RX_PIN 20
#else
#define TX_PIN 13
#define RX_PIN 12
#endif // ESP32C3

#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 0;
#else
static const BaseType_t app_cpu0 = 0;
static const BaseType_t app_cpu1 = 1;
#endif

#ifdef ARDUINO_ESP32_DEV
HardwareSerial CoffeeSerial(0);
CoffeeMachineController coffeeController(Serial, logger);
#else
HardwareSerial CoffeeSerial(1);
CoffeeMachineController coffeeController(CoffeeSerial, logger);
#endif

#endif // MAIN_H