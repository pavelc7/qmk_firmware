#include QMK_KEYBOARD_H

#include "2x40keys.h"

// Defines names for use in layer keycodes and the keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_2x40keys(
	KC_ESC,                       KC_3,    KC_4,    KC_5,                                       TG(1),    TG(2),    KC_8,                      KC_MINS,
	KC_TILD, KC_1,      KC_2,     KC_3,    KC_4,    KC_5,   KC_ESC,                    TG(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
	KC_TAB,  KC_Q,      KC_W,     KC_E,    KC_R,    KC_T,   KC_T,                      KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
	MO(2),   KC_A,      KC_S,     KC_D,    KC_F,    KC_G,   KC_G,                      KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
	KC_LSFT, KC_Z,      KC_X,     KC_C,    KC_V,    KC_B,   KC_LCTRL,                  KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   
	MO(1),   KC_Z,      KC_LCTRL, KC_LALT, KC_LGUI, KC_LSFT, KC_BSPC, KC_ENT,   KC_RALT, KC_RGUI, KC_SPC, KC_SPC, KC_LEFT, KC_DOWN, KC_RIGHT,KC_ENT),

	[1] = LAYOUT_2x40keys(
	 _______,                   _______,_______,_______,                     	                  _______,_______,_______,         		_______,
	 _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,  			 _______,  KC_F6,   KC_F7, KC_F8,   KC_F9,   KC_F10,  KC_F11,  
	 _______, _______, _______, _______, _______, _______, _______,  			 KC__MUTE, _______, KC_7,  KC_8,    KC_9,    _______, KC_F12,
	 _______, _______, _______, _______, _______, _______, _______,  			 KC_BSPC,  _______, KC_4,  KC_5,    KC_6,    _______, _______, 
	 _______, _______, _______, _______, _______, _______, _______,          	  	 _______,  _______, KC_1,  KC_2,    KC_3,    _______, _______, 
	 _______, RESET,   _______, _______, _______, _______, _______,_______,	_______,_______,_______,  KC_0,  _______, RESET,   _______, _______),

    [2] = LAYOUT_2x40keys(
	 _______,               _______, _______, _______,                                      	  _______,_______,_______,           _______,  
	 _______, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2,_______,_______, _______,  	_______,  _______, _______, _______, _______, _______, _______,
	 _______, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN1,  KC_MS_WH_UP,   _______, _______,  	_______,  _______, _______, KC_UP,   _______, _______, _______,
	 _______, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_MS_WH_DOWN, _______, _______,  	_______,  KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
	 _______, _______, _______, _______, _______,_______, _______,                     	_______,  _______, _______, _______, _______, _______, _______,
	 _______, _______, _______, _______, _______,_______, _______,_______,	_______, _______, _______, _______, _______, _______,_______, _______)

};



/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif 
  return true;
}
void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
#endif 
}
*/
// Light LEDs 0 to 4 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_RED}       // Light 4 LEDs, starting with LED 6
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 14, HSV_GREEN}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);


void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
