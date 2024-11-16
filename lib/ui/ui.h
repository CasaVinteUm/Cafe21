// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI800

#ifndef _CAFE21UI800_UI_H
#define _CAFE21UI800_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_home
void ui_home_screen_init(void);
extern lv_obj_t *ui_home;
void ui_event_homeLogo( lv_event_t * e);
extern lv_obj_t *ui_homeLogo;
extern lv_obj_t *ui_homeContainerTitle;
extern lv_obj_t *ui_homeTitle;
extern lv_obj_t *ui_homeSubTitle;
void ui_event_homeButton( lv_event_t * e);
extern lv_obj_t *ui_homeButton;
extern lv_obj_t *ui_homeButtonLabel;
extern lv_obj_t *ui_homeErrorPanel;
extern lv_obj_t *ui_homeErrorIcon;
extern lv_obj_t *ui_homeErrorTitle;
extern lv_obj_t *ui_homeErrorSubTitle;
void ui_event_homeConfig( lv_event_t * e);
extern lv_obj_t *ui_homeConfig;
// CUSTOM VARIABLES

// SCREEN: ui_choose
void ui_choose_screen_init(void);
extern lv_obj_t *ui_choose;
extern lv_obj_t *ui_choosePanel1;
void ui_event_choosePanel1Button( lv_event_t * e);
extern lv_obj_t *ui_choosePanel1Button;
extern lv_obj_t *ui_choosePanel1ButtonLabel;
extern lv_obj_t *ui_choosePanel1Title;
extern lv_obj_t *ui_choosePanel1Image;
extern lv_obj_t *ui_choosePanel1PriceLabel;
extern lv_obj_t *ui_choosePanel1PriceContainerTop;
extern lv_obj_t *ui_choosePanel1PriceSats;
extern lv_obj_t *ui_choosePanel1PriceBrl;
extern lv_obj_t *ui_choosePanel1PriceContainerBottom;
extern lv_obj_t *ui_choosePanel2;
void ui_event_choosePanel2Button( lv_event_t * e);
extern lv_obj_t *ui_choosePanel2Button;
extern lv_obj_t *ui_choosePanel2ButtonLabel;
extern lv_obj_t *ui_choosePanel2Title;
extern lv_obj_t *ui_choosePanel2Image;
extern lv_obj_t *ui_choosePanel2PriceLabel;
extern lv_obj_t *ui_choosePanel2PriceContainerTop;
extern lv_obj_t *ui_choosePanel2PriceSats;
extern lv_obj_t *ui_choosePanel2PriceBrl;
extern lv_obj_t *ui_choosePanel2PriceContainerBottom;
void ui_event_chooseBack( lv_event_t * e);
extern lv_obj_t *ui_chooseBack;
void ui_event_chooseLogo( lv_event_t * e);
extern lv_obj_t *ui_chooseLogo;
// CUSTOM VARIABLES

// SCREEN: ui_payment
void ui_payment_screen_init(void);
extern lv_obj_t *ui_payment;
void ui_event_paymentBack( lv_event_t * e);
extern lv_obj_t *ui_paymentBack;
extern lv_obj_t *ui_paymentPanel;
extern lv_obj_t *ui_paymentTitle;
extern lv_obj_t *ui_paymentSubTitle;
extern lv_obj_t *ui_qrCodeContainer;
void ui_event_paymentLogo( lv_event_t * e);
extern lv_obj_t *ui_paymentLogo;
// CUSTOM VARIABLES

// SCREEN: ui_preparing
void ui_preparing_screen_init(void);
extern lv_obj_t *ui_preparing;
extern lv_obj_t *ui_preparingPanel;
void ui_event_preparingButton( lv_event_t * e);
extern lv_obj_t *ui_preparingButton;
extern lv_obj_t *ui_preparingButtonLabel;
extern lv_obj_t *ui_preparingTitle;
extern lv_obj_t *ui_preparingImage;
extern lv_obj_t *ui_bcPrepIcon;
extern lv_obj_t *ui_preparingProgress;
void ui_event_preparingLogo2( lv_event_t * e);
extern lv_obj_t *ui_preparingLogo2;
// CUSTOM VARIABLES

// SCREEN: ui_success
void ui_success_screen_init(void);
extern lv_obj_t *ui_success;
extern lv_obj_t *ui_successPanel;
extern lv_obj_t *ui_successPanelImage;
extern lv_obj_t *ui_successPanelTitle;
void ui_event_successPanelButton( lv_event_t * e);
extern lv_obj_t *ui_successPanelButton;
extern lv_obj_t *ui_successButtonLabel;
extern lv_obj_t *ui_logoSuccess;
// CUSTOM VARIABLES

// SCREEN: ui_config
void ui_config_screen_init(void);
extern lv_obj_t *ui_config;
extern lv_obj_t *ui_configPanel;
void ui_event_configButtonEspresso( lv_event_t * e);
extern lv_obj_t *ui_configButtonEspresso;
extern lv_obj_t *ui_configButtonEspressoLabel;
void ui_event_configButtonCoffee( lv_event_t * e);
extern lv_obj_t *ui_configButtonCoffee;
extern lv_obj_t *ui_configButtonCoffeeLabel;
void ui_event_configButtonReset( lv_event_t * e);
extern lv_obj_t *ui_configButtonReset;
extern lv_obj_t *ui_configButtonResetLabel;
void ui_event_configButtonBack( lv_event_t * e);
extern lv_obj_t *ui_configButtonBack;
extern lv_obj_t *ui_configButtonBackLabel;
void ui_event_configButtonRestart( lv_event_t * e);
extern lv_obj_t *ui_configButtonRestart;
extern lv_obj_t *ui_configButtonResetLabel1;
extern lv_obj_t *ui_configPasswordPanel;
extern lv_obj_t *ui_configPasswordLabel;
extern lv_obj_t *ui_configPasswordText;
void ui_event_configPasswordKeyboard( lv_event_t * e);
extern lv_obj_t *ui_configPasswordKeyboard;
void ui_event_configBack( lv_event_t * e);
extern lv_obj_t *ui_configBack;
void ui_event_configLogo( lv_event_t * e);
extern lv_obj_t *ui_configLogo;
// CUSTOM VARIABLES

// EVENTS
extern lv_obj_t *ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE( ui_img_logo21_png);   // assets/logo21.png
LV_IMG_DECLARE( ui_img_water_png);   // assets/water.png
LV_IMG_DECLARE( ui_img_config_png);   // assets/config.png
LV_IMG_DECLARE( ui_img_espresso_png);   // assets/espresso.png
LV_IMG_DECLARE( ui_img_coffee_png);   // assets/coffee.png
LV_IMG_DECLARE( ui_img_chevron_png);   // assets/chevron.png
LV_IMG_DECLARE( ui_img_check_png);   // assets/check.png
LV_IMG_DECLARE( ui_img_exit_png);   // assets/exit.png
LV_IMG_DECLARE( ui_img_trash_png);   // assets/trash.png
LV_IMG_DECLARE( ui_img_warning_png);   // assets/warning.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png

// FONTS
LV_FONT_DECLARE( ui_font_LoraRegular24);
LV_FONT_DECLARE( ui_font_LoraRegular40);
LV_FONT_DECLARE( ui_font_LoraRegular64);
LV_FONT_DECLARE( ui_font_OpenSansBold14);
LV_FONT_DECLARE( ui_font_OpenSansBold20);
LV_FONT_DECLARE( ui_font_OpenSansRegular16);
LV_FONT_DECLARE( ui_font_OpenSansRegular20);
LV_FONT_DECLARE( ui_font_OpenSansSemiBold16);

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
