#pragma once

#define ONESHOT_TAP_TOGGLE 2  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define TAPPING_TERM 200

// 2 bytes (uint16_t) for each layer*col*row
// 2*16*5*8
#define EECONFIG_USER_DATA_SIZE 1280


#define KEYPOS_COMBOS

// more time for oneshot layer combos
// doesnt seem to help #define COMBO_TERM 100
