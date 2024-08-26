/* Copyright 2022  CyanDuck
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
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

#include "keycodes.h"
#include QMK_KEYBOARD_H
#include "gzrl.h"

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
    _SYM,
    _NUM,
    _NAV,
};


#define LAYOUT_waterfowl_wrapper(...) LAYOUT(__VA_ARGS__)

#define LAYOUT_waterfowl_base( \
    K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, \
    K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, \
    K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A  \
    ) \
    LAYOUT_waterfowl_wrapper ( \
	K01,		    K02,		    K03,		    K04,		    K05,			K06,     K07,		    K08,		        K09,		K0A, \
	LT(_SYM, K11),  ALT_T(K12),	    SFT_T(K13),     CTL_T(K14),     K15,			K16,	 CTL_T(K17),	SFT_T(K18),	        ALT_T(K19),	LT(_SYM, K1A), \
	GUI_T(K21),     K22,            K23,		    LT(_NUM,K24),	K25,			K26,     K27,		    K28,	            K29,		K2A, \
	XXXXXXX,        KC_ESC,	        KC_TAB,         KC_ENT ,	    XXXXXXX,        XXXXXXX, KC_SPC,     LT(_NAV,KC_BSPC),   KC_DEL,    XXXXXXX \
    )

#define LAYOUT_waterfowl_base_wrapper(...) LAYOUT_waterfowl_base(__VA_ARGS__)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 *<D-g>
 * ,----------------------------------.                      ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |                      |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|                      |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |                      |   H  |   J  |   K  |   L  |   ;  |
 * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |  |CAPS |    |NUMLK|  |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'  `-----'    `-----'  `----------------------------------'
 *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
 *          |  1  |   |  ESC | TAB | ENTER |            | SPACE | BS |  DEL  |   |  4  |
 *          `-----'   `--------------------'            `--------------------'   `-----'
 */
[_QWERTY] =  LAYOUT_waterfowl_base_wrapper(
        _________________BASE__L1__________________,    _________________BASE__R1__________________,
        _________________BASE__L2__________________,    _________________BASE5_R2__________________,
        _________________BASE__L3__________________,    _________________BASE__R3__________________
    ),
[_SYM] = LAYOUT_waterfowl_base_wrapper(
        ________________SYMBOL_L1__________________,    ________________SYMBOL_R1__________________,
        ________________SYMBOL_L2__________________,    ________________SYMBL5_R2__________________,
        ________________SYMBOL_L3__________________,    ________________SYMBOL_R3__________________
    ),
[_NUM] = LAYOUT_waterfowl_wrapper(
        _________________NUMPD_L1__________________,    _________________NUMPD_R1__________________,
        _________________NUMPD_L2__________________,    _________________NUMPD_R2__________________,
        _________________NUMPD_L3__________________,    _________________NUMPD_R3__________________,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
[_NAV] = LAYOUT_waterfowl_wrapper(
        _________________RAISE_L1__________________,    _________________RAISE_R1__________________,
        _________________RAISE_L2__________________,    _________________RAIS5_R2__________________,
        _________________RAISE_L3__________________,    _________________RAISE_R3__________________,
        ___________________BLANK___________________,    ___________________BLANK___________________
    )

};
//
// /* NAVNUM
//  *
//  * ,----------------------------------.                      ,----------------------------------.
//  * |      | PgUp |  UP  | PgDn |      |                      |   /  |   7  |   8  |   9  |   -  |
//  * |------+------+------+------+------|                      |------+------+------+------+------|
//  * | Home | Left | Down | Right| End  |                      |   =  |   4  |   5  |   6  |   +  |
//  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
//  * |      |      |  INS |      |      |  |CAPS |    |NUMLK|  |   0  |   1  |   2  |   3  |   *  |
//  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
//  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
//  *          |  1  |   |  ESC | TAB | ENTER |            | SPACE | BS |  DEL  |   |  4  |
//  *          `-----'   `--------------------'            `--------------------'   `-----'
//  */
// [_NAVNUM] = LAYOUT(
// 	KC_NO,		KC_PGUP,		KC_UP,			KC_PGDN,	KC_NO,				KC_SLSH,	KC_7,	KC_8,		KC_9,			KC_MINS,
// 	KC_HOME,	KC_LEFT,		KC_DOWN,		KC_RGHT,	KC_END,				KC_EQL,		KC_4,	KC_5,		KC_6,			KC_PLUS,
// 	KC_NO,		KC_NO,			KC_INS,			KC_NO,		KC_NO,				KC_0,		KC_1,	KC_2,		KC_3,			KC_ASTR,
// 	KC_1,		LT(3,KC_ESC),	LT(1,KC_TAB),	KC_ENT,		KC_CAPS,			KC_NUM,		KC_SPC,	KC_BSPC,	LT(2,KC_DEL),	KC_4
// ),
//
// /* SYM
//  *
//  * ,----------------------------------.                      ,----------------------------------.
//  * |   %  |   @  |   [  |   ]  |   \  |                      |      |      |   ^  |      |      |
//  * |------+------+------+------+------|                      |------+------+------+------+------|
//  * |   #  |   !  |   (  |   )  |   |  |                      |   _  |   '  |   "  |   ~  |   `  |
//  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
//  * |   $  |   £  |   {  |   }  |   &  |  |CAPS |    |NUMLK|  |      |      |      |      |      |
//  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
//  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
//  *          |  1  |   |  ESC | TAB | ENTER |            | SPACE | BS |  DEL  |   |  4  |
//  *          `-----'   `--------------------'            `--------------------'   `-----'
//  */
// [_SYM] = LAYOUT(
// 	KC_PERC,	KC_AT,			KC_LBRC,		KC_RBRC,	KC_BSLS,		KC_NO,		KC_NO,		KC_CIRC,	KC_NO,			KC_NO,
// 	KC_HASH,	KC_EXLM,		KC_LPRN,		KC_RPRN,	KC_PIPE,		KC_UNDS,	KC_QUOT,	KC_DQT,		KC_TILD,		KC_GRV,
// 	KC_DLR,		KC_NO,			KC_LCBR,		KC_RCBR,	KC_AMPR,		KC_NO,		KC_NO,		KC_NO,		KC_NO,			KC_NO,
// 	KC_1,		LT(3,KC_ESC),	LT(1,KC_TAB),	KC_ENT,		KC_CAPS,		KC_NUM,		KC_SPC,		KC_BSPC,	LT(2,KC_DEL),	KC_4
// ),
//
// /* FUNC
//  *
//  * ,----------------------------------.                      ,----------------------------------.
//  * |      |      |      |      |      |                      |      |  F7  |  F8  |  F9  |  F11 |
//  * |------+------+------+------+------|                      |------+------+------+------+------|
//  * |      |      |      |      |      |                      |      |  F4  |  F5  |  F6  |  F12 |
//  * |------+------+------+------+------|  ,-----.    ,-----.  |------+------+------+------+------|
//  * | Reset|      |      |      |      |  |CAPS |    |NUMLK|  |  F10 |  F1  |  F2  |  F3  |  F13 |
//  * `----------------------------------'  `-----'    `-----'  `----------------------------------'
//  *          ,-----.   ,--------------------.            ,--------------------.   ,-----.
//  *          |  1  |   |  ESC | TAB | ENTER |            | SPACE | BS |  DEL  |   |  4  |
//  *          `-----'   `--------------------'            `--------------------'   `-----'
//  */
// [_FUNC] =  LAYOUT(
// 	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F7,	KC_F8,		KC_F9,			KC_F11,
// 	KC_NO,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_NO,	KC_F4,	KC_F5,		KC_F6,			KC_F12,
// 	QK_BOOT,	KC_NO,			KC_NO,			KC_NO,	KC_NO,			KC_F10,	KC_F1,	KC_F2,		KC_F3,			KC_F13,
// 	KC_1,	LT(3,KC_ESC),	LT(1,KC_TAB),	KC_ENT,	KC_CAPS,		KC_NUM,	KC_SPC,	KC_BSPC,	LT(2,KC_DEL),	KC_4
// ),
// };
