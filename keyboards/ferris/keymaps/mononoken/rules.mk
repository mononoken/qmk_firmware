# Combos
COMBO_ENABLE = yes
VPATH  +=  keyboards/gboards/

SPLIT_KEYBOARD = yes
ENCODER_ENABLE = no
RGBLIGHT_ENABLE = no

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = yes       # For volume keys and similar
MOUSEKEY_ENABLE = no
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no					# Separate implementation leader.c
TAP_DANCE_ENABLE = no
RGB_MATRIX_ENABLE = no

# Saves a bunch of memory
EXTRAFLAGS += -flto
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += oneshot.c
SRC += layermodes.c
SRC += casemodes.c
SRC += tap_hold.c
SRC += repeat.c
SRC += leader.c
