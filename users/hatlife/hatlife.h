// Must include in keymap.c

#include QMK_KEYBOARD_H

const key_override_t shift_home_override = ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_END);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &shift_home_override,
    NULL
};
