#ifdef DISPLAY_WIDTH

#include "LightningController.h"
#include <WiFiClientSecure.h>

LightningController *LightningController::instance = nullptr;

LightningController::LightningController()
{
    instance = this;
}

void LightningController::setOnInvoicePaid(InvoicePaidCallback callback)
{
    onInvoicePaid = callback;
}

void LightningController::websocketInit()
{
#ifdef ARDUINO_ESP32_DEV
    webSocket.begin(lnbitsServer, 80, lnbitsWSApiURL + deviceId);
#else
    webSocket.beginSSL(lnbitsServer, 443, lnbitsWSApiURL + deviceId);
#endif // ARDUINO_ESP32_DEV

    webSocket.onEvent(webSocketEvent);
    webSocket.setReconnectInterval(WS_RECONNECT_INTERVAL);
    if (WS_HB_PING_TIME != 0)
    {
        webSocket.enableHeartbeat(WS_HB_PING_TIME, WS_HB_PONG_WITHIN, WS_HB_PONGS_MISSED);
    }
}

void LightningController::webSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{
    if (instance)
    {
        instance->handleWebSocketEvent(type, payload, length);
    }
}

void LightningController::handleWebSocketEvent(WStype_t type, uint8_t *payload, size_t length)
{
    if (length == 1 || (length == 2 && payload[0] == 0xEF))
    {           // Filter typical corrupt patterns
        return; // Skip processing these messages
    }

    switch (type)
    {
    case WStype_DISCONNECTED:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.println("[WSc] Disconnected!");
#endif // DEBUG_SERIAL
        connerr = true;
        isConnected = false;
    }
    break;
    case WStype_CONNECTED:
    {
#ifndef NO_DEBUG_SERIAL
        if (length && payload)
        {
            Serial.printf("[WSc] Connected to url: %s\n", payload);
        }
        else
        {
            Serial.printf("[WSc] Connected!\n");
        }
#endif // DEBUG_SERIAL
        webSocket.sendTXT("Connected");
        connerr = false;
        isConnected = true;
    }
    break;
    case WStype_TEXT:
    {
        if (length && payload)
        {
            // Make sure we have a null-terminated string
            char *message = (char *)malloc(length + 1);
            if (message)
            {
                memcpy(message, payload, length);
                message[length] = '\0';

#ifndef NO_DEBUG_SERIAL
                Serial.printf("Message: %s\n", message);
#endif // DEBUG_SERIAL

                if (length >= 3 && isdigit(message[0]) && isdigit(message[2]))
                {
                    onInvoicePaid(message[0] - '0'); // Convert char to int directly
                }

                free(message);
            }
        }
    }
    break;
    case WStype_PING:
    case WStype_PONG:
        break;
    case WStype_ERROR:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.println("[WSc] Error received");
        if (length && payload)
        {
            Serial.printf("[WSc] Error payload (%u bytes): ", length);
            for (size_t i = 0; i < length; i++)
            {
                Serial.printf("%02X ", payload[i]);
            }
            Serial.println();
        }
#endif // DEBUG_SERIAL
    }
    break;
    default:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.printf("[WSc] Unknown type %d, length: %u\n", type, length);
        if (length && payload)
        {
            Serial.printf("[WSc] Payload: ");
            for (size_t i = 0; i < length; i++)
            {
                Serial.printf("%02X ", payload[i]);
            }
            Serial.println();
        }
#endif // DEBUG_SERIAL
    }
    break;
    }
}

#endif // DISPLAY_WIDTH