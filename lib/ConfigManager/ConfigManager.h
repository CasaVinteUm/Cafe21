#ifndef CONFIGMANAGER_H
#define CONFIGMANAGER_H

#include <Arduino.h>
#include <nvs.h>
#include <nvs_flash.h>

#include <PaymentGateway.h>

class ConfigManager
{
public:
    ConfigManager();

    bool begin(IPaymentGateway *gateway = nullptr);
    bool load();
    bool save();
    bool reset();

    uint32_t getEspressoPriceSats() const { return espressoPriceSats; }
    uint32_t getCoffeePriceSats() const { return coffeePriceSats; }

    void setEspressoPriceSats(uint32_t price) { espressoPriceSats = price; }
    void setCoffeePriceSats(uint32_t price) { coffeePriceSats = price; }

private:
    static const char *NVS_NAMESPACE;

    nvs_handle_t nvsHandle;
    IPaymentGateway *paymentGateway;
    bool initialized;
    uint32_t espressoPriceSats;
    uint32_t coffeePriceSats;

    void setDefaultValues();
    bool loadGatewayConfig();
    bool saveGatewayConfig();
    bool resetGatewayConfig();
    bool getGatewayNamespace(char *buffer, size_t size) const;
};

#endif // CONFIGMANAGER_H
