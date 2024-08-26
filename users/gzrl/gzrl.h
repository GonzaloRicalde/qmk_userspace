#pragma once
#include QMK_KEYBOARD_H


enum userspace_layers{
    _BASE = 0,
    _LOWER,
    _RAISE,
    _EXTRA,
    // _ADJUST,
    // _GAME,
    // _NAV
};

enum custom_keycodes {
    KC_QWERTY = QK_USER,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE,
    KC_GUITB,
    KC_GNZALTAB,
    GZ_LSFT,
    GZ_RSFT,
    GZ_LALT,
    GZ_RALT
};

#define GC_PIPE S(KC_NUBS)

// brace mods, i'm not entirely sure i still want these
// i know i want to shift to using home row mods
// andi also know i want to move to have brances in a single layer
// but they sure have been nice to have around.
#define G_LSFT LSFT_T(KC_LPRN)
#define G_RSFT RSFT_T(KC_RPRN)
#define G_LOWER LT(_LOWER, KC_LCBR)
#define G_RAISE LT(_RAISE, KC_RCBR)
#define G_LALT LALT_T(KC_LBRC)
#define G_RALT RALT_T(KC_RBRC)

// these are special because they don't do braces
// id like to keep these around in some shape or form.
#define G_CENT LCTL_T(KC_ENT)
#define G_ASPC ALT_T(KC_SPC)
#define G_RCTL LCTL_T(KC_APP)



// #define G_NUMP LT(_NUMPAD, KC_BSPC) // this looks like something that should be in the keymaps and not here




// I'm basing my initial implementation of keymaps on drashna's wrappers
// I think it's a really neat way of sharing keymaps across keyboards of different layouts.
#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________NONE____________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___________________BLANK___________________       _______, _______, _______, _______, _______
//------------------------------------------------------------------------------------------------------------
#define _________________BASE__L1__________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________BASE__L2__________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________BASE__L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________BASE__R1__________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________BASE5_R2__________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________BASE__R2__________________       _________________BASE5_R2__________________, KC_QUOT
#define _________________BASE__R3__________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// These are my traditional raise/lower layouts that  i started with the sofle and have been utilizing
//------------------------------------------------------------------------------------------------------------
#define _________________LOWER_L1__________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________LOWER_L2__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L3__________________       KC_CIRC, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR

#define _________________LOWER_R1__________________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________LOW5R_R2__________________       GC_PIPE, KC_AMPR, KC_ASTR, KC_SLSH, KC_CIRC
#define _________________LOWER_R2__________________       _________________LOW5R_R2__________________, KC_BSLS
#define _________________LOWER_R3__________________       KC_PLUS, KC_MINS, KC_UNDS, KC_EQL,  KC_NUBS

//------------------------------------------------------------------------------------------------------------
#define _________________RAISE_L1__________________       KC_INS , KC_BTN4 , KC_MS_U , KC_BTN5 , KC_WH_U
#define _________________RAISE_L2__________________       KC_CAPS, KC_MS_L , KC_MS_D , KC_MS_R , KC_WH_D
#define _________________RAISE_L3__________________       KC_UNDO, KC_CUT  , KC_COPY , KC_PASTE, KC_BTN3

#define _________________RAISE_R1__________________       KC_PGUP, KC_PRVWD,  KC_UP , KC_NXWD, KC_DLINE
#define _________________RAIS5_R2__________________       KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT , KC_DEL
#define _________________RAISE_R2__________________       _________________RAIS5_R2__________________, KC_BSPC
#define _________________RAISE_R3__________________       KC_BTN1, KC_LSTRT, XXXXXXX, KC_LEND , G_RCTL

//------------------------------------------------------------------------------------------------------------
#define _________________EXTRA_L1__________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________EXTRA_L2__________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________EXTRA_L3__________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________EXTRA_R1__________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________EXTRA_R2__________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________EXTRA_R3__________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

// these are a new version of keymaps that i'm going to try out
// loosely based on pascal getreuers keymaps
// https://github.com/getreuer/qmk-keymap
//------------------------------------------------------------------------------------------------------------
#define ________________SYMBOL_L1__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ________________SYMBOL_L2__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define ________________SYMBOL_L3__________________       KC_CIRC, KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR

#define ________________SYMBOL_R1__________________       GC_PIPE, XXXXXXX, KC_LBRC, KC_RBRC, XXXXXXX
#define ________________SYMBL5_R2__________________       KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_CIRC
#define ________________SYMBOL_R2__________________       ________________SYMBL5_R2__________________, KC_BSLS
#define ________________SYMBOL_R3__________________       KC_EQL,  KC_EQL,  KC_LCBR, KC_RCBR, KC_NUBS

//------------------------------------------------------------------------------------------------------------
#define _________________NUMPD_L1__________________       ___________________NONE____________________
#define _________________NUMPD_L2__________________       ___________________NONE____________________
#define _________________NUMPD_L3__________________       ___________________NONE____________________

#define _________________NUMPD_R1__________________       KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS
#define _________________NUMPD_R2__________________       KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS
#define _________________NUMPD_R3__________________       KC_COMM, KC_1,    KC_2,    KC_3,    KC_DOT

#define TRUNC_6to5( K1, K2, K3, K4, K5, K6) K1, K2, K3, K4, K5 // little macro to truncate the end of the R2 line

