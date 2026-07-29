#include "WiFiManagerWrapper.h"

#include <cerrno>
#include <cstdlib>

WiFiManagerWrapper::WiFiManagerWrapper(ConfigManager &configManager,
                                       IPaymentGateway *gateway,
                                       const char *ssid,
                                       const char *password)
    : config(configManager),
      paymentGateway(gateway),
      shouldSaveConfig(false),
      apSSID(ssid),
      apPassword(password),
      espressoPriceParam(nullptr),
      coffeePriceParam(nullptr)
{
}

void WiFiManagerWrapper::setupParameters()
{
    static char espressoPrice[11];
    static char coffeePrice[11];
    snprintf(espressoPrice, sizeof(espressoPrice), "%lu",
             static_cast<unsigned long>(config.getEspressoPriceSats()));
    snprintf(coffeePrice, sizeof(coffeePrice), "%lu",
             static_cast<unsigned long>(config.getCoffeePriceSats()));

    espressoPriceParam = new WiFiManagerParameter(
        "espresso_sat", "Espresso price (sats, 0 = free)", espressoPrice, 10);
    coffeePriceParam = new WiFiManagerParameter(
        "coffee_sat", "Coffee price (sats, 0 = free)", coffeePrice, 10);
    wm.addParameter(espressoPriceParam);
    wm.addParameter(coffeePriceParam);

    if (paymentGateway == nullptr)
    {
        return;
    }

    for (size_t index = 0; index < paymentGateway->getConfigFieldCount(); ++index)
    {
        const PaymentConfigField &field = paymentGateway->getConfigField(index);
        const char *customAttributes = nullptr;
        if (field.type == PaymentConfigFieldType::Secret)
        {
            customAttributes = "type=\"password\"";
        }
        else if (field.type == PaymentConfigFieldType::UnsignedInteger)
        {
            customAttributes = "type=\"number\" min=\"0\"";
        }
        WiFiManagerParameter *parameter = new WiFiManagerParameter(
            field.key,
            field.label,
            paymentGateway->getConfigValue(index),
            static_cast<int>(field.maxLength),
            customAttributes);
        gatewayParams.push_back(parameter);
        wm.addParameter(parameter);
    }
}

void WiFiManagerWrapper::saveConfigCallback()
{
    shouldSaveConfig = true;
}

void WiFiManagerWrapper::configModeCallback(WiFiManager *myWiFiManager)
{
    log_i("Entered config mode: %s", myWiFiManager->getConfigPortalSSID().c_str());
    log_i("Config IP Address: %s", WiFi.softAPIP().toString().c_str());
}

bool WiFiManagerWrapper::parsePrice(const char *value, uint32_t &price) const
{
    if (value == nullptr)
    {
        return false;
    }

    errno = 0;
    char *end = nullptr;
    unsigned long parsed = strtoul(value, &end, 10);
    if (errno != 0 || end == value || *end != '\0' || parsed > UINT32_MAX)
    {
        return false;
    }

    price = static_cast<uint32_t>(parsed);
    return true;
}

void WiFiManagerWrapper::saveParamsCallback()
{
    uint32_t espressoPrice;
    uint32_t coffeePrice;
    if (!parsePrice(espressoPriceParam->getValue(), espressoPrice) ||
        !parsePrice(coffeePriceParam->getValue(), coffeePrice))
    {
        log_e("Invalid product price");
        return;
    }

    config.setEspressoPriceSats(espressoPrice);
    config.setCoffeePriceSats(coffeePrice);

    if (paymentGateway != nullptr)
    {
        for (size_t index = 0; index < gatewayParams.size(); ++index)
        {
            if (!paymentGateway->setConfigValue(index, gatewayParams[index]->getValue()))
            {
                log_e("Invalid payment configuration field: %s",
                      paymentGateway->getConfigField(index).key);
                return;
            }
        }
    }

    if (!config.save())
    {
        log_e("Failed to save config");
    }
}

bool WiFiManagerWrapper::begin(bool forceConfig)
{
    wm.setSaveParamsCallback([this]()
                             { saveParamsCallback(); });
    wm.setSaveConfigCallback([this]()
                             { saveConfigCallback(); });
    wm.setAPCallback([this](WiFiManager *manager)
                     { configModeCallback(manager); });

    setupParameters();
    WiFi.mode(WIFI_AP_STA);

    if (forceConfig)
    {
        wm.setConfigPortalBlocking(true);
        if (!wm.startConfigPortal(apSSID, apPassword))
        {
            return false;
        }
    }
    else
    {
        wm.setConfigPortalBlocking(true);
        wm.setConnectTimeout(30);
        wm.setConfigPortalTimeout(120);
        if (!wm.autoConnect(apSSID, apPassword))
        {
            return false;
        }
    }

    if (shouldSaveConfig && !config.save())
    {
        return false;
    }

    log_i("Connected! IP: %s", WiFi.localIP().toString().c_str());
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
