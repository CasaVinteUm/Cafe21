#ifdef DISPLAY_WIDTH

#include "LightningController.h"

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
    webSocket.beginSSL(lnbitsServer, 443, lnbitsWSApiURL + deviceId);
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
    switch (type)
    {
    case WStype_DISCONNECTED:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.print("Disconnected from url: ");
        Serial.println((char *)payload);
#endif // DEBUG_SERIAL
        connerr = true;
        // showconnect = true;
    }
    break;
    case WStype_CONNECTED:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.print("Connected to url: ");
        Serial.println((char *)payload);
#endif // DEBUG_SERIAL
        webSocket.sendTXT("Connected");
        connerr = false;
    }
    break;
    case WStype_TEXT:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.print("Message: ");
        Serial.println((char *)payload);
#endif // DEBUG_SERIAL

        if (isdigit(payload[0]) && isdigit(payload[2]))
            onInvoicePaid(String((char)payload[0]).toInt());
    }
    break;
    case WStype_PING:
    case WStype_PONG:
        break;
    case WStype_ERROR:
    {
        // answer to a ping we send
#ifndef NO_DEBUG_SERIAL
        Serial.println("Error received");
#endif // DEBUG_SERIAL
    }
    break;
    default:
    {
#ifndef NO_DEBUG_SERIAL
        Serial.print("Unknown: ");
        Serial.println((char *)payload);
#endif // DEBUG_SERIAL
    }
    break;
    }
}

#endif // DISPLAY_WIDTH