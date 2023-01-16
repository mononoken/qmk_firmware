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
#define NAVI  TO(_NAVI)
#define LSYM  MO(_LSYM)
#define RSYM  MO(_RSYM)
#define SHRT  OSL(_SHRT)
#define NUM   TO(_NUM)
#define FUNC  MO(_SHRT)

#define CLEAR TO(_BASE)

enum custom_keycodes {
  // Multiple chars
  QU = SAFE_RANGE,

  // Layer management
  // CLEAR, // Clear all WORD, one-shots and reset to BASE

  // Instant leader key
  LEADER,

  // Repeat key
  REPEAT,
};

#define xxxxxxx KC_NO

#define MT_SPC  LT(_NAVI, KC_SPC)
#define C_TAB   C(KC_TAB)
#define CS_TAB  RCS(KC_TAB)
#define DN_CTRL MT(MOD_LCTL, KC_DOWN)

#define OS_CTRL  OSM(MOD_LCTL)
#define OS_SHFT  OSM(MOD_LSFT)
#define OS_ALT   OSM(MOD_LALT)
#define OS_GUI   OSM(MOD_LGUI)
