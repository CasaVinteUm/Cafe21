#include "ConfigManager.h"

const char *ConfigManager::NVS_NAMESPACE = "cafe21";

void ConfigManager::setDefaultValues()
{
    // Set defaults
    strcpy(lnbitsServer, "lnbits.casa21.space");
    strcpy(deviceId, "HJiRnWrWUqM7LYGELwBaMd");
    strcpy(button1Lnurl, "LNURL1DP68GURN8GHJ7MRWVF5HGUEWVDSHXCFJXYH8XURPVDJJ7MRWW4EXCER9WE5KXEF0V9CXJTMKXGHKCMN4WFKZ7JZ2D9FXU4MJ2A2HZNFHF3V5W32VWAPXZNTY8ACXJM3AXYNXZMT0W4H8G0FS9CCRZFNYW4EXZARFDAHR6VFXWESHY6TPVFKX202XV9K8XEFXVDHK6MT9DE6R63NPD3EK254NLZL");
    strcpy(button2Lnurl, "LNURL1DP68GURN8GHJ7MRWVF5HGUEWVDSHXCFJXYH8XURPVDJJ7MRWW4EXCER9WE5KXEF0V9CXJTMKXGHKCMN4WFKZ7JZ2D9FXU4MJ2A2HZNFHF3V5W32VWAPXZNTY8ACXJM3AXGNXZMT0W4H8G0FS9CCRZFNYW4EXZARFDAHR6V3XWESHY6TPVFKX202XV9K8XEFXVDHK6MT9DE6R63NPD3EK2CRQ6MQ");
}

ConfigManager::ConfigManager() : initialized(false)
{
    setDefaultValues();
}

bool ConfigManager::begin()
{
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
    log_i("NVS initialized successfully");
    return load();
}

bool ConfigManager::load()
{
    if (!initialized)
        return false;

    // Load all values from NVS
    size_t required_size;
    esp_err_t err;

    // Load strings
    if (nvs_get_str(nvsHandle, "lnbits_server", nullptr, &required_size) == ESP_OK)
    {
        nvs_get_str(nvsHandle, "lnbits_server", lnbitsServer, &required_size);
        log_i("lnbits_server: %s", lnbitsServer);
    }
    if (nvs_get_str(nvsHandle, "device_id", nullptr, &required_size) == ESP_OK)
    {
        nvs_get_str(nvsHandle, "device_id", deviceId, &required_size);
        log_i("device_id: %s", deviceId);
    }
    if (nvs_get_str(nvsHandle, "button1_lnurl", nullptr, &required_size) == ESP_OK)
    {
        nvs_get_str(nvsHandle, "button1_lnurl", button1Lnurl, &required_size);
        log_i("button1_lnurl: %s", button1Lnurl);
    }
    if (nvs_get_str(nvsHandle, "button2_lnurl", nullptr, &required_size) == ESP_OK)
    {
        nvs_get_str(nvsHandle, "button2_lnurl", button2Lnurl, &required_size);
        log_i("button2_lnurl: %s", button2Lnurl);
    }

    log_i("Configuration loaded");
    return true;
}

bool ConfigManager::save()
{
    if (!initialized)
        return false;

    // Save all values to NVS
    esp_err_t err;

    // Save strings
    err = nvs_set_str(nvsHandle, "lnbits_server", lnbitsServer);
    if (err != ESP_OK)
        return false;

    err = nvs_set_str(nvsHandle, "device_id", deviceId);
    if (err != ESP_OK)
        return false;

    err = nvs_set_str(nvsHandle, "button1_lnurl", button1Lnurl);
    if (err != ESP_OK)
        return false;

    err = nvs_set_str(nvsHandle, "button2_lnurl", button2Lnurl);
    if (err != ESP_OK)
        return false;

    err = nvs_commit(nvsHandle);
    if (err != ESP_OK)
        return false;

    log_i("Configuration saved");
    return true;
}

bool ConfigManager::reset()
{
    if (!initialized)
    {
        log_e("Cannot reset: not initialized");
        return false;
    }

    // Erase all keys in our namespace
    esp_err_t err = nvs_erase_all(nvsHandle);
    if (err != ESP_OK)
    {
        log_e("Error erasing NVS: %s", esp_err_to_name(err));
        return false;
    }

    // Commit changes to NVS
    err = nvs_commit(nvsHandle);
    if (err != ESP_OK)
    {
        log_e("Error committing NVS reset: %s", esp_err_to_name(err));
        return false;
    }

    // Reset values to defaults
    setDefaultValues();

    log_i("Configuration reset to defaults");
    return true;
}

void ConfigManager::setLNBitsServer(const char *server)
{
    if (server == nullptr)
    {
        log_w("Attempt to set null LNBits server");
        return;
    }

    if (strlen(server) >= sizeof(lnbitsServer))
    {
        log_e("LNBits server string too long (max %d chars)", sizeof(lnbitsServer) - 1);
        return;
    }

    strcpy(lnbitsServer, server);
    log_i("LNBits server set to: %s", server);
}

void ConfigManager::setDeviceId(const char *id)
{
    if (id == nullptr)
    {
        log_w("Attempt to set null device ID");
        return;
    }

    if (strlen(id) >= sizeof(deviceId))
    {
        log_e("Device ID string too long (max %d chars)", sizeof(deviceId) - 1);
        return;
    }

    strcpy(deviceId, id);
    log_i("Device ID set to: %s", id);
}

void ConfigManager::setButtonLnurl(const uint8_t buttonNumber, const char *lnurl)
{
    if (lnurl == nullptr)
    {
        log_w("Attempt to set null Button %d Lnurl", buttonNumber);
        return;
    }

    if (strlen(lnurl) >= sizeof(lnurl))
    {
        log_e("Button %d Lnurl string too long (max %d chars)", buttonNumber, sizeof(lnurl) - 1);
        return;
    }

    if (buttonNumber == 1)
    {
        strcpy(button1Lnurl, lnurl);
    }
    else if (buttonNumber == 2)
    {
        strcpy(button2Lnurl, lnurl);
    }
    else
    {
        log_e("Trying to set Button Lnurl for invalid button %d", buttonNumber);
        return;
    }

    log_i("Button %d Lnurl set to: %s", buttonNumber, lnurl);
}