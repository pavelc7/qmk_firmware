#include QMK_KEYBOARD_H

#include "2x40keys.h"

// Defines names for use in layer keycodes and the keymap
define MY_layout( \
    k00,           k03, k04, k05,      \
    k10, k11, k12, k13, k14, k15, k16, \
    k20, k21, k22, k23, k24, k25, k26, \
    k30, k31, k32, k33, k34, k35, k36, \
    k40, k41, k42, k43, k44, k45,      \
    k50, k51, k52, k53, k54,           \
    k46, \
    k55, k56, k57, \
    \
         k61, k62, k63,           k66, \
    k70, k71, k72, k73, k74, k75, k76, \
    k80, k81, k82, k83, k84, k85, k86, \
    k90, k91, k92, k93, k94, k95, k96, \
         ka1, ka2, ka3, ka4, ka5, ka6, \
              kb2, kb3, kb4, kb5, kb6, \
    ka0,\
    kb7, kb0, kb1 \
) \
LAYOUT_2x40keys( \
    k00,           k03, k04, k05,                               k61, k62, k63,           k66, \
    k10, k11, k12, k13, k14, k15, k16,                     k70, k71, k72, k73, k74, k75, k76, \
    k20, k21, k22, k23, k24, k25, k26,                     k80, k81, k82, k83, k84, k85, k86, \
    k30, k31, k32, k33, k34, k35, k36,                     k90, k91, k92, k93, k94, k95, k96, \
    k40, k41, k42, k43, k44, k45, k46,                     ka0, ka1, ka2, ka3, ka4, ka5, ka6, \
    k50, k51, k52, k53, k54, k55, k56, k57,           kb7, kb0, kb1, kb2, kb3, kb4, kb5, kb6 \
) 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[0] = LAYOUT_2x40keys(
	KC_ESC,                       KC_3,    KC_4,    KC_5,                                       TG(1),    TG(2),    KC_8,                      KC_MINS,
	KC_TILD, KC_1,      KC_2,     KC_3,    KC_4,    KC_5,   KC_ESC,                    TG(1),   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, 
	KC_TAB,  KC_Q,      KC_W,     KC_E,    KC_R,    KC_T,   KC_T,                      KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, 
	MO(2),   KC_A,      KC_S,     KC_D,    KC_F,    KC_G,   KC_G,                      KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, 
	KC_LSFT, KC_Z,      KC_X,     KC_C,    KC_V,    KC_B,   KC_LCTRL,                  KC_LALT, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,   
	MO(1),   KC_Z,      KC_LCTRL, KC_LALT, KC_LGUI, KC_LSFT, KC_BSPC, KC_ENT,   KC_RGUI, KC_RGUI, KC_SPC, KC_LALT, KC_LEFT, KC_DOWN, KC_RIGHT,KC_UP),

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
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
#endif 
}
