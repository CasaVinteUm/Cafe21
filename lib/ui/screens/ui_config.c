// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI800

#include "../ui.h"

void ui_config_screen_init(void)
{
ui_config = lv_obj_create(NULL);
lv_obj_clear_flag( ui_config, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_config, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_config, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPanel = lv_obj_create(ui_config);
lv_obj_set_width( ui_configPanel, 672);
lv_obj_set_height( ui_configPanel, 400);
lv_obj_set_align( ui_configPanel, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_configPanel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_configPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_configPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_configPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonEspresso = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonEspresso, 328);
lv_obj_set_height( ui_configButtonEspresso, 44);
lv_obj_set_x( ui_configButtonEspresso, 0 );
lv_obj_set_y( ui_configButtonEspresso, 11 );
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
lv_obj_set_style_text_font(ui_configButtonEspressoLabel, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonCoffee = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonCoffee, 328);
lv_obj_set_height( ui_configButtonCoffee, 44);
lv_obj_set_x( ui_configButtonCoffee, 0 );
lv_obj_set_y( ui_configButtonCoffee, 82 );
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
lv_obj_set_style_text_font(ui_configButtonCoffeeLabel, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonReset = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonReset, 328);
lv_obj_set_height( ui_configButtonReset, 44);
lv_obj_set_x( ui_configButtonReset, 0 );
lv_obj_set_y( ui_configButtonReset, 153 );
lv_obj_set_align( ui_configButtonReset, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_configButtonReset, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_configButtonReset, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configButtonReset, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configButtonReset, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configButtonReset, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_configButtonReset, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonReset, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_configButtonReset, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonReset, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonResetLabel = lv_label_create(ui_configButtonReset);
lv_obj_set_width( ui_configButtonResetLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configButtonResetLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_configButtonResetLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_configButtonResetLabel,"Resetar Configurações");
lv_obj_set_style_text_color(ui_configButtonResetLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configButtonResetLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configButtonResetLabel, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configButtonBack = lv_btn_create(ui_configPanel);
lv_obj_set_width( ui_configButtonBack, 328);
lv_obj_set_height( ui_configButtonBack, 44);
lv_obj_set_x( ui_configButtonBack, 0 );
lv_obj_set_y( ui_configButtonBack, 295 );
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
lv_obj_set_style_text_font(ui_configButtonBackLabel, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordPanel = lv_obj_create(ui_config);
lv_obj_set_width( ui_configPasswordPanel, 672);
lv_obj_set_height( ui_configPasswordPanel, 400);
lv_obj_set_align( ui_configPasswordPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_configPasswordPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_configPasswordPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_configPasswordPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_configPasswordPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_configPasswordPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_configPasswordPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordTitle = lv_label_create(ui_configPasswordPanel);
lv_obj_set_width( ui_configPasswordTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_configPasswordTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_configPasswordTitle, -182 );
lv_obj_set_y( ui_configPasswordTitle, -152 );
lv_obj_set_align( ui_configPasswordTitle, LV_ALIGN_CENTER );
lv_label_set_text(ui_configPasswordTitle,"Digite a senha:");
lv_obj_set_style_text_color(ui_configPasswordTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configPasswordTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configPasswordTitle, &ui_font_LoraRegular40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_configPasswordText = lv_textarea_create(ui_configPasswordPanel);
lv_obj_set_width( ui_configPasswordText, 305);
lv_obj_set_height( ui_configPasswordText, 39);
lv_obj_set_x( ui_configPasswordText, 0 );
lv_obj_set_y( ui_configPasswordText, -56 );
lv_obj_set_align( ui_configPasswordText, LV_ALIGN_CENTER );
lv_textarea_set_placeholder_text(ui_configPasswordText,"Placeholder...");
lv_obj_set_style_text_color(ui_configPasswordText, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_configPasswordText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_configPasswordText, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);



ui_configPasswordKeyboard = lv_keyboard_create(ui_configPasswordPanel);
lv_keyboard_set_mode(ui_configPasswordKeyboard,LV_KEYBOARD_MODE_NUMBER);
lv_obj_set_width( ui_configPasswordKeyboard, 300);
lv_obj_set_height( ui_configPasswordKeyboard, 120);
lv_obj_set_x( ui_configPasswordKeyboard, 0 );
lv_obj_set_y( ui_configPasswordKeyboard, 98 );
lv_obj_set_align( ui_configPasswordKeyboard, LV_ALIGN_CENTER );

lv_obj_add_event_cb(ui_configButtonEspresso, ui_event_configButtonEspresso, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonCoffee, ui_event_configButtonCoffee, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonReset, ui_event_configButtonReset, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_configButtonBack, ui_event_configButtonBack, LV_EVENT_ALL, NULL);
lv_keyboard_set_textarea(ui_configPasswordKeyboard,ui_configPasswordText);

}
