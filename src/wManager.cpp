#define ESP_DRD_USE_SPIFFS true

#include <WiFi.h>
#include <SPIFFS.h>
#include <FS.h>
#include <WiFiManager.h>
#include <ArduinoJson.h>
#include "wManager.h"

// JSON configuration file
#define JSON_CONFIG_FILE "/config.json"

// Flag for saving data
bool shouldSaveConfig = false;

char wmLNBitsServer[100] = "demo.lnbits.com";
char wmDeviceId[23] = "TjB6BGbD9RnAQSchgxHMXg";
char wmLNApiKey[33] = "5cd5fba9aea34f14a7fdb38e7f476922";
char wmLNApiKeyWS[35] = "5cd5fba9aea34f14a7fdb38e7f476922";
char wmESPMAC[18] = "bc:dd:c2:47:20:d0";
float wmValue = 10.00;
int wmvalueSats = 0;
float wmValueC = 10.00;
int wmvalueSatsC = 0;
int wmVolume = 300;

// Define WiFiManager Object
WiFiManager wm;

void saveConfigFile()
// Save Config in JSON format
{
  log_d("Salvando configuração...");
  // Create a JSON document
  StaticJsonDocument<512> json;
  json["wmLNBitsServer"] = wmLNBitsServer;
  // json["wmDeviceId"] = wmDeviceId;
  // json["wmLNApiKey"] = wmLNApiKey;
  json["wmLNApiKeyWS"] = wmLNApiKeyWS;
  json["wmValue"] = wmValue;
  json["wmvalueSats"] = wmvalueSatsC;
  json["wmValueC"] = wmValueC;
  json["wmvalueSatsC"] = wmvalueSatsC;
  json["wmVolume"] = wmVolume;
  json["wmESPMAC"] = wmESPMAC;

  // Open config file
  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    // Error, file did not open
    log_e("failed to open config file for writing");
  }

  // Serialize JSON data to write to file
  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    // Error writing file
    log_e("Failed to write to file");
  }
  // Close file
  configFile.close();
}

bool loadConfigFile()
// Load existing configuration file
{
  // Uncomment if we need to format filesystem
  // SPIFFS.format();

  // Read configuration from FS json
  log_d("Mounting File System...");
  // May need to make it begin(true) first time you are using SPIFFS
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    log_d("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      // The file exists, reading and loading
      log_d("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        log_d("Opened configuration file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        configFile.close();
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          log_v("Parsing JSON");
          strcpy(wmLNBitsServer, json["wmLNBitsServer"]);
          // strcpy(wmDeviceId, json["wmDeviceId"]);
          // strcpy(wmLNApiKey, json["wmLNApiKey"]);
          strcpy(wmLNApiKeyWS, json["wmLNApiKeyWS"]);
          strcpy(wmESPMAC, json["wmESPMAC"]);
          wmvalueSats = json["wmvalueSats"].as<int>();
          wmValue = json["wmValue"].as<float>();
          wmvalueSatsC = json["wmvalueSatsC"].as<int>();
          wmValueC = json["wmValueC"].as<float>();
          log_v("Parsing JSON - END!");
          return true;
        }
        else
        {
          // Error loading JSON data
          log_e("Failed to load json config");
        }
      }
    }
  }
  else
  {
    // Error mounting file system
    log_e("Failed to mount FS");
  }

  return false;
}

void saveConfigCallback()
// Callback notifying us of the need to save configuration
{
  log_d("Should save config");
  shouldSaveConfig = true;
  // wm.setConfigPortalBlocking(false);
}

void configModeCallback(WiFiManager *myWiFiManager)
// Called when config mode launched
{
  log_d("Entered Configuration Mode");
  log_d("Config SSID: %s", myWiFiManager->getConfigPortalSSID());
  log_d("Config IP Address: %s", WiFi.softAPIP());
}

void init_WifiManager()
{

  // Change to true when testing to force configuration every time we run
  bool forceConfig = false;

  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    log_w("Forcing config mode as there is no saved config");
    forceConfig = true;
  }

  // Explicitly set WiFi mode
  // WiFi.mode(WIFI_AP_STA);
  WiFi.mode(WIFI_AP_STA);

  // Reset settings (only for development)
  // wm.resetSettings();

  // Set dark theme
  // wm.setClass("invert"); // dark theme

  // Set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);

  // Set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  // Advanced settings
  wm.setConfigPortalBlocking(false); // Hacemos que el portal no bloquee el firmware
  wm.setConnectTimeout(30);          // how long to try to connect for before continuing
  wm.setConfigPortalTimeout(120);    // auto close configportal after n seconds
  // wm.setCaptivePortalEnable(false); // disable captive portal redirection
  // wm.setAPClientCheck(true); // avoid timeout if client connected to softap
  // wm.setTimeout(120);

  // Custom elements

  // Text box (String) - 100 characters maximum
  WiFiManagerParameter lnbitsServerTBox("LNBitsServer", "LNBits Server", wmLNBitsServer, 100);

  /*
  // Text box (String) - 22 characters maximum
  WiFiManagerParameter deviceIdTBox("LNURLDeviceID", "LNURLDevice ID", wmDeviceId, 22);

  // Text box (String) - 25 characters maximum
  WiFiManagerParameter lnApiKeyTBox("LNURLDeviceKey", "LNURLDevice Key", wmLNApiKey, 25);
   */

  WiFiManagerParameter lnApiKeyWSTBox("LNBitsreadkey", "LNBits Wallet Invoice/read key", wmLNApiKeyWS, 35);

  // Need to convert numerical input to string to display the default value.
  char convertedValue[6];
  sprintf(convertedValue, "%.2f", wmValue);

  // Text box (Number) - 7 characters maximum
  WiFiManagerParameter valueFiat("valueFiat", "Preço Expresso R$", convertedValue, 7);

  sprintf(convertedValue, "%d", wmvalueSats);

  // Text box (Number) - 8 characters maximum
  WiFiManagerParameter valueSats("PrecoSatoshis", "Preço Expresso sats", convertedValue, 8);

  sprintf(convertedValue, "%.2f", wmValueC);

  // Text box (Number) - 7 characters maximum
  WiFiManagerParameter valueFiatC("valueFiatC", "Preço Block Coffe R$", convertedValue, 7);

  sprintf(convertedValue, "%d", wmvalueSatsC);

  // Text box (Number) - 8 characters maximum
  WiFiManagerParameter valueSatsC("PrecoSatoshisC", "Preço Block Coffe sats", convertedValue, 8);

  // Add all defined parameters
  wm.addParameter(&lnbitsServerTBox);
  wm.addParameter(&lnApiKeyWSTBox);
  // wm.addParameter(&deviceIdTBox);
  // wm.addParameter(&lnApiKeyTBox);
  wm.addParameter(&valueFiat);
  wm.addParameter(&valueSats);
  wm.addParameter(&valueFiatC);
  wm.addParameter(&valueSatsC);
  log_d("All Parameters done: ");

  if (forceConfig)
  // Run if we need a configuration
  {
    log_w("Force Config...");
    // No configuramos timeout al modulo
    wm.setConfigPortalBlocking(true); // Hacemos que el portal SI bloquee el firmware
    if (!wm.startConfigPortal(wmSSID, wmPASSWD))
    {
      log_e("failed to connect and hit timeout");
      // Could be break forced after edditing, so save new config
      strcpy(wmLNBitsServer, lnbitsServerTBox.getValue()); // , sizeof(wmLNBitsServer));
      // strcpy(wmDeviceId, deviceIdTBox.getValue());//, sizeof(wmDeviceId));
      // strcpy(wmLNApiKey, lnApiKeyTBox.getValue());//, sizeof(wmLNApiKey));
      strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue()); //, sizeof(wmLNApiKeyWS));

      wmValue = atof(valueFiat.getValue());
      wmvalueSats = atoi(valueSats.getValue());

      wmValueC = atof(valueFiatC.getValue());
      wmvalueSatsC = atoi(valueSatsC.getValue());

      saveConfigFile();
      delay(3000);
      // reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }
  }
  else
  {
    log_d("Auto Conecting...");
    // Tratamos de conectar con la configuración inicial ya almacenada
    wm.setCaptivePortalEnable(true); // disable captive portal redirection
    wm.setConfigPortalBlocking(true);
    if (!wm.autoConnect(wmSSID, wmPASSWD))
    {
      log_e("Failed to connect and hit timeout...");
    }
  }

  // Conectado a la red Wifi
  if (WiFi.status() == WL_CONNECTED)
  {
    // tft.pushImage(0, 0, MinerWidth, MinerHeight, MinerScreen);
    log_i("WiFi connected");
    log_d("IP address: %s", WiFi.localIP());
    log_v("MAC: %s", WiFi.macAddress());
    log_v("CH: %s", WiFi.channel());

    // Lets deal with the user config values
    strcpy(wmLNBitsServer, lnbitsServerTBox.getValue()); // , sizeof(wmLNBitsServer));
                                                         // strcpy(wmDeviceId, deviceIdTBox.getValue());//, sizeof(wmDeviceId));
                                                         // strcpy(wmLNApiKey, lnApiKeyTBox.getValue());//, sizeof(wmLNApiKey));
    strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue());     //, sizeof(wmLNApiKeyWS));

    wmValue = atof(valueFiat.getValue());
    wmvalueSats = atoi(valueSats.getValue());
    wmValueC = atof(valueFiatC.getValue());
    wmvalueSatsC = atoi(valueSatsC.getValue());

    // Copy the string value
    // strncpy(wmLNBitsServer, lnbitsServerTBox.getValue(), sizeof(wmLNBitsServer));
    // Serial.print("LNBits Server: ");
    // Serial.println(wmLNBitsServer);
  }
  else
  {
    log_e("Failed to connect. Reseting...");
    strcpy(wmLNBitsServer, lnbitsServerTBox.getValue()); // , sizeof(wmLNBitsServer));
    strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue());     //, sizeof(wmLNApiKeyWS));

    wmValue = atof(valueFiat.getValue());
    wmvalueSats = atoi(valueSats.getValue());

    wmValueC = atof(valueFiat.getValue());
    wmvalueSatsC = atoi(valueSats.getValue());

    saveConfigFile();
    delay(1000);
    ESP.restart();
  }

  // Save the custom parameters to FS
  if (shouldSaveConfig)
  {
    saveConfigFile();
  }
}

void reset_configurations()
{
  log_w("Erasing Config, restarting");
  wm.resetSettings();
  SPIFFS.remove(JSON_CONFIG_FILE); // Borramos fichero
  ESP.restart();
}

//----------------- MAIN PROCESS WIFI MANAGER --------------
int oldStatus = 0;

void wifiManagerProcess()
{

  wm.process(); // avoid delays() in loop when non-blocking and other long running code

  int newStatus = WiFi.status();
  if (newStatus != oldStatus)
  {
    if (newStatus == WL_CONNECTED)
    {
      log_i("CONNECTED - Current ip: %s", WiFi.localIP().toString());
    }
    else
    {
      log_i("current status: %d", newStatus);
    }
    oldStatus = newStatus;
  }
}
