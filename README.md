# Cafe Vinteum

This project converts a Phillips Walita Coffee Machine (EP1220) to accept Lightning payments for a coffee.

## DISCLAIMER

You might void your machine's warranty by attempting to use this software/instructions.

Be advised that CasaVinteUm will not be held responsible for any damage to people/property because you don't know what you're doing.

## Dev Boards

This project works, out of the box, with 3 different dev board displays know as Cheap Yellow Display (CYD):

- esp32-3248S035C (the less capable brother)
- esp32-4827S043C (the middle brother)
- esp32-8048S043C (the good looking, inteligent brother)

Cheap Yellow Displays usually have an ESP32, a display, and integrated touch.

## Dependencies

We use a lot of FOSS in this project, but here we have direct dependencies and software you should at least know what it does.

- [tzapu/WiFiManager](https://github.com/tzapu/WiFiManager)
- [links2004/WebSockets](https://github.com/links2004/WebSockets)
- [rzeldent/esp32_smartdisplay](https://github.com/rzeldent/esp32_smartdisplay)
- [platform io](https://platformio.org)
- [LVGL](https://lvgl.io)
- [ESP32 Partition Calculator](https://esp32.jgarrettcorbin.com) used to make more room for the app on the esp-wroom-32 

The software used to make the screens and navigation is [SquareLine Studio](https://squareline.io/) which offers a free license for personal use.

## Hardware

We basically started from [here](https://github.com/TillFleisch/ESPHome-Philips-Smart-Coffee), but he uses a dedicated PCB to intercept "some" commands from/to the machine to the pannel and vice-versa.

Since we'll be charging for a coffee it didn't make sense to leave the original controls, so we understood the comms protocol between the machine and the control panel and send commands and respond accordingly.

### Perforated Board

The connection between the machine and the CYD is done via header pins and some level-shifters, since the coffee machine uses 5v and ESP32 uses 3v3 for the data lines.

## LnBits

We use LnBits' LNURLDevice extension to deal with the LNURLs and webhook connection.

## Help!

We need help adding translation to the SquareLine project and the messages shown on the screens.