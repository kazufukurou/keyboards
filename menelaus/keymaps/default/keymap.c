#include "menelaus.h"

#define ___X___ KC_NO
#define _______ KC_TRNS
#define SFT_SPC SFT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define CTL_MIN CTL_T(KC_MINS)
#define ALT_ESC ALT_T(KC_ESC)
#define MO1_TAB LT(1, KC_TAB)
#define MO2_BS LT(2, KC_BSPC)
#define PREVENT_STUCK_MODIFIERS

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = {
        { KC_SCLN, KC_COMM, KC_DOT,  KC_P,    KC_Y,          KC_F,    KC_G,    KC_C,    KC_R,    KC_L    },
        { KC_A,    KC_O,    KC_E,    KC_U,    KC_I,          KC_D,    KC_H,    KC_T,    KC_N,    KC_S    },
        { KC_QUOT, KC_Q,    KC_J,    KC_K,    KC_X,          KC_B,    KC_M,    KC_W,    KC_V,    KC_Z    },
        { ___X___, ___X___, ALT_ESC, MO1_TAB, SFT_SPC,       SFT_ENT, MO2_BS,  CTL_MIN, ___X___, ___X___ }
    },
    [1] = {
        { KC_TILD, KC_PERC, KC_LCBR, KC_RCBR, KC_CIRC,       KC_EQL,  KC_7,    KC_8,    KC_9,    KC_EXLM },
        { KC_DLR,  KC_AMPR, KC_LPRN, KC_RPRN, KC_AT,         KC_ASTR, KC_4,    KC_5,    KC_6,    KC_QUES },
        { KC_BSLS, KC_GRV,  KC_LBRC, KC_RBRC, KC_HASH,       KC_PLUS, KC_1,    KC_2,    KC_3,    KC_SLSH },
        { ___X___, ___X___, RESET,   _______, KC_SPC,        _______, KC_0,    KC_PIPE, ___X___, ___X___ }
    },
    [2] = {
        { KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BTN1,       KC_HOME, KC_END,  KC_UP,   KC_INS,  KC_DEL  },
        { KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_BTN2,       KC_PGUP, KC_LEFT, KC_DOWN, KC_RGHT, KC_VOLU },
        { KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_BTN3,       KC_PGDN, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLD },
        { ___X___, ___X___, _______, _______, _______,       KC_MUTE, _______, TO(3),   ___X___, ___X___ }
    },
    [3] = {
        { KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,          KC_T,    KC_Y,    KC_U,    KC_I,    KC_O    },
        { KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,          KC_G,    KC_H,    KC_J,    KC_K,    KC_L    },
        { KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,          KC_B,    KC_N,    KC_M,    KC_P,    KC_PSCR },
        { ___X___, ___X___, KC_LALT, KC_LSFT, KC_SPC,        KC_ENT,  KC_BSPC, TO(0),   ___X___, ___X___ }
    }
};

const uint16_t PROGMEM fn_actions[] = {
};
