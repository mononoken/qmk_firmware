#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"
#include "oneshot.h"

enum layers {
    _BASE = 0,
    _NAVI,
    _SYMB,
    _LSYM,
    _RSYM,
    _OMOD,
    _SHRT,
    _NUM,
    _FUNC,
    _GAME,
    _QWER
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
  // L_CLEAR,
  // R_CLEAR,

  // Instant leader key
  LEADER,

  // Repeat key
  REPEAT,
};

#define xxxxxxx KC_NO

#define BASE    DF(_BASE)
#define SYMB    OSL(_SYMB)
#define L_SYMB  OSL(_LSYM)
#define R_SYMB  OSL(_RSYM)
#define OMOD    OSL(_OMOD)
#define SHRT    OSL(_SHRT)
#define FUNC    OSL(_FUNC)

#define MT_SPC  LT(_NAVI, KC_SPC)
#define C_TAB   C(KC_TAB)
#define CS_TAB  RCS(KC_TAB)
#define DN_CTRL MT(MOD_LCTL, KC_DOWN)
