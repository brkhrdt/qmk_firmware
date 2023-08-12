// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Layers
enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _NAVIGATION,
    _NUMBER,
    _SPECIAL,
    _MOUSE,
};

// Quantum keys / Abbreviations
// qmk_firmware/keyboards/handwired/dactyl_manuform/3x5_3/keymaps/dlford/keymap.c
enum custom_keycodes {
    VVV = KC_TRNS,
    XXX = KC_NO,
    CSA_Q = MEH_T(KC_Q),
    CSA_F1 = MEH_T(KC_F1),
    CSA_1 = MEH_T(KC_1),
    CA_W = LCA_T(KC_W),
    CA_F2 = LCA_T(KC_F2),
    CA_2 = LCA_T(KC_2),
    CS_E = C_S_T(KC_E),
    CS_F = C_S_T(KC_F),
    CS_I = C_S_T(KC_I),
    CS_U = C_S_T(KC_U),
    CS_F3 = C_S_T(KC_F3),
    CS_3 = C_S_T(KC_3),
    CS_F8 = C_S_T(KC_F8),
    CS_8 = C_S_T(KC_8),
    CA_O = LCA_T(KC_O),
    CA_Y = LCA_T(KC_Y),
    CA_F9 = LCA_T(KC_F9),
    CA_9 = LCA_T(KC_9),
    CSA_P = MEH_T(KC_P),
    CSA_SCLN = MEH_T(KC_SCLN),
    CSA_F10 = MEH_T(KC_F10),
    CSA_0 = MEH_T(KC_0),
    LGUI_1 = LGUI_T(KC_1),
    LGUI_A = LGUI_T(KC_A),
    LGUI_FIND = LGUI_T(KC_FIND),
    LGUI_GRV = LGUI_T(KC_GRV),
    LALT_2 = LALT_T(KC_2),
    LALT_S = LALT_T(KC_S),
    LALT_R = LALT_T(KC_R),
    LALT_HOME = LALT_T(KC_HOME),
    LCTL_3 = LCTL_T(KC_3),
    LCTL_D = LCTL_T(KC_D),
    LCTL_S = LCTL_T(KC_S),
    LCTL_PGUP = LCTL_T(KC_PGUP),
    LCTL_LBRC = LCTL_T(KC_LBRC),
    LSFT_4 = LSFT_T(KC_4),
    LSFT_F = LSFT_T(KC_F),
    _LSFT_T = LSFT_T(KC_T),
    LSFT_PGDN = LSFT_T(KC_PGDN),
    LSFT_RBRC = LSFT_T(KC_RBRC),
    RSFT_7 = RSFT_T(KC_7),
    RSFT_J = RSFT_T(KC_J),
    RSFT_N = RSFT_T(KC_N),
    RSFT_DOWN = RSFT_T(KC_DOWN),
    RSFT_MINS = RSFT_T(KC_MINS),
    RCTL_8 = RCTL_T(KC_8),
    RCTL_K = RCTL_T(KC_K),
    RCTL_E = RCTL_T(KC_E),
    RCTL_UP = RCTL_T(KC_UP),
    RCTL_EQL = RCTL_T(KC_EQL),
    RALT_9 = RALT_T(KC_9),
    RALT_L = RALT_T(KC_L),
    RALT_I = RALT_T(KC_I),
    RALT_RGHT = RALT_T(KC_RGHT),
    RALT_BSLS = RALT_T(KC_BSLS),
    RGUI_0 = RGUI_T(KC_0),
    RGUI_SCLN = RGUI_T(KC_SCLN),
    RGUI_O = RGUI_T(KC_O),
    RGUI_F11 = RGUI_T(KC_F11),
    RGUI_QUOT = RGUI_T(KC_QUOT),
    LTNAV_SPC = LT(_NAVIGATION,KC_SPC),
    LT2_TAB = LT(2,KC_TAB),
    DF_QWERTY = DF(0),
    DF_COLEMAK = DF(1),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┐
      * │ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │
      * ├───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┤
      * │ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │
      * └───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┘
      *           ┌───┐                   ┌───┐
      *           │GUI├───┐           ┌───┤Alt│
      *           └───┤Bsp├───┐   ┌───┤Ent├───┘
      *               └───┤   │   │   ├───┘
      *                   └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,                         KC_H,    RSFT_J,  RCTL_K,  RALT_L, RGUI_SCLN,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMMA,  KC_DOT,  KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
	    KC_ESC,  LT(_NAVIGATION,KC_BSPC), KC_TAB,    KC_ENT, LT(_NUMBER,LTNAV_SPC),  KC_DEL
	    //LT(0,KC_ESC),  LT(1,KC_BSPC), LC(2,KC_TAB),    LT(3,KC_DEL), LT(4,LTNAV_SPC),  LT(5,KC_ENT)
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_COLEMAK] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                         KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            LGUI_A,  LALT_R,  LCTL_S,  _LSFT_T, KC_G,                         KC_M,    RSFT_N,  RCTL_E,  RALT_I,  RGUI_O,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMM,  KC_DOT,  KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
	    // LT(0,KC_ESC),  LT(1,KC_BSPC), LC(2,KC_TAB),    LT(3,KC_DEL), LT(4,LTNAV_SPC),  LT(5,KC_ENT)
	    KC_ESC,  LT(_NAVIGATION,KC_BSPC), KC_TAB,    KC_ENT, LT(_NUMBER,LTNAV_SPC),  KC_DEL
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_NAVIGATION] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            XXX,   XXX,    XXX,    XXX,    XXX,                         XXX,    XXX,    XXX,    XXX,    XXX,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT, XXX,                      KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  CW_TOGG,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            XXX,    XXX,    XXX,    XXX,    XXX,                             KC_INS,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       XXX,  XXX, XXX,             KC_MINS, KC_UNDS, KC_BSLS 
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_NUMBER] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_EXLM,  KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS,  KC_MINS,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            LGUI_1,  LALT_2,  LCTL_3,  LSFT_4, KC_5,                         KC_6,    RSFT_7,  RCTL_8,  RALT_9,  RGUI_0,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_COLN,                      KC_SCLN,  KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       KC_PIPE,  KC_BSPC, KC_EQL,    XXX, XXX,  XXX
        //                           |--------+--------+--------|  |--------+--------+--------|
    )
};

