// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21_ui_800

#include "../ui.h"

void ui_preparing_screen_init(void)
{
ui_preparing = lv_obj_create(NULL);
lv_obj_set_style_bg_color(ui_preparing, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_preparing, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_preparingPanel = lv_obj_create(ui_preparing);
lv_obj_set_width( ui_preparingPanel, 360);
lv_obj_set_height( ui_preparingPanel, 372);
lv_obj_set_align( ui_preparingPanel, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_preparingPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_preparingPanel, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_preparingPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_preparingPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_preparingPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_preparingPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_preparingPanel, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_preparingPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_preparingPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_preparingPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_preparingPanel, 16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_preparingButton = lv_btn_create(ui_preparingPanel);
lv_obj_set_width( ui_preparingButton, 328);
lv_obj_set_height( ui_preparingButton, 44);
lv_obj_set_x( ui_preparingButton, 0 );
lv_obj_set_y( ui_preparingButton, 277 );
lv_obj_set_align( ui_preparingButton, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_preparingButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_preparingButton, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_preparingButton, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_preparingButton, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_preparingButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_preparingButton, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_preparingButton, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_preparingButton, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_preparingButton, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_preparingButtonLabel = lv_label_create(ui_preparingButton);
lv_obj_set_width( ui_preparingButtonLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_preparingButtonLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_preparingButtonLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_preparingButtonLabel,"Cancelar");
lv_obj_set_style_text_color(ui_preparingButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_preparingButtonLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_preparingButtonLabel, &ui_font_OpenSansBold20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_preparingTitle = lv_label_create(ui_preparingPanel);
lv_obj_set_width( ui_preparingTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_preparingTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_preparingTitle, 0 );
lv_obj_set_y( ui_preparingTitle, 169 );
lv_obj_set_align( ui_preparingTitle, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_preparingTitle,"Saindo um\nExpresso to the Moon");
lv_obj_set_style_text_color(ui_preparingTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_preparingTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_preparingTitle, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_preparingTitle, &ui_font_LoraRegula24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_preparingImage = lv_img_create(ui_preparingPanel);
lv_img_set_src(ui_preparingImage, &ui_img_expressolarge_png);
lv_obj_set_width( ui_preparingImage, LV_SIZE_CONTENT);  /// 132
lv_obj_set_height( ui_preparingImage, LV_SIZE_CONTENT);   /// 132
lv_obj_set_x( ui_preparingImage, 0 );
lv_obj_set_y( ui_preparingImage, 32 );
lv_obj_set_align( ui_preparingImage, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_preparingImage, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_preparingImage, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_bcPrepIcon = lv_img_create(ui_preparingPanel);
lv_img_set_src(ui_bcPrepIcon, &ui_img_coffelarge_png);
lv_obj_set_width( ui_bcPrepIcon, LV_SIZE_CONTENT);  /// 132
lv_obj_set_height( ui_bcPrepIcon, LV_SIZE_CONTENT);   /// 132
lv_obj_set_x( ui_bcPrepIcon, 0 );
lv_obj_set_y( ui_bcPrepIcon, 6 );
lv_obj_set_align( ui_bcPrepIcon, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_bcPrepIcon, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_bcPrepIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_preparingProgress = lv_bar_create(ui_preparingPanel);
lv_bar_set_value(ui_preparingProgress,25,LV_ANIM_OFF);
lv_bar_set_start_value(ui_preparingProgress, 25, LV_ANIM_OFF);
lv_obj_set_width( ui_preparingProgress, 296);
lv_obj_set_height( ui_preparingProgress, 6);
lv_obj_set_x( ui_preparingProgress, 0 );
lv_obj_set_y( ui_preparingProgress, 247 );
lv_obj_set_align( ui_preparingProgress, LV_ALIGN_TOP_MID );
lv_obj_set_style_bg_color(ui_preparingProgress, lv_color_hex(0x474747), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_preparingProgress, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_set_style_radius(ui_preparingProgress, 4, LV_PART_INDICATOR| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_preparingProgress, lv_color_hex(0xD9D9D9), LV_PART_INDICATOR | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_preparingProgress, 255, LV_PART_INDICATOR| LV_STATE_DEFAULT);

ui_preparingLogo2 = lv_img_create(ui_preparing);
lv_img_set_src(ui_preparingLogo2, &ui_img_logo21_png);
lv_obj_set_width( ui_preparingLogo2, LV_SIZE_CONTENT);  /// 48
lv_obj_set_height( ui_preparingLogo2, LV_SIZE_CONTENT);   /// 48
lv_obj_set_x( ui_preparingLogo2, 728 );
lv_obj_set_y( ui_preparingLogo2, 16 );
lv_obj_add_flag( ui_preparingLogo2, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_preparingLogo2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

lv_obj_add_event_cb(ui_preparingButton, ui_event_preparingButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_preparingLogo2, ui_event_preparingLogo2, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_preparing, ui_event_preparing, LV_EVENT_ALL, NULL);

}
