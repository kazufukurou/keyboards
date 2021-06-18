/* Copyright 2018 ENDO Katsuhiro <ka2hiro@curlybracket.co.jp>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
#define _BASE 0
#define _LOWER 1
#define _RAISE 2
#define _QWERTY 16

#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define CTL_MIN CTL_T(KC_MINS)
#define ALT_ESC ALT_T(KC_ESC)
#define MO1_TAB LT(_LOWER, KC_TAB)
#define MO2_BS LT(_RAISE, KC_BSPC)
#define PREVENT_STUCK_MODIFIERS

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT( \
  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,         KC_F,    KC_G,    KC_C,    KC_R,    KC_L, \
  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,         KC_D,    KC_H,    KC_T,    KC_N,    KC_S, \
  KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,         KC_B,    KC_M,    KC_W,    KC_V,    KC_Z, \
                    ALT_ESC, MO1_TAB, SFT_SPC,      SFT_ENT, MO2_BS,  CTL_MIN \
),

[_LOWER] = LAYOUT( \
  KC_TILD, KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC,      KC_EQL,  KC_7,    KC_8,    KC_9,    KC_EXLM, \
  KC_DLR,  KC_AMPR, KC_LPRN, KC_RPRN, KC_AT,        KC_ASTR, KC_4,    KC_5,    KC_6,    KC_QUES, \
  KC_BSLS, KC_GRV,  KC_LBRC, KC_RBRC, KC_HASH,      KC_PLUS, KC_1,    KC_2,    KC_3,    KC_SLSH, \
                    RESET,   _______, KC_SPC,       KC_ENT,  KC_0,    KC_PIPE \
),

[_RAISE] = LAYOUT( \
  KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN1,      KC_HOME, KC_END,  KC_UP,   KC_INS,  KC_DEL, \
  KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_BTN2,      KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU, \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_BTN3,      KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD, \
                    _______, _______, _______,      KC_MUTE, _______, TO(_QWERTY) \
),

[_QWERTY] = LAYOUT( \
  KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,    KC_Y,    KC_U,    KC_I,    KC_O, \
  KC_TAB,  KC_A,    KC_S,    KC_D,    KC_D,         KC_G,    KC_H,    KC_J,    KC_K,    KC_L, \
  KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,    KC_N,    KC_M,    KC_P,    KC_PSCR, \
                    KC_LALT, KC_LSFT, KC_SPC,       KC_ENT,  KC_BSPC, TO(_BASE) \
)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        // persistant_default_layer_set(1UL<<_BASE);
        set_single_persistent_default_layer(_BASE);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _QWERTY);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_QWERTY);
      } else {
        layer_off(_QWERTY);
      }
      return false;
      break;
  }
  return true;
}

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
}

void led_set_user(uint8_t usb_led) {
}
