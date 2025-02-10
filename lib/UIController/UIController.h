#ifndef UICONTROLLER_H
#define UICONTROLLER_H

#include <esp32_smartdisplay.h>

#include "ui.h"
#include "CoffeeMachineController.h"
#include "LightningController.h"

#define QRCODE_INITIAL_SIZE 200

class UIController
{
public:
    UIController(CoffeeMachineController &coffeeController, LightningController &lightningController);
    void begin();
    void onInvoicePaid(uint8_t type);
    void generateQrCode(uint8_t buttonNumber);
    void clearQrCode();
    void setWaitingPaymentFor(uint8_t type);
    uint8_t getDelayLvgl() const { return delayLvgl; };
    void setIsInitialized(bool isInitialized) { UIController::isInitialized = isInitialized; }

    static void task(void *pvParameters);

private:
    CoffeeMachineController &coffeeController;
    LightningController &lightningController;
    lv_coord_t qrCodeSize = QRCODE_INITIAL_SIZE;
    uint32_t startTime;
    uint8_t timerButtonNumber;
    uint8_t waitingPaymentFor = 0;
    uint8_t delayLvgl = 0;
    bool isInitialized = false;

    static void qrCodeTimerCallback(lv_timer_t *timer);

    void run();
    void showQrCode(uint8_t buttonNumber, lv_coord_t size);
};

#endif // UICONTROLLER_H