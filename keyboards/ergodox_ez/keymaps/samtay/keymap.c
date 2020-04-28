#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "version.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MOUSE 2 // mouse keys
#define SCRLL 3 // scroll keys
#define MDIA 4 // fn/media keys
#define FRMW 5 // firmware keys
#define NUM 6 // numpad keys

enum custom_keycodes {
  PLACEHOLDER = SAFE_RANGE, // can always be here
  EPRM,
  VRSN,
  RGB_SLD
};

/*******************************************************************************
  Graphical layout can be viewed at

  http://www.keyboard-layout-editor.com/#/gists/e2831bdbee9113508428d49c9a963a06

  TODO: layer scroll on top of mouse layer to reduce key dupe

*******************************************************************************/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        _______,   KC_1,    KC_2,           KC_3,    KC_4,   KC_5,   _______,
        KC_TAB,    KC_Q,    KC_W,           KC_E,    KC_R,   KC_T,   KC_GRV,
        OSL(SYMB), KC_A,    KC_S,           KC_D,    KC_F,   KC_G,
        OSM(MOD_LSFT),   LT(MDIA,KC_Z),    KC_X,  LT(MOUSE,KC_C),    LT(NUM,KC_V),   KC_B,   LCTL(KC_MINS),
        MO(FRMW),   _______, _______,        KC_LCTL, ALT_T(KC_ESC),
                                               _______,_______,
                                                                _______,
                                               KC_SPC, KC_LCMD, _______,
        // right hand
        _______,  KC_6,   KC_7,  KC_8,   KC_9,   KC_0,    _______,
        KC_GRV,   KC_Y,   KC_U,  KC_I,   KC_O,   KC_P,    KC_QUOT,
                  KC_H,   KC_J,  KC_K,   KC_L,   KC_SCLN, OSL(SYMB),
        LCTL(KC_PLUS),  KC_N,   KC_M,  LT(MOUSE, KC_COMM),LT(SCRLL, KC_DOT), LT(MDIA,KC_SLSH), OSM(MOD_RSFT),
                  ALT_T(KC_ENT), KC_RCTL,_______,_______,_______,
        _______,  _______,
        _______,
        _______,  KC_RCMD, KC_BSPC
    ),
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       _______,_______,_______,_______,_______,_______,_______,
       _______,KC_EXLM,KC_AT,  KC_HASH,KC_LCBR,_______,_______,
       _______,KC_CIRC,KC_AMPR, KC_PIPE,KC_LPRN,KC_CAPS,
       OSM(MOD_LSFT),KC_TILD,KC_GRV,KC_PERC,KC_LBRC,KC_HOME,_______,
          _______,_______,_______,_______,_______,
                                       _______,_______,
                                               _______,
                               KC_SPC,_______,_______,
       // right hand
       _______,_______,_______,_______,_______,_______,_______,
       _______, _______, KC_RCBR,   KC_MINS,    KC_UNDS,    KC_ASTR, _______,
                _______, KC_RPRN,   KC_EQL,    KC_PLUS,    KC_DLR, _______,
       _______, KC_END, KC_RBRC,   _______,    _______,    KC_BSLS, OSM(MOD_RSFT),
                         _______,_______,  _______,    _______,  _______,
       _______,_______,
       _______,
       _______,  _______, ______
),
// MOUSE // Arrows
[MOUSE] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_MS_U, _______, _______, _______,
       _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______,
       _______, _______, _______, KC_MS_WH_DOWN, KC_MS_WH_UP, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  KC_BTN1, KC_BTN2, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, KC_UP, _______, _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                       _______, _______,_______,_______,_______,
       _______, _______,
       _______,
       _______, _______, _______
),
// MOUSE SCROLLING
[SCRLL] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, KC_WH_U, _______, _______, _______,
       _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           KC_BTN1, KC_BTN2,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, KC_UP, _______, _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                       _______, _______,_______,_______,_______,
       _______, _______,
       _______,
       _______, _______, _______
),
// FN / MEDIA KEYS
[MDIA] = LAYOUT_ergodox(
       // left hand
       _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, _______,
       _______, KC_F11, KC_F12, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           RGB_VAD, RGB_VAI,
                                                    RGB_MOD,
                                  KC_VOLD, KC_VOLU, KC_MUTE,
    // right hand
       _______, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, _______, _______,
       RGB_HUI, RGB_HUD,
       RGB_SLD,
       RGB_TOG, KC_MSTP, KC_MPLY
),
// NUMPAD LAYER
[NUM] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_7,   KC_8,    KC_9, _______, _______,
                _______, KC_4,   KC_5,    KC_6, _______, _______,
       _______, _______, KC_1,   KC_2,    KC_3, _______, _______,
                         _______, KC_0, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
// LAYER JUST FOR NON-ACCIDENTAL FIRMWARE OPS
[FRMW] = LAYOUT_ergodox(
       // left hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
                         _______, _______, _______, VRSN, RESET,
       _______, _______,
       _______,
       _______, _______, _______
),
};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TAP_TOGGLE(SYMB)                // FN1 - Momentary Layer 1 (Symbols)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      break;
    case 1:
      if (record->event.pressed) { // For resetting EEPROM
        eeconfig_init();
      }
      break;
  }
  return MACRO_NONE;
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // dynamically generate these.
    case EPRM:
      if (record->event.pressed) {
        eeconfig_init();
      }
      return false;
      break;
    case VRSN:
      if (record->event.pressed) {
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
      }
      return false;
      break;
    case RGB_SLD:
      if (record->event.pressed) {
        #ifdef RGBLIGHT_ENABLE
          rgblight_mode(1);
        #endif
      }
      return false;
      break;
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
