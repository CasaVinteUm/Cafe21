#include "DummyPaymentGateway.h"

#include <cerrno>
#include <cstdlib>

const PaymentConfigField DummyPaymentGateway::CONFIG_FIELDS[1] = {
    {"delay_ms", "Dummy confirmation delay (ms)", PaymentConfigFieldType::UnsignedInteger, 10}};

bool DummyPaymentGateway::begin()
{
    active = false;
    return true;
}

void DummyPaymentGateway::loop()
{
#ifdef ENABLE_DUMMY_PAYMENT_GATEWAY
    if (active && static_cast<int32_t>(millis() - confirmationTime) >= 0)
    {
        active = false;
        emit(PaymentEventType::Confirmed);
    }
#endif
}

bool DummyPaymentGateway::isAvailable() const
{
#ifdef ENABLE_DUMMY_PAYMENT_GATEWAY
    return true;
#else
    return false;
#endif
}

bool DummyPaymentGateway::requestPayment(const PaymentRequest &request)
{
    if (!isAvailable())
    {
        emit(PaymentEventType::Failed, "", "Payment gateway unavailable");
        return false;
    }

    if (active)
    {
        return false;
    }

    active = true;
    activeProductId = request.productId;
    confirmationTime = millis() + strtoul(delayMs, nullptr, 10);

    String paymentUri = "cafe21-dummy:";
    paymentUri += String(request.productId);
    paymentUri += ":";
    paymentUri += String(request.amountSats);
    emit(PaymentEventType::InvoiceReady, paymentUri);
    return true;
}

void DummyPaymentGateway::cancelPayment()
{
    if (!active)
    {
        return;
    }

    active = false;
    emit(PaymentEventType::Cancelled);
}

void DummyPaymentGateway::setEventCallback(EventCallback callback)
{
    eventCallback = callback;
}

size_t DummyPaymentGateway::getConfigFieldCount() const
{
    return 1;
}

const PaymentConfigField &DummyPaymentGateway::getConfigField(size_t index) const
{
    return CONFIG_FIELDS[index];
}

const char *DummyPaymentGateway::getConfigValue(size_t index) const
{
    return index == 0 ? delayMs : "";
}

bool DummyPaymentGateway::setConfigValue(size_t index, const char *value)
{
    if (index != 0 || value == nullptr)
    {
        return false;
    }

    errno = 0;
    char *end = nullptr;
    unsigned long parsed = strtoul(value, &end, 10);
    if (errno != 0 || end == value || *end != '\0' || parsed < 1000 || parsed > 60000)
    {
        return false;
    }

    snprintf(delayMs, sizeof(delayMs), "%lu", parsed);
    return true;
}

void DummyPaymentGateway::emit(PaymentEventType type, const String &paymentUri, const String &error)
{
    if (!eventCallback)
    {
        return;
    }

    eventCallback({type, activeProductId, paymentUri, error});
}
