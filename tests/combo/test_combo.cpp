// Copyright 2023 Stefan Kerkmann (@KarlK90)
// Copyright 2023 @filterpaper
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

class Combo : public TestFixture {};

TEST_F(Combo, combo_modtest_tapped) {
    TestDriver driver;
    KeymapKey  key_y(0, 0, 1, KC_Y);
    KeymapKey  key_u(0, 0, 2, KC_U);
    set_keymap({key_y, key_u});

    EXPECT_REPORT(driver, (KC_SPACE));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_y, key_u});
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Combo, combo_modtest_held_longer_than_tapping_term) {
    TestDriver driver;
    KeymapKey  key_y(0, 0, 1, KC_Y);
    KeymapKey  key_u(0, 0, 2, KC_U);
    set_keymap({key_y, key_u});

    EXPECT_REPORT(driver, (KC_RIGHT_SHIFT));
    EXPECT_EMPTY_REPORT(driver);
    tap_combo({key_y, key_u}, TAPPING_TERM + 1);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Combo, combo_osmshift_tapped) {
    TestDriver driver;
    KeymapKey  key_z(0, 0, 1, KC_Z);
    KeymapKey  key_x(0, 0, 2, KC_X);
    KeymapKey  key_i(0, 0, 3, KC_I);
    set_keymap({key_z, key_x, key_i});

    EXPECT_NO_REPORT(driver);
    tap_combo({key_z, key_x});
    VERIFY_AND_CLEAR(driver);

    EXPECT_REPORT(driver, (KC_I, KC_LEFT_SHIFT));
    EXPECT_EMPTY_REPORT(driver);
    tap_key(key_i);
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Combo, combo_default_layer_combos_overlap) {
    // Simultaneously press 3 keys that are part of 2 combos,
    // and record the 2nd combo
    TestDriver driver;
    KeymapKey  key_1(0, 0, 0, KC_1);
    KeymapKey  key_2(0, 0, 1, KC_2);
    KeymapKey  key_3(0, 1, 0, KC_3);
    KeymapKey  key_4(0, 1, 1, KC_4);
    set_keymap({key_1, key_2, key_3, key_4});

    {
      InSequence s;
      EXPECT_REPORT(driver, (KC_2));
      EXPECT_REPORT(driver, (KC_2, KC_H));
      EXPECT_REPORT(driver, (KC_H));
      EXPECT_EMPTY_REPORT(driver);
      
    }
    key_1.press();
    run_one_scan_loop();
    idle_for(COMBO_TERM-1);
    key_2.press();
    run_one_scan_loop();
    key_3.press();
    run_one_scan_loop();

    key_1.release();
    run_one_scan_loop();
    key_2.release();
    run_one_scan_loop();
    key_3.release();
    run_one_scan_loop();
    VERIFY_AND_CLEAR(driver);
}

TEST_F(Combo, combo_simultaneous_no_overlap) {
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
