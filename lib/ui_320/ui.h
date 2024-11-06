// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI320

#ifndef _CAFE21UI320_UI_H
#define _CAFE21UI320_UI_H

#ifdef __cplusplus
extern "C" {
#endif

    #include "lvgl.h"

#include "ui_helpers.h"
#include "ui_events.h"

// SCREEN: ui_home
void ui_home_screen_init(void);
extern lv_obj_t *ui_home;
extern lv_obj_t *ui_homeLogo;
extern lv_obj_t *ui_homeConfig;
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
// CUSTOM VARIABLES

// SCREEN: ui_choose
void ui_choose_screen_init(void);
void ui_event_choose( lv_event_t * e);
extern lv_obj_t *ui_choose;
void ui_event_chooseBackButton( lv_event_t * e);
extern lv_obj_t *ui_chooseBackButton;
extern lv_obj_t *ui_chooseLogo;
extern lv_obj_t *ui_choosePanel1;
void ui_event_choosePanel1Button( lv_event_t * e);
extern lv_obj_t *ui_choosePanel1Button;
extern lv_obj_t *ui_choosePanel1ButtonLabel;
extern lv_obj_t *ui_choosePanel1Title;
extern lv_obj_t *ui_choosePanel1Image;
extern lv_obj_t *ui_choosePanel1PriceLabel;
extern lv_obj_t *ui_choosePanel1PriceSats;
extern lv_obj_t *ui_choosePanel1PriceBrl;
extern lv_obj_t *ui_choosePanel2;
void ui_event_choosePanel2Button( lv_event_t * e);
extern lv_obj_t *ui_choosePanel2Button;
extern lv_obj_t *ui_choosePanel2ButtonLabel;
extern lv_obj_t *ui_choosePanel2Title;
extern lv_obj_t *ui_choosePanel2Image;
extern lv_obj_t *ui_choosePanel2PriceLabel;
extern lv_obj_t *ui_choosePanel2PriceSats;
extern lv_obj_t *ui_choosePanel2PriceBrl;
// CUSTOM VARIABLES

// SCREEN: ui_payment
void ui_payment_screen_init(void);
void ui_event_payment( lv_event_t * e);
extern lv_obj_t *ui_payment;
extern lv_obj_t *ui_qrCodeContainer;
extern lv_obj_t *ui_paymentPanel;
extern lv_obj_t *ui_paymentTitle;
extern lv_obj_t *ui_paymentSubtitle;
void ui_event_paymentBackButton( lv_event_t * e);
extern lv_obj_t *ui_paymentBackButton;
extern lv_obj_t *ui_qrCodeLogo;
// CUSTOM VARIABLES

// SCREEN: ui_preparing
void ui_preparing_screen_init(void);
void ui_event_preparing( lv_event_t * e);
extern lv_obj_t *ui_preparing;
extern lv_obj_t *ui_preparingPanel;
void ui_event_preparingCancelButton( lv_event_t * e);
extern lv_obj_t *ui_preparingCancelButton;
extern lv_obj_t *ui_preparingCancelButtonLabel;
extern lv_obj_t *ui_preparingLabel;
extern lv_obj_t *ui_preparingImage;
extern lv_obj_t *ui_preparingProgress;
extern lv_obj_t *ui_preparingLogo;
// CUSTOM VARIABLES

// SCREEN: ui_success
void ui_success_screen_init(void);
void ui_event_success( lv_event_t * e);
extern lv_obj_t *ui_success;
extern lv_obj_t *ui_sucessLogo;
extern lv_obj_t *ui_successPanel;
void ui_event_successPanelButton( lv_event_t * e);
extern lv_obj_t *ui_successPanelButton;
extern lv_obj_t *ui_successPanelButtonLabel;
extern lv_obj_t *ui_successPanelTitle;
extern lv_obj_t *ui_sucessPanelImage;
// CUSTOM VARIABLES

// EVENTS
extern lv_obj_t *ui____initial_actions0;

// IMAGES AND IMAGE SETS
LV_IMG_DECLARE( ui_img_logo21_png);   // assets/logo21.png
LV_IMG_DECLARE( ui_img_config_png);   // assets/config.png
LV_IMG_DECLARE( ui_img_water_png);   // assets/water.png
LV_IMG_DECLARE( ui_img_chevron_png);   // assets/chevron.png
LV_IMG_DECLARE( ui_img_espresso_png);   // assets/espresso.png
LV_IMG_DECLARE( ui_img_coffee_png);   // assets/coffee.png
LV_IMG_DECLARE( ui_img_check_png);   // assets/check.png
LV_IMG_DECLARE( ui_img_exit_png);   // assets/exit.png
LV_IMG_DECLARE( ui_img_trash_png);   // assets/trash.png
LV_IMG_DECLARE( ui_img_warning_png);   // assets/warning.png
LV_IMG_DECLARE( ui_img_wifi_png);   // assets/wifi.png

// FONTS
LV_FONT_DECLARE( ui_font_LoraRegular14);
LV_FONT_DECLARE( ui_font_LoraRegular20);
LV_FONT_DECLARE( ui_font_LoraRegular36);
LV_FONT_DECLARE( ui_font_OpenSansBold14);
LV_FONT_DECLARE( ui_font_OpenSansBold20);
LV_FONT_DECLARE( ui_font_OpenSansSemiBold12);
LV_FONT_DECLARE( ui_font_OpenSansSemiBold14);

// UI INIT
void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif