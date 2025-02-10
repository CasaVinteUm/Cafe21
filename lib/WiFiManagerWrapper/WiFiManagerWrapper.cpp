#include "WiFiManagerWrapper.h"

WiFiManagerWrapper::WiFiManagerWrapper(ConfigManager &configManager, const char *ssid, const char *password)
    : config(configManager), shouldSaveConfig(false), apSSID(ssid), apPassword(password)
{
}

void WiFiManagerWrapper::setupParameters()
{
    // Clean up any existing parameters
    if (lnbitsServerParam)
        delete lnbitsServerParam;
    if (deviceIdParam)
        delete deviceIdParam;
    if (button1LnurlParam)
        delete button1LnurlParam;
    if (button2LnurlParam)
        delete button2LnurlParam;

    // Create parameters
    lnbitsServerParam = new WiFiManagerParameter(
        "lnbits_server",
        "LNBits Server",
        config.getLNBitsServer(),
        100);

    deviceIdParam = new WiFiManagerParameter(
        "device_id",
        "Device ID",
        config.getDeviceId(),
        22);

    button1LnurlParam = new WiFiManagerParameter(
        "button1_lnurl",
        "Button 1 LNURL",
        config.getButton1Lnurl(),
        256);

    button2LnurlParam = new WiFiManagerParameter(
        "button2_lnurl",
        "Button 2 LNURL",
        config.getButton2Lnurl(),
        256);

    // Add parameters to WiFiManager
    wm.addParameter(lnbitsServerParam);
    wm.addParameter(deviceIdParam);
    wm.addParameter(button1LnurlParam);
    wm.addParameter(button2LnurlParam);
}

void WiFiManagerWrapper::saveConfigCallback()
{
    log_i("Should save config");
    shouldSaveConfig = true;
}

void WiFiManagerWrapper::configModeCallback(WiFiManager *myWiFiManager)
{
    log_i("Entered config mode: %s", myWiFiManager->getConfigPortalSSID().c_str());
    log_i("Config IP Address: %s", WiFi.softAPIP().toString().c_str());
}

void WiFiManagerWrapper::saveParamsCallback()
{
    log_i("Saving parameters");

    // Update config with new values
    config.setLNBitsServer(lnbitsServerParam->getValue());
    config.setDeviceId(deviceIdParam->getValue());
    config.setButtonLnurl(1, button1LnurlParam->getValue());
    config.setButtonLnurl(2, button2LnurlParam->getValue());

    // Save to NVS
    if (!config.save())
    {
        log_e("Failed to save config");
    }
}

bool WiFiManagerWrapper::begin(bool forceConfig)
{
    // Set callbacks
    wm.setSaveParamsCallback([this]()
                             { saveParamsCallback(); });
    wm.setSaveConfigCallback([this]()
                             { saveConfigCallback(); });
    wm.setAPCallback([this](WiFiManager *wm)
                     { configModeCallback(wm); });

    // Setup custom parameters
    setupParameters();

    // Set WiFi mode
    WiFi.mode(WIFI_AP_STA);

    if (forceConfig)
    {
        log_i("Forcing config portal");
        wm.setConfigPortalBlocking(true);
        if (!wm.startConfigPortal(apSSID, apPassword))
        {
            log_e("Failed to connect in portal mode");
            return false;
        }
    }
    else
    {
        log_i("Attempting autoconnect");

        // Default settings for auto connect
        wm.setConfigPortalBlocking(true);
        wm.setConnectTimeout(30);
        wm.setConfigPortalTimeout(120);

        if (!wm.autoConnect(apSSID, apPassword))
        {
            log_e("Failed to connect");
            return false;
        }
    }

    if (shouldSaveConfig)
    {
        config.save();
    }

    log_i("Connected! IP: %s", WiFi.localIP().toString().c_str());
    log_i("MAC Address: %s", WiFi.macAddress().c_str());
    return true;
}

void WiFiManagerWrapper::process()
{
    wm.process();
}

void WiFiManagerWrapper::reset()
{
    log_w("Resetting WiFi settings");
    wm.resetSettings();
    WiFi.disconnect(true, true);
}