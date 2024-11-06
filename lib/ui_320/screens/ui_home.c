// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI320

#include "../ui.h"

void ui_home_screen_init(void)
{
ui_home = lv_obj_create(NULL);
lv_obj_add_flag( ui_home, LV_OBJ_FLAG_CHECKABLE | LV_OBJ_FLAG_SCROLL_WITH_ARROW );   /// Flags
lv_obj_clear_flag( ui_home, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_home, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_home, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeLogo = lv_img_create(ui_home);
lv_img_set_src(ui_homeLogo, &ui_img_logo21_png);
lv_obj_set_width( ui_homeLogo, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_homeLogo, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_homeLogo, 436 );
lv_obj_set_y( ui_homeLogo, 12 );
lv_obj_add_flag( ui_homeLogo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_homeLogo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_homeConfig = lv_img_create(ui_home);
lv_img_set_src(ui_homeConfig, &ui_img_config_png);
lv_obj_set_width( ui_homeConfig, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_homeConfig, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_homeConfig, -436 );
lv_obj_set_y( ui_homeConfig, 12 );
lv_obj_set_align( ui_homeConfig, LV_ALIGN_TOP_RIGHT );
lv_obj_add_flag( ui_homeConfig, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_homeConfig, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_homeContainerTitle = lv_obj_create(ui_home);
lv_obj_remove_style_all(ui_homeContainerTitle);
lv_obj_set_width( ui_homeContainerTitle, 480);
lv_obj_set_height( ui_homeContainerTitle, 129);
lv_obj_set_x( ui_homeContainerTitle, 1 );
lv_obj_set_y( ui_homeContainerTitle, 56 );
lv_obj_set_align( ui_homeContainerTitle, LV_ALIGN_TOP_MID );
lv_obj_clear_flag( ui_homeContainerTitle, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_homeTitle = lv_label_create(ui_homeContainerTitle);
lv_obj_set_width( ui_homeTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_homeTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_homeTitle, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_homeTitle,"Bem-Vindo!");
lv_obj_set_style_text_color(ui_homeTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeTitle, &ui_font_LoraRegular36, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeSubTitle = lv_label_create(ui_homeContainerTitle);
lv_obj_set_width( ui_homeSubTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_homeSubTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_homeSubTitle, LV_ALIGN_CENTER );
lv_label_set_text(ui_homeSubTitle,"Escolha seu café e pague de forma simples com Bitcoin");
lv_obj_set_style_text_color(ui_homeSubTitle, lv_color_hex(0x999999), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeSubTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_homeSubTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeSubTitle, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeButton = lv_btn_create(ui_homeContainerTitle);
lv_obj_set_width( ui_homeButton, 135);
lv_obj_set_height( ui_homeButton, 35);
lv_obj_set_align( ui_homeButton, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_homeButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_homeButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_homeButton, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_homeButton, lv_color_hex(0xF7AB14), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_homeButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_color(ui_homeButton, lv_color_hex(0x008F85), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_main_stop(ui_homeButton, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_stop(ui_homeButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_homeButton, LV_GRAD_DIR_VER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_homeButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_homeButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeButton, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeButtonLabel = lv_label_create(ui_homeButton);
lv_obj_set_width( ui_homeButtonLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_homeButtonLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_homeButtonLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_homeButtonLabel,"Pedir um Café");
lv_obj_set_style_text_color(ui_homeButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeButtonLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeButtonLabel, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeErrorPanel = lv_obj_create(ui_home);
lv_obj_set_width( ui_homeErrorPanel, 456);
lv_obj_set_height( ui_homeErrorPanel, 64);
lv_obj_set_x( ui_homeErrorPanel, 0 );
lv_obj_set_y( ui_homeErrorPanel, -32 );
lv_obj_set_align( ui_homeErrorPanel, LV_ALIGN_BOTTOM_MID );
lv_obj_clear_flag( ui_homeErrorPanel, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_scrollbar_mode(ui_homeErrorPanel, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_style_radius(ui_homeErrorPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_homeErrorPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_homeErrorPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_homeErrorPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_homeErrorPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_homeErrorPanel, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_homeErrorPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_homeErrorPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_homeErrorPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_homeErrorPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeErrorIcon = lv_img_create(ui_homeErrorPanel);
lv_img_set_src(ui_homeErrorIcon, &ui_img_water_png);
lv_obj_set_width( ui_homeErrorIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_homeErrorIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_homeErrorIcon, -4 );
lv_obj_set_y( ui_homeErrorIcon, 0 );
lv_obj_set_align( ui_homeErrorIcon, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_homeErrorIcon, LV_OBJ_FLAG_CLICKABLE );   /// Flags
lv_obj_clear_flag( ui_homeErrorIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_homeErrorTitle = lv_label_create(ui_homeErrorPanel);
lv_obj_set_height( ui_homeErrorTitle, 20);
lv_obj_set_width( ui_homeErrorTitle, LV_SIZE_CONTENT);  /// 125
lv_obj_set_x( ui_homeErrorTitle, 35 );
lv_obj_set_y( ui_homeErrorTitle, -6 );
lv_label_set_text(ui_homeErrorTitle,"Ops! Estamos inicializando!");
lv_obj_set_style_text_color(ui_homeErrorTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeErrorTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeErrorTitle, &ui_font_OpenSansSemiBold12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_homeErrorSubTitle = lv_label_create(ui_homeErrorPanel);
lv_obj_set_height( ui_homeErrorSubTitle, 16);
lv_obj_set_width( ui_homeErrorSubTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_x( ui_homeErrorSubTitle, 35 );
lv_obj_set_y( ui_homeErrorSubTitle, 4 );
lv_obj_set_align( ui_homeErrorSubTitle, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_homeErrorSubTitle,"Aguarde!");
lv_obj_set_style_text_color(ui_homeErrorSubTitle, lv_color_hex(0x999999), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_homeErrorSubTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_homeErrorSubTitle, &ui_font_OpenSansSemiBold12, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_homeButton, ui_event_homeButton, LV_EVENT_ALL, NULL);

}
