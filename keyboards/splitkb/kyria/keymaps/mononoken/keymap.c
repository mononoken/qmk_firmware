/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include <stdint.h>
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "leader.h"

#include "g/keymap_combo.h"

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE (Modified RSTHD)
*/
    [_BASE] = LAYOUT(
     KC_ESC,  KC_UNDS, KC_C,    KC_F,    KC_K,    KC_B,                                        KC_X,    KC_J,    KC_O,    KC_U,    KC_MINS, xxxxxxx,
     KC_TAB,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,                                        KC_M,    KC_N,    KC_A,    KC_I,    REPEAT,  KC_COLN,
     KC_LSFT, KC_V,    KC_W,    KC_G,    KC_D,    KC_LPRN, CLEAR,   xxxxxxx, KC_PSCR, CLEAR,   KC_SLSH, KC_L,    KC_COMM, KC_DOT,  KC_Y,    KC_RSFT,
                                xxxxxxx, CODE,    SHRT,    MT_SPC,  L_SYMB,  R_SYMB,  KC_E,    OMOD,    KC_MPLY, KC_MUTE
    ),
    [_NUM] = LAYOUT(
     xxxxxxx, _______, KC_PLUS, KC_ASTR, _______, xxxxxxx,                                     _______, _______, REPEAT,  xxxxxxx, _______, _______,
     xxxxxxx, KC_6,    KC_4,    KC_0,    KC_2,    _______,                                     _______, KC_3,    KC_1,    KC_5,    KC_7,    xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, NUM_G,   KC_8,    _______, _______, _______, _______, _______, _______, KC_9,    _______, _______, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NAVI] = LAYOUT(
     _______, F_SCRN,  CS_TAB,  KC_UP,   C_TAB,   KC_HOME,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, KC_END,  KC_LEFT, DN_CTRL, KC_RGHT, KC_END,                                      xxxxxxx, KC_H,    KC_J,    KC_K,    KC_L,    xxxxxxx,
     xxxxxxx, LST_TAB, M_SCRN,  KC_PGUP, KC_PGDN, xxxxxxx, _______, xxxxxxx, _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, _______, _______, _______, WNAV,    _______, _______, _______
    ),
    [_WNAV] = LAYOUT(
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, xxxxxxx, S_TAB,   KC_LGUI, KC_TAB,  xxxxxxx,                                     xxxxxxx, L_HALF,  F_SCRN,  M_SCRN,  R_HALF,  xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_SYMB] = LAYOUT(
     _______, KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,                                     xxxxxxx, KC_HASH, KC_AT,   KC_CIRC, xxxxxxx, xxxxxxx,
     xxxxxxx, KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,                                     KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_DLR,  xxxxxxx,
     xxxxxxx, xxxxxxx, KC_LABK, KC_RABK, KC_PERC, KC_RPRN, _______, xxxxxxx, _______, _______, xxxxxxx, KC_AMPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______
    ),
    [_LSYM] = LAYOUT(
     _______, KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, _______,                                     xxxxxxx, xxxxxxx, _______, xxxxxxx, _______, xxxxxxx,
     _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,                                     xxxxxxx, KC_3,    KC_1,    KC_5,    KC_7,    _______,
     _______, _______, KC_LABK, KC_RABK, KC_PERC, KC_RPRN, _______, xxxxxxx, _______, _______, xxxxxxx, KC_9,    _______, _______, _______, _______,
                                xxxxxxx, _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______
    ),
    [_RSYM] = LAYOUT(
     _______, xxxxxxx, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,                                     xxxxxxx, KC_HASH, KC_AT,   KC_CIRC, xxxxxxx, xxxxxxx,
     _______, KC_6,    KC_4,    KC_0,    KC_2,    xxxxxxx,                                     KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_DLR,  xxxxxxx,
     _______, _______, xxxxxxx, xxxxxxx, KC_8,    KC_RPRN, _______, xxxxxxx, _______, _______, xxxxxxx, KC_AMPR, xxxxxxx, xxxxxxx, xxxxxxx, _______,
                                xxxxxxx, _______, _______, _______, _______, _______, xxxxxxx, _______, _______, _______
    ),
    [_OMOD] = LAYOUT(
     _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, OS_ALT,  OS_SHFT, OS_GUI,  OS_CTRL, xxxxxxx,                                     xxxxxxx, OS_CTRL, OS_GUI,  OS_SHFT, OS_ALT,  xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, xxxxxxx, _______, _______, xxxxxxx, _______, _______, _______
    ),
    [_SHRT] = LAYOUT(
     xxxxxxx, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), _______, xxxxxxx, _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, xxxxxxx, _______, _______, C(KC_E), FUNC,    _______, _______
    ),
    [_FUNC] = LAYOUT(
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,                                      KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,   xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   xxxxxxx, _______, xxxxxxx, _______, _______, xxxxxxx, KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, xxxxxxx, _______, _______, xxxxxxx, _______, _______, _______
    ),
    [_CODE] = LAYOUT(
     xxxxxxx, GT_SYM,  GT_REF,  PK_DEF,  F_INFIL, GO_BRKT,                                     xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, GT_SYMW, F_ALREF, GT_DEF,  CMD_PAL, QK_OPEN,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, xxxxxxx, SW_HIER, GO_LEDT, GO_BACK, TG_MINM, _______, xxxxxxx, _______, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, _______, _______, _______, KC_LGUI, xxxxxxx, xxxxxxx, KC_RGUI, _______, _______
    ),
    [_GAME] = LAYOUT(
     KC_ESC,  KC_Q,    KC_C,    KC_F,    KC_K,    KC_B,                                        KC_X,    KC_J,    KC_O,    KC_U,    KC_MINS, KC_BSPC,
     KC_TAB,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,                                        KC_M,    KC_N,    KC_A,    KC_I,    REPEAT,  KC_ENT,
     KC_LSFT, KC_V,    KC_W,    KC_G,    KC_D,    KC_Z,    KC_LPRN, KC_BSLS, _______, _______, KC_SLSH, KC_L,    KC_COMM, KC_DOT,  KC_Y,    KC_RSFT,
                                xxxxxxx, KC_LOPT, KC_LCTL, KC_SPC,  KC_SLSH, xxxxxxx, KC_E,    _______, _______, _______
    ),
    [_QWER] = LAYOUT(
     KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
     KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    xxxxxxx, xxxxxxx, CLEAR,   _______, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                                xxxxxxx, KC_LOPT, KC_LCTL, KC_SPC,  xxxxxxx, xxxxxxx, xxxxxxx, _______, _______, _______
    ),
    // TEMPLATE
    // [_XXXX] = LAYOUT(
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    //  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
    //                             xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
    // ),

// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _BASE:
                oled_write_P(PSTR("BASE\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */


#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_BRMU);
        } else {
            tap_code(KC_BRMD);
        }
    } else if (index == 1) {
        // Volume control
                if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up = KC_NO;

// bool tap_undead_key(bool key_down, uint16_t code) {
//     if (key_down) {
//         tap_code16(code);
//         tap_code16(KC_SPACE);
//     }
//     return false;
// }

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

// void enable_gaming(void) {
//     /* autoshift_disable(); */
//     /* layer_on(_GAME); */
// }
// void disable_gaming(void) {
//     /* autoshift_enable(); */
//     /* layer_off(_GAME); */
//     /* layer_off(_GAME2); */
// }

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // // Home-row and other tight combos
        case ctrl_combo_l:
        // case escape_sym:
        // case tab_mod:
        case del:
        case dquo:
        // case coln_sym:
        case ctrl_combo_r:
        case quot:
        case ent:
        // case vsp:
        case gui_combo_l:
        case gui_combo_r:
            return COMBO_TERM;
        // // Vertical combos, very relaxed
        // case small_left_arrow:
        // case lt_eq:
        // case large_right_arrow:
        // case small_right_arrow:
        // case pipe_to:
        // case sp:
        // case gt_eq:
        //     return COMBO_TERM + 55;
        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 25;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case del:
        case backsp:
        case q_comb:
        case qu_comb:
        case z_comb:
        case num:
        // case comb_perc:
        // case comb_grv:
        // case comb_hash:
        // case comb_pipe:
        // case comb_ques:
        // case comb_exlm:
        // case comb_ampr:
        // case comb_labk:
        // case comb_rabk:
        // case comb_lcbr:
        // case comb_lbrc:
        // case comb_at:
        case comb_0:
        case eql:
        case quot:
        case dquo:
            return false;
        default:
            return true;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    /* Disable all combos except specified ones on layer `_GAME` */
    if (layer_state_is(_GAME)) {
        switch (combo_index) {
            // FIX_ME: This does not turn combo on in the layer as expected.
            // case num:
            //     return true;
            default:
                return false;
            }
    }
    return true;
}

// Tapping terms

#ifdef TAPPING_TERM_PER_KEY

#define THUMB_TERM 40
// #define INDEX_TERM -20
// #define MIDDLE_TERM 0
// #define RING_TERM 80
// #define PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_SPC:
            return TAPPING_TERM + THUMB_TERM;
        // case DN_CTRL:
        //     return TAPPING_TERM + MIDDLE_TERM;
        default:
            return TAPPING_TERM;
    }
}
#endif

// Case modes

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case REPEAT:
        // case REV_REP:
            return false;
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        // case KC_ARNG:
        // case KC_ADIA:
        // case KC_ODIA:
        case QU:
        // case SC:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

// void triple_tap(uint16_t keycode) {
//     tap_code16(keycode);
//     tap_code16(keycode);
//     tap_code16(keycode);
// }

// void double_parens_left(uint16_t left, uint16_t right) {
//     tap_code16(left);
//     tap_code16(right);
//     tap_code16(KC_LEFT);
// }

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        // case L_CLEAR:
        //     return true;
        // case R_CLEAR:
        //     return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        // case L_CLEAR:
        // case R_CLEAR:
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
        // case TAB_MOD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_pre(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot_pre(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot_pre(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_post(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot_post(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot_post(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot_post(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
}

// Tap hold

bool tap_hold(uint16_t keycode) {
    // Turn off tap hold on _GAME
    if (layer_state_is(_GAME)) {
        return false;
    } else if (layer_state_is(_NAVI)) {
        return false; 
    } else {
        switch (keycode) {
            // case SE_DQUO:
            // case SE_LABK:
            // case SE_RABK:
            case KC_DOT:
            case KC_COMM:
            case KC_COLN:
            case KC_SLSH:
            case KC_TAB: // Allows for S(TAB) which reverse tabs in most programs.
            case KC_LPRN:
            // case SE_PERC:
            // case GRV:
            // case SE_AT:
            // case SE_PIPE:
            // case SE_EXLM:
            // case SE_AMPR:
            // case SE_QUES:
            // case SE_HASH:
            // case SE_LPRN:
            // case SE_LCBR:
            // case SE_LBRC:
            // case SE_EQL:
            case KC_UNDS:
            // case SE_0:
            // case G(SE_0):
            // case G(SE_1):
            // case G(SE_2):
            // case G(SE_3):
            // case G(SE_4):
            // case G(SE_5):
            // case G(SE_6):
            // case G(SE_7):
            // case G(SE_8):
            // case G(SE_9):
            // case G(SE_K):
            // case G(SE_J):
            // case G(SE_W):
            // case G(SE_E):
            // case G(SE_R):
            // case G(SE_C):
            case KC_A ... KC_Z:
            // case SE_ARNG:
            // case SE_ADIA:
            // case SE_ODIA:
            case QU:
            // case SC:
            // case E_ACUT:
            // case CLOSE_WIN:
            // case C(SE_A):
            // case C(SE_C):
            // case C(SE_W):
            // case C(SE_F):
            // case C(SE_E):
            // case C(SE_R):
            // case C(SE_S):
            // case C(SE_T):
            // case C(SE_H):
            // case C(SE_X):
            // case C(SE_V):
            // case C(SE_G):
            // case C(SE_D):
            // case C(SE_B):
                return true;
            default:
                return false;
        }
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case QU:
            send_string("qu");
            return;
        case KC_Q:
        case KC_Z:
            if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
                tap16_repeatable(C(keycode));
            } else {
                tap16_repeatable(keycode);
            }
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case KC_DOT:
            tap_code16(KC_EXLM);
            return;
        case KC_SLSH:
            tap_code16(KC_BSLS);
            return;
        case KC_COMM:
            tap_code16(KC_QUES);
            return;
        case QU:
            send_string("Qu");
            return;
        case KC_UNDS:
            tap_code16(KC_MINS);
            return;
        case KC_COLN:
            tap_code16(KC_SCLN);
            return;
        case KC_LPRN:
            tap_code16(KC_RPRN);
            return;
        case KC_Q:
        case KC_Z:
            if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
                tap16_repeatable(S(C(keycode)));
            } else {
                tap16_repeatable(S(keycode));
            }
            return;
        default:
            tap16_repeatable(S(keycode));
    }
}

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // // Extra
        // case CLOSE_WIN:
        //     return 160;
        // // Thumb
        // case KC_E:
        //     return 120;
        // // Pinky
        // case KC_R:
        // case SE_COMM:
        // case SE_UNDS:
        // //case UNDS_ODIA:
        // case SE_6:
        // case G(SE_6):
        // case SE_7:
        // case G(SE_7):
        // case C(SE_R):
        // case C(SE_X):
            // return 135;
        // // Ring
        // case SE_J:
        // case SE_C:
        // case SE_S:
        // case SE_V:
        // case SE_U:
        // case SE_DOT:
        // case SE_I:
        // case SE_RPRN:
        // //case RPRN_ADIA:
        // case SE_Q:
        // case QU:
        // case SE_4:
        // case G(SE_4):
        // case SE_5:
        // case G(SE_5):
        // case G(SE_J):
        // case G(SE_R):
        // case C(SE_A):
        // case C(SE_C):
        // case C(SE_S):
        // case C(SE_V):
            // return 105;
        // // Middle
        // case SE_Y:
        // case SE_T:
        // case SE_G:
        // case SE_O:
        // case SE_A:
        // case SE_LPRN:
        // //case LPRN_ARNG:
        // case SE_Z:
        // case SE_0:
        // case G(SE_0):
        // case SE_1:
        // case G(SE_1):
        // case C(SE_W):
        // case C(SE_T):
        // case C(SE_G):
        //     return 100;
        // // Slow index
        // case SE_P:
        // case SE_X:
        // case C(SE_E):
        //     return 105;
        // Index
        default:
            return TAPPING_TERM;
    }
}

// https://github.com/andrewjrae/kyria-keymap#userspace-leader-sequences
void *leader_toggles_func(uint16_t keycode) {
    switch (keycode) {
        case KC_N:
            layer_invert(_NUM);
            return NULL;
        case KC_S:
            layer_invert(_SYMB);
            return NULL;
        // case KC_C:
        //     swap_caps_esc();
        //     return NULL;
        case KC_G:
            layer_invert(_GAME);
            return NULL;
        case KC_Q:
            layer_invert(_QWER);
            return NULL;
        default:
            return NULL;
    }
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T:
            return leader_toggles_func;
        case KC_C:
            tap_code(KC_CAPS);
            // tap_caps_lock();
            return NULL;
        default:
            return NULL;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    // #ifdef CONSOLE_ENABLE
    //     if (record->event.pressed) {
    //         uprintf("0x%04X,%u,%u,%u,%b,0x%02X,0x%02X,%u\n",
    //              keycode,
    //              record->event.key.row,
    //              record->event.key.col,
    //              get_highest_layer(layer_state),
    //              record->event.pressed,
    //              get_mods(),
    //              get_oneshot_mods(),
    //              record->tap.count
    //              );
    //     }
    // #endif

    if (!process_leader(keycode, record)) {
        return false;
    }
    if (!process_num_word(keycode, record)) {
        return false;
    }
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    // if (!process_roll(keycode, record)) {
    //     return false;
    // }
    if (!process_tap_hold(keycode, record)) {
        // Extra register here to allow fast rolls without waiting for tap hold,
        // (which will also overwrite this).
        if (record->event.pressed) {
            register_key_to_repeat(keycode);
        }
        return false;
    }

    switch (keycode) {
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            stop_leading();
            layer_off(_NUM);
            layer_off(_SYMB);
            layer_move(_BASE);
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case CAPSWORD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
        case SAVE_VIM:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code16(KC_S);
                tap_code16(KC_P);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code16(KC_V);
                tap_code16(KC_S);
                tap_code(KC_ENT);
            }
            return false;
        case CLOSE_WIN:
            if (record->event.pressed) {
                tap_code16(KC_ESC);
                tap_code16(KC_COLN);
                tap_code16(KC_Q);
                tap_code16(KC_ENT);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(KC_G));
            }
            return false;
        case KC_ENT:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_NUM)) {
                    tap16_repeatable(KC_PENT);
                } else {
                    tap16_repeatable(KC_ENT);
                }
                disable_num_word();
            }
            return false;
        // case WIN_ALT:
        //     // Always start by sending Alt Tab to goto the next window with only a combo tap.
        //     // We can then do Tab/S-Tab to continue moving around the windows if we want to.
        //     if (record->event.pressed) {
        //         register_code(KC_LALT);
        //         tap_code16(KC_TAB);
        //         layer_on(_WIN);
        //     } else {
        //         layer_off(_WIN);
        //         unregister_code(KC_LALT);
        //     }
        //     return false;
        case LEADER:
            start_leading();
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case GO_LEDT:
            if (record->event.pressed) {
              SEND_STRING(SS_LGUI("kq"));
            }
            return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register keyrepeat here by default.
    bool res = _process_record_user(keycode, record);

    // Space needs some special handling to not interfere with NAV toggling.
    // Maybe there's a more general way to do this, but I dunno.
    if (keycode == MT_SPC) {
        if (!record->event.pressed && last_key_down == MT_SPC) {
            register_key_to_repeat(KC_SPC);
        }
    } else if (res && record->event.pressed) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    if (record->event.pressed) {
        last_key_down = keycode;
    } else {
        last_key_up = keycode;
    }

    return res;
}

void matrix_scan_user(void) {
  tap_hold_matrix_scan();
}
