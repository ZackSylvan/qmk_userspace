#include "hatlife.h"

static bool     sft_ent_held    = false;
static bool     sft_ent_shifted = false;
static bool     sft_ent_pending = false;
static uint32_t sft_ent_timer   = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (sft_ent_pending && timer_elapsed32(sft_ent_timer) > 300) {
        sft_ent_pending = false;
    }

    if (keycode == SFT_ENT) {
        if (record->event.pressed) {
            if (sft_ent_pending) {
                sft_ent_pending = false;
                tap_code(KC_ENT);
            }
            sft_ent_held    = true;
            sft_ent_shifted = false;
            register_code(KC_RSFT);
        } else {
            sft_ent_held = false;
            unregister_code(KC_RSFT);
            if (!sft_ent_shifted) {
                sft_ent_pending = true;
                sft_ent_timer   = timer_read32();
            }
        }
        return false;
    }

    if (record->event.pressed) {
        if (sft_ent_held) {
            sft_ent_shifted = true;
        }
        sft_ent_pending = false;
    }

    return true;
}
