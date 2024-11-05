#ifndef LIGHTNINGCONTROLLER_H
#define LIGHTNINGCONTROLLER_H

#ifdef DISPLAY_WIDTH

#include "WiFi.h"
#include <WebSocketsClient.h>
#include "ui.h"

class LightningController
{
public:
    LightningController();

    // Callback types
    using InvoicePaidCallback = std::function<void(uint8_t)>;

    void setOnInvoicePaid(InvoicePaidCallback callback);
    void websocketInit();
    void websocketLoop() { webSocket.loop(); }

    const String button1Lnurl = "LNURL1DP68GURN8GHJ7MRWVF5HGUEWVDSHXCFJXYH8XURPVDJJ7MRWW4EXCER9WE5KXEF0V9CXJTMKXGHKCMN4WFKZ7JZ2D9FXU4MJ2A2HZNFHF3V5W32VWAPXZNTY8ACXJM3AXYNXZMT0W4H8G0FS9CCRZFNYW4EXZARFDAHR6VFXWESHY6TPVFKX202XV9K8XEFXVDHK6MT9DE6R63NPD3EK254NLZL";
    const String button2Lnurl = "LNURL1DP68GURN8GHJ7MRWVF5HGUEWVDSHXCFJXYH8XURPVDJJ7MRWW4EXCER9WE5KXEF0V9CXJTMKXGHKCMN4WFKZ7JZ2D9FXU4MJ2A2HZNFHF3V5W32VWAPXZNTY8ACXJM3AXGNXZMT0W4H8G0FS9CCRZFNYW4EXZARFDAHR6V3XWESHY6TPVFKX202XV9K8XEFXVDHK6MT9DE6R63NPD3EK2CRQ6MQ";

private:
    InvoicePaidCallback onInvoicePaid;
    WebSocketsClient webSocket;
    const uint32_t WS_RECONNECT_INTERVAL = 10000;
    const uint32_t WS_HB_PING_TIME = 150000;
    const uint32_t WS_HB_PONG_WITHIN = 10000;
    const uint32_t WS_HB_PONGS_MISSED = 4;
    bool connerr = true;
    const String lnbitsServer = "lnbits.casa21.space";
    const String deviceId = "HJiRnWrWUqM7LYGELwBaMd";
    const String lnbitsWSApiURL = "/api/v1/ws/";

    // Make the event handler static and store instance pointer
    static LightningController *instance;
    static void webSocketEvent(WStype_t type, uint8_t *payload, size_t length);
    void handleWebSocketEvent(WStype_t type, uint8_t *payload, size_t length);
};

#endif // LIGHTNINGCONTROLLER_H

#endif // DISPLAY_WIDTH