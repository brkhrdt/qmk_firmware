// Copyright 2024 @Filios92
// SPDX-License-Identifier: GPL-2.0-or-later

// KC_G = 0x0A = 10 on layer 0
// KC_H = 0x0B = 11
// KC_I = 0x0C = 12
// KC_W = 0x14 = 20 on layer 1

//   (0,0) ----H----(1,0) ----X---- (2,0)
//     |              |               |
//     G              I               J
//     |              |               |
//   (0,1) ----X----(1,1) ----X---- (2,1)
const keypos_t default_layer_combo_kps[3] = {{0, 0}, {0, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  default_layer_combo_g        = {.layer = 0, .keyposes = default_layer_combo_kps, .keycode = KC_G};

// overlap with first combo
const keypos_t default_layer_combo_kps_h[3] = {{0, 0}, {1, 0}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  default_layer_combo_h = {.layer = 0, .keyposes = default_layer_combo_kps_h, .keycode = KC_H};

// no overlap with first combo
const keypos_t default_layer_combo_kps_i[3] = {{1, 0}, {1, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  default_layer_combo_i             = {.layer = 0, .keyposes = default_layer_combo_kps_i, .keycode = KC_I};

const keypos_t default_layer_combo_kps_j[3] = {{2, 0}, {2, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  default_layer_combo_j             = {.layer = 0, .keyposes = default_layer_combo_kps_j, .keycode = KC_J};

const keypos_t first_layer_combo_kps[3] = {{0, 0}, {0, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  first_layer_combo        = {.layer = 1, .keyposes = default_layer_combo_kps, .keycode = KC_W};

combo_t key_combos[] = {
    [0] = default_layer_combo_g,
    [1] = default_layer_combo_h,
    [2] = default_layer_combo_i,
    [3] = default_layer_combo_j,
    [4] = first_layer_combo,
};
