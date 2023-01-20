#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _NAVI,
    _SYMB,
    _OMOD,
    _SHRT,
    _NUM,
    _FUNC,
    _GAME,
};

enum custom_keycodes {
  // Multiple chars
  QU = SAFE_RANGE,

  // Instant oneshot mods
  OS_SHFT,
  OS_CTRL,
  OS_ALT,
  OS_GUI,

  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  NUMWORD,

  // Layer management
  // CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR, // Clear all WORD, one-shots and reset to BASE

  // Instant leader key
  LEADER,

  // Repeat key
  REPEAT,
};

#define xxxxxxx KC_NO

#define BASE  DF(_BASE)
#define SYMB  OSL(_SYMB)
#define OMOD  OSL(_OMOD)
#define SHRT  OSL(_SHRT)
#define FUNC  OSL(_FUNC)

#define MT_SPC  LT(_NAVI, KC_SPC)
#define C_TAB   C(KC_TAB)
#define CS_TAB  RCS(KC_TAB)
#define DN_CTRL MT(MOD_LCTL, KC_DOWN)
