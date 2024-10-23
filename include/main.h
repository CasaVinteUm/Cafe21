#ifndef MAIN_H
#define MAIN_H

#ifdef HASDISPLAY
#include "display.h"
#include "ui.h"

void UIController(void *name);
#endif // HASDISPLAY

#if ESP32C3
#define TX_PIN 21
#define RX_PIN 20
#elif DISPLAY3248
#define TX_PIN 21
#define RX_PIN 22
#endif // ESP32C3

void runController(void *name);

#endif // MAIN_H