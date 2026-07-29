#include "UIController.h"

UIController::UIController(CoffeeMachineController &coffeeCtrl, IPaymentGateway &gateway)
    : coffeeController(coffeeCtrl), paymentGateway(gateway) {}

void UIController::begin()
{
    paymentGateway.setEventCallback([this](const PaymentEvent &event)
                                    { onPaymentEvent(event); });
    if (!paymentGateway.begin())
    {
        log_e("Failed to initialize payment gateway");
    }

    // Initialize SmartDisplay
    smartdisplay_init();

    // Get Default Display
    __attribute__((unused)) auto disp = lv_disp_get_default();

// Set Rotation as needed
#if DISPLAY_HEIGHT > DISPLAY_WIDTH
    lv_disp_set_rotation(disp, LV_DISP_ROT_90);
#endif

    // Initialiez UI
    ui_init();

    lv_timer_handler();
    vTaskDelay(500 / portTICK_PERIOD_MS);

#ifdef CONFIG_FREERTOS_UNICORE
    BaseType_t app = 0;
#else
    BaseType_t app = 1;
#endif

    xTaskCreatePinnedToCore(task, "UIController", 10000, this, 1, NULL, app);
}

void UIController::task(void *pvParameters)
{
    static_cast<UIController *>(pvParameters)->run();
}

void UIController::run()
{
    log_i("UI Controller started");

    static bool isBrewingBarAnimated = false;
    static lv_timer_t *progressTimer = NULL;
    static uint32_t progressStartTime = 0;
    static const uint32_t PROGRESS_DURATION = 5000;

    while (true)
    {
        paymentGateway.loop();
        CoffeeMachineError currentError = coffeeController.getCurrentError();
        switch (coffeeController.getCurrentState())
        {
            case CoffeeMachineState::Off:
                coffeeController.sendOnCommand();
                lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(ui_homeErrorIcon, &ui_img_warning_png);
                lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
                lv_label_set_text(ui_homeErrorSubTitle, "Aguarde...\n");
                break;
            case CoffeeMachineState::WaitingForOn:
            case CoffeeMachineState::TurningOn:
                lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
                lv_label_set_text(ui_homeErrorTitle, "Ligando Cafeteira...");
                lv_label_set_text(ui_homeErrorSubTitle, "Aguarde uns instantes.\n");
                break;
            case CoffeeMachineState::Loading:
                lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
                lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
                lv_label_set_text(ui_homeErrorTitle, "Maquina aquecendo...");
                lv_label_set_text(ui_homeErrorSubTitle, "Aguarde uns instantes.\n");
                break;
            case CoffeeMachineState::Ready:
                if (isBrewingBarAnimated)
                {
                    isBrewingBarAnimated = false;
                }
                lv_obj_clear_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                break;
            case CoffeeMachineState::Error:
                lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
                switch (currentError)
                {
                case CoffeeMachineError::NOWATER:
                    lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_homeErrorIcon, &ui_img_water_png);
                    lv_label_set_text(ui_homeErrorTitle, "Ops! O reservatório está vazio");
                    lv_label_set_text(ui_homeErrorSubTitle, "Por favor, adicione água para que possamos preparar o seu café");
                    break;
                case CoffeeMachineError::TRASH:
                    lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
                    lv_label_set_text(ui_homeErrorTitle, "Hora de uma limpeza!");
                    lv_label_set_text(ui_homeErrorSubTitle, "A borra de café precisa ser esvaziada para preparar seu pedido.");
                    break;
                case CoffeeMachineError::GENERAL:
                    lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                    lv_img_set_src(ui_homeErrorIcon, &ui_img_trash_png);
                    lv_label_set_text(ui_homeErrorTitle, "Ops! Estamos com problemas!");
                    lv_label_set_text(ui_homeErrorSubTitle, "Verifique se a bandeja está cheia ou se o café está no final.");
                    break;
                }
                break;
            case CoffeeMachineState::Brewing:
                if (!isBrewingBarAnimated)
                {
                    isBrewingBarAnimated = true;
                    progressStartTime = lv_tick_get();
                    if (!progressTimer)
                    {
                        progressTimer = lv_timer_create([](_lv_timer_t *)
                                                        {
              if (!isBrewingBarAnimated) {
                _ui_screen_change(&ui_success, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_success_screen_init);
                lv_bar_set_value(ui_preparingProgress, 0, LV_ANIM_OFF);
                lv_timer_del(progressTimer);
                progressTimer = NULL;
                return;
            }

            uint32_t elapsed = lv_tick_get() - progressStartTime;
            if (elapsed >= PROGRESS_DURATION) {
                // Reset
                lv_bar_set_value(ui_preparingProgress, 0, LV_ANIM_OFF);
                progressStartTime = lv_tick_get();
            } else {
                // Update progress
                int32_t progress = (elapsed * 100) / PROGRESS_DURATION;
                lv_bar_set_value(ui_preparingProgress, progress, LV_ANIM_OFF);
            } },
                                                        50, NULL);
                    }
                }
                break;
            default:
                lv_obj_clear_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
                lv_obj_clear_flag(ui_homeErrorSubTitle, LV_OBJ_FLAG_HIDDEN);
                lv_obj_add_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
                break;
        }

        delayLvgl = lv_timer_handler();
        vTaskDelay(delayLvgl + 1 / portTICK_PERIOD_MS);
    }
}

void UIController::requestCoffee(uint8_t productId, CoffeeType type, uint32_t amountSats, const char *description)
{
    if (productId != 1 && productId != 2)
    {
        log_e("Product %d is unknown", productId);
        return;
    }

    coffeeController.selectCoffee(type);
    waitingPaymentFor = productId;

    if (amountSats == 0)
    {
        completeOrder(productId);
        return;
    }

    _ui_screen_change(&ui_payment, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_payment_screen_init);
    lv_label_set_text(ui_paymentTitle, "Criando pagamento...");
    lv_label_set_text(ui_paymentSubtitle, "Aguarde...\n");

    if (!paymentGateway.isAvailable())
    {
        showPaymentError("Pagamento indisponível");
        return;
    }

    if (!paymentGateway.requestPayment({productId, amountSats, description}))
    {
        showPaymentError("Não foi possível criar o pagamento");
    }
}

void UIController::startFreeOrder(uint8_t productId, CoffeeType type)
{
    coffeeController.selectCoffee(type);
    waitingPaymentFor = productId;
    completeOrder(productId);
}

void UIController::onPaymentEvent(const PaymentEvent &event)
{
    if (event.productId != waitingPaymentFor)
    {
        return;
    }

    switch (event.type)
    {
    case PaymentEventType::InvoiceReady:
        qrData = event.paymentUri;
        lv_label_set_text(ui_paymentTitle, "Pague seu Café");
        lv_label_set_text(ui_paymentSubtitle, "Escaneie o QR Code");
        generateQrCode();
        break;
    case PaymentEventType::Confirmed:
        completeOrder(event.productId);
        break;
    case PaymentEventType::Cancelled:
        waitingPaymentFor = 0;
        clearQrCode();
        break;
    case PaymentEventType::Expired:
        showPaymentError("Pagamento expirado");
        break;
    case PaymentEventType::Failed:
        showPaymentError(event.error.length() ? event.error.c_str() : "Falha no pagamento");
        break;
    }
}

void UIController::completeOrder(uint8_t productId)
{
    if (waitingPaymentFor != productId)
    {
        return;
    }

    waitingPaymentFor = 0;
    if (productId == 1)
    {
        lv_img_set_src(ui_preparingImage, &ui_img_espresso_png);
    }
    else
    {
        lv_img_set_src(ui_preparingImage, &ui_img_coffee_png);
    }

    _ui_screen_change(&ui_preparing, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_preparing_screen_init);
    clearQrCode();
    coffeeController.startOrder();
}

void UIController::cancelPayment()
{
    paymentGateway.cancelPayment();
    waitingPaymentFor = 0;
    qrData = "";
    clearQrCode();
    coffeeController.selectCoffee(CoffeeType::NONE);
}

void UIController::showPaymentError(const char *message)
{
    lv_label_set_text(ui_paymentTitle, message);
    lv_label_set_text(ui_paymentSubtitle, "Volte e tente novamente.");
}

void UIController::showQrCode(lv_coord_t size)
{
    auto ui_qrcode = lv_qrcode_create(ui_qrCodeContainer, size ? size : QRCODE_INITIAL_SIZE, lv_color_black(), lv_color_white());
    lv_qrcode_update(ui_qrcode, qrData.c_str(), qrData.length());
    lv_obj_center(ui_qrcode);
}

void UIController::qrCodeTimerCallback(lv_timer_t *timer)
{
    // Retrieve the class instance from user data
    UIController *instance = static_cast<UIController *>(timer->user_data);

    // Access member variables and methods
    instance->qrCodeSize = lv_obj_get_content_width(ui_qrCodeContainer) - 5;

    if (instance->qrCodeSize > QRCODE_INITIAL_SIZE)
    {
        instance->showQrCode(instance->qrCodeSize);
        lv_timer_del(timer);
    }
    else
    {
        if (millis() - instance->startTime >= 2000) // 2-second timeout
        {
            lv_timer_del(timer);
            instance->qrCodeSize = QRCODE_INITIAL_SIZE;
        }
    }
}

void UIController::generateQrCode()
{
    if (qrCodeSize <= QRCODE_INITIAL_SIZE)
    {
        // Allocate and initialize timer data
        startTime = millis();
        __attribute__((unused)) lv_timer_t *timer = lv_timer_create(qrCodeTimerCallback, 100, this); // 100ms interval
    }
    else
    {
        showQrCode(qrCodeSize);
    }
}

void UIController::clearQrCode()
{
    lv_timer_create([](lv_timer_t *timer)
                    {
                        lv_obj_clean(ui_qrCodeContainer);
                        lv_timer_del(timer); // Delete the timer after use
                    },
                    500, nullptr); // 500ms delay
}
