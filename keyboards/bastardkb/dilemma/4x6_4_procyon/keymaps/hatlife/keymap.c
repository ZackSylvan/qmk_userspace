// Copyright 2023 Danny Nguyen (@nooges)
// SPDX-License-Identifier: GPL-2.0-or-later
//
// hatlife keymap ported from the Keebio Iris rev8 to the BastardKB Dilemma MAX
// (4x6_4_procyon). Both boards share a 6x4 main grid; the Iris's inner row-3
// Alt/Gui keys fold into this board's 4-key thumb cluster.

#include "hatlife.h"

// Only master side can individually control LEDs.
// Dilemma MAX LED map: 24 underglow + 28 per-key per side (left 0-51, right 52-103).
// LSFT=matrix[3,0]->42, SFT_ENT=matrix[8,0]->94; W[1,2]=32 A[2,1]=40 S[2,2]=39 D[2,3]=38.
// NOTE: confirm these with a lighting test (caps-word + game layer) and adjust if needed.
const int kb_shift_idxs[KB_SHIFT_IDX_COUNT] = { 42, 94 };
const int kb_wasd_idxs[KB_WASD_IDX_COUNT] = { 32, 40, 39, 38 };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_BL] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_EQL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤        ├────────┼────────┼────────┼────────┼────────┼────────┤
     KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_ENT,
  //└────────┴────────┴────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┴────────┴────────┘
                       KC_LBRC, TL_LOWR, KC_SPC,  KC_LALT,         KC_RGUI, KC_BSPC, TL_UPPR, KC_RBRC
  //                  └────────┴────────┴────────┴────────┘        └────────┴────────┴────────┴────────┘
  ),

  [_LWR] = LAYOUT(
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     SCTLTAB, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, KC_F12,
     KC_LCTL, _______, _______, _______, KC_PGDN, KC_HOME,         KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, KC_RCTL,
     _______, _______, _______, _______, _______, KC_PGUP,         _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______,         _______, KC_DEL,  _______, KC_RALT
  ),

  [_RSE] = LAYOUT(
     KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
     CTLTAB,  KC_BRIU, KC_7,    KC_8,    KC_9,    KC_VOLU,          KC_WBAK, KC_WSTP, KC_WREF, KC_WFWD, KC_PSCR, KC_F12,
     RM_TOGG, KC_BRID, KC_4,    KC_5,    KC_6,    KC_VOLD,          KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
     KC_HYPR, KC_0,    KC_1,    KC_2,    KC_3,    KC_MUTE,          KC_MPRV, KC_MSTP, KC_MPLY, KC_MNXT, _______, OSMHYPR,
                       KC_DOT,  _______, _______, _______,         _______, _______, _______, _______
  ),

  [_ADJ] = LAYOUT(
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, QK_BOOT,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, TG(_GME),        _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______,         _______, _______, _______, _______
  ),

  [_GME] = LAYOUT(
     KC_ESC,  _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     KC_LCTL, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, KC_ENT,
                       _______, _______, _______, _______,         _______, _______, _______, _______
  ),

  [_MSE] = LAYOUT(
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, MS_BTN1, MS_BTN3, MS_BTN2, _______, _______,
     _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______,
                       _______, _______, _______, _______,         _______, _______, _______, _______
  )
};

// A finger on the trackpad raises the mouse-button layer (_MSE), so J/K/L act as L/M/R click
// while the left hand drives the pad. The pointing-device auto-mouse trigger isn't usable here
// (POINTING_DEVICE is off so the relative fallback can't fight the smooth native touchpad), so
// drive the layer straight off the digitizer contacts. Pure contact, no motion gating — the
// pad's placement makes stray contact a non-issue. The maxtouch sends a final "no fingers"
// report on lift, so the layer releases cleanly.
#ifdef DIGITIZER_ENABLE
bool digitizer_task_user(digitizer_t *const digitizer_state) {
    static bool mouse_layer_on = false;
    bool        touched        = false;
    for (uint8_t i = 0; i < DIGITIZER_CONTACT_COUNT; i++) {
        if (digitizer_state->contacts[i].tip) {
            touched = true;
            break;
        }
    }
    if (touched != mouse_layer_on) {
        mouse_layer_on = touched;
        if (touched) {
            layer_on(_MSE);
        } else {
            layer_off(_MSE);
        }
    }
    return false;
}
#endif
