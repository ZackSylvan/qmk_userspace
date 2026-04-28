#include "color.h"
#include "quantum.h"

#ifdef KB_SHIFT_IDX_COUNT
extern const int kb_shift_idxs[KB_SHIFT_IDX_COUNT];
#endif
#ifdef KB_WASD_IDX_COUNT
extern const int kb_wasd_idxs[KB_WASD_IDX_COUNT];
#endif

bool rgb_matrix_indicators_user(void) {
    #ifdef KB_SHIFT_IDX_COUNT
        if (is_caps_word_on()) {
            for (uint8_t i = 0; i < KB_SHIFT_IDX_COUNT; i++) {
                rgb_matrix_set_color(kb_shift_idxs[i], 0xFF, 0x20, 0x07);
            }
        }
    #endif
    #ifdef KB_WASD_IDX_COUNT
        if (IS_LAYER_ON(_GME)) {
            for (uint8_t i = 0; i < KB_WASD_IDX_COUNT; i++) {
                rgb_matrix_set_color(kb_wasd_idxs[i], RGB_GOLD);

            }
        }
    #endif
    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv_noeeprom(HSV_OFF);
}
