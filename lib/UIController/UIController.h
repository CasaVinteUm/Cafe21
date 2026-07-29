#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <esp32_smartdisplay.h>

#include "ui.h"
#include "CoffeeMachineController.h"
#include <PaymentGateway.h>

#define QRCODE_INITIAL_SIZE 200

class UIController
{
public:
    UIController(CoffeeMachineController &coffeeController, IPaymentGateway &paymentGateway);

    void begin();
    void requestCoffee(uint8_t productId, CoffeeType type, uint32_t amountSats, const char *description);
    void startFreeOrder(uint8_t productId, CoffeeType type);
    void cancelPayment();
    void clearQrCode();
    uint8_t getDelayLvgl() const { return delayLvgl; }

    static void task(void *pvParameters);

private:
    CoffeeMachineController &coffeeController;
    IPaymentGateway &paymentGateway;
    lv_coord_t qrCodeSize = QRCODE_INITIAL_SIZE;
    uint32_t startTime = 0;
    uint8_t waitingPaymentFor = 0;
    uint8_t delayLvgl = 0;
    String qrData;

    static void qrCodeTimerCallback(lv_timer_t *timer);

    void run();
    void onPaymentEvent(const PaymentEvent &event);
    void completeOrder(uint8_t productId);
    void generateQrCode();
    void showQrCode(lv_coord_t size);
    void showPaymentError(const char *message);
};

#endif // UICONTROLLER_H
