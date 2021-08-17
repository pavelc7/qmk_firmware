#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xAEC7
#define PRODUCT_ID      0x7070
#define DEVICE_VER      0x0707
#define MANUFACTURER    pavelc7
#define PRODUCT         2x40keys

/* key matrix size */

/**
 * Rows are doubled-up
 *
 * https://www.reddit.com/r/olkb/comments/829ubq/rows_and_columns_of_split_using_2_pro_micros/
 * https://github.com/seniorsoftwarevlogger/takmak
 *
 * The reason why the rows are doubled up instead of columns is due to the way the keyboard matrix is scanned.
 * It scans one row at a time. What the slave does it scan its rows and passes it to the master.
 * The master then stores all the row data together by virtually stacking the rows of the left
 * half on top of the right half.
 *
 * A macro remaps the stacked rows to the correct layout later on.
 */
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

/* key matrix pins */
#define MATRIX_ROW_PINS { D4, C6, D7, E6, B4, B5  }
#define MATRIX_COL_PINS { B2, B3, B1, F7, F6, F5, F4}
//#define MATRIX_ROW_PINS_RIGHT { D4, C6, D7, E6, B4, B5 }
//#define MATRIX_COL_PINS_RIGHT { B2, B3, B1, F7, F6, F5, F4 }

/* COL2ROW or ROW2COL */
// COL2ROW means the black mark on your diode is facing to the rows, and between the switch and the rows.
#define DIODE_DIRECTION COL2ROW

#define AUDIO_PIN B6


/* number of backlight levels */
//#define BACKLIGHT_PIN D3

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* ws2812 RGB LED */
#define RGB_DI_PIN D3
#define RGBLED_NUM 7    // Number of LEDs
#define RGBLIGHT_SPLIT   // sync LEDs between RIGHT and LEFT hand


#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT
#ifndef NO_DEBUG
    #define NO_DEBUG
#endif // !NO_DEBUG
#if !defined(NO_PRINT) && !defined(CONSOLE_ENABLE)
    #define NO_PRINT
#endif // !NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION
/**/



//#define USE_I2C
#define SOFT_SERIAL_PIN D0
#define SPLIT_USB_DETECT

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

//#define MASTER_RIGHT
#define EE_HANDS

//#define DEBUG_MATRIX_SCAN_RATE
