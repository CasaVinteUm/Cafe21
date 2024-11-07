// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI480

#include "../ui.h"

void ui_config_screen_init(void)
{
ui_config = lv_obj_create(NULL);
lv_obj_clear_flag( ui_config, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_config, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_config, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPanel = lv_obj_create(ui_config);
lv_obj_set_width( ui_configPanel, 448);
lv_obj_set_height( ui_configPanel, 201);
lv_obj_set_x( ui_configPanel, 0 );
lv_obj_set_y( ui_configPanel, 20 );
lv_obj_set_align( ui_configPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_configPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_configPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_configPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonEspresso = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonEspresso, 180);
lv_obj_set_height( ui_configButtonEspresso, 32);
lv_obj_set_x( ui_configButtonEspresso, -107 );
lv_obj_set_y( ui_configButtonEspresso, -4 );
lv_obj_set_align( ui_configButtonEspresso, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonEspresso, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonEspresso, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonEspresso, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonEspresso, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonEspresso, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonEspresso, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonEspresso, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonEspresso, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonEspresso, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonEspressoLabel = lv_label_create(ui_configButtonEspresso);
lv_obj_set_width( ui_configButtonEspressoLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonEspressoLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_configButtonEspressoLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonEspressoLabel,"Fazer um Espresso");
lv_obj_set_style_text_color(ui_configButtonEspressoLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonEspressoLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonEspressoLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonCoffee = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonCoffee, 180);
lv_obj_set_height( ui_configButtonCoffee, 32);
lv_obj_set_x( ui_configButtonCoffee, 105 );
lv_obj_set_y( ui_configButtonCoffee, -4 );
lv_obj_set_align( ui_configButtonCoffee, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonCoffee, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonCoffee, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonCoffee, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonCoffee, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonCoffee, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonCoffee, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonCoffee, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonCoffee, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonCoffee, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonCoffeeLabel = lv_label_create(ui_configButtonCoffee);
lv_obj_set_width( ui_configButtonCoffeeLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonCoffeeLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_configButtonCoffeeLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonCoffeeLabel,"Fazer um Cafe");
lv_obj_set_style_text_color(ui_configButtonCoffeeLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonCoffeeLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonCoffeeLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonReset = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonReset, 162);
lv_obj_set_height( ui_configButtonReset, 32);
lv_obj_set_x( ui_configButtonReset, 0 );
lv_obj_set_y( ui_configButtonReset, 43 );
lv_obj_set_align( ui_configButtonReset, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonReset, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonReset, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonReset, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonReset, lv_color_hex(0xCF3737), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonReset, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonReset, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonReset, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonReset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonReset, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonResetLabel = lv_label_create(ui_configButtonReset);
lv_obj_set_width( ui_configButtonResetLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonResetLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_configButtonResetLabel, 0 );
lv_obj_set_y( ui_configButtonResetLabel, 1 );
lv_obj_set_align( ui_configButtonResetLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonResetLabel,"Resetar Configurações");
lv_obj_set_style_text_color(ui_configButtonResetLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonResetLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonResetLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonBack = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonBack, 194);
lv_obj_set_height( ui_configButtonBack, 32);
lv_obj_set_x( ui_configButtonBack, 0 );
lv_obj_set_y( ui_configButtonBack, 140 );
lv_obj_set_align( ui_configButtonBack, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonBack, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonBack, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonBack, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonBack, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonBack, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonBack, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonBack, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonBack, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonBack, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonBackLabel = lv_label_create(ui_configButtonBack);
lv_obj_set_width( ui_configButtonBackLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonBackLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_configButtonBackLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonBackLabel,"Voltar");
lv_obj_set_style_text_color(ui_configButtonBackLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonBackLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonBackLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonRestart = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonRestart, 194);
lv_obj_set_height( ui_configButtonRestart, 32);
lv_obj_set_x( ui_configButtonRestart, 0 );
lv_obj_set_y( ui_configButtonRestart, 88 );
lv_obj_set_align( ui_configButtonRestart, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonRestart, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonRestart, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonRestart, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonRestart, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonRestart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonRestart, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonRestart, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonRestart, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonRestart, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonBackLabel1 = lv_label_create(ui_configButtonRestart);
lv_obj_set_width( ui_configButtonBackLabel1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonBackLabel1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_configButtonBackLabel1, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonBackLabel1,"Reiniciar App");
lv_obj_set_style_text_color(ui_configButtonBackLabel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonBackLabel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonBackLabel1, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordPanel = lv_obj_create(ui_config);
lv_obj_set_width( ui_configPasswordPanel, 439);
lv_obj_set_height( ui_configPasswordPanel, 242);
lv_obj_set_align( ui_configPasswordPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_configPasswordPanel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_configPasswordPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configPasswordPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configPasswordPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configPasswordPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_configPasswordPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_configPasswordPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordLabel = lv_label_create(ui_configPasswordPanel);
lv_obj_set_width( ui_configPasswordLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configPasswordLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_configPasswordLabel, 0 );
lv_obj_set_y( ui_configPasswordLabel, -99 );
lv_obj_set_align( ui_configPasswordLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configPasswordLabel,"Senha incorreta!");
lv_obj_add_flag( ui_configPasswordLabel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_set_style_text_color(ui_configPasswordLabel, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configPasswordLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configPasswordLabel, &ui_font_LoraRegular20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordText = lv_textarea_create(ui_configPasswordPanel);
lv_obj_set_width( ui_configPasswordText, 305);
lv_obj_set_height( ui_configPasswordText, LV_SIZE_CONTENT);   /// 39
lv_obj_set_x( ui_configPasswordText, 0 );
lv_obj_set_y( ui_configPasswordText, -56 );
lv_obj_set_align( ui_configPasswordText, LV_ALIGN_CENTER );
lv_textarea_set_max_length(ui_configPasswordText,16);
lv_textarea_set_placeholder_text(ui_configPasswordText,"Digite sua senha");
lv_textarea_set_one_line(ui_configPasswordText,true);
lv_textarea_set_password_mode(ui_configPasswordText, true);
lv_obj_set_style_text_color(ui_configPasswordText, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configPasswordText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configPasswordText, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_configPasswordKeyboard = lv_keyboard_create(ui_configPasswordPanel);
lv_keyboard_set_mode(ui_configPasswordKeyboard,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_configPasswordKeyboard, 300);
lv_obj_set_height( ui_configPasswordKeyboard, 120);
lv_obj_set_x( ui_configPasswordKeyboard, 0 );
lv_obj_set_y( ui_configPasswordKeyboard, 50 );
lv_obj_set_align( ui_configPasswordKeyboard, LV_ALIGN_CENTER );

ui_configLogo = lv_img_create(ui_config);
lv_img_set_src(ui_configLogo, &ui_img_logo21_png);
lv_obj_set_width( ui_configLogo, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_configLogo, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_configLogo, 436 );
lv_obj_set_y( ui_configLogo, 12 );
lv_obj_add_flag( ui_configLogo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_configLogo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_configBackButton = lv_imgbtn_create(ui_config);
lv_imgbtn_set_src(ui_configBackButton, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_chevron_png, NULL);
lv_imgbtn_set_src(ui_configBackButton, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_chevron_png, NULL);
lv_obj_set_width( ui_configBackButton, 32);
lv_obj_set_height( ui_configBackButton, 32);
lv_obj_set_x( ui_configBackButton, -212 );
lv_obj_set_y( ui_configBackButton, -112 );
lv_obj_set_align( ui_configBackButton, LV_ALIGN_CENTER );

lv_obj_add_event_cb(ui_configButtonEspresso, ui_event_configButtonEspresso, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonCoffee, ui_event_configButtonCoffee, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonReset, ui_event_configButtonReset, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonBack, ui_event_configButtonBack, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonRestart, ui_event_configButtonRestart, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_configPasswordKeyboard,ui_configPasswordText);
lv_obj_add_event_cb(ui_configPasswordKeyboard, ui_event_configPasswordKeyboard, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configBackButton, ui_event_configBackButton, LV_EVENT_ALL, NULL);

}
