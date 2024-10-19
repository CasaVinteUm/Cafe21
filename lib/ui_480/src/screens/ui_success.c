// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: Cafe21_ui_480

#include "../ui.h"

void ui_success_screen_init(void)
{
    ui_success = lv_obj_create(NULL);
    lv_obj_set_style_bg_color(ui_success, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_success, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_goBack3 = lv_imgbtn_create(ui_success);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_exitsmall_png, NULL);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_exitsmall_png, NULL);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_DISABLED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(ui_goBack3, LV_IMGBTN_STATE_CHECKED_DISABLED, NULL, &ui__temporary_image, NULL);
    lv_obj_set_height(ui_goBack3, 48);
    lv_obj_set_width(ui_goBack3, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_x(ui_goBack3, -24);
    lv_obj_set_y(ui_goBack3, 16);
    lv_obj_set_align(ui_goBack3, LV_ALIGN_TOP_RIGHT);

    ui_ePanel2 = lv_obj_create(ui_success);
    lv_obj_set_width(ui_ePanel2, 360);
    lv_obj_set_height(ui_ePanel2, 372);
    lv_obj_set_align(ui_ePanel2, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_ePanel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_ePanel2, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_ePanel2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_ePanel2, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_ePanel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_ePanel2, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_ePanel2, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_ePanel2, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_ePanel2, 16, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_ePanel2, 16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_btnCancel1 = lv_btn_create(ui_ePanel2);
    lv_obj_set_width(ui_btnCancel1, 328);
    lv_obj_set_height(ui_btnCancel1, 44);
    lv_obj_set_x(ui_btnCancel1, 0);
    lv_obj_set_y(ui_btnCancel1, 277);
    lv_obj_set_align(ui_btnCancel1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_btnCancel1, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_btnCancel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_btnCancel1, 4, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_btnCancel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_btnCancel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui_btnCancel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_btnCancel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_btnCancel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_btnCancel1, &ui_font_OpenSansBold14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_btnCancelLabel1 = lv_label_create(ui_btnCancel1);
    lv_obj_set_width(ui_btnCancelLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_btnCancelLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_btnCancelLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_btnCancelLabel1, "Finalizar");
    lv_obj_set_style_text_color(ui_btnCancelLabel1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_btnCancelLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_btnCancelLabel1, &ui_font_OpenSansBold20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_prepLabel1 = lv_label_create(ui_ePanel2);
    lv_obj_set_width(ui_prepLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_prepLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_prepLabel1, 0);
    lv_obj_set_y(ui_prepLabel1, 169);
    lv_obj_set_align(ui_prepLabel1, LV_ALIGN_TOP_MID);
    lv_label_set_text(ui_prepLabel1, "Aproveite seu Expresso\nto the Moon");
    lv_obj_set_style_text_color(ui_prepLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_prepLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_prepLabel1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_prepLabel1, &ui_font_LoraRegula24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ePrepIcon1 = lv_img_create(ui_ePanel2);
    lv_img_set_src(ui_ePrepIcon1, &ui_img_checklarge_png);
    lv_obj_set_width(ui_ePrepIcon1, LV_SIZE_CONTENT);   /// 132
    lv_obj_set_height(ui_ePrepIcon1, LV_SIZE_CONTENT);    /// 132
    lv_obj_set_x(ui_ePrepIcon1, 0);
    lv_obj_set_y(ui_ePrepIcon1, 32);
    lv_obj_set_align(ui_ePrepIcon1, LV_ALIGN_TOP_MID);
    lv_obj_add_flag(ui_ePrepIcon1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_ePrepIcon1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_logoSuccess = lv_img_create(ui_success);
    lv_img_set_src(ui_logoSuccess, &ui_img_logo21_png);
    lv_obj_set_width(ui_logoSuccess, LV_SIZE_CONTENT);   /// 48
    lv_obj_set_height(ui_logoSuccess, LV_SIZE_CONTENT);    /// 48
    lv_obj_set_x(ui_logoSuccess, 24);
    lv_obj_set_y(ui_logoSuccess, 16);
    lv_obj_add_flag(ui_logoSuccess, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_logoSuccess, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    lv_obj_add_event_cb(ui_goBack3, ui_event_goBack3, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_btnCancel1, ui_event_btnCancel1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_success, ui_event_success, LV_EVENT_ALL, NULL);

}
