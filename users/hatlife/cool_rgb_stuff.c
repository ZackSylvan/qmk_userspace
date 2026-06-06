#include "color.h"
#include "quantum.h"
#ifdef SPLIT_KEYBOARD
#    include "transactions.h"
#endif

#ifdef KB_SHIFT_IDX_COUNT
extern const int kb_shift_idxs[KB_SHIFT_IDX_COUNT];
#endif
#ifdef KB_WASD_IDX_COUNT
extern const int kb_wasd_idxs[KB_WASD_IDX_COUNT];
#endif

#ifdef SPLIT_KEYBOARD
static bool slave_caps_word_on = false;

static void caps_word_sync_handler(uint8_t in_buflen, const void *in_data, uint8_t out_buflen, void *out_data) {
    slave_caps_word_on = *(const bool *)in_data;
}

void housekeeping_task_user(void) {
    if (is_keyboard_master()) {
        static uint32_t last_sync = 0;
        static bool     last_sent = false;
        bool            current   = is_caps_word_on();
        if (timer_elapsed32(last_sync) > 250 || current != last_sent) {
            if (transaction_rpc_exec(USER_RGB_SYNC_CAPS_WORD, sizeof(current), &current, 0, NULL)) {
                last_sync = timer_read32();
                last_sent = current;
            }
        }
    }
}

static inline bool caps_word_on_this_half(void) {
    return is_keyboard_master() ? is_caps_word_on() : slave_caps_word_on;
}
#else
static inline bool caps_word_on_this_half(void) {
    return is_caps_word_on();
}
#endif

bool rgb_matrix_indicators_user(void) {
#ifdef KB_SHIFT_IDX_COUNT
    if (caps_word_on_this_half()) {
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
#ifdef SPLIT_KEYBOARD
    transaction_register_rpc(USER_RGB_SYNC_CAPS_WORD, caps_word_sync_handler);
#endif
}
