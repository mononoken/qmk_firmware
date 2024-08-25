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
#include "status.h"
#include "oneshot.h"
#include "casemodes.h"
#include "layermodes.h"
#include "tap_hold.h"
#include "repeat.h"
#include "roll.h"
#include "leader.h"

#include "g/keymap_combo.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * Base Layer: Modified RSTHD/treeman
     */
    [_BASE] = LAYOUT(
      KC_UNDS, KC_C,    KC_F,    KC_K,    KC_B,         KC_X,    KC_J,    KC_O,    KC_U,    KC_RPRN,
      KC_R,    KC_S,    KC_T,    KC_H,    KC_P,         KC_M,    KC_N,    KC_A,    KC_I,    REPEAT,
      KC_V,    KC_W,    KC_G,    KC_D,    KC_LPRN,      KC_SLSH, KC_L,    KC_COMM, KC_DOT,  KC_Y,
                                 LSYM,    MT_SPC,       KC_E,    RSYM
    ),
    [_NUM]  = LAYOUT(
      _______, KC_PLUS, KC_ASTR, KC_K,    xxxxxxx,      _______, KC_J,    AT_U,    REPEAT,  _______,
      KC_6,    KC_4,    KC_0,    KC_2,    _______,      KC_BSLS, KC_3,    KC_1,    KC_5,    KC_7,
      KC_PERC, xxxxxxx, NUM_G,   KC_8,    _______,      _______, KC_9,    KC_COMM, KC_DOT,  KC_PERC,
                                 _______, _______,      CANCEL,  _______
    ),
    // Important that the symbols on the base layer have the same positions as these symbols
    [_SYM]  = LAYOUT(
      KC_UNDS, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,      xxxxxxx, KC_HASH, KC_AT,   REPEAT,  KC_RPRN,
      CIRC,    KC_LCBR, KC_RCBR, TILD,    xxxxxxx,      KC_BSLS, GRV,     KC_LBRC, KC_RBRC, KC_DLR,
      KC_PERC, KC_LABK, KC_RABK, KC_PIPE, KC_LPRN,      KC_SLSH, KC_AMPR, KC_COMM, KC_DOT,  KC_PERC,
                                 _______, _______,      CANCEL,  _______
    ),
    [_LSYM]  = LAYOUT(
      KC_UNDS, KC_PLUS, KC_ASTR, KC_EXLM, xxxxxxx,      KC_X,    KC_J,    AT_U,    REPEAT,  KC_RPRN,
      CIRC,    KC_LCBR, KC_RCBR, TILD,    xxxxxxx,      KC_BSLS, KC_3,    KC_1,    KC_5,    KC_7,
      KC_PERC, KC_LABK, KC_RABK, KC_PIPE, KC_LPRN,      KC_SLSH, KC_9,    KC_COMM, KC_DOT,  KC_PERC,
                                 _______, _______,      CANCEL,  NUM
    ),
    [_RSYM]  = LAYOUT(
      _______, KC_PLUS, KC_ASTR, KC_K,    xxxxxxx,      xxxxxxx, KC_HASH, KC_AT,   REPEAT,  KC_RPRN,
      KC_6,    KC_4,    KC_0,    KC_2,    KC_MINS,      KC_BSLS, GRV,     KC_LBRC, KC_RBRC, KC_DLR,
      KC_PERC, xxxxxxx, NUM_G,   KC_8,    KC_LPRN,      KC_SLSH, KC_AMPR, KC_COMM, KC_DOT,  KC_PERC,
                                 NUM,     _______,      CANCEL,  _______
    ),
    [_NAV]  = LAYOUT(
      xxxxxxx, KC_LEFT, KC_UP,   KC_RGHT, KC_HOME,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      SG_T,    SC_TAB,  DN_CTRL, C_TAB,   xxxxxxx,      xxxxxxx, KC_H,    KC_J,    KC_K,    KC_L,
      xxxxxxx, xxxxxxx, KC_PGUP, KC_PGDN, KC_END,       xxxxxxx, YABA_LT, YABA_UP, YABA_DN, YABA_RT,
                                 _______, _______,      WNAV,    _______
    ),
    [_WNAV] = LAYOUT(
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      YABA_FT, xxxxxxx, YABA_BL, xxxxxxx, YABA_MX,
      A(KC_6), A(KC_4), A(KC_0), A(KC_2), A(KC_K),      xxxxxxx, A(KC_3), A(KC_1), A(KC_5), A(KC_7),
      xxxxxxx, xxxxxxx, xxxxxxx, A(KC_8), xxxxxxx,      xxxxxxx, TMUX_LT, TMUX_DN, TMUX_UP, TMUX_RT,
                                 _______, _______,      _______, _______
    ),
    [_MOD]  = LAYOUT(
      _______, KC_PLUS, KC_ASTR, KC_K,    xxxxxxx,      _______, _______, _______, _______, _______,
      KC_6,    KC_4,    KC_0,    KC_2,    KC_MINS,      _______, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,
      KC_PERC, xxxxxxx, NUM_G,   KC_8,    KC_LPRN,      _______, _______, _______, _______, MY_RALT,
                                 _______, _______,      CANCEL,  _______
    ),
    [_SHRT] = LAYOUT(
      G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),      xxxxxxx, OS_GUI,  OS_CTRL, OS_SHFT, OS_ALT,
      G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B),      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, MY_RALT,
                                 _______, G(KC_SPC),    CANCEL,  _______
    ),
    [_FUN]  = LAYOUT(
      xxxxxxx, KC_VOLD, KC_VOLU, xxxxxxx, xxxxxxx,      xxxxxxx, KC_MPRV, KC_MPLY, KC_MUTE, KC_MNXT,
      KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,       KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
      xxxxxxx, KC_BRMU, KC_BRMD, KC_F8,   xxxxxxx,      KC_F13,  KC_F9,   xxxxxxx, xxxxxxx, MY_RALT,
                                 _______, _______,      CANCEL,  _______
    )
};

// Keyboard utils

static uint16_t last_key_down = KC_NO;
static uint16_t last_key_up   = KC_NO;

static bool linux_mode = true;
bool in_linux(void) {
    return linux_mode;
}

static bool swap_caps_escape = false;
bool is_caps_swapped(void) {
    return swap_caps_escape;
}

bool tap_undead_key(bool key_down, uint16_t code) {
    if (key_down) {
        tap_code16(code);
        // tap_code16(KC_SPACE);
    }
    return false;
}

void tap16_repeatable(uint16_t keycode) {
    tap_code16(keycode);
    register_key_to_repeat(keycode);
}

// swap_caps_esc(void) {
//     swap_caps_escape = !swap_caps_escape;
// #ifdef OLED_DRIVER_ENABLE
//     oled_on();
// #endif
// }

void tg_nix(void) {
    linux_mode = !linux_mode;
#ifdef OLED_DRIVER_ENABLE
    oled_on();
#endif
}

bool process_caps(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_ESC);
        } else {
            unregister_code(KC_ESC);
        }
        return false;
    }
    return true;
}

bool process_escape(bool key_down) {
    if (swap_caps_escape) {
        if (key_down) {
            register_code(KC_CAPS);
        } else {
            unregister_code(KC_CAPS);
        }
        return false;
    }
    return true;
}

void tap_escape(void) {
    tap_code(swap_caps_escape ? KC_CAPS : KC_ESC);
}

void tap_caps_lock(void) {
    tap_code(swap_caps_escape ? KC_ESC : KC_CAPS);
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
        // Tighter combos
        case ent:
            return COMBO_TERM - 20;
        // Home-row and other tight combos
        // case ctrl_combo_l:
        case escape_sym:
        case tab:
        // case del:
        // case dquo:
        case coln_sym:
        case scln_sym:
        // case ctrl_combo_r:
        // case quot:
        // case vsp:
        // case gui_combo_l:
        // case gui_combo_r:
            return COMBO_TERM;
        // Vertical combos, very relaxed
        // case small_left_arrow:
        // case lt_eq:
        // case large_right_arrow:
        // case small_right_arrow:
        // case pipe_to:
        // case sp:
        // case gt_eq:
            return COMBO_TERM + 55;
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
        case numword:
        // case rev_rep:
        case eql:
        case gui_combo_l:
        case gui_combo_r:
        case ctrl_combo_l:
        case ctrl_combo_r:
        case shift_combo_l:
        case shift_combo_r:
        case shrt_l:
        case shrt_r:
        case close_win:
        case escape_sym:
        case tab:
        case coln_sym:
        case scln_sym:
        case dquo:
        case lalt:
            return false;
        default:
            return true;
    }
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo, uint16_t keycode, keyrecord_t *record) {
    // FIXME this doesn't seem to work?
    return true;
}

// Tapping terms

#ifdef TAPPING_TERM_PER_KEY

#    define THUMB_TERM 80 // 20
#    define INDEX_TERM -20
#    define MIDDLE_TERM 0
#    define RING_TERM 80
#    define PINKY_TERM 180

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

// Case modes

bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case REPEAT:
        case REV_REP:
            return false;
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case QU:
        case SC:
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

void triple_tap(uint16_t keycode) {
    tap_code16(keycode);
    tap_code16(keycode);
    tap_code16(keycode);
}

void double_parens_left(uint16_t left, uint16_t right) {
    tap_code16(left);
    tap_code16(right);
    tap_code16(KC_LEFT);
}

// One-shot mods

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        case CLEAR:
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
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

void process_oneshot_pre(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_pre(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_pre(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_pre(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_post(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_post(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot_post(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot_post(&os_gui_state, KC_LGUI, OS_GUI, keycode, record);
}

void process_oneshot_key(uint16_t keycode, keyrecord_t *record) {
    update_oneshot_pre(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot_post(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
}

// Tap hold

bool tap_hold(uint16_t keycode) {
    // Prvent tap hold on layers except for whitelisted keys
    if (layer_state_is(_NAV)) {
        switch (keycode) {
          case KC_H:
          case KC_L:
          case A(KC_H):
          case A(KC_J):
          case A(KC_K):
          case A(KC_L):
              return true;
          default:
              return false;
        }
    } else if (layer_state_is(_WNAV)) {
        switch (keycode) {
          case A(KC_0):
          case A(KC_1):
          case A(KC_2):
          case A(KC_3):
          case A(KC_4):
          case A(KC_5):
          case A(KC_6):
          case A(KC_7):
          case A(KC_8):
          case A(KC_H):
          case A(KC_J):
          case A(KC_K):
          case A(KC_L):
              return true;
          default:
              return false;
        }
    } else {
        switch (keycode) {
            case KC_DQUO:
            case KC_LABK:
            case KC_RABK:
            case KC_COMM:
            case KC_DOT:
            case KC_PERC:
            case GRV:
            case KC_AT:
            case KC_PIPE:
            case KC_EXLM:
            case KC_AMPR:
            case KC_QUES:
            case KC_LPRN:
            case KC_LCBR:
            case KC_LBRC:
            case KC_EQL:
            case KC_UNDS:
            case KC_DLR:
            case KC_HASH:
            case A(KC_0):
            case A(KC_1):
            case A(KC_2):
            case A(KC_3):
            case A(KC_4):
            case A(KC_5):
            case A(KC_6):
            case A(KC_7):
            case A(KC_8):
            case A(KC_9):
            case A(KC_K):
            case A(KC_J):
            case A(KC_W):
            case A(KC_E):
            case A(KC_R):
            case A(KC_C):
            case KC_A ... KC_Z:
            case QU:
            case SC:
            case CLOSE_WIN:
            case KC_TAB: // Allows for S(TAB) which reverse tabs in most programs.
            // case C(KC_A):
            // case C(KC_C):
            // case C(KC_W):
            // case C(KC_F):
            // case C(KC_E):
            // case C(KC_R):
            // case C(KC_S):
            // case C(KC_T):
            // case C(KC_H):
            // case C(KC_X):
            // case C(KC_V):
            // case C(KC_G):
            // case C(KC_D):
            // case C(KC_B):
                return true;
            case KC_0:
            case KC_1:
            case KC_2:
            case KC_3:
            case KC_4:
            case KC_5:
            case KC_6:
            case KC_7:
            case KC_8:
            case KC_9:
                if (layer_state_is(_NUM)) {
                    return true;
                } else {
                    return false;
                }
            default:
                return false;
        }
    }
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
        case GRV:
            register_key_to_repeat(keycode);
            tap_undead_key(true, KC_GRV);
            return;
        case QU:
            send_string("qu");
            return;
        case SC:
            send_string("sc");
            return;
        case KC_Q:
        case KC_Z:
            if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
                tap16_repeatable(C(keycode));
            } else {
                tap16_repeatable(keycode);
            }
            return;
        case CLOSE_WIN:
            // tap_code16(G(KC_W));
            // tap_code(KC_Q);
            tap_code16(KC_ESC);
            tap_code16(KC_COLN);
            tap_code(KC_Q);
            tap_code(KC_ENT);
            return;
        case KC_0:
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
            tap_code(keycode);
            return;
        default:
            tap16_repeatable(keycode);
    }
}

void tap_hold_send_hold(uint16_t keycode) {
    disable_caps_word();

    switch (keycode) {
        case KC_COMM:
            tap_code16(KC_QUES);
            return;
        case KC_DOT:
            tap_code16(KC_EXLM);
            return;
        case KC_LABK:
        case KC_RABK:
        case KC_UNDS:
            // FIXME should be repeatable
            double_tap(keycode);
            return;
        case KC_DQUO:
        // case KC_PERC:
        //     send_string("%{}");
        //     return;
        case GRV:
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            tap_undead_key(true, KC_GRV);
            return;
        case KC_AT:
            tap_code16(KC_AT);
            tap16_repeatable(KC_U);
            return;
        case KC_PIPE:
        case KC_AMPR:
        case KC_EQL:
            double_tap_space(keycode);
            return;
        case KC_DLR:
        case KC_HASH:
            tap_code16(keycode);
            double_parens_left(KC_LCBR, KC_RCBR);
            return;
        case KC_EXLM:
            send_string(" != ");
            return;
        // case KC_QUES:
        //     send_string("{:?}");
        //     return;
        case KC_LPRN:
            double_parens_left(keycode, KC_RPRN);
            return;
        case KC_LCBR:
            double_parens_left(keycode, KC_RCBR);
            return;
        case KC_LBRC:
            double_parens_left(keycode, KC_RBRC);
            return;
        case QU:
            send_string("Qu");
            return;
        case SC:
            send_string("Sc");
            return;
        case CLOSE_WIN:
            tap16_repeatable(S(G(KC_C)));
            return;
        case KC_Q:
        case KC_Z:
            if (IS_LAYER_ON(_SHRT) || last_key_up == SHRT) {
                tap16_repeatable(S(C(keycode)));
            } else {
                tap16_repeatable(S(keycode));
            }
            return;
        case KC_0:
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
            tap_code16(C(KC_E));
            tap_code(keycode);
            disable_num_word();
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
        // case KC_UNDS:
        // case KC_R:
        // case KC_6:
        // // case A(KC_6):
        // case KC_SLSH:
        // case KC_Y:
        // case KC_7:
        // // case A(KC_7):
        // // case A(KC_R):
        // // case A(KC_V):
        // // case A(KC_Y):
        //     return 135;
        // // Ring
        // case KC_C:
        // case KC_S:
        // case KC_W:
        // case KC_U:
        // case KC_I:
        // case KC_DOT:
        // case KC_Q:
        // case QU:
        // case KC_4:
        // // case A(KC_4):
        // case KC_5:
        // // case A(KC_5):
        // // case A(KC_J):
        // // case A(KC_R):
        // // case C(KC_A):
        // // case C(KC_C):
        // // case C(KC_S):
        // // case C(KC_V):
        //     return 105;
        // // Middle
        // case KC_F:
        // case KC_T:
        // case KC_G:
        // case KC_O:
        // case KC_A:
        // case KC_COMM:
        // case KC_Z:
        // case KC_0:
        // // case A(KC_0):
        // case KC_1:
        // // case A(KC_1):
        // // case C(KC_W):
        // // case C(KC_T):
        // // case C(KC_G):
        //     return 100;
        // // Slow index
        // case KC_B:
        // case KC_P:
        // case KC_LPRN:
        // case KC_X:
        // case KC_M:
        // case KC_RPRN:
        // // case C(KC_E):
        //     return 105;
        // // Index
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
            layer_invert(_SYM);
            return NULL;
        // case KC_C:
        //     swap_caps_esc();
        //     return NULL;
        default:
            return NULL;
    }
}

void *leader_start_func(uint16_t keycode) {
    switch (keycode) {
        case KC_T:
            return leader_toggles_func;
        case KC_C:
            tap_caps_lock();
            return NULL;
        case ESC_SYM:
            tap_code16(C(S(KC_ESC)));
            return NULL;
        case KC_A:
            layer_invert(_FUN);
            return NULL;
        default:
            return NULL;
    }
}

bool _process_record_user(uint16_t keycode, keyrecord_t *record) {
    // #ifdef CONSOLE_ENABLE
    //     uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    // #endif
    // Error: Too many arguments for format. Meh!
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
    if (!process_roll(keycode, record)) {
        return false;
    }
    if (!process_tap_hold(keycode, record)) {
        // Extra register here to allow fast rolls without waiting for tap hold,
        // (which will also overwrite this).
        if (record->event.pressed) {
            register_key_to_repeat(keycode);
        }
        return false;
    }

    switch (keycode) {
        case ESC_SYM:
            if (record->tap.count && record->event.pressed) {
                tap_escape();
                return false;
            }
            break;
        case KC_CAPS:
            return process_caps(record->event.pressed);
        case CLEAR:
            clear_oneshot_mods();
            if (get_oneshot_layer() != 0) {
                clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
            }
            stop_leading();
            layer_off(_NUM);
            layer_off(_SYM);
            layer_move(_BASE);
            return false;
        case CANCEL:
            layer_off(_NUM);
            layer_off(_SYM);
            layer_off(_FUN);
            stop_leading();
            return false;
        case TILD:
            register_key_to_repeat(TILD);
            return tap_undead_key(record->event.pressed, KC_TILD);
        case CIRC:
            register_key_to_repeat(CIRC);
            return tap_undead_key(record->event.pressed, KC_CIRC);
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
                tap_escape();
                tap_code16(KC_COLN);
                tap_code(KC_W);
                tap_code(KC_ENT);
            }
            return false;
        case VIM_SP:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_S);
            }
            return false;
        case VIM_VS:
            if (record->event.pressed) {
                tap_code16(C(KC_W));
                tap_code(KC_V);
            }
            return false;
        case NUM_G:
            if (record->event.pressed) {
                tap_code16(S(KC_G));
            }
            return false;
        case AT_U:
            if (record->event.pressed) {
                tap_code16(KC_AT);
                tap16_repeatable(KC_U);
            }
            return false;
        case SCLN_SYM:
            if (record->tap.count && record->event.pressed) {
                tap16_repeatable(KC_SCLN);
                return false;
            }
            break;
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
        case LEADER:
            start_leading();
            return false;
        case REPEAT:
            // Enable fast UI rolls with repeat key
            end_tap_hold();
            update_repeat_key(record);
            return false;
        case REV_REP:
            update_reverse_repeat_key(record);
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
