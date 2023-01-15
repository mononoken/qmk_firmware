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
#include QMK_KEYBOARD_H

#include "keycodes.h"
#include "repeat.h"

#include "g/keymap_combo.h"

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: BASE (Modified RSTHD)
*/
    // [_BASE] = LAYOUT(
    //  KC_ESC,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_P,                                        KC_X,    KC_W,    KC_O,    KC_U,    KC_DOT,  xxxxxxx,
    //  KC_TAB,  KC_R,    KC_S,    KC_T,    KC_H,    KC_K,                                        KC_M,    KC_N,    KC_A,    KC_I,    xxxxxxx, xxxxxxx,
    //  KC_LSFT, KC_COMM, KC_V,    KC_G,    KC_D,    KC_B,    BASE,    xxxxxxx, xxxxxxx, xxxxxxx, KC_SLSH, KC_L,    KC_LPRN, KC_RPRN, KC_UNDS, KC_RSFT,
    //                             xxxxxxx, xxxxxxx, SHRT,    MT_SPC,  RSYM,    LSYM,    KC_E,    xxxxxxx, xxxxxxx, xxxxxxx
    // ),
    [_BASE] = LAYOUT(
     KC_ESC,  KC_J,    KC_C,    KC_Y,    KC_F,    KC_COLN,                                     KC_X,    KC_W,    KC_DOT,  KC_U,    KC_UNDS, xxxxxxx,
     KC_TAB,  KC_R,    KC_S,    KC_T,    KC_H,    KC_P,                                        KC_M,    KC_N,    KC_A,    KC_I,    KC_O,    REPEAT,
     KC_LSFT, KC_COMM, KC_V,    KC_G,    KC_D,    KC_B,    BASE,    xxxxxxx, xxxxxxx, xxxxxxx, KC_K,    KC_L,    KC_LPRN, KC_RPRN, KC_SLSH, KC_RSFT,
                                xxxxxxx, xxxxxxx, SHRT,    MT_SPC,  RSYM,    LSYM,    KC_E,    xxxxxxx, xxxxxxx, xxxxxxx
    ),

    [_NAVI] = LAYOUT(
     _______, xxxxxxx, KC_LEFT, KC_UP,   KC_RGHT, KC_HOME,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, xxxxxxx, CS_TAB,  DN_CTRL, C_TAB,   xxxxxxx,                                     xxxxxxx, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, xxxxxxx,
     xxxxxxx, KC_ENT,  xxxxxxx, KC_PGUP, KC_PGDN, KC_END,  _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_LSYM] = LAYOUT(
     _______, KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_BSLS,                                     xxxxxxx, OS_CTRL, OS_GUI,  OS_SHFT, OS_ALT,  xxxxxxx,
     xxxxxxx, xxxxxxx, KC_LABK, KC_RABK, KC_PERC, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_RSYM] = LAYOUT(
     _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, KC_HASH, KC_AT,   KC_CIRC, xxxxxxx, xxxxxxx,
     xxxxxxx, OS_ALT,  OS_SHFT, OS_GUI,  OS_CTRL, xxxxxxx,                                     KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, xxxxxxx, xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_AMPR, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_SHRT] = LAYOUT(
     xxxxxxx, G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B), _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, FUNC,    xxxxxxx, xxxxxxx
    ),
    [_NUM] = LAYOUT(
     xxxxxxx, xxxxxxx, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,                                     KC_X,    xxxxxxx, xxxxxxx, xxxxxxx, KC_DOT,  xxxxxxx,
     xxxxxxx, KC_6,    KC_4,    KC_0,    KC_2,    xxxxxxx,                                     xxxxxxx, KC_3,    KC_1,    KC_5,    KC_7,    xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_8,    xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, KC_SLSH, KC_9,    xxxxxxx, xxxxxxx, KC_UNDS, xxxxxxx,
                                xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, BASE,    xxxxxxx, xxxxxxx, xxxxxxx
    ),
    [_FUNC] = LAYOUT(
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
     xxxxxxx, KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,                                      KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,   xxxxxxx,
     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx
    ),
    // [_COLE] = LAYOUT(
    //  KC_ESC,  KC_LPRN, KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_RPRN, xxxxxxx,
    //  KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    xxxxxxx,
    //  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    //                             xxxxxxx, xxxxxxx, SHRT,    MT_SPC,  LSYM,    KC_UNDS, KC_MINS, xxxxxxx, xxxxxxx, KC_APP
    // ),

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

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up = KC_NO;

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

    // if (!process_leader(keycode, record)) {
    //     return false;
    // }
    // if (!process_num_word(keycode, record)) {
    //     return false;
    // }
    // if (!process_case_modes(keycode, record)) {
    //     return false;
    // }
    // if (!process_roll(keycode, record)) {
    //     return false;
    // }
    // if (!process_tap_hold(keycode, record)) {
    //     // Extra register here to allow fast rolls without waiting for tap hold,
    //     // (which will also overwrite this).
    //     if (record->event.pressed) {
    //         register_key_to_repeat(keycode);
    //     }
    //     return false;
    // }

    switch (keycode) {
        // case ESC_SYM:
        //     if (record->tap.count && record->event.pressed) {
        //         tap_escape();
        //         return false;
        //     }
        //     break;
        // case KC_CAPS:
        //     return process_caps(record->event.pressed);
        // case CLEAR:
        //     clear_oneshot_mods();
        //     if (get_oneshot_layer() != 0) {
        //         clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
        //     }
        //     stop_leading();
        //     layer_off(_NUM);
        //     layer_off(_SYM);
        //     layer_move(_BASE);
        //     return false;
        // case CANCEL:
        //     layer_off(_NUM);
        //     layer_off(_SYM);
        //     stop_leading();
        //     //disable_gaming();
        //     return false;
        // case TILD:
        //     register_key_to_repeat(TILD);
        //     return tap_undead_key(record->event.pressed, SE_TILD);
        // case CIRC:
        //     register_key_to_repeat(CIRC);
        //     return tap_undead_key(record->event.pressed, SE_CIRC);
        // case NUMWORD:
        //     process_num_word_activation(record);
        //     return false;
        // case CAPSWORD:
        //     if (record->event.pressed) {
        //         enable_caps_word();
        //     }
        //     return false;
        // case SAVE_VIM:
        //     if (record->event.pressed) {
        //         tap_escape();
        //         tap_code16(SE_COLN);
        //         tap_code(SE_W);
        //         tap_code(KC_ENT);
        //     }
        //     return false;
        // case VIM_SP:
        //     if (record->event.pressed) {
        //         tap_code16(C(SE_W));
        //         tap_code(SE_S);
        //     }
        //     return false;
        // case VIM_VS:
        //     if (record->event.pressed) {
        //         tap_code16(C(SE_W));
        //         tap_code(SE_V);
        //     }
        //     return false;
        // case NUM_G:
        //     if (record->event.pressed) {
        //         tap_code16(S(KC_G));
        //     }
        //     return false;
        // case COLN_SYM:
        //     if (record->tap.count && record->event.pressed) {
        //         tap16_repeatable(SE_COLN);
        //         return false;
        //     }
        //     break;
        // case KC_ENT:
        //     if (record->event.pressed) {
        //         if (IS_LAYER_ON(_NUM)) {
        //             tap16_repeatable(KC_PENT);
        //         } else {
        //             tap16_repeatable(KC_ENT);
        //         }
        //         disable_num_word();
        //     }
        //     return false;
        // case TG_SWE:
        //     if (record->event.pressed) {
        //         uint16_t swe_key = corresponding_swe_key(last_key());
        //         if (swe_key != KC_NO) {
        //             tap_code16(KC_BSPACE);
        //             tap_code16(swe_key);
        //         }
        //         layer_invert(_SWE);
        //     }
        //     return false;
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
        // case LEADER:
        //     start_leading();
        //     return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            // end_tap_hold();
            update_repeat_key(record);
            return false;
        // case REV_REP:
        //     update_reverse_repeat_key(record);
        //     return false;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // process_oneshot_pre(keycode, record);

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

    // process_oneshot_post(keycode, record);

    if (record->event.pressed) {
        last_key_down = keycode;
    } else {
        last_key_up = keycode;
    }

    return res;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    SEQ_ONE_KEY(KC_C) {
      register_code(KC_CAPS);
    }
  }
}
