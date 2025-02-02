// Copyright 2024 @Filios92
// SPDX-License-Identifier: GPL-2.0-or-later

#include "keyboard_report_util.hpp"
#include "quantum.h"
#include "keycode.h"
#include "test_common.h"
#include "test_driver.hpp"
#include "test_fixture.hpp"
#include "test_keymap_key.hpp"

using testing::_;
using testing::InSequence;

class ComboKeypos : public TestFixture {};

// Tests on default layer
TEST_F(ComboKeypos, combo_default_layer_combo_match) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    set_keymap({key_1, key_2});

    EXPECT_REPORT(driver, (KC_SPACE));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_1, key_2});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combo_reverse) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    set_keymap({key_1, key_2});

    EXPECT_REPORT(driver, (KC_SPACE));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_2, key_1});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combo_repeat) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    set_keymap({key_1, key_2});

    EXPECT_REPORT(driver, (KC_SPACE)).Times(2);
    EXPECT_EMPTY_REPORT(driver).Times(2);
    tap_combo({key_1, key_2});
    tap_combo({key_1, key_2});
    VERIFY_AND_CLEAR(driver);
}


TEST_F(ComboKeypos, combo_default_layer_combo_nomatch) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    KeymapKey  key_3(0, 1, 0, KC_3);
    set_keymap({key_1, key_2, key_3});

    EXPECT_REPORT(driver, (KC_1));
    EXPECT_REPORT(driver, (KC_1, KC_3));
    EXPECT_REPORT(driver, (KC_3));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_1, key_3});
    // idle_for(1000);
    VERIFY_AND_CLEAR(driver);
}

// Tests on layer 1
TEST_F(ComboKeypos, combo_osl_combo_match) {
    TestDriver driver;
    KeymapKey  key_1_0(0, 0, 0, KC_A); // need something on default layer
    KeymapKey  key_2_0(0, 0, 1, KC_B); // need something on default layer
    KeymapKey  osl_key = KeymapKey{0, 1, 1, OSL(1)};
    KeymapKey  key_1(1, 0, 0, KC_1);
    KeymapKey  key_2(1, 0, 1, KC_2); // FOR testing changed col to 1
    set_keymap({key_1_0, key_2_0, osl_key, key_1, key_2});
    

    EXPECT_REPORT(driver, (KC_ENTER));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(osl_key);
    expect_layer_state(1);
    tap_combo({key_1, key_2});

    // key_1.press();
    // run_one_scan_loop();
    // idle_for(COMBO_TERM-1);
    // key_2.press();
    // run_one_scan_loop();
    // expect_layer_state(1);
    // key_1.release();
    // run_one_scan_loop();
    // key_2.release();
    // run_one_scan_loop();

    VERIFY_AND_CLEAR(driver);
}


TEST_F(ComboKeypos, combo_osl_combo_match_reverse_order) {
    TestDriver driver;
    KeymapKey  key_1_0(0, 0, 0, KC_A);
    KeymapKey  osl_key = KeymapKey{0, 0, 1, OSL(1)};
    KeymapKey  key_1(1, 0, 0, KC_1);
    KeymapKey  key_2(1, 0, 1, KC_2);
    set_keymap({key_1_0, osl_key, key_1, key_2});

    EXPECT_REPORT(driver, (KC_ENTER));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(osl_key);
    tap_combo({key_2, key_1});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_osl_locked_combo_repeat) {
    TestDriver driver;
    KeymapKey  key_1_0(0, 0, 0, KC_A);
    KeymapKey  key_2_0(0, 0, 1, KC_B);
    KeymapKey  osl_key = KeymapKey{0, 1, 1, OSL(1)};
    KeymapKey  key_1(1, 0, 0, KC_1);
    KeymapKey  key_2(1, 0, 1, KC_2);
    // KeymapKey  key_trns(1, 1, 1, KC_TRANSPARENT);
    KeymapKey  key_trns(1, 1, 1, QK_LAYER_LOCK);
    set_keymap({key_1_0, key_2_0, osl_key, key_1, key_2, key_trns});

    EXPECT_REPORT(driver, (KC_ENTER)).Times(2);
    EXPECT_EMPTY_REPORT(driver).Times(2);
    expect_layer_state(0);
    tap_key(osl_key);
    expect_layer_state(1);
    tap_key(key_trns);
    tap_key(key_trns);
    tap_key(key_trns);
    tap_key(key_trns);
    expect_layer_state(1);
    idle_for(5000);
    expect_layer_state(1);
    tap_combo({key_1, key_2});
    idle_for(500);
    tap_combo({key_2, key_1});
    VERIFY_AND_CLEAR(driver);
}


TEST_F(ComboKeypos, combo_first_layer_combo_nomatch) {
    TestDriver driver;
    KeymapKey  key_1_0(0, 0, 0, KC_A);
    KeymapKey  osl_key = KeymapKey{0, 0, 1, OSL(1)};
    KeymapKey  key_3_0(0, 1, 0, KC_C);
    KeymapKey  key_1(1, 0, 0, KC_1);
    KeymapKey  key_2(1, 0, 1, KC_2);
    KeymapKey  key_3(1, 1, 0, KC_3);
    set_keymap({key_1_0, osl_key, key_3_0, key_1, key_2, key_3});
    {
      InSequence s;
      EXPECT_REPORT(driver, (KC_1));
      EXPECT_EMPTY_REPORT(driver);
      EXPECT_REPORT(driver, (KC_C));
      EXPECT_EMPTY_REPORT(driver);
    }
    tap_key(osl_key);
    tap_combo({key_1, key_3});
    VERIFY_AND_CLEAR(driver);
}

// TEST_F(Combo, combo_modtest_held_longer_than_tapping_term) {
//     TestDriver driver;
//     KeymapKey  key_y(0, 0, 1, KC_Y);
//     KeymapKey  key_u(0, 0, 2, KC_U);
//     set_keymap({key_y, key_u});

//     EXPECT_REPORT(driver, (KC_RIGHT_SHIFT));
//     EXPECT_EMPTY_REPORT(driver);
//     tap_combo({key_y, key_u}, TAPPING_TERM + 1);
//     VERIFY_AND_CLEAR(driver);
// }

// TEST_F(Combo, combo_osmshift_tapped) {
//     TestDriver driver;
//     KeymapKey  key_z(0, 0, 1, KC_Z);
//     KeymapKey  key_x(0, 0, 2, KC_X);
//     KeymapKey  key_i(0, 0, 3, KC_I);
//     set_keymap({key_z, key_x, key_i});

//     EXPECT_NO_REPORT(driver);
//     tap_combo({key_z, key_x});
//     VERIFY_AND_CLEAR(driver);

//     EXPECT_REPORT(driver, (KC_I, KC_LEFT_SHIFT));
//     EXPECT_EMPTY_REPORT(driver);
//     tap_key(key_i);
//     VERIFY_AND_CLEAR(driver);
// }


// TEST_F(ComboRepress, combo_repress_tapped) {
//     TestDriver driver;
//     KeymapKey  key_f(0, 0, 0, KC_F);
//     KeymapKey  key_g(0, 0, 1, KC_G);
//     set_keymap({key_f, key_g});

//     EXPECT_REPORT(driver, (KC_LEFT_ALT)).Times(2);
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT));
//     EXPECT_EMPTY_REPORT(driver);
//     tap_combo({key_f, key_g}, 20);
//     VERIFY_AND_CLEAR(driver);
// }

// TEST_F(ComboRepress, combo_repress_held_released_one_key_and_repressed) {
//     TestDriver driver;
//     KeymapKey  key_f(0, 0, 0, KC_F);
//     KeymapKey  key_g(0, 0, 1, KC_G);
//     KeymapKey  key_h(0, 0, 2, KC_H);
//     KeymapKey  key_j(0, 0, 3, KC_J);
//     set_keymap({key_f, key_g, key_h, key_j});

//     /* Press combo F+G */
//     EXPECT_REPORT(driver, (KC_LEFT_ALT)).Times(2);
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT));
//     key_f.press();
//     run_one_scan_loop();
//     key_g.press();
//     run_one_scan_loop();
//     idle_for(COMBO_TERM + 1);
//     VERIFY_AND_CLEAR(driver);

//     /* Release G */
//     EXPECT_NO_REPORT(driver);
//     key_g.release();
//     idle_for(80);
//     VERIFY_AND_CLEAR(driver);

//     /* Tap G */
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT));
//     EXPECT_REPORT(driver, (KC_LEFT_ALT));
//     tap_key(key_g, TAPPING_TERM + 1);
//     VERIFY_AND_CLEAR(driver);

//     /* Tap G, but hold for longer */
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT));
//     EXPECT_REPORT(driver, (KC_LEFT_ALT));
//     tap_key(key_g, TAPPING_TERM * 2);
//     VERIFY_AND_CLEAR(driver);

//     idle_for(500);

//     /* Tap other combo while holding F */
//     EXPECT_REPORT(driver, (KC_ESCAPE, KC_LEFT_ALT));
//     EXPECT_REPORT(driver, (KC_LEFT_ALT));
//     tap_combo({key_h, key_j}, TAPPING_TERM + 1);
//     VERIFY_AND_CLEAR(driver);

//     /* G press and hold */
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT));
//     EXPECT_REPORT(driver, (KC_LEFT_ALT));
//     key_g.press();
//     run_one_scan_loop();
//     VERIFY_AND_CLEAR(driver);

//     /* F release and tap */
//     EXPECT_REPORT(driver, (KC_LEFT_ALT, KC_LEFT_SHIFT)).Times(2);
//     EXPECT_REPORT(driver, (KC_TAB, KC_LEFT_ALT, KC_LEFT_SHIFT));
//     EXPECT_REPORT(driver, (KC_LEFT_ALT));
//     key_f.release();
//     run_one_scan_loop();
//     tap_key(key_f);
//     VERIFY_AND_CLEAR(driver);

//     /* Release G */
//     EXPECT_EMPTY_REPORT(driver);
//     key_g.release();
//     run_one_scan_loop();
//     VERIFY_AND_CLEAR(driver);
// }

// TEST_F(ComboRepress, combo_repress_normal_combo) {
//     TestDriver driver;
//     KeymapKey  key_f(0, 0, 0, KC_F);
//     KeymapKey  key_g(0, 0, 1, KC_G);
//     KeymapKey  key_h(0, 0, 2, KC_H);
//     KeymapKey  key_j(0, 0, 3, KC_J);
//     set_keymap({key_f, key_g, key_h, key_j});

//     /* Press combo H+J */
//     EXPECT_REPORT(driver, (KC_ESCAPE));
//     key_h.press();
//     run_one_scan_loop();
//     key_j.press();
//     run_one_scan_loop();
//     idle_for(COMBO_TERM + 10);
//     VERIFY_AND_CLEAR(driver);

//     /* Release H */
//     EXPECT_NO_REPORT(driver);
//     key_h.release();
//     idle_for(80);
//     VERIFY_AND_CLEAR(driver);

//     /* Tap H */
//     EXPECT_REPORT(driver, (KC_H, KC_ESCAPE));
//     EXPECT_REPORT(driver, (KC_ESCAPE));
//     tap_key(key_h);
//     VERIFY_AND_CLEAR(driver);

//     /* Tap H, but hold for longer */
//     EXPECT_REPORT(driver, (KC_H, KC_ESCAPE));
//     EXPECT_REPORT(driver, (KC_ESCAPE));
//     tap_key(key_h, TAPPING_TERM + 1);
//     VERIFY_AND_CLEAR(driver);

//     idle_for(500);

//     /* Tap other combo while holding K */
//     EXPECT_REPORT(driver, (KC_ESCAPE, KC_LEFT_ALT)).Times(2);
//     EXPECT_REPORT(driver, (KC_ESCAPE, KC_TAB, KC_LEFT_ALT));
//     EXPECT_REPORT(driver, (KC_ESCAPE));
//     tap_combo({key_f, key_g}, TAPPING_TERM + 1);
//     VERIFY_AND_CLEAR(driver);

//     /* H press and hold */
//     EXPECT_REPORT(driver, (KC_H, KC_ESCAPE));
//     key_h.press();
//     run_one_scan_loop();
//     VERIFY_AND_CLEAR(driver);

//     /* J release and tap */
//     EXPECT_REPORT(driver, (KC_H));
//     key_j.release();
//     run_one_scan_loop();
//     VERIFY_AND_CLEAR(driver);

//     /* Release G */
//     EXPECT_EMPTY_REPORT(driver);
//     key_h.release();
//     run_one_scan_loop();
//     VERIFY_AND_CLEAR(driver);
// }
