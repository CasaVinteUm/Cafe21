// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 8.3.11
// Project name: Cafe21_ui_480

#include "../ui.h"


void ui_event_comp_goBack_goBack(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    lv_obj_t ** comp_goBack = lv_event_get_user_data(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_hero, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 500, 0, &ui_hero_screen_init);
    }
}

// COMPONENT goBack

lv_obj_t * ui_goBack_create(lv_obj_t * comp_parent)
{

    lv_obj_t * cui_goBack;
    cui_goBack = lv_imgbtn_create(comp_parent);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_RELEASED, NULL, &ui_img_chevronsmall_png, NULL);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_PRESSED, NULL, &ui_img_chevronsmall_png, NULL);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_DISABLED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &ui__temporary_image, NULL);
    lv_imgbtn_set_src(cui_goBack, LV_IMGBTN_STATE_CHECKED_DISABLED, NULL, &ui__temporary_image, NULL);
    lv_obj_set_width(cui_goBack, 32);
    lv_obj_set_height(cui_goBack, 32);
    lv_obj_set_x(cui_goBack, 12);
    lv_obj_set_y(cui_goBack, 8);

    lv_obj_t ** children = lv_mem_alloc(sizeof(lv_obj_t *) * _UI_COMP_GOBACK_NUM);
    children[UI_COMP_GOBACK_GOBACK] = cui_goBack;
    lv_obj_add_event_cb(cui_goBack, get_component_child_event_cb, LV_EVENT_GET_COMP_CHILD, children);
    lv_obj_add_event_cb(cui_goBack, del_component_child_event_cb, LV_EVENT_DELETE, children);
    lv_obj_add_event_cb(cui_goBack, ui_event_comp_goBack_goBack, LV_EVENT_ALL, children);
    ui_comp_goBack_create_hook(cui_goBack);
    return cui_goBack;
}

