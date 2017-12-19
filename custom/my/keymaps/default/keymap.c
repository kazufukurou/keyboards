#include "my.h"

#define SFT_ENT SFT_T(KC_ENT)
#define SFT_BS SFT_T(KC_BSPC)
#define CTL_QUO CTL_T(KC_QUOT)
#define ALT_TAB ALT_T(KC_TAB)
#define PREVENT_STUCK_MODIFIERS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base
 * .-------------------------------------------------------------------------------.
 * |   ;:  |  ,<   |  .>   |   P   |   Y   |   F   |   G   |   C   |   R   |   L   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   A   |   O   |   E   |   U   |   I   |   D   |   H   |   T   |   N   |   S   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |Ctl/'" |   Q   |   J   |   K   |   X   |   B   |   M   |   W   |   V   |   Z   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |Tab/Alt|  Fn1  |Shf/Bs | Space | Space |Sft/Ent|  Fn2  |  -_   |       |
 * '-------------------------------------------------------------------------------'
 */
    [0] = {
        { KC_SCLN, KC_COM,   KC_DOT, KC_P,    KC_Y,   KC_F,   KC_G,    KC_C, KC_R,    KC_L  },
        { KC_A,    KC_O,     KC_E,   KC_U,    KC_I,   KC_D,   KC_H,    KC_T, KC_N,    KC_S  },
        { CTL_QUO, KC_Q,     KC_J,   KC_K,    KC_X,   KC_B,   KC_M,    KC_W, KC_V,    KC_Z  },
        { KC_NO,   ALT_TAB,  F(1),   SFT_BS,  KC_SPC, KC_SPC, SFT_ENT, F(2), KC_MINS, KC_NO }
    },
/*
 * Fn1
 * .-------------------------------------------------------------------------------.
 * |   ~   |   %   |   {   |   }   |   ^   |   =   |   7   |   8   |   9   |   !   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   $   |   &   |   (   |   )   |   @   |   *   |   4   |   5   |   6   |   ?   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |   \   |   `   |   [   |   ]   |   #   |   +   |   1   |   2   |   3   |   /   |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |  Esc  |  Fn1  |       |       |       |       |   0   |   |   |       |
 * '-------------------------------------------------------------------------------'
 */
    [1] = {
        { KC_TILD, KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC, KC_EQL,  KC_7,  KC_8,    KC_9,    KC_EXLM },
        { KC_DLR,  KC_AMPR, KC_LPRN, KC_RPRN, KC_AT,   KC_ASTR, KC_4,  KC_5,    KC_6,    KC_QUES },
        { KC_BSLS, KC_GRV,  KC_LBRC, KC_RBRC, KC_HASH, KC_PLUS, KC_1,  KC_2,    KC_3,    KC_SLSH },
        { KC_NO,   KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0,  KC_PIPE, KC_TRNS, KC_NO   }
    },
/*
 * Fn2
 * .-------------------------------------------------------------------------------.
 * |  F9   |  F10  |  F11  |  F12  |  MB1  | Home  |  End  |  Up   |  Ins  |  Del  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F5   |  F6   |  F7   |  F8   |  MB2  | PgUp  | Left  | Down  | Right | Vol+  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |  F1   |  F2   |  F3   |  F4   |  MB3  | PgDn  | Prev  | Play  | Next  | Vol-  |
 * |-------+-------+-------+-------+-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       | Reset |  Fn2  | Mute  |       |
 * '-------------------------------------------------------------------------------'
 */

    [2] = {
        {KC_F9, KC_F10, KC_F11,  KC_F12, KC_BTN1, KC_HOME, KC_END,  KC_UP,   KC_INS,  KC_DEL  },
        {KC_F5, KC_F6,  KC_F7,   KC_F8,  KC_BTN2, KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU },
        {KC_F1, KC_F2,  KC_F3,   KC_F4,  KC_BTN3, KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD },
        {KC_NO, KC_NO,  KC_TRNS, KC_NO,  KC_NO,   KC_NO,   RESET,   KC_TRNS, KC_MUTE, KC_NO   }
    }

};

const uint16_t PROGMEM fn_actions[] = {
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) // MACRODOWN only works in this function
{
    return MACRO_NONE;
};
