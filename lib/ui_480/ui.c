// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI480

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////


// SCREEN: ui_home
void ui_home_screen_init(void);
lv_obj_t *ui_home;
lv_obj_t *ui_homeLogo;
lv_obj_t *ui_homeContainerTitle;
lv_obj_t *ui_homeTitle;
lv_obj_t *ui_homeSubTitle;
void ui_event_homeButton( lv_event_t * e);
lv_obj_t *ui_homeButton;
lv_obj_t *ui_homeButtonLabel;
lv_obj_t *ui_homeErrorPanel;
lv_obj_t *ui_homeErrorIcon;
lv_obj_t *ui_homeErrorTitle;
lv_obj_t *ui_homeErrorSubTitle;
void ui_event_homeConfig( lv_event_t * e);
lv_obj_t *ui_homeConfig;
// CUSTOM VARIABLES


// SCREEN: ui_choose
void ui_choose_screen_init(void);
void ui_event_choose( lv_event_t * e);
lv_obj_t *ui_choose;
void ui_event_chooseBackButton( lv_event_t * e);
lv_obj_t *ui_chooseBackButton;
lv_obj_t *ui_chooseLogo;
lv_obj_t *ui_choosePanel1;
void ui_event_choosePanel1Button( lv_event_t * e);
lv_obj_t *ui_choosePanel1Button;
lv_obj_t *ui_choosePanel1ButtonLabel;
lv_obj_t *ui_choosePanel1Title;
lv_obj_t *ui_choosePanel1Image;
lv_obj_t *ui_choosePanel1PriceLabel;
lv_obj_t *ui_choosePanel1PriceSats;
lv_obj_t *ui_choosePanel1PriceBrl;
lv_obj_t *ui_choosePanel2;
void ui_event_choosePanel2Button( lv_event_t * e);
lv_obj_t *ui_choosePanel2Button;
lv_obj_t *ui_choosePanel2ButtonLabel;
lv_obj_t *ui_choosePanel2Title;
lv_obj_t *ui_choosePanel2Image;
lv_obj_t *ui_choosePanel2PriceLabel;
lv_obj_t *ui_choosePanel2PriceSats;
lv_obj_t *ui_choosePanel2PriceBrl;
// CUSTOM VARIABLES


// SCREEN: ui_payment
void ui_payment_screen_init(void);
void ui_event_payment( lv_event_t * e);
lv_obj_t *ui_payment;
lv_obj_t *ui_qrCodeContainer;
lv_obj_t *ui_paymentPanel;
lv_obj_t *ui_paymentTitle;
lv_obj_t *ui_paymentSubtitle;
void ui_event_paymentBackButton( lv_event_t * e);
lv_obj_t *ui_paymentBackButton;
lv_obj_t *ui_qrCodeLogo;
// CUSTOM VARIABLES


// SCREEN: ui_preparing
void ui_preparing_screen_init(void);
void ui_event_preparing( lv_event_t * e);
lv_obj_t *ui_preparing;
lv_obj_t *ui_preparingPanel;
void ui_event_preparingCancelButton( lv_event_t * e);
lv_obj_t *ui_preparingCancelButton;
lv_obj_t *ui_preparingCancelButtonLabel;
lv_obj_t *ui_preparingLabel;
lv_obj_t *ui_preparingImage;
lv_obj_t *ui_preparingProgress;
lv_obj_t *ui_preparingLogo;
// CUSTOM VARIABLES


// SCREEN: ui_success
void ui_success_screen_init(void);
void ui_event_success( lv_event_t * e);
lv_obj_t *ui_success;
lv_obj_t *ui_sucessLogo;
lv_obj_t *ui_successPanel;
void ui_event_successPanelButton( lv_event_t * e);
lv_obj_t *ui_successPanelButton;
lv_obj_t *ui_successPanelButtonLabel;
lv_obj_t *ui_successPanelTitle;
lv_obj_t *ui_sucessPanelImage;
// CUSTOM VARIABLES


// SCREEN: ui_config
void ui_config_screen_init(void);
lv_obj_t *ui_config;
lv_obj_t *ui_configPanel;
void ui_event_configButtonEspresso( lv_event_t * e);
lv_obj_t *ui_configButtonEspresso;
lv_obj_t *ui_configButtonEspressoLabel;
void ui_event_configButtonCoffee( lv_event_t * e);
lv_obj_t *ui_configButtonCoffee;
lv_obj_t *ui_configButtonCoffeeLabel;
void ui_event_configButtonReset( lv_event_t * e);
lv_obj_t *ui_configButtonReset;
lv_obj_t *ui_configButtonResetLabel;
void ui_event_configButtonBack( lv_event_t * e);
lv_obj_t *ui_configButtonBack;
lv_obj_t *ui_configButtonBackLabel;
void ui_event_configButtonRestart( lv_event_t * e);
lv_obj_t *ui_configButtonRestart;
lv_obj_t *ui_configButtonBackLabel1;
lv_obj_t *ui_configPasswordPanel;
lv_obj_t *ui_configPasswordLabel;
lv_obj_t *ui_configPasswordText;
void ui_event_configPasswordKeyboard( lv_event_t * e);
lv_obj_t *ui_configPasswordKeyboard;
lv_obj_t *ui_configLogo;
void ui_event_configBackButton( lv_event_t * e);
lv_obj_t *ui_configBackButton;
// CUSTOM VARIABLES

// EVENTS
lv_obj_t *ui____initial_actions0;

// IMAGES AND IMAGE SETS
const lv_img_dsc_t *ui_imgset_logo[1] = {&ui_img_logo21_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////
void ui_event_homeButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_choose, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_choose_screen_init);
}
}

void ui_event_homeConfig( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      homeConfigClicked( e );
}
}

void ui_event_choose( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( &ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}
}

void ui_event_chooseBackButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      chooseBackButtonClicked( e );
}
}

void ui_event_choosePanel1Button( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      chooseButton1Clicked( e );
}
}

void ui_event_choosePanel2Button( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      chooseButton2Clicked( e );
}
}

void ui_event_payment( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( &ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}
}

void ui_event_paymentBackButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      paymentBackButtonClicked( e );
}
}

void ui_event_preparing( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( &ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}
}

void ui_event_preparingCancelButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      preparingCancelButtonClicked( e );
}
}

void ui_event_success( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
lv_indev_wait_release(lv_indev_get_act());
      _ui_screen_change( &ui_home, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_home_screen_init);
}
}

void ui_event_successPanelButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      successPanelButtonClicked( e );
}
}

void ui_event_configButtonEspresso( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      configButtonEspressoClicked( e );
}
}

void ui_event_configButtonCoffee( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      configButtonCoffeeClicked( e );
}
}

void ui_event_configButtonReset( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      configButtonResetClicked( e );
}
}

void ui_event_configButtonBack( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      configButtonBackClicked( e );
}
}

void ui_event_configButtonRestart( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      configButtonRestartClicked( e );
}
}

void ui_event_configPasswordKeyboard( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_VALUE_CHANGED) {
      configPasswordKeyboardValueChanged( e );
}
}

void ui_event_configBackButton( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);

if ( event_code == LV_EVENT_CLICKED) {
      _ui_screen_change( &ui_home, LV_SCR_LOAD_ANIM_MOVE_LEFT, 500, 0, &ui_home_screen_init);
}
}

///////////////////// SCREENS ////////////////////

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_home_screen_init();
ui_choose_screen_init();
ui_payment_screen_init();
ui_preparing_screen_init();
ui_success_screen_init();
ui_config_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_disp_load_scr( ui_home);
}
