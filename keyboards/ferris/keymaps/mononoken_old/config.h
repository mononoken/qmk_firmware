/*
Copyright 2020 Pierre Chevalier <pierrechevalier83@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/*#pragma once*/
/*// Set the mouse settings to a comfortable speed/accuracy trade-off,*/
/*// assuming a screen refresh rate of 60 Htz or higher*/
/*// The default is 50. This makes the mouse ~3 times faster and more accurate*/
/*#define MOUSEKEY_INTERVAL 16*/
/*// The default is 20. Since we made the mouse about 3 times faster with the previous setting,*/
/*// give it more time to accelerate to max speed to retain precise control over short distances.*/
/*#define MOUSEKEY_TIME_TO_MAX 40*/
/*// The default is 300. Let's try and make this as low as possible while keeping the cursor responsive*/
/*#define MOUSEKEY_DELAY 100*/
/*// It makes sense to use the same delay for the mouseweel*/
/*#define MOUSEKEY_WHEEL_DELAY 100*/
/*// The default is 100*/
/*#define MOUSEKEY_WHEEL_INTERVAL 50*/
/*// The default is 40*/
/*#define MOUSEKEY_WHEEL_TIME_TO_MAX 100*/
/**/
/*// Pick good defaults for enabling homerow modifiers*/
/*#define TAPPING_TERM 200*/
/*#define PERMISSIVE_HOLD*/
/*#define QUICK_TAP_TERM 0*/
/**/
/*// Underglow configuration*/
/*#ifdef RGBLIGHT_ENABLE*/
/*#    define RGBLIGHT_EFFECT_BREATHING*/
/*#    define RGBLIGHT_EFFECT_RAINBOW_MOOD*/
/*#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL*/
/*#    define RGBLIGHT_EFFECT_SNAKE*/
/*#    define RGBLIGHT_EFFECT_KNIGHT*/
/*#    define RGBLIGHT_EFFECT_CHRISTMAS*/
/*#    define RGBLIGHT_EFFECT_STATIC_GRADIENT*/
/*#    define RGBLIGHT_EFFECT_RGB_TEST*/
/*#    define RGBLIGHT_EFFECT_ALTERNATING*/
/*#    define RGBLIGHT_EFFECT_TWINKLE*/
/*#    define RGBLIGHT_HUE_STEP 8*/
/*#    define RGBLIGHT_SAT_STEP 8*/
/*#    define RGBLIGHT_VAL_STEP 8*/
/*#endif*/

#pragma once

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_DISABLE_KEYCODES
    #define RGBLIGHT_LAYERS
#endif

// Home-row mods: https://precondition.github.io/home-row-mods#tap-hold-configuration-settings
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM_PER_KEY
#ifdef TAPPING_TERM_PER_KEY
#define TAPPING_TERM 170
#else
// Only for thumbs
#define TAPPING_TERM 240
#endif

// Prevent normal rollover on alphas from accidentally triggering mods.
// Now default
/*#define IGNORE_MOD_TAP_INTERRUPT*/
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD
// Immediately turn on layer if key is pressed quickly
// #define HOLD_ON_OTHER_KEY_PRESS

// Combos
/*#define COMBO_VARIABLE_LEN*/
#undef COMBO_TERM
#define COMBO_TERM 64
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space
#define COMBO_ONLY_FROM_LAYER 0

// Handle combo trigger behavior for triggering combos based on active layer
#define COMBO_SHOULD_TRIGGER

#define DEFAULT_XCASE_SEPARATOR KC_MINS
#define XCASE_DELIMITER_KEY KC_UNDS

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Save space
//#define LAYER_STATE_8BIT
#define LAYER_STATE_16BIT
// These are a bit iffy, as I don't know what they're doing, but it "works fine" according to Discord people
// #undef LOCKING_SUPPORT_ENABLE
// #undef LOCKING_RESYNC_ENABLE

// Fixes issue where splitkb does not wake up second half after sleep
#define USB_SUSPEND_WAKEUP_DELAY 200
