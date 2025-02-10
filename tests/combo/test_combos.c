// Copyright 2023 Stefan Kerkmann (@KarlK90)
// Copyright 2023 @filterpaper
// Copyright 2023 Nick Brassel (@tzarc)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

enum combos { modtest, osmshift, combo12, combo13, combo34, combo56 };

uint16_t const modtest_combo[]  = {KC_Y, KC_U, COMBO_END};
uint16_t const osmshift_combo[] = {KC_Z, KC_X, COMBO_END};
uint16_t const combo_12[] = {KC_1, KC_2, COMBO_END};
uint16_t const combo_13[] = {KC_1, KC_3, COMBO_END};
uint16_t const combo_34[] = {KC_3, KC_4, COMBO_END};
uint16_t const combo_56[] = {KC_5, KC_6, COMBO_END};
// no combo_24

// clang-format off
combo_t key_combos[] = {
    [modtest]  = COMBO(modtest_combo, RSFT_T(KC_SPACE)),
    [osmshift] = COMBO(osmshift_combo, OSM(MOD_LSFT)),
    [combo12] = COMBO(combo_12, KC_G),
    [combo13] = COMBO(combo_13, KC_H),
    [combo34] = COMBO(combo_34, KC_I),
    [combo56] = COMBO(combo_56, KC_J),
};
// clang-format on
