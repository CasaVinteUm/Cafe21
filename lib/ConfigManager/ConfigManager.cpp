#include "ConfigManager.h"

const char *ConfigManager::NVS_NAMESPACE = "cafe21";

ConfigManager::ConfigManager()
    : paymentGateway(nullptr), initialized(false)
{
    setDefaultValues();
}

void ConfigManager::setDefaultValues()
{
    espressoPriceSats = 0;
    coffeePriceSats = 0;
}

bool ConfigManager::begin(IPaymentGateway *gateway)
{
    paymentGateway = gateway;

    esp_err_t err = nvs_flash_init();
    if (err == ESP_ERR_NVS_NO_FREE_PAGES || err == ESP_ERR_NVS_NEW_VERSION_FOUND)
    {
        log_w("NVS needs to be erased");
        ESP_ERROR_CHECK(nvs_flash_erase());
        err = nvs_flash_init();
    }

    err = nvs_open(NVS_NAMESPACE, NVS_READWRITE, &nvsHandle);
    if (err != ESP_OK)
    {
        log_e("Error opening NVS handle: %s", esp_err_to_name(err));
        return false;
    }

    initialized = true;
    return load();
}

bool ConfigManager::load()
{
    if (!initialized)
    {
        return false;
    }

    nvs_get_u32(nvsHandle, "espresso_sat", &espressoPriceSats);
    nvs_get_u32(nvsHandle, "coffee_sat", &coffeePriceSats);
    return loadGatewayConfig();
}

bool ConfigManager::save()
{
    if (!initialized)
    {
        return false;
    }

    if (nvs_set_u32(nvsHandle, "espresso_sat", espressoPriceSats) != ESP_OK ||
        nvs_set_u32(nvsHandle, "coffee_sat", coffeePriceSats) != ESP_OK ||
        nvs_commit(nvsHandle) != ESP_OK)
    {
        return false;
    }

    return saveGatewayConfig();
}

bool ConfigManager::reset()
{
    if (!initialized)
    {
        return false;
    }

    if (nvs_erase_all(nvsHandle) != ESP_OK || nvs_commit(nvsHandle) != ESP_OK)
    {
        return false;
    }

    setDefaultValues();
    return resetGatewayConfig();
}

bool ConfigManager::getGatewayNamespace(char *buffer, size_t size) const
{
    if (paymentGateway == nullptr)
    {
        return false;
    }

    int written = snprintf(buffer, size, "pay_%s", paymentGateway->getId());
    return written > 0 && static_cast<size_t>(written) < size && written <= 15;
}

bool ConfigManager::loadGatewayConfig()
{
    char configNamespace[16];
    if (!getGatewayNamespace(configNamespace, sizeof(configNamespace)))
    {
        return paymentGateway == nullptr;
    }

    nvs_handle_t gatewayHandle;
    if (nvs_open(configNamespace, NVS_READONLY, &gatewayHandle) != ESP_OK)
    {
        return true;
    }

    for (size_t index = 0; index < paymentGateway->getConfigFieldCount(); ++index)
    {
        const PaymentConfigField &field = paymentGateway->getConfigField(index);
        if (strlen(field.key) > 15)
        {
            continue;
        }

        size_t requiredSize = 0;
        if (nvs_get_str(gatewayHandle, field.key, nullptr, &requiredSize) != ESP_OK ||
            requiredSize > field.maxLength + 1)
        {
            continue;
        }

        char *value = new char[requiredSize];
        if (nvs_get_str(gatewayHandle, field.key, value, &requiredSize) == ESP_OK)
        {
            paymentGateway->setConfigValue(index, value);
        }
        delete[] value;
    }

    nvs_close(gatewayHandle);
    return true;
}

bool ConfigManager::saveGatewayConfig()
{
    char configNamespace[16];
    if (!getGatewayNamespace(configNamespace, sizeof(configNamespace)))
    {
        return paymentGateway == nullptr;
    }

    nvs_handle_t gatewayHandle;
    if (nvs_open(configNamespace, NVS_READWRITE, &gatewayHandle) != ESP_OK)
    {
        return false;
    }

    bool success = true;
    for (size_t index = 0; index < paymentGateway->getConfigFieldCount(); ++index)
    {
        const PaymentConfigField &field = paymentGateway->getConfigField(index);
        if (strlen(field.key) > 15 ||
            nvs_set_str(gatewayHandle, field.key, paymentGateway->getConfigValue(index)) != ESP_OK)
        {
            success = false;
            break;
        }
    }

    success = success && nvs_commit(gatewayHandle) == ESP_OK;
    nvs_close(gatewayHandle);
    return success;
}

bool ConfigManager::resetGatewayConfig()
{
    char configNamespace[16];
    if (!getGatewayNamespace(configNamespace, sizeof(configNamespace)))
    {
        return paymentGateway == nullptr;
    }

    nvs_handle_t gatewayHandle;
    if (nvs_open(configNamespace, NVS_READWRITE, &gatewayHandle) != ESP_OK)
    {
        return false;
    }

    bool success = nvs_erase_all(gatewayHandle) == ESP_OK &&
                   nvs_commit(gatewayHandle) == ESP_OK;
    nvs_close(gatewayHandle);
    return success;
}
