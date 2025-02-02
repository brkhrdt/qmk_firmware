// Copyright 2024 @Filios92
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

/* enum combos { alttab, esc }; */

/* uint16_t const alttab_combo[] = {KC_F, KC_G, COMBO_END}; */
/* uint16_t const esc_combo[]    = {KC_H, KC_J, COMBO_END}; */

/* // clang-format off */
/* combo_t key_combos[] = { */
/*     [alttab]  = COMBO(alttab_combo, KC_NO), */
/*     [esc]     = COMBO(esc_combo, KC_ESC) */
/* }; */
/* // clang-format on */

const keypos_t default_layer_combo_kps[3] = {{0, 0}, {0, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  default_layer_combo      = {.layer=0, .keyposes = default_layer_combo_kps, .keycode = KC_SPACE};

const keypos_t first_layer_combo_kps[3] = {{0, 0}, {0, 1}, {(uint8_t)-1, (uint8_t)-1}};
const combo_t  first_layer_combo      = {.layer=1, .keyposes = default_layer_combo_kps, .keycode = KC_ENTER};

combo_t key_combos[] = {
  [0]    = default_layer_combo,
  [1]    = first_layer_combo,
};
