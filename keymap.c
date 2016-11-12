#include "planck.h"
#include "keymap_extras/keymap_dvp.h"


#define SFT_ENT SFT_T(KC_ENT)
#define CTL_ESC CTL_T(KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
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
  {KC_TAB,  DP_SCLN, DP_COMM, DP_DOT,  DP_P,    DP_Y,    DP_F,    DP_G,    DP_C,    DP_R,    DP_L,    KC_BSPC},
  {CTL_ESC, DP_A,    DP_O,    DP_E,    DP_U,    DP_I,    DP_D,    DP_H,    DP_T,    DP_N,    DP_S,    DP_MINS},
  {KC_LSFT, DP_QUOT, DP_Q,    DP_J,    DP_K,    DP_X,    DP_B,    DP_M,    DP_W,    DP_V,    DP_Z,    KC_UP},
  {F(2),    KC_LGUI, KC_LALT, F(1),    SFT_ENT, KC_SPC,  KC_SPC,  SFT_ENT, F(1),    KC_LEFT, KC_RGHT, KC_DOWN}
},

/*
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
  {KC_NO,   DP_TILD, DP_PERC, DP_LCBR, DP_RCBR, DP_CIRC, DP_EQL,  DP_7,    DP_8,    DP_9,    DP_EXLM, KC_BSPC},
  {KC_NO,   DP_DLR,  DP_AMPR, DP_LPRN, DP_RPRN, DP_AT,   DP_ASTR, DP_4,    DP_5,    DP_6,    DP_QUES, DP_PIPE},
  {KC_NO,   KC_NO,   DP_GRV,  DP_LBRC, DP_RBRC, DP_HASH, DP_PLUS, DP_1,    DP_2,    DP_3,    DP_SLSH, DP_BSLS},
  {KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   KC_NO,   DP_0,    KC_TRNS, KC_NO,   KC_NO,   KC_NO}
},

/*
 * .-----------------------------------------------------------------------.
 * |     | F9  | F10 | F11 | F12 |     |     | MB1 | Up  | MB2 |     | Del |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | F5  | F6  | F7  | F8  |     |     |Left |Down |Right|     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     | F1  | F2  | F3  | F4  |     |     |Prev |Play |Next |     |     |
 * |-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----|
 * |     |     |     |     |     |           |Vol- |Mute |Vol+ |     |Reset|
 * '-----------------------------------------------------------------------'
 */
[2] = {
  {KC_NO,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NO,   KC_NO,   KC_BTN1, KC_UP,   KC_BTN2, KC_INS,  KC_DEL},
  {KC_NO,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_NO,   KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT, KC_NO,   KC_NO},
  {KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_NO,   KC_NO,   KC_MPRV, KC_MPLY, KC_MNXT, KC_NO,   KC_NO},
  {KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLD, KC_MUTE, KC_VOLU, KC_NO,   RESET}
},

};

const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_MOMENTARY(1),
    [2] = ACTION_LAYER_MOMENTARY(2),
};
