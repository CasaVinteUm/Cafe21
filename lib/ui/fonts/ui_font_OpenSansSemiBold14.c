/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font D:/Arduino/PlatformIO_Projetos/Casa21/Cafe21/Cafe21/UI_Design/assets/OpenSans-SemiBold.ttf -o D:/Arduino/PlatformIO_Projetos/Casa21/Cafe21/Cafe21/UI_Design/assets\ui_font_OpenSansSemiBold14.c --format lvgl -r 0x20-0xff --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_OPENSANSSEMIBOLD14
#define UI_FONT_OPENSANSSEMIBOLD14 1
#endif

#if UI_FONT_OPENSANSSEMIBOLD14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0xfc, 0xf0,

    /* U+0022 "\"" */
    0x99, 0x90,

    /* U+0023 "#" */
    0x12, 0x32, 0x36, 0xff, 0x24, 0x24, 0xff, 0x6c,
    0x48, 0x48,

    /* U+0024 "$" */
    0x10, 0xfb, 0xf6, 0x8f, 0xf, 0x7, 0x8b, 0x97,
    0xf8, 0x40, 0x80,

    /* U+0025 "%" */
    0x71, 0x1b, 0x23, 0x68, 0x6d, 0xd, 0xdc, 0xee,
    0xc2, 0xd8, 0x5b, 0x13, 0x62, 0x38,

    /* U+0026 "&" */
    0x38, 0x36, 0x1b, 0xd, 0x83, 0x3, 0x8f, 0x35,
    0x8e, 0xc7, 0x3e, 0xc0,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x36, 0x6c, 0xcc, 0xcc, 0xc6, 0x63,

    /* U+0029 ")" */
    0xc6, 0x63, 0x33, 0x33, 0x36, 0x6c,

    /* U+002A "*" */
    0x30, 0x8e, 0xff, 0x71, 0x60, 0x0,

    /* U+002B "+" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0,

    /* U+002C "," */
    0x69, 0x0,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0xc4, 0x23, 0x11, 0x8c, 0x46, 0x0,

    /* U+0030 "0" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0x6c,
    0x70,

    /* U+0031 "1" */
    0x1b, 0xf6, 0x31, 0x8c, 0x63, 0x18, 0xc0,

    /* U+0032 "2" */
    0x7d, 0x8c, 0x18, 0x30, 0xe3, 0x86, 0x18, 0x61,
    0xfc,

    /* U+0033 "3" */
    0x7c, 0xc, 0x18, 0x63, 0x1, 0xc1, 0x83, 0x8f,
    0xf0,

    /* U+0034 "4" */
    0xc, 0x38, 0x71, 0x66, 0xc9, 0xb3, 0x7f, 0xc,
    0x18,

    /* U+0035 "5" */
    0x7d, 0x83, 0x6, 0xf, 0xc1, 0xc1, 0x83, 0xf,
    0xf0,

    /* U+0036 "6" */
    0x3c, 0xc1, 0x6, 0xee, 0x78, 0xf1, 0xe3, 0x6c,
    0x78,

    /* U+0037 "7" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x6, 0x18, 0x30,
    0xc0,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1f, 0x73, 0x8f, 0xb1, 0xe3, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x79, 0x9b, 0x1e, 0x3c, 0x6f, 0xc1, 0x82, 0xc,
    0xf0,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0xf0, 0xe, 0x80,

    /* U+003C "<" */
    0x2, 0x18, 0xc6, 0xe, 0x7, 0x1, 0x80,

    /* U+003D "=" */
    0xfe, 0x0, 0x7, 0xf0,

    /* U+003E ">" */
    0x81, 0xc0, 0xe0, 0x61, 0xce, 0x30, 0x0,

    /* U+003F "?" */
    0x7c, 0xc, 0x18, 0x71, 0xc6, 0xc, 0x0, 0x30,
    0x60,

    /* U+0040 "@" */
    0x1f, 0x6, 0x19, 0x7d, 0xd9, 0x9b, 0x33, 0x66,
    0x6c, 0xcc, 0xee, 0x40, 0xc, 0x10, 0x7c, 0x0,

    /* U+0041 "A" */
    0xc, 0xe, 0x5, 0x6, 0xc3, 0x21, 0x19, 0xfc,
    0xc2, 0x41, 0xe0, 0xc0,

    /* U+0042 "B" */
    0xfd, 0x8f, 0x1e, 0x3f, 0x98, 0xf1, 0xe3, 0xc7,
    0xf8,

    /* U+0043 "C" */
    0x3e, 0xc7, 0x86, 0xc, 0x18, 0x30, 0x60, 0x60,
    0x7c,

    /* U+0044 "D" */
    0xf8, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc2,
    0xc6, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xff, 0xc, 0x30, 0xc3, 0xf0,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xc3, 0xfc, 0x30, 0xc3, 0x0,

    /* U+0047 "G" */
    0x1f, 0x60, 0xe0, 0xc0, 0xcf, 0xc3, 0xc3, 0xc3,
    0x63, 0x3f,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+0049 "I" */
    0xff, 0xff, 0xf0,

    /* U+004A "J" */
    0x18, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0x0,

    /* U+004B "K" */
    0xc2, 0xc6, 0xcc, 0xd8, 0xf0, 0xf8, 0xcc, 0xcc,
    0xc6, 0xc3,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xe0, 0xfc, 0x1f, 0xc7, 0xe8, 0xbd, 0x17, 0xb6,
    0xf2, 0x9e, 0x53, 0xce, 0x78, 0x8c,

    /* U+004E "N" */
    0xe1, 0xf0, 0xfc, 0x7b, 0x3d, 0x9e, 0x6f, 0x17,
    0x8f, 0xc3, 0xe1, 0xc0,

    /* U+004F "O" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x1f, 0x0,

    /* U+0050 "P" */
    0xfd, 0x8f, 0x1e, 0x3c, 0xff, 0xb0, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xf, 0x7,
    0x83, 0x63, 0x1f, 0x1, 0x80, 0x60, 0x38,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc6, 0xc6, 0xce, 0xf8, 0xc8, 0xcc,
    0xc6, 0xc3,

    /* U+0053 "S" */
    0x7f, 0x83, 0x7, 0x7, 0x87, 0x83, 0x83, 0x87,
    0xf0,

    /* U+0054 "T" */
    0xff, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0056 "V" */
    0xc1, 0xa0, 0x98, 0xcc, 0x62, 0x21, 0xb0, 0xd0,
    0x28, 0x1c, 0xc, 0x0,

    /* U+0057 "W" */
    0xc3, 0x1a, 0x38, 0xd1, 0x44, 0xca, 0x26, 0x5b,
    0x16, 0xd8, 0xa2, 0x87, 0x14, 0x38, 0xe0, 0xc3,
    0x0,

    /* U+0058 "X" */
    0x43, 0x31, 0x8d, 0x86, 0x81, 0xc0, 0xe0, 0xd0,
    0x4c, 0x63, 0x60, 0x80,

    /* U+0059 "Y" */
    0xc3, 0xc3, 0x66, 0x24, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfe, 0xc, 0x30, 0xc1, 0x86, 0xc, 0x30, 0xc1,
    0xfc,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,

    /* U+005C "\\" */
    0xc2, 0x18, 0xc2, 0x18, 0x42, 0x18, 0x40,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x10, 0x18, 0x18, 0x24, 0x24, 0x42, 0x42,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x99, 0x80,

    /* U+0061 "a" */
    0x7c, 0x8c, 0x1b, 0xfc, 0x78, 0xf3, 0xbf,

    /* U+0062 "b" */
    0xc1, 0x83, 0x7, 0xec, 0xf8, 0xf1, 0xe3, 0xc7,
    0x9f, 0xf0,

    /* U+0063 "c" */
    0x3d, 0x8c, 0x30, 0xc3, 0x6, 0x5f,

    /* U+0064 "d" */
    0x6, 0xc, 0x1b, 0xfe, 0xf8, 0xf1, 0xe3, 0xc7,
    0xdd, 0xf8,

    /* U+0065 "e" */
    0x3c, 0xcf, 0x1f, 0xfc, 0x18, 0x18, 0x9f,

    /* U+0066 "f" */
    0x3d, 0x86, 0x3e, 0x61, 0x86, 0x18, 0x61, 0x86,
    0x0,

    /* U+0067 "g" */
    0x7f, 0xc6, 0xc6, 0xc6, 0x3c, 0x60, 0x60, 0x3e,
    0xc3, 0xc3, 0x7e,

    /* U+0068 "h" */
    0xc1, 0x83, 0x7, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+0069 "i" */
    0xf3, 0xff, 0xfc,

    /* U+006A "j" */
    0x33, 0x3, 0x33, 0x33, 0x33, 0x33, 0x3e,

    /* U+006B "k" */
    0xc1, 0x83, 0x6, 0x3c, 0xdb, 0x3c, 0x7c, 0xc9,
    0x9b, 0x18,

    /* U+006C "l" */
    0xff, 0xff, 0xfc,

    /* U+006D "m" */
    0xfd, 0xee, 0x73, 0xc6, 0x3c, 0x63, 0xc6, 0x3c,
    0x63, 0xc6, 0x3c, 0x63,

    /* U+006E "n" */
    0xfd, 0xcf, 0x1e, 0x3c, 0x78, 0xf1, 0xe3,

    /* U+006F "o" */
    0x38, 0xdb, 0x1e, 0x3c, 0x78, 0xdb, 0x1c,

    /* U+0070 "p" */
    0xfd, 0x9f, 0x1e, 0x3c, 0x78, 0xfb, 0x7e, 0xc1,
    0x83, 0x0,

    /* U+0071 "q" */
    0x7f, 0xdf, 0x1e, 0x3c, 0x78, 0xf9, 0xbf, 0x6,
    0xc, 0x18,

    /* U+0072 "r" */
    0xff, 0x31, 0x8c, 0x63, 0x18,

    /* U+0073 "s" */
    0x7f, 0xc, 0x3e, 0x3c, 0x30, 0xfe,

    /* U+0074 "t" */
    0x23, 0x3e, 0xc6, 0x31, 0x8c, 0x61, 0xc0,

    /* U+0075 "u" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf3, 0xbf,

    /* U+0076 "v" */
    0xc2, 0x8d, 0x9b, 0x22, 0xc5, 0x8e, 0xc,

    /* U+0077 "w" */
    0xc6, 0x29, 0xcd, 0x29, 0xb5, 0xa6, 0xb4, 0x73,
    0x8c, 0x71, 0x8c,

    /* U+0078 "x" */
    0x46, 0x64, 0x3c, 0x18, 0x38, 0x3c, 0x66, 0xc6,

    /* U+0079 "y" */
    0xc7, 0x8d, 0x13, 0x66, 0xc5, 0xe, 0x8, 0x30,
    0x63, 0x80,

    /* U+007A "z" */
    0xfc, 0x31, 0x8c, 0x31, 0x8c, 0x3f,

    /* U+007B "{" */
    0x19, 0x8c, 0x63, 0x1b, 0x6, 0x31, 0x8c, 0x30,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xe1, 0x8c, 0x63, 0x18, 0x26, 0x31, 0x8d, 0xc0,

    /* U+007E "~" */
    0xf3, 0x3c,

    /* U+00A0 " " */
    0x0,

    /* U+00A1 "¡" */
    0xf3, 0xff, 0xf0,

    /* U+00A2 "¢" */
    0x11, 0xfe, 0x30, 0xc3, 0xe, 0x1f, 0x10, 0x40,

    /* U+00A3 "£" */
    0x3e, 0xc1, 0x83, 0xf, 0xcc, 0x18, 0x30, 0x41,
    0xfc,

    /* U+00A4 "¤" */
    0xfc, 0x63, 0x1f, 0x80,

    /* U+00A5 "¥" */
    0xc2, 0x8d, 0x91, 0x63, 0x8f, 0x86, 0x3e, 0x18,
    0x30,

    /* U+00A6 "¦" */
    0xf8, 0x7c,

    /* U+00A7 "§" */
    0x7f, 0xe, 0x1e, 0xdf, 0x3e, 0xce, 0xc, 0x3f,
    0x80,

    /* U+00A8 "¨" */
    0xf0,

    /* U+00A9 "©" */
    0x1e, 0x18, 0x44, 0xea, 0x61, 0x90, 0x64, 0x19,
    0x6, 0x61, 0x4e, 0x98, 0x61, 0xe0,

    /* U+00AA "ª" */
    0xf1, 0xf9, 0xf0,

    /* U+00AB "«" */
    0x24, 0xdb, 0x66, 0xc6, 0xc4, 0xc0,

    /* U+00AC "¬" */
    0xfc, 0x10, 0x41,

    /* U+00AD "­" */
    0xf0,

    /* U+00AE "®" */
    0x1e, 0x18, 0x45, 0xca, 0x49, 0x92, 0x67, 0x19,
    0x46, 0x49, 0x52, 0x98, 0x61, 0xe0,

    /* U+00AF "¯" */
    0xfe,

    /* U+00B0 "°" */
    0x74, 0x63, 0x17, 0x0,

    /* U+00B1 "±" */
    0x10, 0x20, 0x47, 0xf1, 0x2, 0x4, 0x0, 0xfe,

    /* U+00B2 "²" */
    0xf1, 0x12, 0x4f,

    /* U+00B3 "³" */
    0xf1, 0x61, 0x1e,

    /* U+00B4 "´" */
    0x7a, 0x0,

    /* U+00B5 "µ" */
    0xc7, 0x8f, 0x1e, 0x3c, 0x78, 0xf3, 0xff, 0xc1,
    0x83, 0x0,

    /* U+00B6 "¶" */
    0x7f, 0xf7, 0xef, 0xdf, 0xbf, 0x5e, 0x85, 0xa,
    0x14, 0x28, 0x50, 0xa0,

    /* U+00B7 "·" */
    0xf0,

    /* U+00B8 "¸" */
    0x4c, 0xf0,

    /* U+00B9 "¹" */
    0x7c, 0x92, 0x40,

    /* U+00BA "º" */
    0x69, 0x99, 0x60,

    /* U+00BB "»" */
    0x48, 0xd8, 0xd9, 0xb6, 0xd9, 0x0,

    /* U+00BC "¼" */
    0x31, 0x1e, 0x60, 0xc8, 0x1b, 0x3, 0x4c, 0x7b,
    0x82, 0x70, 0xd6, 0x1b, 0xe6, 0x18,

    /* U+00BD "½" */
    0x31, 0x1e, 0x20, 0xc8, 0x19, 0x3, 0x5e, 0x7a,
    0xc2, 0x18, 0xc6, 0x11, 0x86, 0x3c,

    /* U+00BE "¾" */
    0xf1, 0x82, 0x21, 0x88, 0xb, 0x1, 0x4d, 0xdb,
    0x82, 0xb0, 0xd6, 0x13, 0xe6, 0x18,

    /* U+00BF "¿" */
    0x30, 0xc0, 0xc, 0x31, 0x8c, 0x30, 0xc1, 0xe0,

    /* U+00C0 "À" */
    0x30, 0xc, 0x1, 0x0, 0x0, 0xc0, 0xe0, 0x50,
    0x6c, 0x32, 0x11, 0x9f, 0xcc, 0x24, 0x1e, 0xc,

    /* U+00C1 "Á" */
    0x6, 0x6, 0x2, 0x0, 0x0, 0xc0, 0xe0, 0x50,
    0x6c, 0x32, 0x11, 0x9f, 0xcc, 0x24, 0x1e, 0xc,

    /* U+00C2 "Â" */
    0xc, 0xa, 0x8, 0x80, 0x0, 0xc0, 0xe0, 0x50,
    0x6c, 0x32, 0x11, 0x9f, 0xcc, 0x24, 0x1e, 0xc,

    /* U+00C3 "Ã" */
    0x3a, 0x17, 0x0, 0x1, 0x81, 0xc0, 0xa0, 0xd8,
    0x64, 0x23, 0x3f, 0x98, 0x48, 0x3c, 0x18,

    /* U+00C4 "Ä" */
    0x3c, 0x0, 0x0, 0x3, 0x1, 0x80, 0xc0, 0xf0,
    0x48, 0x66, 0x3f, 0x10, 0x98, 0x68, 0x10,

    /* U+00C5 "Å" */
    0x1c, 0xa, 0x5, 0x3, 0x81, 0xc0, 0xa0, 0xd8,
    0x6c, 0x22, 0x3f, 0x98, 0xc8, 0x2c, 0x18,

    /* U+00C6 "Æ" */
    0xf, 0xf0, 0xb0, 0x1b, 0x1, 0x30, 0x33, 0xe2,
    0x30, 0x7f, 0x4, 0x30, 0xc3, 0xc, 0x3f,

    /* U+00C7 "Ç" */
    0x3e, 0xc3, 0x86, 0xc, 0x18, 0x30, 0x60, 0x60,
    0x7c, 0x20, 0x21, 0xc0,

    /* U+00C8 "È" */
    0x60, 0xc1, 0x0, 0xff, 0xc, 0x30, 0xff, 0xc,
    0x30, 0xc3, 0xf0,

    /* U+00C9 "É" */
    0xc, 0x62, 0x0, 0xff, 0xc, 0x30, 0xff, 0xc,
    0x30, 0xc3, 0xf0,

    /* U+00CA "Ê" */
    0x31, 0xec, 0x40, 0xff, 0xc, 0x30, 0xff, 0xc,
    0x30, 0xc3, 0xf0,

    /* U+00CB "Ë" */
    0x78, 0x0, 0x3f, 0xc3, 0xc, 0x3e, 0xc3, 0xc,
    0x30, 0xfc,

    /* U+00CC "Ì" */
    0xc6, 0x10, 0x33, 0x33, 0x33, 0x33, 0x33,

    /* U+00CD "Í" */
    0x36, 0x80, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc,

    /* U+00CE "Î" */
    0x31, 0xe8, 0x40, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0xc, 0x30, 0xc0,

    /* U+00CF "Ï" */
    0xf0, 0x6, 0x66, 0x66, 0x66, 0x66, 0x60,

    /* U+00D0 "Ð" */
    0x7c, 0x31, 0x98, 0x6c, 0x3f, 0x9b, 0xd, 0x86,
    0xc2, 0x63, 0x3e, 0x0,

    /* U+00D1 "Ñ" */
    0x1a, 0x16, 0x0, 0x1c, 0x3e, 0x1f, 0x8f, 0x67,
    0xb3, 0xcd, 0xe2, 0xf1, 0xf8, 0x7c, 0x38,

    /* U+00D2 "Ò" */
    0x10, 0x4, 0x0, 0x0, 0x3, 0xe3, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x31, 0xf0,

    /* U+00D3 "Ó" */
    0x4, 0x4, 0x2, 0x0, 0x3, 0xe3, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x31, 0xf0,

    /* U+00D4 "Ô" */
    0x1c, 0xa, 0x8, 0x80, 0x3, 0xe3, 0x1b, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x78, 0x36, 0x31, 0xf0,

    /* U+00D5 "Õ" */
    0x3e, 0x0, 0x0, 0x7, 0xc6, 0x36, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+00D6 "Ö" */
    0x36, 0x0, 0x0, 0x7, 0xc6, 0x36, 0xf, 0x7,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+00D7 "×" */
    0xcd, 0xe3, 0xc, 0x4a, 0x10,

    /* U+00D8 "Ø" */
    0x3f, 0x31, 0xb1, 0x78, 0xbc, 0x9e, 0x4f, 0x47,
    0xa3, 0x63, 0x3f, 0x0,

    /* U+00D9 "Ù" */
    0x30, 0x10, 0x8, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00DA "Ú" */
    0xc, 0x8, 0x10, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00DB "Û" */
    0x18, 0x3c, 0x24, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00DC "Ü" */
    0x3c, 0x0, 0x0, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00DD "Ý" */
    0xc, 0x18, 0x0, 0xc3, 0xc3, 0x66, 0x24, 0x3c,
    0x18, 0x18, 0x18, 0x18, 0x18,

    /* U+00DE "Þ" */
    0xc1, 0x83, 0xf6, 0x3c, 0x78, 0xf3, 0xfe, 0xc1,
    0x80,

    /* U+00DF "ß" */
    0x7c, 0xc6, 0xc6, 0xce, 0xd8, 0xd8, 0xce, 0xc7,
    0xc3, 0xc3, 0xde,

    /* U+00E0 "à" */
    0x30, 0x20, 0x3, 0xe4, 0x60, 0xdf, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00E1 "á" */
    0xc, 0x30, 0x3, 0xe4, 0x60, 0xdf, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00E2 "â" */
    0x38, 0x59, 0x3, 0xe4, 0x60, 0xdf, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00E3 "ã" */
    0x76, 0x98, 0x3, 0xe4, 0x60, 0xdf, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00E4 "ä" */
    0x6c, 0x0, 0x3, 0xe0, 0x60, 0xdf, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00E5 "å" */
    0x38, 0x50, 0xe0, 0x7, 0xc8, 0xc1, 0xbf, 0xc7,
    0x8f, 0x3b, 0xb0,

    /* U+00E6 "æ" */
    0x7b, 0xc9, 0x8c, 0x31, 0xbf, 0xfc, 0xc1, 0x98,
    0x33, 0x8b, 0x9f,

    /* U+00E7 "ç" */
    0x3d, 0x8c, 0x30, 0xc3, 0x6, 0x5f, 0x10, 0x23,
    0x80,

    /* U+00E8 "è" */
    0x20, 0x20, 0x1, 0xe6, 0x78, 0xff, 0xe0, 0xc0,
    0xc4, 0xf8,

    /* U+00E9 "é" */
    0x8, 0x20, 0x1, 0xe6, 0x78, 0xff, 0xe0, 0xc0,
    0xc4, 0xf8,

    /* U+00EA "ê" */
    0x38, 0xd8, 0x1, 0xe6, 0x78, 0xff, 0xe0, 0xc0,
    0xc4, 0xf8,

    /* U+00EB "ë" */
    0x6c, 0x0, 0x1, 0xe6, 0x78, 0xff, 0xe0, 0xc0,
    0xc4, 0xf8,

    /* U+00EC "ì" */
    0xcc, 0x36, 0xdb, 0x6d, 0x80,

    /* U+00ED "í" */
    0x6c, 0xc, 0xcc, 0xcc, 0xcc, 0xc0,

    /* U+00EE "î" */
    0x31, 0x20, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3,
    0x0,

    /* U+00EF "ï" */
    0xf0, 0x6, 0x66, 0x66, 0x66, 0x60,

    /* U+00F0 "ð" */
    0x3c, 0x30, 0xf0, 0x67, 0xf9, 0xf1, 0xe3, 0xc6,
    0x98, 0xe0,

    /* U+00F1 "ñ" */
    0x64, 0xb8, 0x7, 0xee, 0x78, 0xf1, 0xe3, 0xc7,
    0x8f, 0x18,

    /* U+00F2 "ò" */
    0x20, 0x20, 0x1, 0xc6, 0xd8, 0xf1, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+00F3 "ó" */
    0x8, 0x20, 0x1, 0xc6, 0xd8, 0xf1, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+00F4 "ô" */
    0x38, 0x50, 0x1, 0xc6, 0xd8, 0xf1, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+00F5 "õ" */
    0x64, 0xb0, 0x1, 0xc6, 0xd8, 0xf1, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+00F6 "ö" */
    0x6c, 0x0, 0x1, 0xc6, 0xd8, 0xf1, 0xe3, 0xc6,
    0xd8, 0xe0,

    /* U+00F7 "÷" */
    0x30, 0x60, 0x7, 0xf0, 0x6, 0xc, 0x0,

    /* U+00F8 "ø" */
    0x3c, 0xdb, 0x3e, 0xbd, 0x7c, 0xdb, 0x3c,

    /* U+00F9 "ù" */
    0x20, 0x20, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00FA "ú" */
    0x8, 0x20, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00FB "û" */
    0x38, 0xd8, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00FC "ü" */
    0x6c, 0x0, 0x6, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0x9d, 0xf8,

    /* U+00FD "ý" */
    0x8, 0x20, 0x6, 0x3c, 0x68, 0x9b, 0x36, 0x28,
    0x70, 0x41, 0x83, 0x1c, 0x0,

    /* U+00FE "þ" */
    0xc1, 0x83, 0x7, 0xec, 0xf8, 0xf1, 0xe3, 0xc7,
    0xdf, 0xf6, 0xc, 0x18, 0x0,

    /* U+00FF "ÿ" */
    0x3c, 0x0, 0x0, 0xc2, 0x66, 0x66, 0x24, 0x3c,
    0x1c, 0x18, 0x8, 0x10, 0x10, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 58, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 62, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 98, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 6, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 128, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 27, .adv_w = 193, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 166, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 54, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 54, .adv_w = 71, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 60, .adv_w = 71, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 66, .adv_w = 123, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 72, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 79, .adv_w = 61, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 81, .adv_w = 72, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 82, .adv_w = 61, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 87, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 128, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 115, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 124, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 61, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 61, .box_w = 2, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 183, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 190, .adv_w = 128, .box_w = 7, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 194, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 201, .adv_w = 102, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 201, .box_w = 11, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 226, .adv_w = 148, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 148, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 164, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 125, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 274, .adv_w = 119, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 163, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 168, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 68, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 67, .box_w = 5, .box_h = 13, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 314, .adv_w = 143, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 122, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 206, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 346, .adv_w = 175, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 176, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 379, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 394, .adv_w = 143, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 123, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 127, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 433, .adv_w = 140, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 212, .box_w = 13, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 462, .adv_w = 139, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 133, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 484, .adv_w = 129, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 493, .adv_w = 74, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 499, .adv_w = 87, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 74, .box_w = 4, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 512, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 519, .adv_w = 95, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 520, .adv_w = 72, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 522, .adv_w = 130, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 539, .adv_w = 111, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 81, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 571, .adv_w = 124, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 582, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 62, .box_w = 4, .box_h = 14, .ofs_x = -1, .ofs_y = -3},
    {.bitmap_index = 602, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 62, .box_w = 2, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 615, .adv_w = 214, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 627, .adv_w = 142, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 137, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 641, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 651, .adv_w = 139, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 661, .adv_w = 97, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 109, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 89, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 142, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 120, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 183, .box_w = 11, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 123, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 712, .adv_w = 120, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 722, .adv_w = 107, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 728, .adv_w = 86, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 736, .adv_w = 123, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 738, .adv_w = 86, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 746, .adv_w = 128, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 748, .adv_w = 58, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 749, .adv_w = 62, .box_w = 2, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 752, .adv_w = 128, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 769, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 773, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 123, .box_w = 1, .box_h = 14, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 784, .adv_w = 112, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 133, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 9},
    {.bitmap_index = 794, .adv_w = 186, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 808, .adv_w = 82, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 811, .adv_w = 124, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 817, .adv_w = 128, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 820, .adv_w = 72, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 821, .adv_w = 186, .box_w = 10, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 835, .adv_w = 112, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = 11},
    {.bitmap_index = 836, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 840, .adv_w = 128, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 81, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 851, .adv_w = 81, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 854, .adv_w = 72, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 856, .adv_w = 143, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 866, .adv_w = 147, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 878, .adv_w = 61, .box_w = 2, .box_h = 2, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 879, .adv_w = 48, .box_w = 3, .box_h = 4, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 881, .adv_w = 81, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 884, .adv_w = 85, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 887, .adv_w = 124, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 893, .adv_w = 176, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 907, .adv_w = 184, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 182, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 935, .adv_w = 102, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 943, .adv_w = 148, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 959, .adv_w = 148, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 148, .box_w = 9, .box_h = 14, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 991, .adv_w = 148, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1006, .adv_w = 148, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 148, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1036, .adv_w = 204, .box_w = 12, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1051, .adv_w = 142, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1063, .adv_w = 125, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1074, .adv_w = 125, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1085, .adv_w = 125, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1096, .adv_w = 125, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1106, .adv_w = 68, .box_w = 4, .box_h = 14, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 68, .box_w = 4, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1120, .adv_w = 68, .box_w = 6, .box_h = 14, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1131, .adv_w = 68, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1138, .adv_w = 164, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1150, .adv_w = 175, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1165, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1181, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1197, .adv_w = 176, .box_w = 9, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1213, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1228, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1243, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1248, .adv_w = 176, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1260, .adv_w = 166, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1274, .adv_w = 166, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1288, .adv_w = 166, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1302, .adv_w = 166, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1315, .adv_w = 133, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1328, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1337, .adv_w = 149, .box_w = 8, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1348, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1358, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1368, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1378, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1388, .adv_w = 130, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1398, .adv_w = 130, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1409, .adv_w = 199, .box_w = 11, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1420, .adv_w = 111, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1429, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1439, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1449, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1459, .adv_w = 129, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1469, .adv_w = 62, .box_w = 3, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1474, .adv_w = 62, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1480, .adv_w = 62, .box_w = 6, .box_h = 11, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 1489, .adv_w = 62, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1495, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1505, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1515, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1525, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1535, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1545, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1555, .adv_w = 137, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1565, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1572, .adv_w = 137, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1579, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1589, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1599, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1609, .adv_w = 142, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1619, .adv_w = 120, .box_w = 7, .box_h = 14, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 1632, .adv_w = 139, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1645, .adv_w = 120, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -3}
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
        .range_start = 160, .range_length = 96, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
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
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 2,
    .bpp = 1,
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
const lv_font_t ui_font_OpenSansSemiBold14 = {
#else
lv_font_t ui_font_OpenSansSemiBold14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_OPENSANSSEMIBOLD14*/

