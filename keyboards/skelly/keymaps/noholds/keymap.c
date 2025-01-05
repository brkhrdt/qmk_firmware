// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "config.h"


// Layers
enum layers {
    _COLEMAK = 0,
    _QWERTY,
    _L,
    _R,
    _LR,
    _RL,
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
    LGUI_5 = LGUI_T(KC_5),
    LGUI_A = LGUI_T(KC_A),
    LGUI_G = LGUI_T(KC_G),
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
    RGUI_6 = RGUI_T(KC_6),
    RGUI_SCLN = RGUI_T(KC_SCLN),
    RGUI_O = RGUI_T(KC_O),
    RGUI_M = RGUI_T(KC_M),
    RGUI_F11 = RGUI_T(KC_F11),
    RGUI_QUOT = RGUI_T(KC_QUOT),
    /* LTNAV_SPC = LT(_NAVIGATION,KC_SPC), */
    /* LTNAV_A = LT(_NAVIGATION,KC_A), */
    /* LTNUM_A = LT(_NUMBER,KC_A), */
    /* LTNUM_O = LT(_NUMBER,KC_O), */
    LT2_TAB = LT(2,KC_TAB),
    DF_QWERTY = DF(0),
    DF_COLEMAK = DF(1),

    // my keys
    // top row
    my_Q = KC_Q,
    my_W = KC_W,
    my_F = KC_F,
    my_P = KC_P,
    my_B = KC_B,
    my_J = KC_J,
    my_L = KC_L,
    my_U = KC_U,
    my_Y = KC_Y,
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
    my_Z = KC_Z,
    my_X = KC_X,
    my_C = KC_C,
    my_D = KC_D,
    my_V = KC_V,
    my_K = KC_K,
    my_H = KC_H,
    my_COMMA = KC_COMM,
    my_DOT = KC_DOT,
    my_SLSH = KC_SLSH,

    // thumb row
    my_ESC = KC_ESC,
    my_BSPC = KC_BSPC,
    my_TAB = KC_TAB,
    my_ENT = KC_ENT,
    my_SPC = KC_SPC,

    // Escape
    ESCBSPC = LT(0, KC_ESC),
    
    // Custom keys
    VIM_WINDOW_LEFT = SAFE_RANGE,
    VIM_WINDOW_RIGHT,
    VIM_WINDOW_DOWN,
    VIM_WINDOW_UP,
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

const uint16_t PROGMEM mk_combo[] = {my_M, my_K, COMBO_END};
const uint16_t PROGMEM nh_combo[] = {my_N, my_H, COMBO_END};
const uint16_t PROGMEM ecomma_combo[] = {my_E, my_COMMA, COMBO_END};
const uint16_t PROGMEM idot_combo[] = {my_I, my_DOT, COMBO_END};
const uint16_t PROGMEM oslash_combo[] = {my_O, my_SLSH, COMBO_END};

const uint16_t PROGMEM tn_combo[] = {my_T, my_N, COMBO_END};
const uint16_t PROGMEM st_combo[] = {my_S, my_T, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {my_N, my_E, COMBO_END};
const uint16_t PROGMEM zx_combo[] = {my_Z, my_X, COMBO_END};
/* const uint16_t PROGMEM xc_combo[] = {my_X, my_C, COMBO_END}; */
const uint16_t PROGMEM cd_combo[] = {my_C, my_D, COMBO_END};
const uint16_t PROGMEM hcomma_combo[] = {my_H, my_COMMA, COMBO_END};
const uint16_t PROGMEM commadot_combo[] = {my_COMMA, my_DOT, COMBO_END};
const uint16_t PROGMEM dotslash_combo[] = {my_DOT, my_SLSH, COMBO_END};

combo_t key_combos[] = {
  [QA_COMBO] = COMBO(((const uint16_t PROGMEM []){my_Q, my_A, COMBO_END}	 ), KC_PIPE),	
  [WR_COMBO] = COMBO(((const uint16_t PROGMEM []){my_W, my_R, COMBO_END}	 ), KC_EQL),	
  [FS_COMBO] = COMBO(((const uint16_t PROGMEM []){my_F, my_S, COMBO_END}	 ), KC_UNDS),	
  [PT_COMBO] = COMBO(((const uint16_t PROGMEM []){my_P, my_T, COMBO_END}	 ), KC_MINS),	
  [BG_COMBO] = COMBO(((const uint16_t PROGMEM []){my_B, my_G, COMBO_END}	 ), KC_COLN),	
  [JM_COMBO] = COMBO(((const uint16_t PROGMEM []){my_J, my_M, COMBO_END}	 ), KC_LEFT),        	
  [LN_COMBO] = COMBO(((const uint16_t PROGMEM []){my_L, my_N, COMBO_END}	 ), KC_DOWN),        	
  [UE_COMBO] = COMBO(((const uint16_t PROGMEM []){my_U, my_E, COMBO_END}	 ), KC_UP),          	
  [YI_COMBO] = COMBO(((const uint16_t PROGMEM []){my_Y, my_I, COMBO_END}	 ), KC_RGHT),        	
  [QUOTO_COMBO] = COMBO(((const uint16_t PROGMEM []){my_QUOT, my_O, COMBO_END}	 ), KC_BSLS),        	


  [AZ_COMBO] = COMBO(((const uint16_t PROGMEM []){my_A, my_Z, COMBO_END}	 ), KC_1),	
  [RX_COMBO] = COMBO(((const uint16_t PROGMEM []){my_R, my_X, COMBO_END}	 ), KC_2),	
  [SC_COMBO] = COMBO(((const uint16_t PROGMEM []){my_S, my_C, COMBO_END}	 ), KC_3),	
  [TD_COMBO] = COMBO(((const uint16_t PROGMEM []){my_T, my_D, COMBO_END}	 ), KC_4),	
  [GV_COMBO] = COMBO(((const uint16_t PROGMEM []){my_G, my_V, COMBO_END}	 ), KC_5),	
  [MK_COMBO] = COMBO(((const uint16_t PROGMEM []){my_M, my_K, COMBO_END}	 ), KC_6),	
  [NH_COMBO] = COMBO(((const uint16_t PROGMEM []){my_N, my_H, COMBO_END}	 ), KC_7),	
  [ECOMMA_COMBO] = COMBO(((const uint16_t PROGMEM []){my_E, my_COMMA, COMBO_END} ), KC_8),	
  [IDOT_COMBO] = COMBO(((const uint16_t PROGMEM []){my_I, my_DOT, COMBO_END}	 ), KC_9),	
  [OSLSH_COMBO] = COMBO(((const uint16_t PROGMEM []){my_O, my_SLSH, COMBO_END}	 ), KC_0),	

  [PB_COMBO] = COMBO(((const uint16_t PROGMEM []){my_P, my_B, COMBO_END}		), VIM_WINDOW_LEFT), // change to alt tab
  [TG_COMBO] = COMBO(((const uint16_t PROGMEM []){my_T, my_G, COMBO_END}		), VIM_WINDOW_LEFT),
  [DV_COMBO] = COMBO(((const uint16_t PROGMEM []){my_D, my_V, COMBO_END}		), VIM_WINDOW_UP),
  [JL_COMBO] = COMBO(((const uint16_t PROGMEM []){my_J, my_L, COMBO_END}		), VIM_WINDOW_LEFT), // change to alt tab
  [MN_COMBO] = COMBO(((const uint16_t PROGMEM []){my_M, my_N, COMBO_END}		), VIM_WINDOW_RIGHT),
  [KH_COMBO] = COMBO(((const uint16_t PROGMEM []){my_K, my_H, COMBO_END}		), VIM_WINDOW_DOWN),

  /* [PT_COMBO] = COMBO(((const uint16_t PROGMEM []){my_P, my_T, COMBO_END}), VIM_WINDOW_LEFT), */
  /* [BG_COMBO] = COMBO(bg_combo, VIM_WINDOW_DOWN), */
  /* [JM_COMBO] = COMBO(jm_combo, VIM_WINDOW_UP), */
  /* [LN_COMBO] = COMBO(ln_combo, VIM_WINDOW_RIGHT), */
  /* [GV_COMBO] = COMBO(gv_combo, KC_COLN), */
  /* [MK_COMBO] = COMBO(mk_combo, KC_LEFT), */
  /* [NH_COMBO] = COMBO(nh_combo, KC_DOWN), */
  /* [ECOMMA_COMBO] = COMBO(ecomma_combo, KC_UP), */
  /* [IDOT_COMBO] = COMBO(idot_combo, KC_RGHT), */
  /* /\* [OSLASH_COMBO] = COMBO(oslash_combo,), *\/ */

  [TN_COMBO] = COMBO(tn_combo, CW_TOGG),
  /* [ST_COMBO] = COMBO(st_combo, KC_TAB), */
  /* [NE_COMBO] = COMBO(ne_combo, KC_DEL), */
  /* [ZX_COMBO] = COMBO(zx_combo, KC_PIPE), */
  /* /\* [XC_COMBO] = COMBO(xc_combo, KC_PIPE), *\/ */
  /* [CD_COMBO] = COMBO(cd_combo, KC_EQL), */
  /* [HCOMMA_COMBO] = COMBO(hcomma_combo, KC_MINS), */
  /* [COMMADOT_COMBO] = COMBO(commadot_combo, KC_UNDS), */
  /* [DOTSLASH_COMBO] = COMBO(dotslash_combo, KC_BSLS) */
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
                                       ESCBSPC, OSL(_R), my_TAB,      my_ENT,  OSL(_L), my_SPC
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_L] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                    |--------------------------------------------|
            KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                             _______,  _______, _______,  _______, _______,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,       _______,  _______, _______,  _______, _______,
        //|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_COLN,                       _______,  _______, _______,  _______, _______, 
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       TO(0),  TG(_LR), KC_EQL,    _______, _______,  _______
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_LR] = LAYOUT_split_3x5_3( // TODO need to make transparent keys hardcoded b/c osm layer wipes
        //|--------------------------------------------|                             |--------------------------------------------|
            KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                                             KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
        //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,                     KC_LEFT, KC_DOWN,  KC_UP,  KC_RGHT,  XXX,
        //|--------+--------+--------+--------+--------|                             |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_COLN,                                  KC_INS,  KC_HOME, KC_PGDN,  KC_PGUP,  KC_END,
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
                                        TO(0),  XXX, _______,    _______, TG(_RL),  _______
        //                           |--------+--------+--------|  |--------+--------+--------|
    ),
    [_RL] = LAYOUT_split_3x5_3(
        //|--------------------------------------------|                     |--------------------------------------------|
            KC_1,  KC_2,  KC_3,  KC_4,    KC_5,                                     KC_6,    KC_7,    KC_8,    KC_9,   KC_0,
        //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LCTL), OSM(MOD_LSFT),  KC_BSPC,            KC_DEL, OSM(MOD_RSFT), OSM(MOD_RCTL), OSM(MOD_RALT),  OSM(MOD_RGUI),
        //|--------+--------+--------+--------+--------|                     |--------+--------+--------+--------+--------|
            KC_TILD, KC_LCBR, KC_LBRC,   KC_LPRN, KC_COLN,                       KC_SCLN,  KC_RPRN, KC_RBRC, KC_RCBR,  KC_GRV,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       TO(0), XXX, _______,    _______, XXX,  _______
        //                           |--------+--------+--------|  |--------+--------+--------|
    )
};


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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ESCBSPC:
    // https://getreuer.info/posts/keyboards/faqs/index.html#mt-doesnt-work-with-this-keycode-qmk
    /* if (record->tap.count == 0) { */
    /*   if (record->event.pressed) { */
    /*     register_code(KC_BSPC); */
    /*   } else { */
    /*     unregister_code(KC_BSPC); */
    /*   } */
    /* } else { */
    /*   clear_oneshot_mods(); */
    /*   clear_oneshot_locked_mods(); */
    /*   unregister_mods(mods); */
      clear_keyboard();
      tap_code(KC_ESC);
    /* } */
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
