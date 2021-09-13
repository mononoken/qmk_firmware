#pragma once

#include QMK_KEYBOARD_H

#include "quantum.h"

enum layers {
    _BASE = 0,
    _NUM,
    _NAV,
    _LMOD,
    _RMOD,
    _FUN,
    _OPT,
};

enum custom_keycodes {
    // Instant oneshot mods
    OS_SFT,
    OS_CTL,
    OS_ALT,
    OS_GUI,
};

#define xxxxxxx KC_NO

#define OS_SFT OSM(MOD_LSFT)
#define OS_ALT OSM(MOD_LALT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_GUI OSM(MOD_LGUI)

#define BASE TO(_BASE)
#define NUM OSL(_NUM)
#define LMOD OSL(_LMOD)
#define RMOD OSL(_RMOD)
#define OPT OSL(_OPT)
#define FUN OSL(_FUN)
#define NAV MO(_NAV)
