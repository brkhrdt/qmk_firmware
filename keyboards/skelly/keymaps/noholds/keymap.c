// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include <stdint.h>
#include "eeconfig.h"
#include "keyboard.h"
#include "process_combo.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

#include "config.h"

#include "print.h"

typedef union {
    uint32_t raw;
    struct {
        uint16_t key_counts[16][5][8];
        uint16_t combo_counts[100];
    };
} user_config_t;

user_config_t user_config = {.key_counts = {{{0}}}, .combo_counts = {0}};
// use MATRIC_COL/ROW var?
/* static uint16_t key_history[16][5][8] = {{{0}}}; */

void keyboard_post_init_user(void) {
    // Customise these values to desired behaviour
    debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;

    eeconfig_read_user_datablock(&user_config);
}

// Layers
enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _L,
    _R,
    _LR,
    _RL,
    _G,
};

// Quantum keys / Abbreviations
// qmk_firmware/keyboards/handwired/dactyl_manuform/3x5_3/keymaps/dlford/keymap.c
enum custom_keycodes {
    VVV       = KC_TRNS,
    XXX       = KC_NO,
    CSA_Q     = MEH_T(KC_Q),
    CSA_F1    = MEH_T(KC_F1),
    CSA_1     = MEH_T(KC_1),
    CA_W      = LCA_T(KC_W),
    CA_F2     = LCA_T(KC_F2),
    CA_2      = LCA_T(KC_2),
    CS_E      = C_S_T(KC_E),
    CS_F      = C_S_T(KC_F),
    CS_I      = C_S_T(KC_I),
    CS_U      = C_S_T(KC_U),
    CS_F3     = C_S_T(KC_F3),
    CS_3      = C_S_T(KC_3),
    CS_F8     = C_S_T(KC_F8),
    CS_8      = C_S_T(KC_8),
    CA_O      = LCA_T(KC_O),
    CA_Y      = LCA_T(KC_Y),
    CA_F9     = LCA_T(KC_F9),
    CA_9      = LCA_T(KC_9),
    CSA_P     = MEH_T(KC_P),
    CSA_SCLN  = MEH_T(KC_SCLN),
    CSA_F10   = MEH_T(KC_F10),
    CSA_0     = MEH_T(KC_0),
    LGUI_1    = LGUI_T(KC_1),
    LGUI_5    = LGUI_T(KC_5),
    LGUI_A    = LGUI_T(KC_A),
    LGUI_G    = LGUI_T(KC_G),
    LGUI_FIND = LGUI_T(KC_FIND),
    LGUI_GRV  = LGUI_T(KC_GRV),
    LALT_2    = LALT_T(KC_2),
    LALT_S    = LALT_T(KC_S),
    LALT_R    = LALT_T(KC_R),
    LALT_HOME = LALT_T(KC_HOME),
    LCTL_3    = LCTL_T(KC_3),
    LCTL_D    = LCTL_T(KC_D),
    LCTL_S    = LCTL_T(KC_S),
    LCTL_PGUP = LCTL_T(KC_PGUP),
    LCTL_LBRC = LCTL_T(KC_LBRC),
    LSFT_4    = LSFT_T(KC_4),
    LSFT_F    = LSFT_T(KC_F),
    _LSFT_T   = LSFT_T(KC_T),
    LSFT_PGDN = LSFT_T(KC_PGDN),
    LSFT_RBRC = LSFT_T(KC_RBRC),
    RSFT_7    = RSFT_T(KC_7),
    RSFT_J    = RSFT_T(KC_J),
    RSFT_N    = RSFT_T(KC_N),
    RSFT_DOWN = RSFT_T(KC_DOWN),
    RSFT_MINS = RSFT_T(KC_MINS),
    RCTL_8    = RCTL_T(KC_8),
    RCTL_K    = RCTL_T(KC_K),
    RCTL_E    = RCTL_T(KC_E),
    RCTL_UP   = RCTL_T(KC_UP),
    RCTL_EQL  = RCTL_T(KC_EQL),
    RALT_9    = RALT_T(KC_9),
    RALT_L    = RALT_T(KC_L),
    RALT_I    = RALT_T(KC_I),
    RALT_RGHT = RALT_T(KC_RGHT),
    RALT_BSLS = RALT_T(KC_BSLS),
    RGUI_0    = RGUI_T(KC_0),
    RGUI_6    = RGUI_T(KC_6),
    RGUI_SCLN = RGUI_T(KC_SCLN),
    RGUI_O    = RGUI_T(KC_O),
    RGUI_M    = RGUI_T(KC_M),
    RGUI_F11  = RGUI_T(KC_F11),
    RGUI_QUOT = RGUI_T(KC_QUOT),
    /* LTNAV_SPC = LT(_NAVIGATION,KC_SPC), */
    /* LTNAV_A = LT(_NAVIGATION,KC_A), */
    /* LTNUM_A = LT(_NUMBER,KC_A), */
    /* LTNUM_O = LT(_NUMBER,KC_O), */
    LT2_TAB    = LT(2, KC_TAB),
    DF_QWERTY  = DF(0),
    DF_COLEMAK = DF(1),

    // my keys
    // top row
    my_Q    = KC_Q,
    my_W    = KC_W,
    my_F    = KC_F,
    my_P    = KC_P,
    my_B    = KC_B,
    my_J    = KC_J,
    my_L    = KC_L,
    my_U    = KC_U,
    my_Y    = KC_Y,
    my_QUOT = KC_QUOT,

    // home row
    my_A = KC_A,
    my_R = KC_R,
    my_S = KC_S,
    my_T = KC_T,
    my_G = KC_G,
    my_M = KC_M,
    my_N = KC_N,
    my_E = KC_E,
    my_I = KC_I,
    my_O = KC_O,

    // bottom row
    my_Z     = KC_Z,
    my_X     = KC_X,
    my_C     = KC_C,
    my_D     = KC_D,
    my_V     = KC_V,
    my_K     = KC_K,
    my_H     = KC_H,
    my_COMMA = KC_COMM,
    my_DOT   = KC_DOT,
    my_SLSH  = KC_SLSH,

    // thumb row
    my_ESC  = KC_ESC,
    my_BSPC = KC_BSPC,
    my_TAB  = KC_TAB,
    my_ENT  = KC_ENT,
    my_SPC  = KC_SPC,

    // Escape

    // Custom keys
    VIM_WINDOW_LEFT = SAFE_RANGE,
    VIM_WINDOW_RIGHT,
    VIM_WINDOW_DOWN,
    VIM_WINDOW_UP,
    EJECT,
    SHIFT_INSERT,
    DUMPCNT,
};

enum combos {

    // top + home row
    QA_COMBO,
    WR_COMBO,
    FS_COMBO,
    PT_COMBO,
    BG_COMBO,
    JM_COMBO,
    LN_COMBO,
    UE_COMBO,
    YI_COMBO,
    QUOTO_COMBO,

    // home + bottom row
    AZ_COMBO,
    RX_COMBO,
    SC_COMBO,
    TD_COMBO,
    GV_COMBO,
    MK_COMBO,
    NH_COMBO,
    ECOMMA_COMBO,
    IDOT_COMBO,
    OSLSH_COMBO,

    // center index finger
    PB_COMBO,
    TG_COMBO,
    DV_COMBO,
    JL_COMBO,
    MN_COMBO,
    KH_COMBO,

    /* MK_COMBO, */
    /* NH_COMBO, */
    /* ECOMMA_COMBO, */
    /* IDOT_COMBO, */
    /* OSLASH_COMBO, */

    TN_COMBO,
    ST_COMBO,
    NE_COMBO,
    ZX_COMBO,
    XC_COMBO,
    CD_COMBO,
    HCOMMA_COMBO,
    COMMADOT_COMBO,
    DOTSLASH_COMBO
};

const uint16_t PROGMEM pt_combo[] = {my_P, my_T, COMBO_END};
const uint16_t PROGMEM bg_combo[] = {my_B, my_G, COMBO_END};
const uint16_t PROGMEM jm_combo[] = {my_J, my_M, COMBO_END};
const uint16_t PROGMEM ln_combo[] = {my_L, my_N, COMBO_END};

const uint16_t PROGMEM gv_combo[] = {my_G, my_V, COMBO_END};

const uint16_t PROGMEM mk_combo[]     = {my_M, my_K, COMBO_END};
const uint16_t PROGMEM nh_combo[]     = {my_N, my_H, COMBO_END};
const uint16_t PROGMEM ecomma_combo[] = {my_E, my_COMMA, COMBO_END};
const uint16_t PROGMEM idot_combo[]   = {my_I, my_DOT, COMBO_END};
const uint16_t PROGMEM oslash_combo[] = {my_O, my_SLSH, COMBO_END};

const uint16_t PROGMEM tn_combo[] = {my_T, my_N, COMBO_END};
const uint16_t PROGMEM st_combo[] = {my_S, my_T, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {my_N, my_E, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {my_Z, my_X, COMBO_END};
/* const uint16_t PROGMEM xc_combo[] = {my_X, my_C, COMBO_END}; */
const uint16_t PROGMEM cd_combo[]       = {my_C, my_D, COMBO_END};
const uint16_t PROGMEM hcomma_combo[]   = {my_H, my_COMMA, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {my_COMMA, my_DOT, COMBO_END};
const uint16_t PROGMEM dotslash_combo[] = {my_DOT, my_SLSH, COMBO_END};

#define COMBOEND (uint8_t)-1
/* #ifdef KEYPOS_COMBOS */
/* #define COMBO(l, ck, ca) \  */
/*   { .layer = (l), .keyposes = &(ck)[0], .keycode = (ca) } */
/* #endif */
const keypos_t kps[3] = {{0, 0}, {0, 1}, {COMBOEND, COMBOEND}};
const combo_t  c      = {.layer=_L, .keyposes = kps, .keycode = KC_EQL};

// clang-format off
#define COMBO_LAYOUT( L, H00, H01, H02, H03, H04,    H05, H06, H07, H08, H09, H10, H11, H12, H13, H14,    H15, H16, H17, H18, H19 ) \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 0}, {1, 0}, {COMBOEND, COMBOEND}}, .keycode = H00}, \
      {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 1}, {1, 1}, {COMBOEND, COMBOEND}}, .keycode = H01}, \
      {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 2}, {1, 2}, {COMBOEND, COMBOEND}}, .keycode = H02}, \
      {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 3}, {1, 3}, {COMBOEND, COMBOEND}}, .keycode = H03}, \
      {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 4}, {1, 4}, {COMBOEND, COMBOEND}}, .keycode = H04}, 

#define COMBO_LAYOUT_VERTICAL( L, V00, V01, V02, V03, V04,    V05, V06, V07, V08, V09, V10, V11, V12, V13, V14,    V15, V16, V17, V18, V19 ) \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 0}, {0, 1}, {COMBOEND, COMBOEND}}, .keycode = V00}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{1, 0}, {1, 1}, {COMBOEND, COMBOEND}}, .keycode = V01}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{2, 0}, {2, 1}, {COMBOEND, COMBOEND}}, .keycode = V02}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{3, 0}, {3, 1}, {COMBOEND, COMBOEND}}, .keycode = V03}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{4, 0}, {4, 1}, {COMBOEND, COMBOEND}}, .keycode = V04}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{4, 4}, {4, 5}, {COMBOEND, COMBOEND}}, .keycode = V05}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{3, 4}, {3, 5}, {COMBOEND, COMBOEND}}, .keycode = V06}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{2, 4}, {2, 5}, {COMBOEND, COMBOEND}}, .keycode = V07}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{1, 4}, {1, 5}, {COMBOEND, COMBOEND}}, .keycode = V08}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 4}, {0, 5}, {COMBOEND, COMBOEND}}, .keycode = V09}, \
\
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 1}, {0, 2}, {COMBOEND, COMBOEND}}, .keycode = V10}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{1, 1}, {1, 2}, {COMBOEND, COMBOEND}}, .keycode = V11}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{2, 1}, {2, 2}, {COMBOEND, COMBOEND}}, .keycode = V12}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{3, 1}, {3, 2}, {COMBOEND, COMBOEND}}, .keycode = V13}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{4, 1}, {4, 2}, {COMBOEND, COMBOEND}}, .keycode = V14}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{4, 5}, {4, 6}, {COMBOEND, COMBOEND}}, .keycode = V15}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{3, 5}, {3, 6}, {COMBOEND, COMBOEND}}, .keycode = V16}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{2, 5}, {2, 6}, {COMBOEND, COMBOEND}}, .keycode = V17}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{1, 5}, {1, 6}, {COMBOEND, COMBOEND}}, .keycode = V18}, \
  {.layer = L, .keyposes = (const keypos_t PROGMEM[]){{0, 5}, {0, 6}, {COMBOEND, COMBOEND}}, .keycode = V19}

/* combo_t key_combos[] = { */
/*   [0] = c, */
/* }; */
combo_t key_combos[] =
    {
 COMBO_LAYOUT_VERTICAL(_COLEMAK,
        //|--------------------------------------------|                    |--------------------------------------------|
           KC_PIPE, KC_EQL,   KC_UNDS,  KC_MINS,    KC_COLN,              KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,    KC_BSLS,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
           KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                       ),
 COMBO_LAYOUT_VERTICAL(_L,
        //|--------------------------------------------|                    |--------------------------------------------|
           OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,            KC_DEL, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT),  OSM(MOD_RGUI),
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                       ),
 COMBO_LAYOUT_VERTICAL(_R,
        //|--------------------------------------------|                    |--------------------------------------------|
           OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,            KC_DEL, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT),  OSM(MOD_RGUI),
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,    KC_7,    KC_8,    KC_9,    KC_0
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
                       ),


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
    /* [_QWERTY] = LAYOUT_split_3x5_3( */
    /*     //|--------------------------------------------|                    |--------------------------------------------| */
    /*         KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, */
    /*     //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------| */
    /*         LGUI_A,  LALT_S,  LCTL_D,  LSFT_F,  KC_G,                         KC_H,    RSFT_J,  RCTL_K,  RALT_L, RGUI_SCLN, */
    /*     //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------| */
    /*         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMMA,  KC_DOT,  KC_SLSH, */
    /*     //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------| */
	/*     KC_ESC,  LT(_NAVIGATION,KC_BSPC), KC_TAB,    KC_ENT, LT(_NUMBER,LTNAV_SPC), TG(_NUMBER) */
	/*     //LT(0,KC_ESC),  LT(1,KC_BSPC), LC(2,KC_TAB),    LT(3,KC_DEL), LT(4,LTNAV_SPC),  LT(5,KC_ENT) */
    /*     //                           |--------+--------+--------|  |--------+--------+--------| */
    /* ), */
    [_COLEMAK] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            my_Q,   my_W,    my_F,    my_P,    my_B,                          my_J,    my_L,    my_U,    my_Y,    my_QUOT,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            my_A,   my_R,    my_S,    my_T,    my_G,                          my_M,    my_N,    my_E,    my_I,    my_O,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            my_Z,    my_X,    my_C,    my_D,    my_V,                         my_K,    my_H,    my_COMMA,  my_DOT,  my_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
	    // LT(0,my_ESC),  LT(1,my_BSPC), LC(2,my_TAB),    LT(3,my_DEL), LT(4,LTNAV_SPC),  LT(5,my_ENT)
                                       EJECT, OSL(_R), my_TAB,      my_ENT,  OSL(_L), my_SPC
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_L] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                             _______,  _______, _______,  _______, _______,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,       _______,  _______, _______,  _______, _______,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_PLUS,                       _______,  _______, _______,  _______, _______, 
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       TO(0),  TO(_LR), _______,    _______, _______,  _______
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_LR] = LAYOUT_split_3x5_3( 
        //|--------------------------------------------|                             |--------------------------------------------|
            KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
        //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,                     KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  XXX,
        //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_PLUS,                                  KC_INS,  KC_PGDN,  KC_PGUP,  KC_HOME, KC_END,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                           TO(0),  XXX, _______,             _______, XXX, _______
            //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_R] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
           _______,    _______,     _______,    _______,   _______,                KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            _______,  _______, _______,  _______, _______,                      KC_DEL, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT),  OSM(MOD_RGUI),
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            _______, _______, _______,   _______, _______,                      KC_SCLN,  KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                        TO(0),  XXX, _______,    _______, TO(_RL),  TO(_G)
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_RL] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                     |--------------------------------------------|
            DUMPCNT,  KC_2,  KC_3,  KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
        //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,            KC_DEL, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT),  OSM(MOD_RGUI),
        //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_PLUS,                       KC_SCLN,  KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       TO(0), XXX, _______,    _______, XXX,  _______
        //                           |--------+--------+--------|  |--------+--------+--------|
                               ),
    [_G] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                          KC_J,    KC_L,    KC_U,    KC_Y,    KC_QUOT,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                          KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,                         KC_K,    KC_H,    KC_COMMA,  KC_DOT,  KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                             KC_TAB, KC_SPC, KC_LSFT,      KC_ENT,  KC_BSPC, TO(0)
        //                           |--------+--------+--------|  |--------+--------+--------|
    )
};
// clang-format on

/* // Add more time to windows key triggering */
/* uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { */
/*     switch (keycode) { */
/*         case LTNUM_A: */
/*             return TAPPING_TERM + 150; */
/*         case LTNUM_O: */
/*             return TAPPING_TERM + 150; */
/*         case LGUI_G: */
/*             return TAPPING_TERM + 250; */
/*         case RGUI_M: */
/*             return TAPPING_TERM + 250; */
/*         case LGUI_A: */
/*             return TAPPING_TERM + 250; */
/*         case RGUI_O: */
/*             return TAPPING_TERM + 250; */
/*         default: */
/*             return TAPPING_TERM; */
/*     } */
/* } */

/* void process_combo_event(uint16_t combo_index, bool pressed) { */
/*   switch(combo_index) { */
/*     case VIM_WINDOW_LEFT_COMBO: */
/*       if (pressed) { */
/* 	// Send Control+W */
/* 	register_code(KC_LCTL); */
/* 	tap_code(KC_W); */
/* 	unregister_code(KC_LCTL); */

/*         // Send J */
/*         tap_code(KC_H); */
/*       } */
/*       break; */
/*     case VIM_WINDOW_RIGHT_COMBO: */
/*       if (pressed) { */
/* 	// Send Control+W */
/* 	register_code(KC_LCTL); */
/* 	tap_code(KC_W); */
/* 	unregister_code(KC_LCTL); */

/*         // Send J */
/*         tap_code(KC_L); */
/*       } */
/*       break; */
/*   } */
/* } */

void dprint_key_counts(void) {
    uint32_t total = 0;
    for (int i = 0; i < 16; i++) {
        dprintf("Layer %d:\n", i);
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 8; k++) {
                dprintf("%5u ", user_config.key_counts[i][j][k]);
                total += user_config.key_counts[i][j][k];
            }
            dprintf("\n");
        }
        dprintf("\n");
    }
    dprintf("Total: %lu\n", total);
}

void send_key_count_csv(void) {
    char csvrowstr[100];
    SEND_STRING("layer,col,row,count,combo\n");
    for (uint8_t layer = 0; layer < 16; layer++) {
        for (uint8_t col = 0; col < 5; col++) {
            for (uint8_t row = 0; row < 8; row++) {
                snprintf(csvrowstr, sizeof(csvrowstr), "%u,%u,%u,%u,-1\n", layer, col, row, user_config.key_counts[layer][col][row]);
                SEND_STRING(csvrowstr);
            }
        }
    }
    for (uint8_t combo = 0; combo < 100; combo++) {
        snprintf(csvrowstr, sizeof(csvrowstr), "%u,%u,%u,%u,%u\n", 0, 0, 0, user_config.combo_counts[combo], combo);
        SEND_STRING(csvrowstr);
    }
}

uint16_t onehot_to_int(uint16_t onehot) {
    if (onehot == 0) {
        return 0; // check early if default layer
    }
    for (int i = 0; i < 16; i++) {
        if (onehot & (1 << i)) {
            return i;
        }
    }
    return 0; // default layer
}

void count_press(keyrecord_t *record) {
    /* uint16_t layer = onehot_to_int(layer_state); */
    uint8_t col = record->event.key.col;
    uint8_t row = record->event.key.row;

    uint8_t layer = get_highest_layer(layer_state);

    if (record->event.type == KEY_EVENT) {
        dprintf("Record key press: lay: %2u, col: %2u, row: %2u\n", layer, col, row);
        user_config.key_counts[layer][col][row] += 1;
    }
}

/* void process_combo_event(uint16_t combo_index, bool pressed) { */
/*   dprintf("COMBO: idx: %2u, pressed: %2u\n", combo_index, pressed); */
/*   /\* count_combo(combo_index); *\/ */
/*   if (pressed) { */
/*     uint8_t layer = get_highest_layer(layer_state); */
/*     dprintf("Record combo press: lay: %2u, idx: %2u\n", layer, combo_index); */
/*     user_config.combo_counts[combo_index] += 1; */
/*   } */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, type: %u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.type, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    if (record->event.pressed) {
        count_press(record);
        static uint16_t key_presses = 0;
        key_presses += 1;
        if (key_presses > 1000) {
            dprint("Updating eeprom with current key counts.\n");
            eeconfig_update_user_datablock(&user_config); // Writes the new status to EEPROM
            key_presses = 0;
        }
    }
    switch (keycode) {
        case SHIFT_INSERT:
            if (record->event.pressed) {
                register_code(KC_LSFT);
                tap_code(KC_INSERT);
                unregister_code(KC_LSFT);
            }
            break;
        case DUMPCNT:
            if (record->event.pressed) {
                dprint_key_counts();
                send_key_count_csv();
            }
            break;
        case EJECT:
            // have this key in the default layer and it
            // will first clear mods, if no mods then it sends escape
            // other layers this position should TO(0) back to default layer so
            // that if you enable layer to lock a oneshot mod, you can get back to default layer to
            // use the locked mod with both sides e.g. C-d and C-u
            if (record->event.pressed) {
                const uint8_t mods = get_mods() | get_oneshot_mods() | get_weak_mods() | get_oneshot_locked_mods();
                // if layr clear, elif mods clear, else esc
                /* if (!layer_state_is(0)) { */
                /*   layer_clear(); */
                /* } */
                /* else if (mods) { */
                if (mods) {
                    clear_mods();
                    clear_weak_mods();
                    clear_oneshot_mods();
                    clear_oneshot_locked_mods();
                } else {
                    tap_code(KC_ESC);
                }
                /* } */
            }
            break;

        case VIM_WINDOW_LEFT:
            if (record->event.pressed) {
                /* SEND_STRING(SS_LCTRL("w")"h"); */
                // Send Control+W
                tap_code(KC_ESC);
                register_code(KC_LCTL);
                tap_code(KC_W);
                unregister_code(KC_LCTL);

                // Send J
                tap_code(KC_H);
            }
            break;
        case VIM_WINDOW_RIGHT:
            if (record->event.pressed) {
                // Send Control+W
                tap_code(KC_ESC);
                register_code(KC_LCTL);
                tap_code(KC_W);
                unregister_code(KC_LCTL);

                // Send J
                tap_code(KC_L);
            }
            break;
        case VIM_WINDOW_DOWN:
            if (record->event.pressed) {
                // Send Control+W
                tap_code(KC_ESC);
                register_code(KC_LCTL);
                tap_code(KC_W);
                unregister_code(KC_LCTL);

                // Send J
                tap_code(KC_J);
            }
            break;
        case VIM_WINDOW_UP:
            if (record->event.pressed) {
                // Send Control+W
                tap_code(KC_ESC);
                register_code(KC_LCTL);
                tap_code(KC_W);
                unregister_code(KC_LCTL);

                // Send J
                tap_code(KC_K);
            }
            break;
    }
    return true;
}
