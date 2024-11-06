SET(SOURCES screens/ui_home.c
    screens/ui_choose.c
    screens/ui_payment.c
    screens/ui_preparing.c
    screens/ui_success.c
    screens/ui_config.c
    ui.c
    components/ui_comp_hook.c
    ui_helpers.c
    images/ui_img_logo21_png.c
    images/ui_img_water_png.c
    images/ui_img_config_png.c
    images/ui_img_chevron_png.c
    images/ui_img_espresso_png.c
    images/ui_img_coffee_png.c
    images/ui_img_check_png.c
    images/ui_img_exit_png.c
    images/ui_img_trash_png.c
    images/ui_img_warning_png.c
    images/ui_img_wifi_png.c
    fonts/ui_font_LoraRegular14.c
    fonts/ui_font_LoraRegular20.c
    fonts/ui_font_LoraRegular36.c
    fonts/ui_font_OpenSansBold14.c
    fonts/ui_font_OpenSansBold20.c
    fonts/ui_font_OpenSansSemiBold12.c
    fonts/ui_font_OpenSansSemiBold14.c)

add_library(ui ${SOURCES})
