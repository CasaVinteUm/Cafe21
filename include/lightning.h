#ifndef _LIGHTNING_V2_UI_H
#define _LIGHTNING_V2_UI_H

#include "WiFi.h"
#include <ArduinoJson.h>
#include <WebSocketsClient.h>
#include "ui.h"

extern String payloadStr;
extern bool paid;
extern bool confirmed;
extern bool expired;
extern String qrData;

extern String lnbitsServer;  // = "legend.lnbits.com";
extern String deviceId; // = "BESNK";
extern String invoice; // = "Z4GbwoXMzHEBhfoDP6Dt4Z";
extern String invoice_w; // = "e76b9317648145058af55d49b16c831f";

//////////////////WEBSOCKET///////////////////
extern WebSocketsClient webSocket;
extern bool connerr;
extern int converted;
extern bool showconnect;

void lightning_init();
void webSocketEvent(WStype_t type, uint8_t * payload, size_t length);
extern bool getSats();
extern bool getInvoice(int noSats);
extern bool checkInvoice();

#endif