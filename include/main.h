#ifndef MAIN_H
#define MAIN_H

#include <Arduino.h>
#include <CoffeeMachineMessage.h>
#include <CoffeeMachineController.h>
#include <MessageLogger.h>
#include "wManager.h"

#ifdef DISPLAY_WIDTH
#include <esp32_smartdisplay.h>
#include <ui.h>
#include <LightningController.h>

void UIController(void *name);
void generateQrCode(uint8_t buttonNumber);
void onInvoicePaid(uint8_t type);
#endif // DISPLAY_WIDTH

#ifdef ESP32C3
#define TX_PIN 21
#define RX_PIN 20
#else
#define TX_PIN 13
#define RX_PIN 12
#endif

void runController(void *name);

uint8_t isWaitingPayment = 0;

#endif // MAIN_H