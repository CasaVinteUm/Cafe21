// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.5.0
// LVGL version: 8.3.11
// Project name: Cafe21UI480

#include "../ui.h"

void ui_choose_screen_init(void)
{
ui_choose = lv_obj_create(NULL);
lv_obj_set_style_bg_color(ui_choose, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_choose, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_chooseBackButton = lv_imgbtn_create(ui_choose);
lv_imgbtn_set_src(ui_chooseBackButton, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_chevron_png, NULL);
lv_imgbtn_set_src(ui_chooseBackButton, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_chevron_png, NULL);
lv_obj_set_width( ui_chooseBackButton, 32);
lv_obj_set_height( ui_chooseBackButton, 32);
lv_obj_set_x( ui_chooseBackButton, -212 );
lv_obj_set_y( ui_chooseBackButton, -112 );
lv_obj_set_align( ui_chooseBackButton, LV_ALIGN_CENTER );

ui_chooseLogo = lv_img_create(ui_choose);
lv_img_set_src(ui_chooseLogo, &ui_img_logo21_png);
lv_obj_set_width( ui_chooseLogo, LV_SIZE_CONTENT);  /// 32
lv_obj_set_height( ui_chooseLogo, LV_SIZE_CONTENT);   /// 32
lv_obj_set_x( ui_chooseLogo, 436 );
lv_obj_set_y( ui_chooseLogo, 12 );
lv_obj_add_flag( ui_chooseLogo, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_chooseLogo, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_choosePanel1 = lv_obj_create(ui_choose);
lv_obj_set_width( ui_choosePanel1, 218);
lv_obj_set_height( ui_choosePanel1, 200);
lv_obj_set_x( ui_choosePanel1, 12 );
lv_obj_set_y( ui_choosePanel1, -12 );
lv_obj_set_align( ui_choosePanel1, LV_ALIGN_BOTTOM_LEFT );
lv_obj_clear_flag( ui_choosePanel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_choosePanel1, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_choosePanel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_choosePanel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_choosePanel1, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_choosePanel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_choosePanel1, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_choosePanel1, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_choosePanel1, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_choosePanel1, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_choosePanel1, 12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1Button = lv_btn_create(ui_choosePanel1);
lv_obj_set_width( ui_choosePanel1Button, 194);
lv_obj_set_height( ui_choosePanel1Button, 36);
lv_obj_set_align( ui_choosePanel1Button, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_choosePanel1Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_choosePanel1Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_choosePanel1Button, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_choosePanel1Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_choosePanel1Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_choosePanel1Button, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_choosePanel1Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1Button, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1ButtonLabel = lv_label_create(ui_choosePanel1Button);
lv_obj_set_width( ui_choosePanel1ButtonLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1ButtonLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_choosePanel1ButtonLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_choosePanel1ButtonLabel,"Pedir um espresso");
lv_obj_set_style_text_color(ui_choosePanel1ButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1ButtonLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1ButtonLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1Title = lv_label_create(ui_choosePanel1);
lv_obj_set_width( ui_choosePanel1Title, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1Title, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel1Title, 0 );
lv_obj_set_y( ui_choosePanel1Title, 55 );
lv_obj_set_align( ui_choosePanel1Title, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_choosePanel1Title,"Espresso to the Moon");
lv_obj_set_style_text_color(ui_choosePanel1Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1Title, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1Title, &ui_font_LoraRegular14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1Image = lv_img_create(ui_choosePanel1);
lv_img_set_src(ui_choosePanel1Image, &ui_img_espresso_png);
lv_obj_set_width( ui_choosePanel1Image, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1Image, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel1Image, 0 );
lv_obj_set_y( ui_choosePanel1Image, -9 );
lv_obj_set_align( ui_choosePanel1Image, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_choosePanel1Image, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_choosePanel1Image, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_choosePanel1PriceLabel = lv_label_create(ui_choosePanel1);
lv_obj_set_width( ui_choosePanel1PriceLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1PriceLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel1PriceLabel, 0 );
lv_obj_set_y( ui_choosePanel1PriceLabel, 85 );
lv_label_set_text(ui_choosePanel1PriceLabel,"Preço");
lv_obj_set_style_text_color(ui_choosePanel1PriceLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1PriceLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1PriceLabel, &ui_font_OpenSansSemiBold12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1PriceSats = lv_label_create(ui_choosePanel1);
lv_obj_set_width( ui_choosePanel1PriceSats, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1PriceSats, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel1PriceSats, 0 );
lv_obj_set_y( ui_choosePanel1PriceSats, 109 );
lv_label_set_text(ui_choosePanel1PriceSats,"1.414 sats");
lv_obj_set_style_text_color(ui_choosePanel1PriceSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1PriceSats, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1PriceSats, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel1PriceBrl = lv_label_create(ui_choosePanel1);
lv_obj_set_width( ui_choosePanel1PriceBrl, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel1PriceBrl, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel1PriceBrl, 0 );
lv_obj_set_y( ui_choosePanel1PriceBrl, 109 );
lv_obj_set_align( ui_choosePanel1PriceBrl, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_choosePanel1PriceBrl,"R$ 5.00");
lv_obj_set_style_text_color(ui_choosePanel1PriceBrl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel1PriceBrl, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel1PriceBrl, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2 = lv_obj_create(ui_choose);
lv_obj_set_width( ui_choosePanel2, 218);
lv_obj_set_height( ui_choosePanel2, 200);
lv_obj_set_x( ui_choosePanel2, -12 );
lv_obj_set_y( ui_choosePanel2, -12 );
lv_obj_set_align( ui_choosePanel2, LV_ALIGN_BOTTOM_RIGHT );
lv_obj_clear_flag( ui_choosePanel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_choosePanel2, 8, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_choosePanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_choosePanel2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_choosePanel2, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_choosePanel2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_choosePanel2, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_choosePanel2, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_choosePanel2, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_choosePanel2, 12, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_choosePanel2, 12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2Button = lv_btn_create(ui_choosePanel2);
lv_obj_set_width( ui_choosePanel2Button, 194);
lv_obj_set_height( ui_choosePanel2Button, 36);
lv_obj_set_align( ui_choosePanel2Button, LV_ALIGN_BOTTOM_MID );
lv_obj_add_flag( ui_choosePanel2Button, LV_OBJ_FLAG_SCROLL_ON_FOCUS );   /// Flags
lv_obj_clear_flag( ui_choosePanel2Button, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_choosePanel2Button, 4, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_choosePanel2Button, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_choosePanel2Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_color(ui_choosePanel2Button, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2Button, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_choosePanel2Button, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2Button, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2ButtonLabel = lv_label_create(ui_choosePanel2Button);
lv_obj_set_width( ui_choosePanel2ButtonLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2ButtonLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_choosePanel2ButtonLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_choosePanel2ButtonLabel,"Pedir um Block Coffee");
lv_obj_set_style_text_color(ui_choosePanel2ButtonLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2ButtonLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2ButtonLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2Title = lv_label_create(ui_choosePanel2);
lv_obj_set_width( ui_choosePanel2Title, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2Title, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel2Title, 0 );
lv_obj_set_y( ui_choosePanel2Title, 55 );
lv_obj_set_align( ui_choosePanel2Title, LV_ALIGN_TOP_MID );
lv_label_set_text(ui_choosePanel2Title,"Block Coffee");
lv_obj_set_style_text_color(ui_choosePanel2Title, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2Title, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2Title, &ui_font_LoraRegular14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2Image = lv_img_create(ui_choosePanel2);
lv_img_set_src(ui_choosePanel2Image, &ui_img_coffee_png);
lv_obj_set_width( ui_choosePanel2Image, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2Image, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel2Image, 0 );
lv_obj_set_y( ui_choosePanel2Image, -9 );
lv_obj_set_align( ui_choosePanel2Image, LV_ALIGN_TOP_MID );
lv_obj_add_flag( ui_choosePanel2Image, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_choosePanel2Image, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_choosePanel2PriceLabel = lv_label_create(ui_choosePanel2);
lv_obj_set_width( ui_choosePanel2PriceLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2PriceLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel2PriceLabel, 0 );
lv_obj_set_y( ui_choosePanel2PriceLabel, 85 );
lv_label_set_text(ui_choosePanel2PriceLabel,"Preço");
lv_obj_set_style_text_color(ui_choosePanel2PriceLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2PriceLabel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2PriceLabel, &ui_font_OpenSansSemiBold12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2PriceSats = lv_label_create(ui_choosePanel2);
lv_obj_set_width( ui_choosePanel2PriceSats, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2PriceSats, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel2PriceSats, 0 );
lv_obj_set_y( ui_choosePanel2PriceSats, 109 );
lv_label_set_text(ui_choosePanel2PriceSats,"1.414 sats");
lv_obj_set_style_text_color(ui_choosePanel2PriceSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2PriceSats, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2PriceSats, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_choosePanel2PriceBrl = lv_label_create(ui_choosePanel2);
lv_obj_set_width( ui_choosePanel2PriceBrl, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_choosePanel2PriceBrl, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_choosePanel2PriceBrl, 0 );
lv_obj_set_y( ui_choosePanel2PriceBrl, 109 );
lv_obj_set_align( ui_choosePanel2PriceBrl, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_choosePanel2PriceBrl,"R$ 5.00");
lv_obj_set_style_text_color(ui_choosePanel2PriceBrl, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_choosePanel2PriceBrl, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_choosePanel2PriceBrl, &ui_font_OpenSansBold14, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_chooseBackButton, ui_event_chooseBackButton, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_choosePanel1Button, ui_event_choosePanel1Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_choosePanel2Button, ui_event_choosePanel2Button, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_choose, ui_event_choose, LV_EVENT_ALL, NULL);

}