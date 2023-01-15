#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    _BASE = 0,
    _NAVI,
    _LSYM,
    _RSYM,
    _SHRT,
    _NUM,
    _FUNC,
};

#define BASE  DF(_BASE)
#define LSYM  MO(_LSYM)
#define RSYM  MO(_RSYM)
#define SHRT  OSL(_SHRT)
#define FUNC  MO(_SHRT)

enum custom_keycodes {
  REPEAT,
};

#define xxxxxxx KC_NO

#define MT_SPC  LT(_NAVI, KC_SPC)
#define C_TAB   G(KC_TAB)
#define CS_TAB  SGUI(KC_TAB)
#define DN_CTRL MT(MOD_LCTL, KC_DOWN)

#define OS_CTRL  OSM(MOD_LCTL)
#define OS_SHFT  OSM(MOD_LSFT)
#define OS_ALT   OSM(MOD_LALT)
#define OS_GUI   OSM(MOD_LGUI)
