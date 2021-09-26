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
#include "oneshot.h"
#include "layermodes.h"
#include "repeat.h"
#include "tap_hold.h"

#include "g/keymap_combo.h"

/*#ifdef ENCODER_ENABLE
#    include "encoder_utils.h"
#endif
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
    * Base Layer: Colemak DH
    */
    [_BASE] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_EQL,  BASE,
      KC_TAB,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_RCTL,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    _______, _______, NUMP,    KC_BSPC, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LSFT,
                                 KC_MPLY, NUMP,    LMOD,    KC_SPC,  NAV,     REPEAT,  KC_MINS, RMOD,    NUMP,    xxxxxxx
    ),
    [_NUM] = LAYOUT(
      _______, xxxxxxx, KC_PLUS, KC_ASTR, xxxxxxx, xxxxxxx,                                     xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, BASE,
      _______, KC_6,    KC_4,    KC_0,    KC_2,    KC_MINS,                                     xxxxxxx, KC_3,    KC_1,    KC_5,    KC_7,    _______,
      _______, xxxxxxx, xxxxxxx, xxxxxxx, KC_8,    xxxxxxx, _______, _______, _______, _______, xxxxxxx, KC_9,    KC_COMM, KC_DOT,  KC_SLSH, _______,
                                 _______, _______, _______, _______, _______, CANCEL,  _______, _______, _______, _______
    ),
    [_NAV] = LAYOUT(
      _______, _______, _______, KC_UP,   KC_PGUP, KC_HOME,                                     _______, _______, _______, _______, _______, BASE,
      _______, KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,                                      _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
      _______, C_HOME,  _______, C_HOME,  KC_PGDN, KC_END,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    // Important that the symbols on the base layer have the same positions as these symbols
    [_LMOD] = LAYOUT(
      _______, OPT,     C(KC_W), C(KC_A), _______, _______,                                     _______, KC_HASH, KC_DLR,  KC_AT,   KC_SCLN, BASE,
      _______, OS_ALT,  OS_SHFT, OS_CTRL, OS_GUI,  _______,                                     KC_DQT,  KC_QUOT, KC_LBRC, KC_RBRC, KC_COLN, _______,
      _______, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), C(KC_V), _______, _______, _______, _______, KC_CIRC, KC_AMPR, KC_LPRN, KC_RPRN, KC_QUES, _______,
                                 _______, _______, _______, _______, _______, CLEAR,   _______, FUN,     _______, _______
    ),
    [_RMOD] = LAYOUT(
      _______, KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, _______,                                     _______, _______, _______, _______, _______, BASE,
      _______, KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_GRV,                                      _______, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,  _______,
      _______, KC_BSLS, KC_LABK, KC_RABK, KC_UNDS, KC_PERC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, FUN,     _______, _______, CLEAR,   _______, _______, _______, _______
    ),
    [_FUN] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, BASE,
      _______, KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,                                      KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,   _______,
      _______, _______, _______, _______, KC_F8,   _______, _______, _______, _______, _______, _______, KC_F9,   _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_OPT] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, BASE,
      _______, _______, _______, KC_CAPS, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    [_NUMP] = LAYOUT(
      _______, KC_BSPC, KC_7,    KC_8,    KC_9,    KC_PLUS,                                     KC_PLUS, KC_7,    KC_8,    KC_9,    KC_BSPC, BASE,
      _______, KC_ASTR, KC_4,    KC_5,    KC_6,    KC_MINS,                                     KC_MINS, KC_4,    KC_5,    KC_6,    KC_ASTR, _______,
      _______, KC_SLSH, KC_1,    KC_2,    KC_3,    KC_EQL,  _______, _______, _______, _______, KC_EQL,  KC_1,    KC_2,    KC_3,    KC_SLSH, _______,
                                 _______, KC_0,    KC_DOT,  _______, BASE,    BASE,    _______, KC_0,    KC_DOT,  _______
    ),
    /*
    [_BLANK] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    */
};

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

void tap_space_shift(uint16_t key, bool key_down) {
    if (key_down) {
        tap_code16(key);
        tap_code(KC_SPC);
        set_oneshot_mods(MOD_BIT(KC_LSFT));
    }
}

void double_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_tap_space(uint16_t keycode) {
    tap_code16(KC_SPC);
    double_tap(keycode);
    tap_code16(KC_SPC);
}

// Combos

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Home-row and other tight combos
        case tab:
        case escape:
        case enter:
            return COMBO_TERM;
        // Regular combos, slightly relaxed
        default:
            return COMBO_TERM + 25;
    }
}

bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    switch (index) {
        case del:
        case backsp:
        case wbacksp:
        case capslock:
        case numlock:
        case num:
            return false;
        default:
            return true;
    }
}

// Tapping terms

#ifdef TAPPING_TERM_PER_KEY

#define THUMB_TERM 20
#define INDEX_TERM -20
#define MIDDLE_TERM 0
#define RING_TERM 80
#define PINKY_TERM 180

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case MT_SPC:
            return TAPPING_TERM + THUMB_TERM;
        case DN_CTRL:
            return TAPPING_TERM + MIDDLE_TERM;
        default:
            return TAPPING_TERM;
    }
}
#endif

// Tap hold

uint16_t tap_hold_timeout(uint16_t keycode) {
    switch (keycode) {
        // Thumb
        case KC_MINS:
            return 120;
        // Pinky
        case KC_A:
        case KC_Q:
        case KC_Z:
        case KC_EQL:
        case KC_O:
        case KC_SLSH:
        case KC_6:
        case KC_7:
            return 135;
        // Ring
        case KC_X:
        case KC_R:
        case KC_W:
        case KC_DOT:
        case KC_I:
        case KC_Y:
        case KC_4:
        case KC_5:
            return 105;
        // Middle
        case KC_C:
        case KC_S:
        case KC_F:
        case KC_COMM:
        case KC_E:
        case KC_U:
        case KC_0:
        case KC_1:
            return 100;
        // Index
        default:
            return 100;
    }
}

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case LMOD:
        case RMOD:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
        case LMOD:
        case RMOD: 
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_GUI:
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

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_num_word(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            layer_move(_BASE);
            return false;
        case TO_NUM:
            layer_on(_NUM);
            return false;
        case NUMWORD:
            process_num_word_activation(record);
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(KC_G));
            }
            return false;
        case CANCEL:
            layer_off(_NUM);
            layer_off(_LMOD);
            layer_off(_RMOD);
            return false;
        case KC_TAB:
            if (record->event.pressed) {
                switch (get_highest_layer(layer_state)) {
                    case _LMOD:
                    case _RMOD:
                        tap16_repeatable(C(S(KC_TAB)));
                        break;
                    case _NAV:
                        tap16_repeatable(C(KC_TAB));
                        break;
                    default:
                        tap16_repeatable(KC_TAB);
                }
            }
            return false;
        case KC_ENT:
            if (record->event.pressed) {
                switch (get_highest_layer(layer_state)) {
                    case _NUM:
                        tap16_repeatable(KC_PENT);
                        break;
                    default:
                        tap16_repeatable(KC_ENT);
                }
            }
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            update_repeat_key(record);
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
            return false;
        case REP_A:
            if (record->event.pressed) {
                tap_code16(last_key());
                tap_code16(KC_A);
            }
            return false;
    }

    return true;
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_oneshot_pre(keycode, record);

    bool res = _process_record_user(keycode, record);

    // If `false` was returned, then we did something special and should register that manually.
    // Otherwise register it here by default.
    // Skip Space to not interfere with NAV toggling.
    if (res && record->event.pressed && keycode != KC_SPC) {
        register_key_to_repeat(keycode);
    }

    process_oneshot_post(keycode, record);

    return res;
}