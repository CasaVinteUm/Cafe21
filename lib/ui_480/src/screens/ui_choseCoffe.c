// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: Cafe21_ui_480

#include "../ui.h"

void ui_choseCoffe_screen_init(void)
{
    ui_choseCoffe = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_choseCoffe, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_choseCoffe, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ePanel = lv_obj_create(ui_choseCoffe);
    lv_obj_set_width(ui_ePanel, 360);
    lv_obj_set_height(ui_ePanel, 372);
    lv_obj_set_x(ui_ePanel, 24);
    lv_obj_set_y(ui_ePanel, 80);
    lv_obj_clear_flag(ui_ePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ePanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ePanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ePanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ePanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ePanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ePanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ePanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_primaryButton1 = lv_btn_create(ui_ePanel);
    lv_obj_set_width(ui_primaryButton1, 328);
    lv_obj_set_height(ui_primaryButton1, 44);
    lv_obj_set_x(ui_primaryButton1, -3);
    lv_obj_set_y(ui_primaryButton1, 294);
    lv_obj_set_align(ui_primaryButton1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_primaryButton1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_primaryButton1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_primaryButton1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_primaryButton1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_primaryButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_primaryButton1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_primaryButton1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_primaryButton1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_primaryButton1, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pbLabel1 = lv_label_create(ui_primaryButton1);
    lv_obj_set_width(ui_pbLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_pbLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_pbLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_pbLabel1, "Pedir um Expresso");
    lv_obj_set_style_text_color(ui_pbLabel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pbLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_pbLabel1, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eTitle = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eTitle, 0);
    lv_obj_set_y(ui_eTitle, 142);
    lv_obj_set_align(ui_eTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_eTitle, "Expresso to the Moon");
    lv_obj_set_style_text_color(ui_eTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eTitle, &ui_font_LoraRegula24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_expressoOrder = lv_img_create(ui_ePanel);
    lv_img_set_src(ui_expressoOrder, &ui_img_expressolarge_png);
    lv_obj_set_width(ui_expressoOrder, LV_SIZE_CONTENT);   /// 132
    lv_obj_set_height(ui_expressoOrder, LV_SIZE_CONTENT);    /// 132
    lv_obj_set_x(ui_expressoOrder, 0);
    lv_obj_set_y(ui_expressoOrder, 6);
    lv_obj_set_align(ui_expressoOrder, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_expressoOrder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_expressoOrder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_ePrLabel = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_ePrLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_ePrLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_ePrLabel, 0);
    lv_obj_set_y(ui_ePrLabel, 200);
    lv_label_set_text(ui_ePrLabel, "Preço");
    lv_obj_set_style_text_color(ui_ePrLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_ePrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_ePrLabel, &ui_font_OpenSansSemiBold16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eConteiner = lv_obj_create(ui_ePanel);
    lv_obj_remove_style_all(ui_eConteiner);
    lv_obj_set_width(ui_eConteiner, 326);
    lv_obj_set_height(ui_eConteiner, 52);
    lv_obj_set_x(ui_eConteiner, 0);
    lv_obj_set_y(ui_eConteiner, 230);
    lv_obj_set_align(ui_eConteiner, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_eConteiner, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_eConteiner, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_eConteiner, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_eConteiner, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_eConteiner, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_eConteiner, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_eConteiner, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eSats = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eSats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eSats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eSats, 0);
    lv_obj_set_y(ui_eSats, 246);
    lv_label_set_text(ui_eSats, "1.414 sats");
    lv_obj_set_style_text_color(ui_eSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eSats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eSats, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eReal = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eReal, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eReal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eReal, 0);
    lv_obj_set_y(ui_eReal, 246);
    lv_obj_set_align(ui_eReal, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_eReal, "R$ 5.00");
    lv_obj_set_style_text_color(ui_eReal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eReal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eReal, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eConteiner3 = lv_obj_create(ui_ePanel);
    lv_obj_remove_style_all(ui_eConteiner3);
    lv_obj_set_width(ui_eConteiner3, 326);
    lv_obj_set_height(ui_eConteiner3, 52);
    lv_obj_set_x(ui_eConteiner3, 0);
    lv_obj_set_y(ui_eConteiner3, 230);
    lv_obj_set_align(ui_eConteiner3, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_eConteiner3, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_eConteiner3, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_eConteiner3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_eConteiner3, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_eConteiner3, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_eConteiner3, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_eConteiner3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cPanel = lv_obj_create(ui_choseCoffe);
    lv_obj_set_width(ui_cPanel, 360);
    lv_obj_set_height(ui_cPanel, 372);
    lv_obj_set_x(ui_cPanel, -25);
    lv_obj_set_y(ui_cPanel, 80);
    lv_obj_set_align(ui_cPanel, LV_ALIGN_TOP_RIGHT);
    lv_obj_clear_flag(ui_cPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cPanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cPanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cPanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cPanel, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_primaryButton2 = lv_btn_create(ui_cPanel);
    lv_obj_set_width(ui_primaryButton2, 328);
    lv_obj_set_height(ui_primaryButton2, 44);
    lv_obj_set_x(ui_primaryButton2, -3);
    lv_obj_set_y(ui_primaryButton2, 294);
    lv_obj_set_align(ui_primaryButton2, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_primaryButton2, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_primaryButton2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_primaryButton2, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_primaryButton2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_primaryButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_primaryButton2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_primaryButton2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_primaryButton2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_primaryButton2, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pbLabel2 = lv_label_create(ui_primaryButton2);
    lv_obj_set_width(ui_pbLabel2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_pbLabel2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_pbLabel2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_pbLabel2, "Pedir um Block Coffe");
    lv_obj_set_style_text_color(ui_pbLabel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pbLabel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_pbLabel2, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_bcTitle = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_bcTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_bcTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_bcTitle, 0);
    lv_obj_set_y(ui_bcTitle, 142);
    lv_obj_set_align(ui_bcTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_bcTitle, "Block Coffe");
    lv_obj_set_style_text_color(ui_bcTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_bcTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_bcTitle, &ui_font_LoraRegula24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_coffeOrder = lv_img_create(ui_cPanel);
    lv_img_set_src(ui_coffeOrder, &ui_img_coffelarge_png);
    lv_obj_set_width(ui_coffeOrder, LV_SIZE_CONTENT);   /// 132
    lv_obj_set_height(ui_coffeOrder, LV_SIZE_CONTENT);    /// 132
    lv_obj_set_x(ui_coffeOrder, 0);
    lv_obj_set_y(ui_coffeOrder, 6);
    lv_obj_set_align(ui_coffeOrder, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_coffeOrder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_coffeOrder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_cPrLabel = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cPrLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cPrLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cPrLabel, 0);
    lv_obj_set_y(ui_cPrLabel, 200);
    lv_label_set_text(ui_cPrLabel, "Preço");
    lv_obj_set_style_text_color(ui_cPrLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cPrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cPrLabel, &ui_font_OpenSansSemiBold16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cConteiner = lv_obj_create(ui_cPanel);
    lv_obj_remove_style_all(ui_cConteiner);
    lv_obj_set_width(ui_cConteiner, 328);
    lv_obj_set_height(ui_cConteiner, 52);
    lv_obj_set_x(ui_cConteiner, 0);
    lv_obj_set_y(ui_cConteiner, 230);
    lv_obj_set_align(ui_cConteiner, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_cConteiner, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_cConteiner, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cConteiner, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cConteiner, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_cConteiner, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_cConteiner, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_cConteiner, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cSats = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cSats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cSats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cSats, 0);
    lv_obj_set_y(ui_cSats, 246);
    lv_label_set_text(ui_cSats, "1.414 sats");
    lv_obj_set_style_text_color(ui_cSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cSats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cSats, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cReal = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cReal, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cReal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cReal, 0);
    lv_obj_set_y(ui_cReal, 246);
    lv_obj_set_align(ui_cReal, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_cReal, "R$ 5.00");
    lv_obj_set_style_text_color(ui_cReal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cReal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cReal, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cConteiner2 = lv_obj_create(ui_cPanel);
    lv_obj_remove_style_all(ui_cConteiner2);
    lv_obj_set_width(ui_cConteiner2, 326);
    lv_obj_set_height(ui_cConteiner2, 52);
    lv_obj_set_x(ui_cConteiner2, 0);
    lv_obj_set_y(ui_cConteiner2, 230);
    lv_obj_set_align(ui_cConteiner2, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_cConteiner2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_border_color(ui_cConteiner2, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cConteiner2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cConteiner2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui_cConteiner2, LV_BORDER_SIDE_TOP, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_cConteiner2, lv_color_hex(0x333333), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_cConteiner2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_goBack = ui_goBack_create(ui_choseCoffe);
    lv_obj_set_x(ui_goBack, 24);
    lv_obj_set_y(ui_goBack, 16);

    lv_obj_add_event_cb(ui_primaryButton1, ui_event_primaryButton1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ePanel, ui_event_ePanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_primaryButton2, ui_event_primaryButton2, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_cPanel, ui_event_cPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_choseCoffe, ui_event_choseCoffe, LV_EVENT_ALL, NULL);

}
