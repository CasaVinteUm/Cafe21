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
    lv_obj_set_width(ui_ePanel, 218);
    lv_obj_set_height(ui_ePanel, 210);
    lv_obj_set_x(ui_ePanel, 12);
    lv_obj_set_y(ui_ePanel, -12);
    lv_obj_set_align(ui_ePanel, LV_ALIGN_BOTTOM_LEFT);
    lv_obj_clear_flag(ui_ePanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ePanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ePanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ePanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ePanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ePanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ePanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ePanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ePanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ePanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_secundaryButtonE = lv_btn_create(ui_ePanel);
    lv_obj_set_width(ui_secundaryButtonE, 194);
    lv_obj_set_height(ui_secundaryButtonE, 36);
    lv_obj_set_align(ui_secundaryButtonE, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_secundaryButtonE, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_secundaryButtonE, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_secundaryButtonE, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_secundaryButtonE, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_secundaryButtonE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_secundaryButtonE, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_secundaryButtonE, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_secundaryButtonE, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_secundaryButtonE, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_pbLabel1 = lv_label_create(ui_secundaryButtonE);
    lv_obj_set_width(ui_pbLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_pbLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_pbLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_pbLabel1, "Pedir um expresso");
    lv_obj_set_style_text_color(ui_pbLabel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_pbLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_pbLabel1, &ui_font_OpenSansSemiBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eTitle = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eTitle, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eTitle, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eTitle, 0);
    lv_obj_set_y(ui_eTitle, 65);
    lv_obj_set_align(ui_eTitle, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_eTitle, "Expresso to the Moon");
    lv_obj_set_style_text_color(ui_eTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eTitle, &ui_font_LoraRegular14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_expressoOrder = lv_img_create(ui_ePanel);
    lv_img_set_src(ui_expressoOrder, &ui_img_expresso_png);
    lv_obj_set_width(ui_expressoOrder, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_expressoOrder, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_expressoOrder, 0);
    lv_obj_set_y(ui_expressoOrder, -9);
    lv_obj_set_align(ui_expressoOrder, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_expressoOrder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_expressoOrder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_sbeLabel = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_sbeLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sbeLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_sbeLabel, 0);
    lv_obj_set_y(ui_sbeLabel, 95);
    lv_label_set_text(ui_sbeLabel, "Preço");
    lv_obj_set_style_text_color(ui_sbeLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_sbeLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_sbeLabel, &ui_font_OpenSansSemiBold12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eSats = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eSats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eSats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eSats, 0);
    lv_obj_set_y(ui_eSats, 119);
    lv_label_set_text(ui_eSats, "1.414 sats");
    lv_obj_set_style_text_color(ui_eSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eSats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eSats, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_eReal = lv_label_create(ui_ePanel);
    lv_obj_set_width(ui_eReal, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_eReal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_eReal, 0);
    lv_obj_set_y(ui_eReal, 119);
    lv_obj_set_align(ui_eReal, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_eReal, "R$ 5.00");
    lv_obj_set_style_text_color(ui_eReal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_eReal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_eReal, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_goBack = ui_goBack_create(ui_choseCoffe);
    lv_obj_set_x(ui_goBack, 12);
    lv_obj_set_y(ui_goBack, 8);

    ui_cPanel = lv_obj_create(ui_choseCoffe);
    lv_obj_set_width(ui_cPanel, 218);
    lv_obj_set_height(ui_cPanel, 210);
    lv_obj_set_x(ui_cPanel, -12);
    lv_obj_set_y(ui_cPanel, -12);
    lv_obj_set_align(ui_cPanel, LV_ALIGN_BOTTOM_RIGHT);
    lv_obj_clear_flag(ui_cPanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_cPanel, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_cPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_cPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_cPanel, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_cPanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_cPanel, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_cPanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_cPanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_cPanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_cPanel, 12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_secundaryButtonC = lv_btn_create(ui_cPanel);
    lv_obj_set_width(ui_secundaryButtonC, 194);
    lv_obj_set_height(ui_secundaryButtonC, 36);
    lv_obj_set_align(ui_secundaryButtonC, LV_ALIGN_BOTTOM_MID);
    lv_obj_add_flag(ui_secundaryButtonC, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_secundaryButtonC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_secundaryButtonC, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_secundaryButtonC, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_secundaryButtonC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_secundaryButtonC, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_secundaryButtonC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_secundaryButtonC, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_secundaryButtonC, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_sbcLabel = lv_label_create(ui_secundaryButtonC);
    lv_obj_set_width(ui_sbcLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_sbcLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_sbcLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_sbcLabel, "Pedir um Block Coffe");
    lv_obj_set_style_text_color(ui_sbcLabel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_sbcLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_sbcLabel, &ui_font_OpenSansSemiBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cTitle1 = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cTitle1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cTitle1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cTitle1, 0);
    lv_obj_set_y(ui_cTitle1, 65);
    lv_obj_set_align(ui_cTitle1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_cTitle1, "Block Coffe");
    lv_obj_set_style_text_color(ui_cTitle1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cTitle1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cTitle1, &ui_font_LoraRegular14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_coffeOrder = lv_img_create(ui_cPanel);
    lv_img_set_src(ui_coffeOrder, &ui_img_coffe_png);
    lv_obj_set_width(ui_coffeOrder, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_coffeOrder, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_coffeOrder, 0);
    lv_obj_set_y(ui_coffeOrder, -9);
    lv_obj_set_align(ui_coffeOrder, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_coffeOrder, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_coffeOrder, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_cPrLabel = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cPrLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cPrLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cPrLabel, 0);
    lv_obj_set_y(ui_cPrLabel, 95);
    lv_label_set_text(ui_cPrLabel, "Preço");
    lv_obj_set_style_text_color(ui_cPrLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cPrLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cPrLabel, &ui_font_OpenSansSemiBold12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cSats = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cSats, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cSats, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cSats, 0);
    lv_obj_set_y(ui_cSats, 119);
    lv_label_set_text(ui_cSats, "1.414 sats");
    lv_obj_set_style_text_color(ui_cSats, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cSats, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cSats, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_cReal = lv_label_create(ui_cPanel);
    lv_obj_set_width(ui_cReal, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_cReal, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_cReal, 0);
    lv_obj_set_y(ui_cReal, 119);
    lv_obj_set_align(ui_cReal, LV_ALIGN_TOP_RIGHT);
    lv_label_set_text(ui_cReal, "R$ 5.00");
    lv_obj_set_style_text_color(ui_cReal, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_cReal, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_cReal, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_secundaryButtonE, ui_event_secundaryButtonE, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_ePanel, ui_event_ePanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_secundaryButtonC, ui_event_secundaryButtonC, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_cPanel, ui_event_cPanel, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_choseCoffe, ui_event_choseCoffe, LV_EVENT_ALL, NULL);

}