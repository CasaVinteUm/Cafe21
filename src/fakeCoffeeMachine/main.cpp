#include <Arduino.h>
#include <HardwareSerial.h>

#define TX_PIN 21
#define RX_PIN 20

void sendMessage();
void processMessage();

void setup()
{
#if ARDUINO_USB_CDC_ON_BOOT == 1
    delay(5000);
#endif

    Serial.begin(115200);
    Serial.println("ESP32 Coffee Machine Logger Starting...");

    Serial1.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);

    delay(1000);
}

void loop()
{
    sendMessage();
    processMessage();
    delay(100); // Stabilize loop
}

byte messageType = 0x00;
bool isTurningOn = false;
byte loadCount = 0;
byte brewingCount = 0;
bool blinkState = false;
byte selectedBeveragePos = 0;

void sendMessage()
{
    // Default Ready command:
    // 0xD5 0x55 0x00 0x07 0x07 0x07 0x07 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x39 0x0D
    byte *message = new byte[19];
    message[0] = 0xD5;
    message[1] = 0x55;
    for (byte i = 2; i < 19; i++)
    {
        message[i] = 0x00;
    }

    // Deal with Loading Messages
    if (isTurningOn)
    {
        if (messageType == 0x03 && loadCount++ <= 5)
        {
            loadCount++;
        }
        else if (messageType == 0x04) // Interpolate between 1 and 2
        {
            messageType = 0x05;
        }
        else
        {
            messageType = 0x04;
        }

        if (loadCount++ >= 25) // Send Loading for 25 times
        {
            isTurningOn = false;
            messageType = 0x01; // Set message as status
        }
    }

    switch (messageType)
    {
    case 0x00: // Off
        Serial1.write(0x00);
        return;
    case 0x02: // Beep
        message[2] = 0x01;
        break;
    case 0x03: // Turning On
        break;
    case 0x04: // Loading 1
        message[3] = 0x03;
        message[5] = 0x07;
        break;
    case 0x05: // Loading 2
        message[5] = 0x03;
        message[6] = 0x07;
        break;
    case 0x06: // Espresso
        message[3] = 0x07;
        message[8] = 0x38;
        message[9] = 0x07;
        message[10] = 0x38;
        message[11] = 0x07;
        if (blinkState)
        {
            message[16] = 0x07;
        }
        else
        {
            message[16] = 0x00;
        }
        blinkState = !blinkState; // Flip blinkState
        break;
    case 0x07: // Coffee
        message[5] = 0x07;
        message[8] = 0x38;
        message[9] = 0x07;
        message[10] = 0x38;
        message[11] = 0x07;
        if (blinkState)
        {
            message[16] = 0x07;
        }
        else
        {
            message[16] = 0x00;
        }
        blinkState = !blinkState; // Flip blinkState
        break;
    case 0x08: // Start/Stop
        if (blinkState)
        {
            message[selectedBeveragePos] = 0x07;
        }
        else
        {
            message[selectedBeveragePos] = 0x00;
        }
        blinkState = !blinkState; // Flip blinkState
        message[16] = 0x07;

        if (brewingCount++ >= 25)
        {
            brewingCount = 0;
            messageType = 0x01;
        }
        break;
    case 0x01: // Ready
    default:
        message[3] = 0x07;
        message[4] = 0x07;
        message[5] = 0x07;
        message[6] = 0x07;
        break;
    }

    Serial1.write(message, 19);
    Serial.print("Writing: ");
    for (size_t i = 0; i < 19; i++)
    {
        Serial.print("0x");
        if (message[i] < 0x10)
            Serial.print("0");
        Serial.print(message[i], HEX);
        Serial.print(" ");
    }
    Serial.println();
}

void processMessage()
{
    static uint8_t messageBuffer[12];
    static size_t messageIndex = 0;

    while (Serial1.available())
    {
        uint8_t incomingByte = Serial1.read();

        // If we get a init header anywhere else, reset the buffer and fill up the message again
        if (messageIndex != 0 && incomingByte == 0xD5)
        {
            messageIndex = 0;
        }

        switch (messageIndex)
        {
        case 0:                       // Check Header
            if (incomingByte != 0xD5) // Header is incorrect; continue
            {
                continue;
            }
            break;
        case 1:                       // Check for header completion
            if (incomingByte != 0x55) // Header is incorrect; reset
            {
                messageIndex = 0;
                if (incomingByte != 0xD5) // Header is plain wrong; continue
                {
                    continue;
                }
            }
            break;
        case 2:
            if (incomingByte == 0x0A) // Message is beep; set accordingly
            {
                messageType = 0x02;
            }
            else if (incomingByte == 0x01) // Message is On;
            {
                messageType = 0x03;
                isTurningOn = true;
            }
        case 7:
            if (incomingByte == 0x02) // Message is Espresso;
            {
                selectedBeveragePos = 3;
                messageType = 0x06;
            }
            else if (incomingByte == 0x08) // Message is Coffee;
            {
                selectedBeveragePos = 5;
                messageType = 0x07;
            }
            break;
        case 9:
            if (incomingByte == 0x01) // Message is Start/Stop;
            {
                messageType = 0x08;
            }
            break;
        default:
            if (incomingByte == 0xD5) // If we get a init header anywhere else; reset
            {
                messageIndex = 0;
            }
            break;
        }

        messageBuffer[messageIndex++] = incomingByte;

        if (messageIndex >= 12) // We reached the end of the message
        {
            messageIndex = 0;
            sendMessage();
            delay(10); // Stabilize loop
            Serial.print("received: ");
            for (size_t i = 0; i < 12; i++)
            {
                Serial.print("0x");
                if (messageBuffer[i] < 0x10)
                    Serial.print("0");
                Serial.print(messageBuffer[i], HEX);
                Serial.print(" ");
            }
            Serial.println();
        }
    }
}