OLED_ENABLE = yes
OLED_DRIVER = SSD1306   	# Enables the use of OLED displays
ENCODER_ENABLE = no       # Enables the use of one or more encoders
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow

# Custom settings
AUTO_SHIFT_ENABLE = yes

# Combos
COMBO_ENABLE = yes
VPATH  +=  keyboards/gboards/

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similar
MOUSEKEY_ENABLE = no        # Them mouse keys yo
KEY_OVERRIDE_ENABLE = no
LEADER_ENABLE = no
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