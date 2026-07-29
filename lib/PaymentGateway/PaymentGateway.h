#ifndef PAYMENTGATEWAY_H
#define PAYMENTGATEWAY_H

#include <Arduino.h>
#include <functional>

enum class PaymentEventType
{
    InvoiceReady,
    Confirmed,
    Cancelled,
    Expired,
    Failed
};

enum class PaymentConfigFieldType
{
    Text,
    Secret,
    UnsignedInteger
};

struct PaymentRequest
{
    uint8_t productId;
    uint32_t amountSats;
    String description;
};

struct PaymentEvent
{
    PaymentEventType type;
    uint8_t productId;
    String paymentUri;
    String error;
};

struct PaymentConfigField
{
    const char *key;
    const char *label;
    PaymentConfigFieldType type;
    size_t maxLength;
};

class IPaymentGateway
{
public:
    using EventCallback = std::function<void(const PaymentEvent &)>;

    virtual ~IPaymentGateway() = default;

    virtual const char *getId() const = 0;
    virtual bool begin() = 0;
    virtual void loop() = 0;
    virtual bool isAvailable() const = 0;
    virtual bool requestPayment(const PaymentRequest &request) = 0;
    virtual void cancelPayment() = 0;
    virtual void setEventCallback(EventCallback callback) = 0;

    virtual size_t getConfigFieldCount() const = 0;
    virtual const PaymentConfigField &getConfigField(size_t index) const = 0;
    virtual const char *getConfigValue(size_t index) const = 0;
    virtual bool setConfigValue(size_t index, const char *value) = 0;
};

#endif // PAYMENTGATEWAY_H
