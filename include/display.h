#ifdef HASDISPLAY

#ifndef DISPLAY_H
#define DISPLAY_H

#include <Arduino.h>
#include <lvgl.h>
// #include "touch_main.h"
#include <Arduino_GFX_Library.h>

#ifdef ESP32_3248S035C

#define GFX_BL GPIO_BCKL
#define TFT_BL 27

#endif // ESP32_3248S035C

void display_init();

#endif // DISPLAY_H
#endif // HASDISPLAY