#ifndef DUMMYPAYMENTGATEWAY_H
#define DUMMYPAYMENTGATEWAY_H

#include <PaymentGateway.h>

class DummyPaymentGateway : public IPaymentGateway
{
public:
    bool begin() override;
    void loop() override;
    bool isAvailable() const override;
    bool requestPayment(const PaymentRequest &request) override;
    void cancelPayment() override;
    void setEventCallback(EventCallback callback) override;

    const char *getId() const override { return "dummy"; }
    size_t getConfigFieldCount() const override;
    const PaymentConfigField &getConfigField(size_t index) const override;
    const char *getConfigValue(size_t index) const override;
    bool setConfigValue(size_t index, const char *value) override;

private:
    static const PaymentConfigField CONFIG_FIELDS[1];

    EventCallback eventCallback;
    char delayMs[11] = "5000";
    uint8_t activeProductId = 0;
    uint32_t confirmationTime = 0;
    bool active = false;

    void emit(PaymentEventType type, const String &paymentUri = "", const String &error = "");
};

#endif // DUMMYPAYMENTGATEWAY_H
