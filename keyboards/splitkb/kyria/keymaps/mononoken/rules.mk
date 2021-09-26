COMBO_ENABLE = yes
ENCODER_ENABLE = yes        # One or more encoders

VPATH += keyboards/gboards # Easy definition of combos

OLED_ENABLE = yes
OLED_DRIVER = SSD1306   # Enables the use of OLED displays
AUTO_SHIFT_ENABLE = yes

# Extra features that are nice but takes space
WPM_ENABLE = yes
EXTRAKEY_ENABLE = yes        # For volume keys and similar
MOUSEKEY_ENABLE = no        # Them mouse keys yo
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no        # Keyboard RGB underglow
RGB_MATRIX_ENABLE = no      # Disable RGB, not used on Kyria

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no

SRC += oneshot.c
SRC += layermodes.c
SRC += repeat.c
SRC += tap_hold.c

#ifeq ($(strip $(ENCODER_ENABLE)), yes)
#	SRC += encoder_utils.c
#endif