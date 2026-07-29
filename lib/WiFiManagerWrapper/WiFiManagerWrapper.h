#ifndef WIFIMANAGERWRAPPER_H
#define WIFIMANAGERWRAPPER_H

#include <vector>
#include <WiFiManager.h>

#include "ConfigManager.h"
#include <PaymentGateway.h>

class WiFiManagerWrapper
{
public:
    WiFiManagerWrapper(ConfigManager &configManager,
                       IPaymentGateway *gateway = nullptr,
                       const char *ssid = "Cafe21",
                       const char *password = "Cafeina21");
    bool begin(bool forceConfig = false);
    void process();
    void reset();
    bool isConnected() const { return WiFi.status() == WL_CONNECTED; }

    String getIPAddress() const { return WiFi.localIP().toString(); }
    String getMACAddress() const { return WiFi.macAddress(); }

    void setPortalTimeout(unsigned long seconds) { wm.setConfigPortalTimeout(seconds); }
    void setPortalBlocking(bool enable) { wm.setConfigPortalBlocking(enable); }
    void setConnectTimeout(unsigned long seconds) { wm.setConnectTimeout(seconds); }
    void setCaptivePortal(bool enable) { wm.setCaptivePortalEnable(enable); }

private:
    WiFiManager wm;
    ConfigManager &config;
    IPaymentGateway *paymentGateway;
    bool shouldSaveConfig;
    const char *apSSID;
    const char *apPassword;

    WiFiManagerParameter *espressoPriceParam;
    WiFiManagerParameter *coffeePriceParam;
    std::vector<WiFiManagerParameter *> gatewayParams;

    void setupParameters();
    void saveConfigCallback();
    void configModeCallback(WiFiManager *myWiFiManager);
    void saveParamsCallback();
    bool parsePrice(const char *value, uint32_t &price) const;
};

#endif // WIFIMANAGERWRAPPER_H
