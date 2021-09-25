#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _NUM,
    _NAV,
    _LMOD,
    _RMOD,
    _FUN,
    _OPT,
    _NUMP,
};

enum custom_keycodes {
    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_GUI,

    // Direct dead keys ~`^
    TILD = SAFE_RANGE,
    GRV,
    CIRC,

    // Custom keycodes for instant processing for NUMWORD
    NUM_G,

    NUMWORD,

    // Layer management
    CANCEL, // Cancel SYMWORD and NUMWORD
    CLEAR, // Clear all WORD, one-shots and reset to BASE

    TO_NUM,

    // Repeat keys
    REPEAT,
    REV_REP,

    // Multiple chars
    REP_A,
};

#define xxxxxxx KC_NO

#define OS_SHFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTRL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)

// treeman stuff
#define MT_BTN1 LGUI_T(KC_BTN1)
#define MT_SPC LT(_NAV, KC_SPC)
#define SFT OSM(MOD_LSFT)
#define ALT OSM(MOD_LALT)
#define MY_RALT OSM(MOD_RALT)
#define CTRL OSM(MOD_LCTL)
#define GUI OSM(MOD_LGUI)
#define DN_CTRL LCTL_T(KC_DOWN)

#define BASE TO(_BASE)
#define NUM OSL(_NUM)
#define LMOD OSL(_LMOD)
#define RMOD OSL(_RMOD)
#define OPT OSL(_OPT)
#define FUN OSL(_FUN)
#define NAV MO(_NAV)
#define NUMP TG(_NUMP)

#define C_HOME C(KC_HOME)

#define MT_SPC LT(_NAV, KC_SPC)