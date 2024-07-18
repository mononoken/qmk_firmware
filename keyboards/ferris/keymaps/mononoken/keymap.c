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


/* This file has lots of code that was adapted or copied from
 * https://github.com/treeman/qmk_firmware
 * It originally was copied from his ferris keymap to work for my kyria.
 * And now it is being copied from my kyria keymap to my ferris lol.
 */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
      KC_UNDS, KC_C,    KC_F,    KC_K,    KC_B,         KC_X,    KC_J,    KC_O,    KC_U,    KC_MINS,
      KC_R,    KC_S,    KC_T,    KC_H,    KC_P,         KC_M,    KC_N,    KC_A,    KC_I,    REPEAT,
      KC_V,    KC_W,    KC_G,    KC_D,    KC_LPRN,      KC_SLSH, KC_L,    KC_COMM, KC_DOT,  KC_Y,
                                 L_SYMB,  KC_SPC,       KC_E,    R_SYMB
    ),
    [_NUM] = LAYOUT(
      _______, KC_PLUS, KC_ASTR, _______, xxxxxxx,      _______, _______, REPEAT,  xxxxxxx, _______,
      KC_6,    KC_4,    KC_0,    KC_2,    _______,      _______, KC_3,    KC_1,    KC_5,    KC_7,
      KC_PERC, xxxxxxx, NUM_G,   KC_8,    _______,      _______, KC_9,    _______, _______, xxxxxxx,
                                 _______, _______,      _______, _______
    ),
    [_NAVI] = LAYOUT(
      xxxxxxx, KC_LEFT, KC_UP,   KC_RGHT, KC_HOME,      LCA(KC_W),LCA(KC_E),A(KC_S), A(KC_G),LCA(KC_M),
      KC_END,  CS_TAB,  DN_CTRL, C_TAB,   xxxxxxx,      xxxxxxx, KC_H,    KC_J,    KC_K,    KC_L,
      xxxxxxx, xxxxxxx, KC_PGUP, KC_PGDN, KC_END,       xxxxxxx, A(KC_H), A(KC_J), A(KC_K), A(KC_L),
                                _______, _______,       _______, _______
    ),
    [_WNAV] = LAYOUT(
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      LCA(KC_W),LCA(KC_E),A(KC_S), A(KC_G),LCA(KC_M),
      A(KC_6), A(KC_4), A(KC_0), A(KC_2), xxxxxxx,      xxxxxxx, A(KC_3), A(KC_1), A(KC_5), A(KC_7),
      xxxxxxx, xxxxxxx, xxxxxxx, A(KC_8), xxxxxxx,      xxxxxxx, LCA(KC_LEFT),LCA(KC_DOWN),LCA(KC_UP),LCA(KC_RGHT),
                                xxxxxxx, xxxxxxx,       xxxxxxx, xxxxxxx
    ),
    [_SYMB] = LAYOUT(
      KC_TILD, KC_PLUS, KC_ASTR, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, KC_AT,   KC_HASH, _______,
      KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, xxxxxxx,      KC_GRV,  KC_AMPR, KC_LBRC, KC_RBRC, KC_DLR,
      KC_PERC, KC_LABK, KC_RABK, KC_BSLS, KC_RPRN,      xxxxxxx, xxxxxxx, KC_QUES, KC_EXLM, xxxxxxx,
                                 _______, _______,      _______, _______
    ),
    [_LSYM] = LAYOUT(
      KC_TILD, KC_PLUS, KC_ASTR, xxxxxxx, _______,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, _______,
      KC_CIRC, KC_LCBR, KC_RCBR, KC_PIPE, xxxxxxx,      xxxxxxx, KC_3,    KC_1,    KC_5,    KC_7,
      KC_PERC, KC_LABK, KC_RABK, KC_BSLS, KC_RPRN,      xxxxxxx, KC_9,    _______, _______, _______,
                                 _______, _______,      _______, _______
    ),
    [_RSYM] = LAYOUT(
      xxxxxxx, KC_PLUS, KC_ASTR, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, KC_AT,   KC_HASH, _______,
      KC_6,    KC_4,    KC_0,    KC_2,    xxxxxxx,      KC_GRV,  KC_AMPR, KC_LBRC, KC_RBRC, KC_DLR,
      _______, xxxxxxx, xxxxxxx, KC_8,    KC_RPRN,      xxxxxxx, xxxxxxx, KC_QUES, KC_EXLM, xxxxxxx,
                                 _______, _______,      _______, _______
    ),
    [_SHRT] = LAYOUT(
      G(KC_Q), G(KC_W), G(KC_E), G(KC_R), G(KC_T),      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      G(KC_A), G(KC_S), G(KC_D), G(KC_F), G(KC_G),      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_B),      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                 _______, _______,      C(KC_E), FUNC
    ),
    [_FUNC] = LAYOUT(
      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      KC_F6,   KC_F4,   KC_F10,  KC_F2,   KC_F12,       KC_F11,  KC_F3,   KC_F1,   KC_F5,   KC_F7,
      xxxxxxx, xxxxxxx, xxxxxxx, KC_F8,   KC_F14,       KC_F13,  KC_F9,   xxxxxxx, xxxxxxx, xxxxxxx,
                                 _______, _______,      _______, _______
    ),
    [_CODE] = LAYOUT(
      GT_SYM,  GT_REF,  PK_DEF,  F_INFIL, GO_BRKT,      xxxxxxx, xxxxxxx, _______, xxxxxxx, xxxxxxx,
      GT_SYMW, F_ALREF, GT_DEF,  CMD_PAL, QK_OPEN,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
      xxxxxxx, SW_HIER, GO_LEDT, GO_BACK, TG_MINM,      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx,
                                 KC_LGUI, _______,      _______, KC_RGUI
    ),
    [_GAME] = LAYOUT(
      KC_Q,    KC_C,    KC_F,    KC_K,    KC_B,         KC_X,    KC_J,    KC_O,    KC_U,    KC_MINS,
      KC_R,    KC_S,    KC_T,    KC_H,    KC_P,         KC_M,    KC_N,    KC_A,    KC_I,    REPEAT,
      KC_V,    KC_W,    KC_G,    KC_D,    KC_Z,         KC_SLSH, KC_L,    KC_COMM, KC_DOT,  KC_Y,
                                KC_LCTL, KC_SPC,        KC_E,    xxxxxxx
    ),
    [_QWER] = LAYOUT(
      KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_ENT,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
                                 KC_LCTL, KC_SPC,       KC_BSPC, KC_LSFT
    ),
};

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
        // case ent:
        // case vsp:
        case gui_combo_l:
        case gui_combo_r:
        case opt_combo_l:
            return COMBO_TERM;
        case ent:
            return COMBO_TERM - 20;
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
            return false;
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case QU:
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
        switch (keycode) {
          case A(KC_H):
          case A(KC_J):
          case A(KC_K):
          case A(KC_L):
          case A(KC_S):
          case A(KC_G):
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
          case A(KC_S):
          case A(KC_G):
              return true;
          default:
              return false;
        }
    } else {
        switch (keycode) {
            case KC_DOT:
            case KC_COMM:
            case KC_COLN:
            case KC_SLSH:
            case KC_TAB: // Allows for S(TAB) which reverse tabs in most programs.
            case KC_LPRN:
            case KC_UNDS:
            case A(KC_0):
            case A(KC_1):
            case A(KC_2):
            case A(KC_3):
            case A(KC_4):
            case A(KC_5):
            case A(KC_6):
            case A(KC_7):
            case A(KC_8):
            case A(KC_K):
            case A(KC_J):
            case A(KC_S):
            case A(KC_G):
            case A(KC_R):
            case A(KC_C):
            case KC_A ... KC_Z:
            case QU:
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
