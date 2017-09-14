#include "planck.h"

#define SFT_ENT SFT_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)
#define PREVENT_STUCK_MODIFIERS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base
 * .-----------------------------------------------------------------------------.
 * |  Tab  | ;:  | ,<  | .>  |   P   |  Y  |  F  |   G   |  C  |  R  |  L  |Bksp |
 * |-------+-----+-----+-----+-------+-----+-----+-------+-----+-----+-----+-----|
 * |Ctl/Esc|  A  |  O  |  E  |   U   |  I  |  D  |   H   |  T  |  N  |  S  | -_  |
 * |-------+-----+-----+-----+-------+-----+-----+-------+-----+-----+-----+-----|
 * | Shift | '"  |  Q  |  J  |   K   |  X  |  B  |   M   |  W  |  V  |  Z  | Up  |
 * |-------+-----+-----+-----+-------+-----+-----+-------+-----+-----+-----+-----|
 * |  Fn2  |Meta | Alt | Fn1 |Shf/Ent|   Space   |Sft/Ent| Fn1 |Left |Right|Down |
 * '-----------------------------------------------------------------------------'
 */
[0] = {
  {KC_TAB,  KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC},
  {CTL_ESC, KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_MINS},
  {KC_LSFT, KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_UP},
  {F(2),    KC_LGUI, KC_LALT, F(1),    SFT_ENT, KC_SPC,  KC_SPC,  SFT_ENT, F(1),    KC_LEFT, KC_RGHT, KC_DOWN}
},

/*
 * Fn1
 * .-----------------------------------------------------------------------.
 * |     |  ~  |  %  |  {  |  }  |  ^  |  =  |  7  |  8  |  9  |  !  |Bksp |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |  $  |  &  |  (  |  )  |  @  |  *  |  4  |  5  |  6  |  ?  |  |  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |  `  |  [  |  ]  |  #  |  +  |  1  |  2  |  3  |  /  |  \  |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |  0  |     |     |     |     |
 * '-----------------------------------------------------------------------'
 */
[1] = {
  {KC_NO,   KC_TILD, KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_EXLM, KC_BSPC},
  {KC_NO,   KC_DLR,  KC_AMPR, KC_LPRN, KC_RPRN, KC_AT,   KC_ASTR, KC_4,    KC_5,    KC_6,    KC_QUES, KC_PIPE},
  {KC_NO,   KC_NO,   KC_GRV,  KC_LBRC, KC_RBRC, KC_HASH, KC_PLUS, KC_1,    KC_2,    KC_3,    KC_SLSH, KC_BSLS},
  {KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_0,    KC_TRNS, KC_NO,   KC_NO,   KC_NO}
},

/*
 * Fn2
 * .-----------------------------------------------------------------------.
 * |     | F9  | F10 | F11 | F12 |     |     | MB1 | MB2 | MB3 | Ins | Del |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | F5  | F6  | F7  | F8  |     |     |Vol- |Mute |Vol+ |PgUp |Home |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | F1  | F2  | F3  | F4  |     |     |Prev |Play |Next |PgDn | End |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |     |     |     |     |Reset|
 * '-----------------------------------------------------------------------'
 */
[2] = {
  {KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_BTN1, KC_BTN2, KC_BTN3, KC_INS,  KC_DEL},
  {KC_TRNS, KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_PGUP, KC_HOME},
  {KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_PGDN, KC_END},
  {KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET}
},

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
};
