CAPS_WORD_ENABLE = yes
TRI_LAYER_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

SRC += hatlife.c

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
  SRC += cool_rgb_stuff.c
endif
