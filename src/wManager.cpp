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

// Variables to hold data from custom textboxes
//char wm_lnbitsWSApiURL[80] = "/api/v1/ws/";

char wmLNBitsServer[100] = "demo.lnbits.com";
char wmDeviceId[23] = "TjB6BGbD9RnAQSchgxHMXg";
char wmLNApiKey[33] = "5cd5fba9aea34f14a7fdb38e7f476922";
char wmLNApiKeyWS[35] = "5cd5fba9aea34f14a7fdb38e7f476922";
char wmESPMAC[18] = "bc:dd:c2:47:20:d0";
float wmPreco = 10.00;
int wmprecoSats = 0;
int wmVolume = 300;


// Define WiFiManager Object
WiFiManager wm;

void saveConfigFile()
// Save Config in JSON format
{
  Serial.println(F("Salvando configuração..."));  
  // Create a JSON document
  StaticJsonDocument<512> json;
  json["wmLNBitsServer"] = wmLNBitsServer;
 // json["wmDeviceId"] = wmDeviceId;
 // json["wmLNApiKey"] = wmLNApiKey;
  json["wmLNApiKeyWS"] = wmLNApiKeyWS;
  json["wmPreco"] = wmPreco;
  json["wmprecoSats"] = wmprecoSats;
  json["wmVolume"] = wmVolume;
  json["wmESPMAC"] = wmESPMAC;

  // Open config file
  File configFile = SPIFFS.open(JSON_CONFIG_FILE, "w");
  if (!configFile)
  {
    // Error, file did not open
    Serial.println("failed to open config file for writing");
  }

  // Serialize JSON data to write to file
  serializeJsonPretty(json, Serial);
  if (serializeJson(json, configFile) == 0)
  {
    // Error writing file
    //Serial.println(F("Failed to write to file"));
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
  Serial.println("Mounting File System...");

  // May need to make it begin(true) first time you are using SPIFFS
  if (SPIFFS.begin(false) || SPIFFS.begin(true))
  {
    Serial.println("mounted file system");
    if (SPIFFS.exists(JSON_CONFIG_FILE))
    {
      // The file exists, reading and loading
      Serial.println("reading config file");
      File configFile = SPIFFS.open(JSON_CONFIG_FILE, "r");
      if (configFile)
      {
        Serial.println("Opened configuration file");
        StaticJsonDocument<512> json;
        DeserializationError error = deserializeJson(json, configFile);
        configFile.close();
        serializeJsonPretty(json, Serial);
        if (!error)
        {
          Serial.println("Parsing JSON");
          
          strcpy(wmLNBitsServer, json["wmLNBitsServer"]);
          // strcpy(wmDeviceId, json["wmDeviceId"]);
          // strcpy(wmLNApiKey, json["wmLNApiKey"]);
          strcpy(wmLNApiKeyWS, json["wmLNApiKeyWS"]);
          strcpy(wmESPMAC, json["wmESPMAC"]);          
          wmprecoSats = json["wmprecoSats"].as<int>();
          wmVolume = json["wmVolume"].as<int>();
          wmPreco = json["wmPreco"].as<float>();
          Serial.println("Parsing JSON - END!");
          return true;
        }
        else
        {
          // Error loading JSON data
          Serial.println("Failed to load json config");
        }
      }
    }
  }
  else
  {
    // Error mounting file system
    Serial.println("Failed to mount FS");
  }

  return false;
}

void saveConfigCallback()
// Callback notifying us of the need to save configuration
{
  Serial.println("Should save config");
  shouldSaveConfig = true;  
  //wm.setConfigPortalBlocking(false);
}

void configModeCallback(WiFiManager *myWiFiManager)
// Called when config mode launched
{
  Serial.println("Entered Configuration Mode");

  Serial.print("Config SSID: ");
  Serial.println(myWiFiManager->getConfigPortalSSID());

  Serial.print("Config IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void init_WifiManager()
{

  // Change to true when testing to force configuration every time we run
  bool forceConfig = false;
 
  bool spiffsSetup = loadConfigFile();
  if (!spiffsSetup)
  {
    Serial.println(F("Forcing config mode as there is no saved config"));
    forceConfig = true;    
  }

  // Explicitly set WiFi mode
  // WiFi.mode(WIFI_AP_STA);
  WiFi.mode(WIFI_AP_STA);

  // Reset settings (only for development)
  //wm.resetSettings();

  //Set dark theme
  //wm.setClass("invert"); // dark theme
  
  // Set config save notify callback
  wm.setSaveConfigCallback(saveConfigCallback);

  // Set callback that gets called when connecting to previous WiFi fails, and enters Access Point mode
  wm.setAPCallback(configModeCallback);

  //Advanced settings
  wm.setConfigPortalBlocking(false); //Hacemos que el portal no bloquee el firmware
  wm.setConnectTimeout(30); // how long to try to connect for before continuing
  wm.setConfigPortalTimeout(120); // auto close configportal after n seconds
  // wm.setCaptivePortalEnable(false); // disable captive portal redirection
  // wm.setAPClientCheck(true); // avoid timeout if client connected to softap
  //wm.setTimeout(120);
  
  // Custom elements

  // Text box (String) - 100 characters maximum
  WiFiManagerParameter lnbitsServerTBox("LNBitsServer", "LNBits Server", wmLNBitsServer , 100);
  
  /* 
  // Text box (String) - 22 characters maximum
  WiFiManagerParameter deviceIdTBox("LNURLDeviceID", "LNURLDevice ID", wmDeviceId, 22);

  // Text box (String) - 25 characters maximum
  WiFiManagerParameter lnApiKeyTBox("LNURLDeviceKey", "LNURLDevice Key", wmLNApiKey, 25);
   */

  WiFiManagerParameter lnApiKeyWSTBox("LNBitsreadkey", "LNBits Wallet Invoice/read key", wmLNApiKeyWS, 35);

  WiFiManagerParameter wmESPMACTBox("MACADD", "Endereço MAC dos sensores", wmESPMAC, 18);

  // Need to convert numerical input to string to display the default value.
  char convertedValue[6];
  sprintf(convertedValue, "%.2f", wmPreco); 
  
  // Text box (Number) - 7 characters maximum
  WiFiManagerParameter precoReais("PrecoReais", "Preço R$", convertedValue, 7); 

  sprintf(convertedValue, "%d", wmprecoSats); 
  
  // Text box (Number) - 8 characters maximum
  WiFiManagerParameter precoSats("PrecoSatoshis", "Preço sats", convertedValue, 8);

  sprintf(convertedValue, "%d", wmVolume); 
  // Text box (Number) - 8 characters maximum
  WiFiManagerParameter volumeCopo("VolumeCopo", "Volume Copo (ml)", convertedValue, 4);
  
  

  // Add all defined parameters
  wm.addParameter(&lnbitsServerTBox);  
  wm.addParameter(&lnApiKeyWSTBox);
  // wm.addParameter(&deviceIdTBox);
  // wm.addParameter(&lnApiKeyTBox);
  wm.addParameter(&precoReais);
  wm.addParameter(&precoSats);
  wm.addParameter(&volumeCopo);
  wm.addParameter(&wmESPMACTBox);

  Serial.println("All Parameters done: ");

  if (forceConfig)
    // Run if we need a configuration
  {
    Serial.println("Force Config...");
    //No configuramos timeout al modulo
    wm.setConfigPortalBlocking(true); //Hacemos que el portal SI bloquee el firmware    
    if (!wm.startConfigPortal("BityChopp","satschopp"))
    {
      Serial.println("failed to connect and hit timeout");
      //Could be break forced after edditing, so save new config
      strcpy(wmLNBitsServer, lnbitsServerTBox.getValue());// , sizeof(wmLNBitsServer));
      // strcpy(wmDeviceId, deviceIdTBox.getValue());//, sizeof(wmDeviceId));
      // strcpy(wmLNApiKey, lnApiKeyTBox.getValue());//, sizeof(wmLNApiKey));
      strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue());//, sizeof(wmLNApiKeyWS));
      strcpy(wmESPMAC, wmESPMACTBox.getValue());
     
      wmPreco = atof(precoReais.getValue());
      wmprecoSats = atoi(precoSats.getValue());
      wmVolume = atoi(volumeCopo.getValue());
      
      saveConfigFile();
      delay(3000);
      //reset and try again, or maybe put it to deep sleep
      ESP.restart();
      delay(5000);
    }
  }
  else
  {
    Serial.println("Auto Conecta...");
    //Tratamos de conectar con la configuración inicial ya almacenada
    wm.setCaptivePortalEnable(true); // disable captive portal redirection
    wm.setConfigPortalBlocking(true);
    if (!wm.autoConnect("BityChopp","satschopp"))
    {
      Serial.println("Failed to connect and hit timeout...");            
    }
  }

  //Conectado a la red Wifi
  if(WiFi.status() == WL_CONNECTED){
    //tft.pushImage(0, 0, MinerWidth, MinerHeight, MinerScreen);
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
    Serial.print("MAC:");
    Serial.println(WiFi.macAddress());
    Serial.print("CH:");
    Serial.println(WiFi.channel());

    // Lets deal with the user config values
    strcpy(wmLNBitsServer, lnbitsServerTBox.getValue());// , sizeof(wmLNBitsServer));
   // strcpy(wmDeviceId, deviceIdTBox.getValue());//, sizeof(wmDeviceId));
   // strcpy(wmLNApiKey, lnApiKeyTBox.getValue());//, sizeof(wmLNApiKey));
    strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue());//, sizeof(wmLNApiKeyWS));
    strcpy(wmESPMAC, wmESPMACTBox.getValue());
    
    wmPreco = atof(precoReais.getValue());
    wmprecoSats = atoi(precoSats.getValue());
    wmVolume = atoi(volumeCopo.getValue());
  
    // Copy the string value
    // strncpy(wmLNBitsServer, lnbitsServerTBox.getValue(), sizeof(wmLNBitsServer));
    // Serial.print("LNBits Server: ");
    // Serial.println(wmLNBitsServer);
  } else {
        Serial.println("Failed to connect reseting...");      
        strcpy(wmLNBitsServer, lnbitsServerTBox.getValue());// , sizeof(wmLNBitsServer));
        strcpy(wmLNApiKeyWS, lnApiKeyWSTBox.getValue());//, sizeof(wmLNApiKeyWS));     
        strcpy(wmESPMAC, wmESPMACTBox.getValue());       
        wmPreco = atof(precoReais.getValue());
        wmprecoSats = atoi(precoSats.getValue());
        wmVolume = atoi(volumeCopo.getValue());                        
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

void reset_configurations() {
  Serial.println("Erasing Config, restarting");
  wm.resetSettings();
  SPIFFS.remove(JSON_CONFIG_FILE); //Borramos fichero
  ESP.restart();
}


//----------------- MAIN PROCESS WIFI MANAGER --------------
int oldStatus = 0;

void wifiManagerProcess() {
  
  wm.process(); // avoid delays() in loop when non-blocking and other long running code
  
  int newStatus = WiFi.status();
  if (newStatus != oldStatus) {
    if (newStatus == WL_CONNECTED) {
      Serial.println("CONNECTED - Current ip: " + WiFi.localIP().toString());
    } else {
      Serial.print("[Error] - current status: ");
      Serial.println(newStatus);
    }
    oldStatus = newStatus;
  }
}


