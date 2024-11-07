#include "UIController.h"

UIController::UIController(CoffeeMachineController &coffeeCtrl, LightningController &lightCtrl)
    : coffeeController(coffeeCtrl), lightningController(lightCtrl) {}

void UIController::begin()
{
    lightningController.setOnInvoicePaid(std::bind(&UIController::onInvoicePaid, this, std::placeholders::_1));

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
        if (lightningController.getIsConnected())
        {
            // Handle UI state
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
        }
        else
        {
            lv_obj_clear_flag(ui_homeErrorPanel, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_homeButton, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(ui_homeSubTitle, LV_OBJ_FLAG_HIDDEN);
            lv_img_set_src(ui_homeErrorIcon, &ui_img_wifi_png);
            lv_label_set_text(ui_homeErrorTitle, "Conectando ao WiFi e LNBits...");
            lv_label_set_text(ui_homeErrorSubTitle, "Aguarde...\n");
        }

        delayLvgl = lv_timer_handler();
        vTaskDelay(delayLvgl + 1 / portTICK_PERIOD_MS);
    }
}

void UIController::setWaitingPaymentFor(uint8_t type)
{
    if (type != 1 && type != 2)
    {
        log_e("Type %d is unknown", type);
        return;
    }

    waitingPaymentFor = type;
}

void UIController::onInvoicePaid(uint8_t type)
{
    if (waitingPaymentFor == type)
    {
        waitingPaymentFor = 0;
        if (type == 1)
        {
            lv_img_set_src(ui_preparingImage, &ui_img_espresso_png);
            lv_label_set_text(ui_homeErrorTitle, "Minerando seu\nEspresso To The Moon");
        }
        else
        {
            lv_img_set_src(ui_preparingImage, &ui_img_coffee_png);
            lv_label_set_text(ui_homeErrorTitle, "Minerando seu\nBlock Coffee");
        }
        _ui_screen_change(&ui_preparing, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_preparing_screen_init);
        clearQrCode();
        coffeeController.startOrder();
    }
    else
    {
        log_i("Invoice paid for: %d", type);
        return;
    }
}

void UIController::showQrCode(uint8_t buttonNumber, lv_coord_t size)
{
    // Create and update QR code
    log_d("Generating QRCode for button %d. %s", buttonNumber, buttonNumber == 1 ? lightningController.getButton1Lnurl() : lightningController.getButton2Lnurl());
    auto ui_qrcode = lv_qrcode_create(ui_qrCodeContainer, size ? size : QRCODE_INITIAL_SIZE, lv_color_black(), lv_color_white());
    String qrData = buttonNumber == 1 ? lightningController.getButton1Lnurl() : lightningController.getButton2Lnurl();
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
        instance->showQrCode(instance->timerButtonNumber, instance->qrCodeSize);
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

void UIController::generateQrCode(uint8_t buttonNumber)
{
    if (qrCodeSize <= QRCODE_INITIAL_SIZE)
    {
        // Allocate and initialize timer data
        startTime = millis();
        timerButtonNumber = buttonNumber;

        // Create a one-shot timer that will generate the QR code after the screen is loaded
        // Create timer that will generate the QR code after the screen is loaded
        __attribute__((unused)) lv_timer_t *timer = lv_timer_create(qrCodeTimerCallback, 100, this); // 100ms interval
    }
    else
    {
        showQrCode(buttonNumber, qrCodeSize);
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