#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <Arduino.h>
#include <nvs_flash.h>
#include <nvs.h>
#include "esp_log.h"

class ConfigManager
{
private:
    static const char *NVS_NAMESPACE;
    nvs_handle_t nvsHandle;
    bool initialized;

    // Configuration values
    char lnbitsServer[100];
    char deviceId[23];
    char button1Lnurl[256];
    char button2Lnurl[256];

    void setDefaultValues();

public:
    ConfigManager();
    bool begin();
    bool load();
    bool save();
    bool reset();

    // Getters
    const char *getLNBitsServer() const { return lnbitsServer; }
    const char *getDeviceId() const { return deviceId; }
    const char *getButton1Lnurl() const { return button1Lnurl; }
    const char *getButton2Lnurl() const { return button2Lnurl; }

    // Setters
    void setLNBitsServer(const char *server);
    void setDeviceId(const char *id);
    void setButtonLnurl(const uint8_t buttonNumber, const char *lnurl);
};

#endif // CONFIGMANAGER_H