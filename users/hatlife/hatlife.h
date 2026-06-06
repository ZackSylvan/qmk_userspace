#pragma once

#include QMK_KEYBOARD_H

enum hatlife_keycodes {
    SFT_ENT_KEY = SAFE_RANGE,
};

#define SFT_ENT SFT_ENT_KEY

static const key_override_t shift_home_override __attribute__((unused)) = ko_make_basic(MOD_MASK_SHIFT, KC_HOME, KC_END);

static const key_override_t *key_overrides[] __attribute__((unused)) = {
    &shift_home_override,
};
