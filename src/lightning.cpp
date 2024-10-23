#include "lightning.h"

String ssid = "GeorgeHomeC";
String wifiPassword = "Cz1mwyh.";
String payloadStr;
bool paid;
bool confirmed = false;
bool expired = false;
String qrData;
String dataId;

WebSocketsClient webSocket;
const uint32_t WS_RECONNECT_INTERVAL = 10000;  // websocket reconnect interval (ms)
const uint32_t WS_HB_PING_TIME = 150000;          // ping server every WS_HB_PING_TIME ms (set to 0 to disable heartbeat)
const uint32_t WS_HB_PONG_WITHIN = 100000;        // expect pong from server within WS_HB_PONG_WITHIN ms
const uint32_t WS_HB_PONGS_MISSED = 4;             // consider connection disconnected if pong is not received WS_HB_PONGS_MISSED times
bool connerr = true;

String lnbitsWSApiURL = "/api/v1/ws/";
int converted = 0;
String lncurrency = "BRL";
bool showconnect = false;

#define LN_TESTE

#ifdef LN_TESTE // Servidor Legends Testes George
String lnbitsServer = "demo.lnbits.com"; // "2c8b8a7b06.d.voltageapp.io"; // legend.lnbits.comsss";
String deviceId = "TjB6BGbD9RnAQSchgxHMXg"; // "BESNK";
String invoice = "Z4GbwoXMzHEBhfoDP6Dt4Z__";
String invoice_w = "5cd5fba9aea34f14a7fdb38e7f476922"; //"d38d0ec41e8a4df9bd8b9e428f18f048";
#else // Servidor SaaS - Nó Ricardo
String lnbitsServer = "thrilleddotterel9.lnbits.com";
String deviceId = "XVdwC";
String invoice = "BKUBHuA6LTdgn6tMqT4JEg";
String invoice_w = "0c3d308f70b04231ad00139aba0ed017";
#endif

//////////LIGHTNING//////////////////////
void websocket_init(){
  webSocket.beginSSL(lnbitsServer.c_str(), 443, (lnbitsWSApiURL + deviceId).c_str());
  webSocket.onEvent(webSocketEvent);
  webSocket.setReconnectInterval(WS_RECONNECT_INTERVAL);  
  if (WS_HB_PING_TIME != 0) {
    /* Serial.print(F("Enabling WS heartbeat with ping time "));
    Serial.print(WS_HB_PING_TIME);
    Serial.print(F("ms, pong time "));
    Serial.print(WS_HB_PONG_WITHIN);
    Serial.print(F("ms, "));
    Serial.print(WS_HB_PONGS_MISSED);
    Serial.println(F(" missed pongs to reconnect.")); */
    webSocket.enableHeartbeat(WS_HB_PING_TIME, WS_HB_PONG_WITHIN, WS_HB_PONGS_MISSED);
  }
}

void lightning_init(){
    WiFi.begin(ssid.c_str(), wifiPassword.c_str());
    while (WiFi.status() != WL_CONNECTED ) {      
      digitalWrite(2, HIGH);
      Serial.print(".");    
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}

void webSocketEvent(WStype_t type, uint8_t * payload, size_t length) {
    switch(type) {
        case WStype_DISCONNECTED:
            //Serial.println(F("[WSc] Disconnected!"));
            Serial.printf("[WSc] Disconnected to url: %s\n",  payload);
            connerr = true;
            showconnect = true;
            break;
        case WStype_CONNECTED:
            {
            Serial.printf("[WSc] Connected to url: %s\n",  payload);
			      webSocket.sendTXT("Connected");
            connerr = false;            
            }
            break;
        case WStype_TEXT:
            payloadStr = (char*)payload;
            Serial.println("Retorno [WSc]:");
            Serial.println(payloadStr);
            paid = true;
            break;
        case WStype_PING:
            // pong will be send automatically
            //Serial.println("[WSc] ping received");
            Serial.print("ping ");
            break;
        case WStype_PONG:
            // answer to a ping we send
            //Serial.println("[WSc] pong received");
            Serial.print("pong ");
            break;    
    		case WStype_ERROR:
        // answer to a ping we send
            Serial.println("[WSc] error received");
            break; 			
        default:
            Serial.println("Retorno [WSc]:");
            Serial.println(payloadStr);
            break;
    	/* 	case WStype_FRAGMENT_TEXT_START:
    		case WStype_FRAGMENT_BIN_START:
    		case WStype_FRAGMENT:
        case WStype_BIN:
    		case WStype_FRAGMENT_FIN:
    			break; */
    }
}

bool getSats()
{
  WiFiClientSecure client;
  client.setInsecure(); //Some versions of WiFiClientSecure need this

  lnbitsServer.toLowerCase();
  if (lnbitsServer.substring(0, 8) == "https://")
  {
    lnbitsServer = lnbitsServer.substring(8, lnbitsServer.length());
  }
  const char *lnbitsServerChar = lnbitsServer.c_str();
  const char *invoiceChar = invoice.c_str();
  const char *lncurrencyChar = lncurrency.c_str();

  //Serial.println("connecting to LNbits server " + lnbitsServer);
  if (!client.connect(lnbitsServerChar, 443))
  {
    Serial.println("failed to connect to LNbits server " + lnbitsServer);
    return false;
  } else {
    Serial.println("Connected to LNbits server " + lnbitsServer);
  }

  const String toPost = "{\"amount\" : 1, \"to\" : \"sat\", \"from_\" : \"" + String(lncurrencyChar) + "\"}";
  const String url = "/api/v1/conversion";
  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
            "Host: " + String(lnbitsServerChar) + "\r\n" +
            "User-Agent: ESP32\r\n" +
            //  "X-Api-Key: " + String(invoiceChar) + " \r\n" +
              "accept: application/json\r\n"
              "Content-Type: application/json\r\n" +
              "Connection: close\r\n" +
              "Content-Length: " + toPost.length() + "\r\n" +
               "\r\n" +
               toPost + "\n");
  Serial.println(toPost);
  while (client.connected())
  {
    const String line = client.readStringUntil('\n');
    // Serial.println(line);
    if (line == "\r")
    {
      break;
    }    
  }
  
  const String line = client.readString();
  Serial.println(line);
  StaticJsonDocument<150> doc;
  DeserializationError error = deserializeJson(doc, line);
  
  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.f_str());
    return false;
  }
  // serializeJsonPretty(doc, Serial);
  converted = doc["sats"];
  return true;
}

// Variáveis para implementação
char teste_invoice = 0;

// Para produção deve ser false
bool testar = false;

bool getInvoice(int noSats)
{
  WiFiClientSecure client;
  client.setInsecure(); //Some versions of WiFiClientSecure need this

  lnbitsServer.toLowerCase();
  if (lnbitsServer.substring(0, 8) == "https://")
  {
    lnbitsServer = lnbitsServer.substring(8, lnbitsServer.length());
  }
  const char *lnbitsServerChar = lnbitsServer.c_str();
  const char *invoiceChar = invoice_w.c_str();

  if (!client.connect(lnbitsServerChar, 443))
  {
    Serial.println("failed");
    // error("SERVER DOWN");
    // delay(3000);
    return false;
  }

  const String toPost = "{ \"unit\": \"sat\", \"out\": false,\"amount\" : " + String(noSats) + ", \"memo\" :\"BitSampaChope-" + String(random(1, 1000)) + "\", \"expiry\": 240 }";  // Expira em 4 minutos
  const String url = "/api/v1/payments";
  client.print(String("POST ") + url + " HTTP/1.1\r\n" +
               "Host: " + lnbitsServerChar + "\r\n" +
               "User-Agent: ESP32\r\n" +
               "X-Api-Key: " + invoiceChar + " \r\n" +
               "Content-Type: application/json\r\n" +
               "Connection: close\r\n" +
               "Content-Length: " + toPost.length() + "\r\n" +
               "\r\n" +
               toPost + "\n");

  while (client.connected())
  {
    const String line = client.readStringUntil('\n');

    if (line == "\r")
    {
      break;
    }
  }
  const String line = client.readString();

  StaticJsonDocument<1000> doc;
  DeserializationError error = deserializeJson(doc, line);
  
  /* Serial.println("======== Invoice ========");
  serializeJsonPretty(doc, Serial);
  Serial.println("");
  Serial.println("======== FIM Invoice ========"); */

  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.f_str());
    return false;
  }

  const char *payment_hash = doc["checking_id"];
  // verificar se retornou...
  const char *payment_request = doc["payment_request"];
  qrData = payment_request;
  dataId = payment_hash;
  Serial.print("Invoice Hash:");
  Serial.println(dataId);
  teste_invoice = 0;
  return true;
}

bool checkInvoice()
{
  WiFiClientSecure client;
  client.setInsecure(); //Some versions of WiFiClientSecure need this

  const char *lnbitsServerChar = lnbitsServer.c_str();
  // const char *invoiceChar = invoice.c_str();
  if (!client.connect(lnbitsServerChar, 443))
  {
    Serial.println("SERVER DOWN");
    //delay(3000);
    return false;
  }

  const String url = "/api/v1/payments/";
  client.print(String("GET ") + url + dataId + " HTTP/1.1\r\n" +
               "Host: " + lnbitsServerChar + "\r\n" +
               "User-Agent: ESP32\r\n" +
               "Content-Type: application/json\r\n" +
               "Connection: close\r\n\r\n");
  while (client.connected())
  {
    const String line = client.readStringUntil('\n');
    if (line == "\r")
    {
      break;
    }
  }

  const String line = client.readString();
  Serial.println(line);
  StaticJsonDocument<2000> doc;

  DeserializationError error = deserializeJson(doc, line);
  if (error)
  {
    Serial.print("deserializeJson() failed: ");
    Serial.println(error.f_str());
    return false;
  }
  
  // serializeJsonPretty(doc, Serial);

  if (doc["paid"])
  {
    confirmed = true;
    teste_invoice = 0;
  }

  if (doc["detail"] == "Payment does not exist.") {
    expired = true;
  }

  if (testar) {
    teste_invoice++;
    if (teste_invoice>1) confirmed = true;
  }

  return confirmed;
}