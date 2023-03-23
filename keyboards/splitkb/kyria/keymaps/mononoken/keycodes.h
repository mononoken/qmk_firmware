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
    _CODE,
    _GAME,
    _QWER,
};

enum custom_keycodes {
  // Multiple chars
  QU = SAFE_RANGE,

    // Vim
  SAVE_VIM,
  VIM_VS,
  VIM_SP,
  CLOSE_WIN,

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

  // For VSCode navigation
  GO_LEDT, // Go to last edit
};

#define xxxxxxx KC_NO

#define BASE      DF(_BASE)
#define SYMB      OSL(_SYMB)
#define L_SYMB    OSL(_LSYM)
#define R_SYMB    OSL(_RSYM)
#define OMOD      OSL(_OMOD)
#define SHRT      OSL(_SHRT)
#define FUNC      OSL(_FUNC)
#define CODE      OSL(_CODE)


#define MT_SPC    LT(_NAVI, KC_SPC)
#define C_TAB     C(KC_TAB)
#define CS_TAB    RCS(KC_TAB)
#define DN_CTRL   MT(MOD_LCTL, KC_DOWN)

#define LST_TAB   LSG(KC_T) // Open last closed tab in Firefox

// For _CODE
// Navigation
#define GT_SYM    LSG(KC_O) // Go to symbol
#define GT_SYMW   G(KC_T) // Go to symbol in workspace
#define GT_DEF    KC_F12 // Go to definition
#define PK_DEF    A(KC_F12) // Peek definition
#define GT_REF    S(KC_F12) // Go to reference
#define F_ALREF   LSA(KC_F12) // Find all references
#define SW_HIER   LSA(KC_H) // Show hierarchy
#define TG_MINM   LSA(KC_M) // Toggle minimap
#define GO_BACK   C(KC_MINS) // Go back
#define GO_BRKT   LSG(KC_BSLS)
#define F_INFIL   LSG(KC_F) // Find in files

#define CMD_PAL   LSG(KC_P) // Open command palette
#define QK_OPEN   G(KC_P) // Quick open


