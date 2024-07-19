#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "quantum/action.h"
#include "quantum/quantum_keycodes.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _NUM,
    _SYM,
    _NAV,
    _WNAV,
    _SHRT,
    _SPEC,
    _FUN,
};

enum custom_keycodes {
    // Direct dead keys ~`^
    TILD = QK_USER,
    GRV,
    CIRC,

    // Vim
    SAVE_VIM,
    VIM_VS,
    VIM_SP,
    CLOSE_WIN,

    // Multiple chars
    QU,
    SC,
    AT_U,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    // Smart caps lock and layers that turn off on certain keys
    CAPSWORD,
    NUMWORD,

    // Layer management
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR,  // Clear all WORD, one-shots and reset to BASE

    // Instant leader key
    LEADER,

    // Repeat keys
    REPEAT,
    REV_REP,
};

#define xxxxxxx KC_NO

#define MT_SPC LT(_NAV, KC_SPC)
#define MY_RALT OSM(MOD_RALT)
#define DN_CTRL LCTL_T(KC_DOWN)

#define ESC_SYM LT(_SYM, KC_ESC)

#define COLN_SYM LT(_SYM, KC_COLN)

#define C_TAB C(KC_TAB)
#define S_TAB S(KC_TAB)
#define SC_TAB S(C(KC_TAB))

#define SG_T S(G(KC_T)) // Open last closed tab in browser

#define MY_LALT OSM(MOD_LALT)

#define SHRT OSL(_SHRT)
#define WNAV MO(_WNAV)
#define TG_WNAV TG(_WNAV)
#define OPT OSL(_OPT)
#define SPEC OSL(_SPEC)
#define FUN OSL(_FUN)

#define GAME2 OSL(_GAME2)

#define SYM_LFT ALGR(KC_Y)    // ← y
#define SYM_DWN ALGR(KC_U)    // ↓ u
#define SYM_RHT ALGR(KC_I)    // → i
#define SYM_UP ALGR(S(KC_U))  // ↑ U
#define SYM_LDQ ALGR(KC_V)    // “ v
#define SYM_RDQ ALGR(KC_B)    // ” b
#define SYM_LQO ALGR(S(KC_V)) // ‘ V
#define SYM_RQO ALGR(S(KC_B)) // ’ B
