/*******************************************************************************
 * Size: 10 px
 * Bpp: 2
 * Opts: --bpp 2 --size 10 --font D:/Arduino/PlatformIo_Projetos/Casa21/Cafe21/Cafe21/UI_Design_480x270/assets/Lora-Regular.ttf -o D:/Arduino/PlatformIo_Projetos/Casa21/Cafe21/Cafe21/UI_Design_480x270/assets\ui_font_OpenSansRegular10.c --format lvgl -r 0x20-0xff --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_OPENSANSREGULAR10
#define UI_FONT_OPENSANSREGULAR10 1
#endif

#if UI_FONT_OPENSANSREGULAR10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */

    /* U+0021 "!" */
    0x33, 0x22, 0x10, 0x30,

    /* U+0022 "\"" */
    0x59, 0x60, 0x0,

    /* U+0023 "#" */
    0x2, 0x8, 0x2, 0x4, 0x2a, 0xb9, 0x8, 0x20,
    0x6e, 0xb8, 0x8, 0x50, 0x14, 0x80,

    /* U+0024 "$" */
    0x0, 0x2, 0x2, 0x65, 0x41, 0x70, 0x3, 0x80,
    0x19, 0x3, 0x66, 0x42, 0x0, 0x40,

    /* U+0025 "%" */
    0x29, 0x8, 0x24, 0xc5, 0x5, 0x32, 0x0, 0x56,
    0x54, 0x2, 0x22, 0x2, 0x18, 0x91, 0x2, 0x60,
    0x0, 0x0,

    /* U+0026 "&" */
    0x15, 0x40, 0x30, 0x80, 0x26, 0x40, 0x1d, 0x50,
    0x63, 0x50, 0x90, 0xd0, 0x25, 0x68,

    /* U+0027 "'" */
    0x55, 0x0,

    /* U+0028 "(" */
    0x0, 0x12, 0x8, 0x92, 0x49, 0x18, 0x20, 0x50,
    0x40,

    /* U+0029 ")" */
    0x1, 0x2, 0x9, 0x18, 0x61, 0x89, 0x20, 0x44,
    0x0,

    /* U+002A "*" */
    0x8, 0x16, 0x11, 0xd0, 0x98, 0x0, 0x0,

    /* U+002B "+" */
    0x4, 0x2, 0x5, 0x94, 0x20, 0x4, 0x0,

    /* U+002C "," */
    0x3, 0x10,

    /* U+002D "-" */
    0x2a, 0x0,

    /* U+002E "." */
    0x6,

    /* U+002F "/" */
    0x0, 0x0, 0x0, 0x50, 0x3, 0x0, 0x20, 0x1,
    0x80, 0xc, 0x0, 0x90, 0x2, 0x0, 0x20, 0x1,
    0x40, 0x4, 0x0, 0x0,

    /* U+0030 "0" */
    0x19, 0x83, 0x9, 0x60, 0x66, 0x6, 0x60, 0x63,
    0x8, 0x19, 0x40,

    /* U+0031 "1" */
    0x24, 0x64, 0x14, 0x14, 0x14, 0x14, 0x28,

    /* U+0032 "2" */
    0x26, 0x14, 0x60, 0x14, 0x8, 0x8, 0x8, 0x7,
    0xa8,

    /* U+0033 "3" */
    0x26, 0x5, 0x18, 0x1, 0x40, 0x60, 0x0, 0xc4,
    0xc, 0x26, 0x40,

    /* U+0034 "4" */
    0x2, 0x0, 0x70, 0x13, 0x1, 0x30, 0xab, 0x80,
    0x30, 0x7, 0x40,

    /* U+0035 "5" */
    0x3a, 0x44, 0x2, 0x60, 0x6, 0x0, 0xd4, 0x32,
    0x60,

    /* U+0036 "6" */
    0x19, 0x82, 0x4, 0x66, 0x46, 0xc, 0x60, 0x93,
    0xc, 0x29, 0x40,

    /* U+0037 "7" */
    0xaa, 0x40, 0x40, 0x10, 0x14, 0x8, 0x2, 0x1,
    0x40,

    /* U+0038 "8" */
    0x25, 0x42, 0xc, 0x35, 0x41, 0xf0, 0x21, 0xc5,
    0xc, 0x25, 0x40,

    /* U+0039 "9" */
    0x26, 0x46, 0xc, 0x50, 0xc6, 0xc, 0x15, 0xc1,
    0xc, 0x26, 0x0,

    /* U+003A ":" */
    0x20, 0x0, 0x20,

    /* U+003B ";" */
    0x30, 0x0, 0x31, 0x10,

    /* U+003C "<" */
    0x0, 0x1, 0x96, 0x41, 0x90, 0x2, 0x40, 0x0,

    /* U+003D "=" */
    0x55, 0x55, 0x50,

    /* U+003E ">" */
    0x0, 0x19, 0x0, 0x24, 0x19, 0x64, 0x0, 0x0,

    /* U+003F "?" */
    0x16, 0x10, 0x90, 0x20, 0x10, 0x14, 0x0, 0x0,
    0xc0,

    /* U+0040 "@" */
    0x6, 0x90, 0x24, 0x8, 0x21, 0x65, 0x58, 0x52,
    0x58, 0x91, 0x25, 0x10, 0x20, 0x4, 0x5, 0x50,

    /* U+0041 "A" */
    0x0, 0x40, 0x1, 0xc0, 0x1, 0x80, 0x4, 0x20,
    0x9, 0x70, 0x4, 0x14, 0x24, 0x2c,

    /* U+0042 "B" */
    0x39, 0x83, 0x8, 0x30, 0x83, 0x68, 0x30, 0x63,
    0x3, 0x35, 0x80,

    /* U+0043 "C" */
    0x9, 0x64, 0xc0, 0x16, 0x0, 0x24, 0x0, 0x60,
    0x0, 0xc0, 0x0, 0xa5, 0x0,

    /* U+0044 "D" */
    0x39, 0x50, 0xc0, 0x93, 0x0, 0xcc, 0x3, 0x30,
    0xc, 0xc0, 0x93, 0x59, 0x0,

    /* U+0045 "E" */
    0x39, 0x93, 0x0, 0x30, 0x43, 0x54, 0x30, 0x3,
    0x1, 0x35, 0x60,

    /* U+0046 "F" */
    0x39, 0x83, 0x0, 0x30, 0x3, 0x60, 0x30, 0x3,
    0x0, 0x34, 0x0,

    /* U+0047 "G" */
    0x9, 0x68, 0x30, 0x4, 0x60, 0x0, 0x90, 0x18,
    0x60, 0x8, 0x30, 0x8, 0xa, 0x54,

    /* U+0048 "H" */
    0x34, 0x2c, 0x30, 0x18, 0x30, 0x18, 0x35, 0x68,
    0x30, 0x18, 0x30, 0x18, 0x34, 0x28,

    /* U+0049 "I" */
    0x34, 0xc3, 0xc, 0x30, 0xc3, 0x40,

    /* U+004A "J" */
    0xb, 0x0, 0x80, 0x20, 0x8, 0x2, 0x0, 0x83,
    0x80,

    /* U+004B "K" */
    0x34, 0xa0, 0xc1, 0x3, 0x10, 0xe, 0x80, 0x32,
    0x40, 0xc3, 0x3, 0x43, 0x40,

    /* U+004C "L" */
    0x34, 0x3, 0x0, 0x30, 0x3, 0x0, 0x30, 0x3,
    0x1, 0x35, 0x60,

    /* U+004D "M" */
    0x34, 0x3, 0xb, 0x1, 0xc1, 0x80, 0x70, 0x58,
    0x4c, 0x13, 0x13, 0x8, 0x60, 0x82, 0x8, 0x34,

    /* U+004E "N" */
    0x30, 0x18, 0x2c, 0x4, 0x16, 0x4, 0x12, 0x44,
    0x10, 0xc4, 0x10, 0x34, 0x20, 0x18,

    /* U+004F "O" */
    0x9, 0x60, 0x30, 0xc, 0x60, 0x9, 0x90, 0x9,
    0x60, 0x9, 0x30, 0xc, 0x9, 0x60,

    /* U+0050 "P" */
    0x39, 0x83, 0x6, 0x30, 0x33, 0x9, 0x35, 0x43,
    0x0, 0x34, 0x0,

    /* U+0051 "Q" */
    0x9, 0x60, 0x30, 0xc, 0x60, 0x9, 0x90, 0x9,
    0x60, 0x9, 0x30, 0xc, 0x9, 0x60, 0x0, 0x34,
    0x0, 0x9,

    /* U+0052 "R" */
    0x39, 0x80, 0xc1, 0x83, 0x9, 0xd, 0x90, 0x32,
    0x40, 0xc3, 0x3, 0x46, 0x0,

    /* U+0053 "S" */
    0x25, 0x85, 0x8, 0x30, 0x0, 0xb0, 0x0, 0xc4,
    0x8, 0x65, 0x40,

    /* U+0054 "T" */
    0x97, 0x71, 0x8, 0x40, 0x20, 0x0, 0x80, 0x2,
    0x0, 0x8, 0x0, 0xb0, 0x0,

    /* U+0055 "U" */
    0x70, 0x18, 0x30, 0x4, 0x30, 0x4, 0x30, 0x4,
    0x30, 0x4, 0x20, 0x10, 0xa, 0x90,

    /* U+0056 "V" */
    0x2c, 0x9, 0xc, 0x4, 0x8, 0x10, 0x6, 0x20,
    0x3, 0x10, 0x1, 0xc0, 0x0, 0x80,

    /* U+0057 "W" */
    0xb0, 0x10, 0xa0, 0xc2, 0xc1, 0x2, 0x7, 0x4,
    0x6, 0x15, 0x10, 0xd, 0xd, 0x0, 0x28, 0x38,
    0x0, 0x50, 0x40, 0x0,

    /* U+0058 "X" */
    0x70, 0x60, 0x92, 0x0, 0xd0, 0x1, 0x80, 0xa,
    0x40, 0x43, 0x6, 0xb, 0x0,

    /* U+0059 "Y" */
    0x2c, 0x18, 0xc, 0x10, 0x6, 0x10, 0x2, 0x80,
    0x0, 0x80, 0x0, 0x80, 0x1, 0xc0,

    /* U+005A "Z" */
    0x65, 0xd4, 0xc, 0x3, 0x0, 0x50, 0xc, 0x3,
    0x1, 0x65, 0xa0,

    /* U+005B "[" */
    0x39, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
    0x39,

    /* U+005C "\\" */
    0x0, 0x2, 0x40, 0x3, 0x0, 0x6, 0x0, 0x8,
    0x0, 0x8, 0x0, 0x14, 0x0, 0x20, 0x0, 0x20,
    0x0, 0x80, 0x0, 0x40,

    /* U+005D "]" */
    0xac, 0x20, 0x82, 0x8, 0x20, 0x83, 0xac,

    /* U+005E "^" */
    0x1, 0x40, 0x5, 0x20, 0x20, 0x8,

    /* U+005F "_" */
    0x6a, 0xa4,

    /* U+0060 "`" */
    0x0, 0x80, 0x0,

    /* U+0061 "a" */
    0x26, 0x4, 0x81, 0x66, 0x48, 0x66, 0x40,

    /* U+0062 "b" */
    0x60, 0x2, 0x0, 0x36, 0x86, 0xc, 0x60, 0x96,
    0xc, 0x66, 0x40,

    /* U+0063 "c" */
    0x15, 0x58, 0x29, 0x1, 0x80, 0x29, 0x40,

    /* U+0064 "d" */
    0x0, 0xc0, 0xc, 0x25, 0xc6, 0xc, 0x90, 0xc6,
    0xc, 0x29, 0xd0,

    /* U+0065 "e" */
    0x15, 0x46, 0x58, 0xa0, 0x7, 0x0, 0x29, 0x40,

    /* U+0066 "f" */
    0x16, 0x30, 0x74, 0x30, 0x30, 0x30, 0x30,

    /* U+0067 "g" */
    0x0, 0x52, 0x64, 0x60, 0x82, 0x50, 0x50, 0x3,
    0xe4, 0x50, 0x96, 0x54,

    /* U+0068 "h" */
    0x70, 0x3, 0x0, 0x36, 0x83, 0xc, 0x30, 0xc3,
    0xc, 0x70, 0xd0,

    /* U+0069 "i" */
    0x30, 0x7, 0xc, 0x30, 0xc3, 0x0,

    /* U+006A "j" */
    0xc, 0x1, 0xc3, 0xc, 0x30, 0xc2, 0x90,

    /* U+006B "k" */
    0x70, 0x3, 0x0, 0x31, 0x83, 0x10, 0x38, 0x3,
    0x30, 0x71, 0xc0,

    /* U+006C "l" */
    0x70, 0xc3, 0xc, 0x30, 0xc7, 0x0,

    /* U+006D "m" */
    0x76, 0x9a, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc3, 0x0,

    /* U+006E "n" */
    0x36, 0x83, 0xc, 0x30, 0x83, 0x8, 0x30, 0xd0,

    /* U+006F "o" */
    0x15, 0x46, 0xc, 0x90, 0x96, 0x8, 0x25, 0x40,

    /* U+0070 "p" */
    0x76, 0x83, 0x9, 0x30, 0xa3, 0x9, 0x35, 0x43,
    0x0, 0x70, 0x0,

    /* U+0071 "q" */
    0x15, 0xc6, 0xc, 0x90, 0xc6, 0xc, 0x29, 0xc0,
    0xc, 0x0, 0xc0,

    /* U+0072 "r" */
    0x77, 0xc, 0x3, 0x0, 0xc0, 0x30, 0x0,

    /* U+0073 "s" */
    0x26, 0x18, 0x42, 0xd1, 0xc, 0x56, 0x0,

    /* U+0074 "t" */
    0x0, 0x30, 0x74, 0x30, 0x30, 0x30, 0x29,

    /* U+0075 "u" */
    0x70, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x25, 0xc0,

    /* U+0076 "v" */
    0xa1, 0x82, 0x10, 0x31, 0x1, 0x90, 0xc, 0x0,

    /* U+0077 "w" */
    0xb1, 0x45, 0x31, 0xc4, 0x21, 0x84, 0x1c, 0x70,
    0x8, 0x20,

    /* U+0078 "x" */
    0x71, 0x82, 0x50, 0xc, 0x1, 0x70, 0x62, 0x80,

    /* U+0079 "y" */
    0xb0, 0x83, 0x4, 0x15, 0x0, 0xd0, 0x8, 0x0,
    0x40, 0x60, 0x0,

    /* U+007A "z" */
    0x66, 0x50, 0x80, 0xc0, 0x81, 0x65, 0x80,

    /* U+007B "{" */
    0x14, 0x30, 0x30, 0x90, 0x20, 0x30, 0x30, 0x30,
    0x14,

    /* U+007C "|" */
    0x22, 0x22, 0x22, 0x22, 0x20,

    /* U+007D "}" */
    0x60, 0x20, 0x20, 0x8, 0x20, 0x20, 0x20, 0x20,
    0x60,

    /* U+007E "~" */
    0x68, 0x40, 0x40,

    /* U+00A0 " " */

    /* U+00A1 "¡" */
    0x60, 0x12, 0x26, 0x70,

    /* U+00A2 "¢" */
    0x0, 0x2, 0x2, 0x55, 0x41, 0x90, 0x18, 0x2,
    0x90, 0x20,

    /* U+00A3 "£" */
    0x15, 0x43, 0x0, 0x30, 0x3, 0x90, 0x14, 0x2,
    0x40, 0x57, 0x80,

    /* U+00A4 "¤" */
    0x25, 0x4c, 0x53, 0x14, 0x95,

    /* U+00A5 "¥" */
    0x74, 0x24, 0x90, 0x40, 0xc4, 0x2, 0x50, 0x7,
    0x80, 0x1d, 0x0, 0x34, 0x0,

    /* U+00A6 "¦" */
    0x22, 0x21, 0x1, 0x22, 0x20,

    /* U+00A7 "§" */
    0x16, 0x8, 0x13, 0x41, 0x68, 0x91, 0xdc, 0x21,
    0xe4, 0x9, 0x21, 0x45, 0x40,

    /* U+00A8 "¨" */
    0x58, 0x0,

    /* U+00A9 "©" */
    0x5, 0x50, 0x5, 0x6a, 0x41, 0x91, 0x22, 0x30,
    0x5, 0x89, 0x1, 0x54, 0xa8, 0x82, 0x40, 0x50,
    0x19, 0x40,

    /* U+00AA "ª" */
    0x18, 0x18, 0x58, 0x10,

    /* U+00AB "«" */
    0x0, 0x2, 0x2, 0x21, 0x98, 0x25, 0x41, 0x0,
    0x0,

    /* U+00AC "¬" */
    0x6a, 0x80, 0x20, 0x0,

    /* U+00AE "®" */
    0x5, 0x60, 0x9, 0x41, 0x42, 0x22, 0x22, 0xe,
    0x45, 0x82, 0x21, 0x54, 0x85, 0x82, 0x40, 0x50,
    0x1a, 0x40,

    /* U+00AF "¯" */
    0x68,

    /* U+00B0 "°" */
    0x18, 0x41, 0x41, 0x28,

    /* U+00B1 "±" */
    0x4, 0x2, 0x5, 0x94, 0x20, 0x4, 0x15, 0x50,

    /* U+00B2 "²" */
    0x18, 0x8, 0x10, 0x68,

    /* U+00B3 "³" */
    0x18, 0x8, 0x8, 0x18,

    /* U+00B4 "´" */
    0x10, 0x80, 0x0,

    /* U+00B5 "µ" */
    0x30, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x39, 0xd2,
    0x0, 0x30, 0x0,

    /* U+00B6 "¶" */
    0x7b, 0x2d, 0x83, 0x60, 0x58, 0x16, 0x5, 0x81,
    0x60, 0x58, 0x16, 0x0,

    /* U+00B7 "·" */
    0x3, 0x0,

    /* U+00B8 "¸" */
    0x0, 0x91, 0x0,

    /* U+00B9 "¹" */
    0x20, 0x82, 0x8,

    /* U+00BA "º" */
    0x24, 0x42, 0x52, 0x14,

    /* U+00BB "»" */
    0x0, 0x2, 0x2, 0x20, 0x66, 0x22, 0x2, 0x0,
    0x0,

    /* U+00BC "¼" */
    0x0, 0x0, 0x20, 0x20, 0x20, 0x50, 0x20, 0x80,
    0x22, 0x8, 0x4, 0x18, 0x4, 0x58, 0x10, 0x8,

    /* U+00BD "½" */
    0x0, 0x0, 0x20, 0x20, 0x20, 0x50, 0x20, 0x94,
    0x22, 0x15, 0x5, 0x8, 0x8, 0x20, 0x10, 0x29,

    /* U+00BE "¾" */
    0x14, 0x4, 0x8, 0x10, 0x8, 0x10, 0x8, 0x80,
    0x15, 0xc, 0x1, 0x18, 0x8, 0x18, 0x0, 0x8,

    /* U+00BF "¿" */
    0xc, 0x0, 0x0, 0x80, 0x10, 0x60, 0x24, 0x52,
    0x50,

    /* U+00C0 "À" */
    0x2, 0x0, 0x0, 0x40, 0x0, 0x40, 0x1, 0xc0,
    0x1, 0x80, 0x4, 0x20, 0x9, 0x70, 0x4, 0x14,
    0x24, 0x2c,

    /* U+00C1 "Á" */
    0x0, 0x90, 0x0, 0x0, 0x0, 0x40, 0x1, 0xc0,
    0x1, 0x80, 0x4, 0x20, 0x9, 0x70, 0x4, 0x14,
    0x24, 0x2c,

    /* U+00C2 "Â" */
    0x0, 0x0, 0x1, 0x80, 0x0, 0x0, 0x0, 0x40,
    0x1, 0xc0, 0x1, 0x80, 0x4, 0x20, 0x9, 0x70,
    0x4, 0x14, 0x24, 0x2c,

    /* U+00C3 "Ã" */
    0x6, 0x10, 0x4, 0x90, 0x0, 0x40, 0x1, 0xc0,
    0x1, 0x80, 0x4, 0x20, 0x9, 0x70, 0x4, 0x14,
    0x24, 0x2c,

    /* U+00C4 "Ä" */
    0x0, 0x0, 0x6, 0x50, 0x0, 0x0, 0x0, 0x40,
    0x1, 0xc0, 0x1, 0x80, 0x4, 0x20, 0x9, 0x70,
    0x4, 0x14, 0x24, 0x2c,

    /* U+00C5 "Å" */
    0x1, 0x40, 0x2, 0x40, 0x1, 0x80, 0x2, 0xc0,
    0x1, 0x80, 0x4, 0x60, 0x9, 0x70, 0x4, 0x14,
    0x24, 0x2c,

    /* U+00C6 "Æ" */
    0x0, 0x39, 0x60, 0x0, 0x90, 0x0, 0x5, 0x44,
    0x0, 0x46, 0x50, 0x2, 0x64, 0x0, 0x10, 0x50,
    0x42, 0x43, 0x97, 0x0,

    /* U+00C7 "Ç" */
    0x9, 0x64, 0xc0, 0x16, 0x0, 0x24, 0x0, 0x60,
    0x0, 0xc0, 0x0, 0xa5, 0x0, 0xa0, 0x0, 0x90,
    0x0, 0x0,

    /* U+00C8 "È" */
    0x8, 0x0, 0x10, 0x39, 0x93, 0x0, 0x30, 0x43,
    0x54, 0x30, 0x3, 0x1, 0x35, 0x60,

    /* U+00C9 "É" */
    0x1, 0x40, 0x0, 0x39, 0x93, 0x0, 0x30, 0x43,
    0x54, 0x30, 0x3, 0x1, 0x35, 0x60,

    /* U+00CA "Ê" */
    0x0, 0x0, 0x60, 0x0, 0x3, 0x99, 0x30, 0x3,
    0x4, 0x35, 0x43, 0x0, 0x30, 0x13, 0x56,

    /* U+00CB "Ë" */
    0x0, 0x0, 0xd8, 0x0, 0x3, 0x99, 0x30, 0x3,
    0x4, 0x35, 0x43, 0x0, 0x30, 0x13, 0x56,

    /* U+00CC "Ì" */
    0x50, 0x3, 0x4c, 0x30, 0xc3, 0xc, 0x34,

    /* U+00CD "Í" */
    0x8, 0x10, 0x34, 0x30, 0x30, 0x30, 0x30, 0x30,
    0x34,

    /* U+00CE "Î" */
    0x0, 0x28, 0x0, 0x34, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x34,

    /* U+00CF "Ï" */
    0x0, 0x9c, 0x0, 0x34, 0x30, 0x30, 0x30, 0x30,
    0x30, 0x34,

    /* U+00D0 "Ð" */
    0x39, 0x50, 0xc0, 0x93, 0x0, 0xdd, 0x43, 0x30,
    0xc, 0xc0, 0x93, 0x59, 0x0,

    /* U+00D1 "Ñ" */
    0x6, 0x10, 0x4, 0x90, 0x30, 0x18, 0x2c, 0x4,
    0x16, 0x4, 0x12, 0x44, 0x10, 0xc4, 0x10, 0x34,
    0x20, 0x18,

    /* U+00D2 "Ò" */
    0x6, 0x0, 0x0, 0x0, 0x9, 0x60, 0x30, 0xc,
    0x60, 0x9, 0x90, 0x9, 0x60, 0x9, 0x30, 0xc,
    0x9, 0x60,

    /* U+00D3 "Ó" */
    0x0, 0x80, 0x1, 0x0, 0x9, 0x60, 0x30, 0xc,
    0x60, 0x9, 0x90, 0x9, 0x60, 0x9, 0x30, 0xc,
    0x9, 0x60,

    /* U+00D4 "Ô" */
    0x0, 0x0, 0x2, 0x80, 0x0, 0x0, 0x9, 0x60,
    0x30, 0xc, 0x60, 0x9, 0x90, 0x9, 0x60, 0x9,
    0x30, 0xc, 0x9, 0x60,

    /* U+00D5 "Õ" */
    0x6, 0x10, 0x4, 0x90, 0x9, 0x60, 0x30, 0xc,
    0x60, 0x9, 0x90, 0x9, 0x60, 0x9, 0x30, 0xc,
    0x9, 0x60,

    /* U+00D6 "Ö" */
    0x0, 0x0, 0x5, 0x80, 0x0, 0x0, 0x9, 0x60,
    0x30, 0xc, 0x60, 0x9, 0x90, 0x9, 0x60, 0x9,
    0x30, 0xc, 0x9, 0x60,

    /* U+00D7 "×" */
    0x0, 0x8, 0x80, 0xd0, 0x88, 0x0, 0x0,

    /* U+00D8 "Ø" */
    0x0, 0x0, 0x9, 0x74, 0x30, 0x2c, 0x60, 0x89,
    0x91, 0x49, 0x62, 0x9, 0x38, 0xc, 0x1d, 0x60,
    0x0, 0x0,

    /* U+00D9 "Ù" */
    0x6, 0x0, 0x0, 0x0, 0x70, 0x18, 0x30, 0x4,
    0x30, 0x4, 0x30, 0x4, 0x30, 0x4, 0x20, 0x10,
    0xa, 0x90,

    /* U+00DA "Ú" */
    0x0, 0x80, 0x0, 0x0, 0x70, 0x18, 0x30, 0x4,
    0x30, 0x4, 0x30, 0x4, 0x30, 0x4, 0x20, 0x10,
    0xa, 0x90,

    /* U+00DB "Û" */
    0x0, 0x0, 0x2, 0x80, 0x0, 0x0, 0x70, 0x18,
    0x30, 0x4, 0x30, 0x4, 0x30, 0x4, 0x30, 0x4,
    0x20, 0x10, 0xa, 0x90,

    /* U+00DC "Ü" */
    0x0, 0x0, 0x5, 0x80, 0x0, 0x0, 0x70, 0x18,
    0x30, 0x4, 0x30, 0x4, 0x30, 0x4, 0x30, 0x4,
    0x20, 0x10, 0xa, 0x90,

    /* U+00DD "Ý" */
    0x0, 0x50, 0x0, 0x0, 0x2c, 0x18, 0xc, 0x10,
    0x6, 0x10, 0x2, 0x80, 0x0, 0x80, 0x0, 0x80,
    0x1, 0xc0,

    /* U+00DE "Þ" */
    0x34, 0x3, 0x54, 0x30, 0x93, 0x6, 0x30, 0x93,
    0x54, 0x34, 0x0,

    /* U+00DF "ß" */
    0x19, 0x80, 0xc0, 0xc7, 0x14, 0xc, 0xd0, 0x30,
    0xe0, 0xc4, 0x93, 0x26, 0x0,

    /* U+00E0 "à" */
    0x4, 0x2, 0x0, 0x0, 0x98, 0x12, 0x5, 0x99,
    0x21, 0x99,

    /* U+00E1 "á" */
    0x4, 0x2, 0x0, 0x0, 0x98, 0x12, 0x5, 0x99,
    0x21, 0x99,

    /* U+00E2 "â" */
    0x8, 0x4, 0x80, 0x0, 0x98, 0x12, 0x5, 0x99,
    0x21, 0x99,

    /* U+00E3 "ã" */
    0x1a, 0x0, 0x2, 0x60, 0x48, 0x16, 0x64, 0x86,
    0x64,

    /* U+00E4 "ä" */
    0x22, 0x0, 0x2, 0x60, 0x48, 0x16, 0x64, 0x86,
    0x64,

    /* U+00E5 "å" */
    0x4, 0x1, 0x0, 0x0, 0x98, 0x12, 0x5, 0x99,
    0x21, 0x99,

    /* U+00E6 "æ" */
    0x26, 0x98, 0x2, 0x98, 0x17, 0x40, 0x92, 0x40,
    0x65, 0xa4,

    /* U+00E7 "ç" */
    0x15, 0x58, 0x29, 0x1, 0x80, 0x29, 0x41, 0x80,
    0x24, 0x0,

    /* U+00E8 "è" */
    0x4, 0x0, 0x80, 0x0, 0x1, 0x54, 0x65, 0x8a,
    0x0, 0x70, 0x2, 0x94,

    /* U+00E9 "é" */
    0x0, 0x0, 0x90, 0x0, 0x1, 0x54, 0x65, 0x8a,
    0x0, 0x70, 0x2, 0x94,

    /* U+00EA "ê" */
    0x0, 0x1, 0xa0, 0x0, 0x1, 0x54, 0x65, 0x8a,
    0x0, 0x70, 0x2, 0x94,

    /* U+00EB "ë" */
    0x17, 0x0, 0x0, 0x15, 0x46, 0x58, 0xa0, 0x7,
    0x0, 0x29, 0x40,

    /* U+00EC "ì" */
    0x0, 0x80, 0x1c, 0x30, 0xc3, 0xc,

    /* U+00ED "í" */
    0x0, 0x80, 0x1c, 0x30, 0xc3, 0xc,

    /* U+00EE "î" */
    0x11, 0x90, 0x1c, 0x30, 0xc3, 0xc,

    /* U+00EF "ï" */
    0xc8, 0x7, 0xc, 0x30, 0xc3, 0x0,

    /* U+00F0 "ð" */
    0x0, 0x1, 0x80, 0x2, 0x2, 0x68, 0x60, 0xc9,
    0xc, 0x60, 0xc2, 0x60,

    /* U+00F1 "ñ" */
    0xa, 0x40, 0x0, 0x36, 0x83, 0xc, 0x30, 0x83,
    0x8, 0x30, 0xd0,

    /* U+00F2 "ò" */
    0x4, 0x0, 0x50, 0x0, 0x1, 0x54, 0x60, 0xc9,
    0x9, 0x60, 0x82, 0x54,

    /* U+00F3 "ó" */
    0x1, 0x0, 0x50, 0x0, 0x1, 0x54, 0x60, 0xc9,
    0x9, 0x60, 0x82, 0x54,

    /* U+00F4 "ô" */
    0x0, 0x0, 0xa0, 0x0, 0x1, 0x54, 0x60, 0xc9,
    0x9, 0x60, 0x82, 0x54,

    /* U+00F5 "õ" */
    0x1a, 0x0, 0x0, 0x15, 0x46, 0xc, 0x90, 0x96,
    0x8, 0x25, 0x40,

    /* U+00F6 "ö" */
    0x16, 0x0, 0x0, 0x15, 0x46, 0xc, 0x90, 0x96,
    0x8, 0x25, 0x40,

    /* U+00F7 "÷" */
    0x0, 0x3, 0x5, 0x94, 0x0, 0xc, 0x0, 0x0,

    /* U+00F8 "ø" */
    0x0, 0x1, 0x6c, 0x62, 0xc9, 0x59, 0x68, 0x83,
    0x94, 0x10, 0x0,

    /* U+00F9 "ù" */
    0x4, 0x0, 0x50, 0x0, 0x7, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc2, 0x5c,

    /* U+00FA "ú" */
    0x1, 0x0, 0x50, 0x0, 0x7, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc2, 0x5c,

    /* U+00FB "û" */
    0x0, 0x0, 0xa0, 0x0, 0x7, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc2, 0x5c,

    /* U+00FC "ü" */
    0x1a, 0x0, 0x0, 0x70, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x25, 0xc0,

    /* U+00FD "ý" */
    0x1, 0x0, 0x80, 0x0, 0xb, 0x8, 0x30, 0x41,
    0x50, 0xd, 0x0, 0x80, 0x4, 0x6, 0x0,

    /* U+00FE "þ" */
    0x60, 0x2, 0x0, 0x36, 0x46, 0xc, 0x60, 0x96,
    0xc, 0x76, 0x46, 0x0, 0xa0, 0x0,

    /* U+00FF "ÿ" */
    0x16, 0x0, 0x0, 0xb0, 0x83, 0x4, 0x15, 0x0,
    0xd0, 0x8, 0x0, 0x40, 0x60, 0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 42, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 0, .adv_w = 43, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 55, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 7, .adv_w = 133, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 21, .adv_w = 85, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 35, .adv_w = 139, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 111, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 33, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 69, .adv_w = 49, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 78, .adv_w = 49, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 87, .adv_w = 83, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 94, .adv_w = 85, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 101, .adv_w = 40, .box_w = 2, .box_h = 4, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 103, .adv_w = 78, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 105, .adv_w = 39, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 110, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 126, .adv_w = 99, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 58, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 86, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 89, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 87, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 175, .adv_w = 87, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 92, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 74, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 90, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 215, .adv_w = 92, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 40, .box_w = 2, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 42, .box_w = 2, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 233, .adv_w = 85, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 85, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 244, .adv_w = 85, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 76, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 127, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 277, .adv_w = 100, .box_w = 8, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 100, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 112, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 119, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 100, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 88, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 122, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 125, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 54, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 60, .box_w = 5, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 109, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 92, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 417, .adv_w = 147, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 122, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 127, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 97, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 490, .adv_w = 100, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 91, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 102, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 527, .adv_w = 120, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 541, .adv_w = 104, .box_w = 8, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 159, .box_w = 11, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 104, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 588, .adv_w = 101, .box_w = 8, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 602, .adv_w = 98, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 57, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 622, .adv_w = 110, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 642, .adv_w = 57, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 649, .adv_w = 132, .box_w = 8, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 655, .adv_w = 117, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 657, .adv_w = 40, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 660, .adv_w = 83, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 667, .adv_w = 93, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 678, .adv_w = 85, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 685, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 87, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 54, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 88, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 723, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 734, .adv_w = 45, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 740, .adv_w = 42, .box_w = 3, .box_h = 9, .ofs_x = -1, .ofs_y = -2},
    {.bitmap_index = 747, .adv_w = 86, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 758, .adv_w = 44, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 143, .box_w = 9, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 776, .adv_w = 97, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 94, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 803, .adv_w = 92, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 814, .adv_w = 69, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 821, .adv_w = 74, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 828, .adv_w = 62, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 835, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 843, .adv_w = 81, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 851, .adv_w = 128, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 85, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 869, .adv_w = 84, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 880, .adv_w = 82, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 887, .adv_w = 53, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 896, .adv_w = 37, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 901, .adv_w = 53, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 910, .adv_w = 85, .box_w = 5, .box_h = 2, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 913, .adv_w = 42, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 39, .box_w = 2, .box_h = 8, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 917, .adv_w = 85, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 927, .adv_w = 88, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 938, .adv_w = 86, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 943, .adv_w = 113, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 956, .adv_w = 39, .box_w = 2, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 961, .adv_w = 85, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 974, .adv_w = 62, .box_w = 4, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 976, .adv_w = 140, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 994, .adv_w = 65, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 998, .adv_w = 85, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1007, .adv_w = 85, .box_w = 5, .box_h = 3, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1011, .adv_w = 140, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1029, .adv_w = 57, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 1030, .adv_w = 65, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1034, .adv_w = 85, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1042, .adv_w = 62, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1046, .adv_w = 59, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1050, .adv_w = 40, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 1053, .adv_w = 98, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1064, .adv_w = 80, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1076, .adv_w = 40, .box_w = 2, .box_h = 3, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 1078, .adv_w = 47, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1081, .adv_w = 45, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1084, .adv_w = 67, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 1088, .adv_w = 85, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1097, .adv_w = 121, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 126, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1129, .adv_w = 127, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1145, .adv_w = 75, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1154, .adv_w = 100, .box_w = 8, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1172, .adv_w = 100, .box_w = 8, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1190, .adv_w = 100, .box_w = 8, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1210, .adv_w = 100, .box_w = 8, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1228, .adv_w = 100, .box_w = 8, .box_h = 10, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1248, .adv_w = 100, .box_w = 8, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1266, .adv_w = 152, .box_w = 11, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1286, .adv_w = 112, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1304, .adv_w = 100, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1318, .adv_w = 100, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1332, .adv_w = 100, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1347, .adv_w = 100, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1362, .adv_w = 54, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1369, .adv_w = 54, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1378, .adv_w = 54, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1388, .adv_w = 54, .box_w = 4, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1398, .adv_w = 119, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1411, .adv_w = 122, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1429, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1447, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1465, .adv_w = 127, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1485, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1503, .adv_w = 127, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1523, .adv_w = 85, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1530, .adv_w = 127, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1548, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1566, .adv_w = 120, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1584, .adv_w = 120, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1604, .adv_w = 120, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1624, .adv_w = 101, .box_w = 8, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1642, .adv_w = 95, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1653, .adv_w = 109, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1666, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1676, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1686, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1696, .adv_w = 83, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1705, .adv_w = 83, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1714, .adv_w = 83, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1724, .adv_w = 124, .box_w = 8, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1734, .adv_w = 85, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1744, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1756, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1768, .adv_w = 87, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1780, .adv_w = 87, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1791, .adv_w = 45, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1797, .adv_w = 45, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1803, .adv_w = 45, .box_w = 3, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1809, .adv_w = 45, .box_w = 3, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1815, .adv_w = 89, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1827, .adv_w = 97, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1838, .adv_w = 94, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1850, .adv_w = 94, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1862, .adv_w = 94, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1874, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1885, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1896, .adv_w = 85, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1904, .adv_w = 94, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1915, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1927, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1939, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1951, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1962, .adv_w = 84, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1977, .adv_w = 92, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 1991, .adv_w = 84, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 160, .range_length = 13, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 174, .range_length = 82, .glyph_id_start = 109,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 7,
    3, 13,
    3, 15,
    3, 16,
    3, 21,
    3, 33,
    7, 3,
    7, 8,
    8, 7,
    8, 13,
    8, 15,
    8, 16,
    8, 21,
    8, 33,
    9, 9,
    9, 17,
    9, 20,
    9, 21,
    9, 23,
    9, 25,
    9, 26,
    9, 92,
    10, 10,
    10, 62,
    10, 94,
    12, 18,
    12, 19,
    12, 20,
    12, 24,
    13, 3,
    13, 8,
    13, 17,
    13, 23,
    13, 24,
    14, 18,
    14, 19,
    14, 20,
    14, 24,
    15, 3,
    15, 8,
    15, 17,
    15, 23,
    15, 24,
    16, 16,
    16, 17,
    16, 21,
    16, 23,
    17, 10,
    17, 13,
    17, 15,
    17, 16,
    17, 19,
    17, 24,
    17, 61,
    17, 62,
    17, 94,
    18, 14,
    18, 16,
    18, 62,
    18, 118,
    19, 14,
    19, 16,
    19, 20,
    19, 21,
    19, 62,
    19, 118,
    20, 10,
    20, 16,
    20, 24,
    20, 62,
    20, 94,
    21, 3,
    21, 8,
    21, 10,
    21, 16,
    21, 62,
    21, 111,
    22, 16,
    23, 10,
    23, 16,
    23, 24,
    23, 62,
    23, 94,
    24, 12,
    24, 13,
    24, 14,
    24, 15,
    24, 16,
    24, 21,
    24, 27,
    24, 62,
    24, 98,
    24, 118,
    25, 10,
    25, 16,
    25, 26,
    25, 62,
    25, 94,
    25, 118,
    26, 10,
    26, 13,
    26, 15,
    26, 16,
    26, 24,
    26, 62,
    26, 94,
    30, 18,
    30, 24,
    33, 3,
    33, 8,
    60, 9,
    60, 17,
    60, 18,
    60, 19,
    60, 20,
    60, 21,
    60, 23,
    60, 25,
    60, 26,
    60, 92,
    61, 3,
    61, 8,
    61, 17,
    61, 18,
    61, 19,
    61, 20,
    61, 21,
    61, 22,
    61, 23,
    61, 24,
    61, 25,
    61, 26,
    92, 9,
    92, 17,
    92, 18,
    92, 20,
    92, 21,
    92, 23,
    92, 25,
    92, 26,
    92, 92,
    94, 10,
    94, 62,
    94, 94,
    111, 21,
    118, 18,
    118, 19,
    118, 20,
    118, 24,
    118, 25
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -2, -20, -20, -18, -7, -3, -8, -8,
    -2, -20, -17, -17, -7, -3, -3, -3,
    -2, -4, -3, -2, -2, -2, -3, -4,
    -2, -3, -3, -2, -6, -20, -20, -2,
    -2, -5, -4, -5, -4, -10, -20, -17,
    -2, -2, -5, -51, -2, -7, -3, -3,
    -3, -3, -8, -1, -4, -2, -5, -3,
    -2, -3, -2, -3, -3, -4, -2, -4,
    -3, -3, -3, -6, -4, -4, -2, -2,
    -2, -2, -4, -3, -2, -6, -2, -6,
    -1, -3, -2, -2, -7, -3, -7, -12,
    -2, -4, 1, -2, -3, -3, -6, -1,
    -4, -2, -2, -3, -3, -3, -8, -4,
    -4, -2, -2, -6, -2, -2, -4, -5,
    -4, -2, -3, -6, -5, -4, -4, -3,
    -18, -17, -8, -5, -3, -5, -6, -5,
    -7, -9, -6, -6, -2, -3, -2, -2,
    -3, -3, -2, -2, -2, -2, -3, -2,
    -5, -5, -5, -4, -11, -2
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 150,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 2,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_OpenSansRegular10 = {
#else
lv_font_t ui_font_OpenSansRegular10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 13,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_OPENSANSREGULAR10*/

