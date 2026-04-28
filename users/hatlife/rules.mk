CAPS_WORD_ENABLE = yes
TRI_LAYER_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += cool_rgb_stuff.c
endif
