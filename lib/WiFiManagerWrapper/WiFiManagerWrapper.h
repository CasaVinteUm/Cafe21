#ifndef WIFIMANAGERWRAPPER_H
#define WIFIMANAGERWRAPPER_H

#include <WiFiManager.h>
#include "ConfigManager.h"

class WiFiManagerWrapper
{
private:
    WiFiManager wm;
    ConfigManager &config;
    bool shouldSaveConfig;

    const char *apSSID;
    const char *apPassword;

    WiFiManagerParameter *lnbitsServerParam;
    WiFiManagerParameter *deviceIdParam;
    WiFiManagerParameter *button1LnurlParam;
    WiFiManagerParameter *button2LnurlParam;

    void setupParameters();
    void saveConfigCallback();
    void configModeCallback(WiFiManager *myWiFiManager);
    void saveParamsCallback();

public:
    WiFiManagerWrapper(ConfigManager &configManager,
                       const char *ssid = "Cafe21",
                       const char *password = "Cafeina21");

    bool begin(bool forceConfig = false);
    void process();
    void reset();
    bool isConnected() const { return WiFi.status() == WL_CONNECTED; }

    String getIPAddress() const { return WiFi.localIP().toString(); }
    String getMACAddress() const { return WiFi.macAddress(); }

    // Portal configuration
    void setPortalTimeout(unsigned long seconds) { wm.setConfigPortalTimeout(seconds); }
    void setPortalBlocking(bool enable) { wm.setConfigPortalBlocking(enable); }
    void setConnectTimeout(unsigned long seconds) { wm.setConnectTimeout(seconds); }
    void setCaptivePortal(bool enable) { wm.setCaptivePortalEnable(enable); }
};

#endif // WIFIMANAGERWRAPPER_H