#ifdef DISPLAY_WIDTH

#include "LightningController.h"

LightningController *LightningController::instance = nullptr;

LightningController::LightningController(ConfigManager &configManager)
    : config(configManager)
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
    webSocket.begin(config.getLNBitsServer(), 80, lnbitsWSApiURL + config.getDeviceId());
#else
    webSocket.beginSSL(config.getLNBitsServer(), 443, lnbitsWSApiURL + config.getDeviceId());
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
        log_d("Disconnected!");
        connerr = true;
        isConnected = false;
    }
    break;
    case WStype_CONNECTED:
    {
        if (length && payload)
        {
            log_d("Connected to url: %s\n", payload);
        }
        else
        {
            log_d("Connected!\n");
        }
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

                log_d("Message: %s\n", message);

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
        log_e("Error received");
        if (length && payload)
        {
            char hexString[length * 5 + 1];
            MessageLogger::hexDump(payload, length, hexString, sizeof(hexString));
            log_e("Error payload (%u bytes): %s", length, hexString);
        }
    }
    break;
    default:
    {
        log_d("Unknown type %d, length: %u\n", type, length);
        if (length && payload)
        {
            char hexString[length * 5 + 1];
            MessageLogger::hexDump(payload, length, hexString, sizeof(hexString));
            log_e("Payload (%u bytes): %s", length, hexString);
        }
    }
    break;
    }
}

#endif // DISPLAY_WIDTH