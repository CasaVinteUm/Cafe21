#ifndef LIGHTNINGCONTROLLER_H
#define LIGHTNINGCONTROLLER_H

#ifdef DISPLAY_WIDTH

#include "WiFi.h"
#include <WebSocketsClient.h>
#include "ui.h"
#include "esp_log.h"

#include "MessageLogger.h"
#include "ConfigManager.h"

class LightningController
{
public:
    LightningController(ConfigManager &configManager);

    // Callback types
    using InvoicePaidCallback = std::function<void(uint8_t)>;

    void setOnInvoicePaid(InvoicePaidCallback callback);
    void websocketInit();
    void websocketLoop() { webSocket.loop(); }

    const bool getIsConnected() { return isConnected; };

    const char *getButton1Lnurl() { return config.getButton1Lnurl(); };
    const char *getButton2Lnurl() { return config.getButton2Lnurl(); };

private:
    ConfigManager &config;
    InvoicePaidCallback onInvoicePaid;
    WebSocketsClient webSocket;
    const uint32_t WS_RECONNECT_INTERVAL = 10000;
    const uint32_t WS_HB_PING_TIME = 30000;
    const uint32_t WS_HB_PONG_WITHIN = 10000;
    const uint32_t WS_HB_PONGS_MISSED = 4;
    bool connerr = true;
    bool isConnected = false;
    const String lnbitsWSApiURL = "/api/v1/ws/";

    // Make the event handler static and store instance pointer
    static LightningController *instance;
    static void webSocketEvent(WStype_t type, uint8_t *payload, size_t length);
    void handleWebSocketEvent(WStype_t type, uint8_t *payload, size_t length);
};

#endif // LIGHTNINGCONTROLLER_H

#endif // DISPLAY_WIDTH