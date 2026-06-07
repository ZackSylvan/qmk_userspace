#pragma once

// RGB indicator LED indices for cool_rgb_stuff.c (recomputed for the Dilemma MAX
// LED map: 24 underglow + 28 per-key per side; left 0-51, right 52-103).
#define KB_SHIFT_IDX_COUNT 2
#define KB_WASD_IDX_COUNT 4

// The trackpad runs as a native precision touchpad via the digitizer (hid-multitouch on
// Linux). It's on the LEFT half, so the raw multi-finger report must cross the split to the
// USB/master half. (The relative-mouse fallback is disabled in rules.mk — it would fight the
// smooth absolute cursor.)
#define SPLIT_DIGITIZER_ENABLE
#define DIGITIZER_LEFT

// Trackpad orientation for the digitizer/absolute path (POINTING_DEVICE_ROTATION_90 does NOT
// apply here). Currently 0deg (no flags) and tracking correctly. If it ever reads rotated or
// mirrored, toggle these:
// #define MXT_SWITCH_XY
// #define MXT_INVERT_X
// #define MXT_INVERT_Y
