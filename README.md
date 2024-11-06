# Cafe Vinteum

This project transforms a **Philips Walita Coffee Machine (EP1220)** into a smart coffee dispenser that accepts **Bitcoin Lightning Network** payments. By replacing the original control panel with an ESP32 development board featuring a display and touch interface, users can purchase coffee seamlessly using Lightning payments.

## Table of Contents

- [Introduction](#introduction)
- [Disclaimer](#disclaimer)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
  - [Supported Dev Boards](#supported-dev-boards)
  - [Additional Hardware](#additional-hardware)
- [Software Dependencies](#software-dependencies)
- [Installation](#installation)
  - [Hardware Setup](#hardware-setup)
  - [Firmware Installation](#firmware-installation)
- [Usage](#usage)
- [LNBits Integration](#lnbits-integration)
- [Help Wanted](#help-wanted)
- [Contributing](#contributing)
- [Acknowledgments](#acknowledgments)
- [License](#license)
- [Contact](#contact)

## Introduction

**Cafe Vinteum** aims to modernize the coffee experience by integrating cryptocurrency payments directly into a popular coffee machine model. This project is ideal for tech enthusiasts, coffee lovers, and anyone interested in the practical applications of the Lightning Network.

## Disclaimer

You might void your machine's warranty by attempting to use this software and following these instructions.

Be advised that **CasaVinteUm** will not be held responsible for any damage to people or property resulting from improper use or misunderstanding of this project.

## Features

- **Lightning Payments**: Accepts payments via the Bitcoin Lightning Network.
- **Touchscreen Interface**: User-friendly navigation and coffee selection.
- **Wi-Fi Connectivity**: Easy network setup using WiFiManager.
- **Customizable UI**: Built with LVGL and SquareLine Studio for flexibility.
- **Open Source**: Built with open-source tools and libraries.

## Hardware Requirements

### Supported Dev Boards

This project works out of the box with three different development board displays known as **Cheap Yellow Display (CYD)**:

- **esp32-3248S035C**: The less capable brother.
- **esp32-4827S043C**: The middle brother.
- **esp32-8048S043C**: The good-looking, intelligent brother.

These displays typically include:

- An **ESP32** microcontroller.
- An integrated **LCD display**.
- **Touchscreen** capability.

### Additional Hardware

- **Philips Walita Coffee Machine (EP1220)**
- **Level Shifters**: To adjust voltage levels between the coffee machine (5V) and ESP32 (3.3V).
- **Perforated Board**: For assembling the custom circuit.
- **Header Pins and Connectors**: For secure connections.
- **Power Supply**: Ensure adequate power for both the ESP32 and the coffee machine.

## Software Dependencies

We utilize several open-source libraries and tools:

- [PlatformIO](https://platformio.org): Integrated development environment for IoT.
- [LVGL](https://lvgl.io): Powerful graphics library for embedded systems.
- [SquareLine Studio](https://squareline.io): Design tool for creating UI interfaces (free for personal use).
- [WiFiManager](https://github.com/tzapu/WiFiManager): Simplifies Wi-Fi configuration on the ESP32.
- [WebSockets](https://github.com/links2004/WebSockets): Enables real-time communication via WebSockets.
- [ESP32 Smart Display](https://github.com/rzeldent/esp32_smartdisplay): Facilitates smart display functionalities.
- [ESP32 Partition Tool](https://esp32.jgarrettcorbin.com): Creates custom partition tables for more storage.
- [SquareLine Studio Boards](https://github.com/nGoline/squarelinestudio-boards): Board definitions for SquareLine Studio.

## Installation

### Hardware Setup

1. **Disassemble the Coffee Machine**:
   - Carefully remove the original control panel from the Philips EP1220.
   - Preserve all connectors and cables for reuse.

2. **Prepare the ESP32 Board**:
   - Choose one of the supported CYD boards.
   - Install any necessary firmware (see Firmware Installation below).

3. **Assemble the Circuit**:
   - Use a perforated board to mount the level shifters and header pins.
   - Connect the coffee machine's data lines to the level shifters.
   - Connect the level shifters to the ESP32 board.
   - Ensure all connections match the voltage requirements (5V ↔ 3.3V).

4. **Integration**:
   - Mount the ESP32 display where the original control panel was located.
   - Secure all components to prevent movement or disconnection.

   *Note: Detailed schematics and wiring diagrams are available in the `/hardware` directory.*

### Firmware Installation

1. **Set Up Development Environment**:
   - Install [PlatformIO](https://platformio.org/install) in your preferred IDE (VSCode recommended).

2. **Clone the Repository**:
   ```bash
   git clone https://github.com/yourusername/cafe-vinteum.git
   ```

3. **Install Libraries**:
   - Open the project in PlatformIO.
   - PlatformIO should automatically install the required libraries specified in `platformio.ini`.

4. **Configure Wi-Fi (Optional)**:
   - By default, WiFiManager handles Wi-Fi setup.
   - If you prefer to hardcode your Wi-Fi credentials, modify the relevant sections in the code.

5. **Compile and Upload Firmware**:
   - Connect the ESP32 board to your computer via USB.
   - In PlatformIO, build and upload the firmware:
     ```
     pio run --target upload
     ```

6. **UI Design with SquareLine Studio**:
   - Follow the instructions [here](https://github.com/nGoline/squarelinestudio-boards) to install the boards on SquareLine Studio.
   - Open the provided UI project in SquareLine Studio.
   - Export the UI assets.
   - Ensure the exported assets are placed in the `/assets` directory of your PlatformIO project.

7. **Adjust Partition Scheme** for non-s3 boards:
   - Use the [ESP32 Partition Tool](https://esp32.jgarrettcorbin.com) to create a custom partition if needed.
   - Update the `partitions.csv` file in your project accordingly.

## Usage

1. **Power On the Machine**:
   - Plug in the modified coffee machine.
   - The coffee machine will turn on automatically.

2. **Wi-Fi Configuration**:
   - On first boot, the ESP32 will create an access point (e.g., `CafeVinteum_AP`).
   - Connect to this AP using a smartphone or laptop.
   - Follow the captive portal to input your Wi-Fi credentials.

3. **Connect to LNBits**:
   - Configure the LNBits integration (see [LNBits Integration](#lnbits-integration)).

4. **Using the Touch Interface**:
   - Select your preferred coffee type on the touchscreen.
   - A QR code will appear for payment.

5. **Make a Payment**:
   - Use a Lightning-compatible wallet to scan the QR code.
   - Upon successful payment, the machine will brew your coffee.

## LNBits Integration

We use [LNBits](https://lnbits.com) and its **LNURLDevice** extension to handle Lightning payments.

### Setup Instructions

1. **Install LNBits**:
   - You can self-host LNBits or use a hosted instance.
   - Follow the official [LNBits installation guide](https://docs.lnbits.com/guide/installation.html).

2. **Enable LNURLDevice Extension**:
   - In LNBits, navigate to the Extensions page.
   - Enable and set up the LNURLDevice extension.

3. **Create a new device**:
   - Choose the option Switch;
   - Click the plus(+) button twice to add two configurations;
   - Set the price for Espresso and Coffee, respectivelly;
   - Set the duration and GPIO pin for the **Espresso** as `1` and `1`.
   - Set the duration and GPIO pin for the **Coffee** as `2` and `2`.

4. **Update Firmware Configuration**:
   - In your ESP32 code, update the LNBits API endpoint and LNURLs for each beverage.
   - You can also set this up on the captive portal during first boot.

5. **Test the Connection**:
   - Trigger a test payment to ensure the system works end-to-end.

## Help Wanted

We need assistance with:

- **Translations**: Adding multiple language support to the SquareLine project and touchscreen messages.
- **Testing**: Running the project on different hardware setups and reporting issues.
- **Documentation**: Improving installation guides, especially for the hardware setup.

If you're interested in contributing, please check out the [Contributing](#contributing) section.

## Contributing

We welcome contributions from the community!

- **Fork the Repository**: Create your own fork and work on it.
- **Create a Branch**: Use descriptive branch names for your features or fixes.
- **Pull Requests**: Submit a pull request to the `main` branch with a clear description of your changes.
- **Report Issues**: Use the GitHub Issues page to report bugs or suggest enhancements.

Please adhere to the coding standards and follow the existing code style.

## Acknowledgments

- **[TillFleisch](https://github.com/TillFleisch/ESPHome-Philips-Smart-Coffee)**: For the initial inspiration and groundwork in understanding the communication protocol between the machine and the control panel.
- **Open-Source Community**: For providing the tools and libraries that make this project possible.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or support, please open an issue on GitHub.