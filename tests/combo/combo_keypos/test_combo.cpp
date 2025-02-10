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

    EXPECT_REPORT(driver, (KC_G));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_1, key_2});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combo_reverse) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    set_keymap({key_1, key_2});

    EXPECT_REPORT(driver, (KC_G));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_2, key_1});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combo_repeat) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    set_keymap({key_1, key_2});

    EXPECT_REPORT(driver, (KC_G)).Times(2);
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
    KeymapKey  key_4(0, 1, 1, KC_4);
    set_keymap({key_1, key_2, key_3, key_4});

    EXPECT_REPORT(driver, (KC_2));
    EXPECT_REPORT(driver, (KC_2, KC_4));
    EXPECT_REPORT(driver, (KC_4));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_2, key_4});
    // idle_for(1000);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combos_overlap) {
    // Simultaneously press 3 keys that are part of 2 combos,
  // record the 2nd combo
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    KeymapKey  key_3(0, 1, 0, KC_3);
    KeymapKey  key_4(0, 1, 1, KC_4);
    set_keymap({key_1, key_2, key_3, key_4});

    {
      InSequence s;
      EXPECT_REPORT(driver, (KC_2));
      // EXPECT_EMPTY_REPORT(driver);
      EXPECT_REPORT(driver, (KC_2, KC_H));
      EXPECT_REPORT(driver, (KC_H));
      EXPECT_EMPTY_REPORT(driver);
      
    }
    // EXPECT_REPORT(driver, (KC_G));
    // EXPECT_REPORT(driver, (KC_SLSH));
    // EXPECT_EMPTY_REPORT(driver).Times(2);
    // tap_combo({key_1, key_2});
    // tap_combo({key_1, key_4});
    key_1.press();
    run_one_scan_loop();
    idle_for(COMBO_TERM-1);
    key_2.press();
    run_one_scan_loop();

    // key_1.press();
    // run_one_scan_loop();
    // idle_for(COMBO_TERM-1);
    key_3.press();
    run_one_scan_loop();

    key_1.release();
    run_one_scan_loop();
    key_2.release();
    run_one_scan_loop();

    key_3.release();
    run_one_scan_loop();
    // idle_for(1000);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(ComboKeypos, combo_default_layer_combos_no_overlap) {
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    KeymapKey  key_3(0, 1, 0, KC_3);
    KeymapKey  key_4(0, 1, 1, KC_4);
    KeymapKey  key_5(0, 2, 0, KC_5);
    KeymapKey  key_6(0, 2, 1, KC_6);
    set_keymap({key_1, key_2, key_3, key_4, key_5, key_6});

    {
      InSequence s;
      EXPECT_REPORT(driver, (KC_G));
      EXPECT_REPORT(driver, (KC_G, KC_J));
      EXPECT_REPORT(driver, (KC_J));
      EXPECT_EMPTY_REPORT(driver);
      
    }
    key_1.press();
    run_one_scan_loop();
    key_2.press();
    run_one_scan_loop();
    key_5.press();
    run_one_scan_loop();
    key_6.press();
    run_one_scan_loop();

    key_1.release();
    run_one_scan_loop();
    key_2.release();
    run_one_scan_loop();
    key_5.release();
    run_one_scan_loop();
    key_6.release();
    run_one_scan_loop();
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
    
    EXPECT_REPORT(driver, (KC_W));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(osl_key);
    expect_layer_state(1);
    tap_combo({key_1, key_2});

    VERIFY_AND_CLEAR(driver);
}


TEST_F(ComboKeypos, combo_osl_combo_match_reverse_order) {
    TestDriver driver;
    KeymapKey  key_1_0(0, 0, 0, KC_A);
    KeymapKey  osl_key = KeymapKey{0, 0, 1, OSL(1)};
    KeymapKey  key_1(1, 0, 0, KC_1);
    KeymapKey  key_2(1, 0, 1, KC_2);
    set_keymap({key_1_0, osl_key, key_1, key_2});

    EXPECT_REPORT(driver, (KC_W));
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

    EXPECT_REPORT(driver, (KC_W)).Times(2);
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

