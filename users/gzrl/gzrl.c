

#include "gzrl.h"
#include "keycodes.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(MOD_BIT(KC_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(MOD_BIT(KC_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    // CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(MOD_BIT(KC_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(MOD_BIT(KC_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(MOD_BIT(KC_LCTL));
                unregister_code(KC_Z);
            }
            return false;
            break;
        case KC_GUITB:
            if (record->event.pressed) {
                register_mods(MOD_BIT(KC_LGUI));
                register_code(KC_TAB);
            } else {
                unregister_mods(mod_config((MOD_LGUI)));
                unregister_code(KC_TAB);
            }
            return false;
            break;

        case G_LOWER:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;

        case G_RAISE:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            break;

        case G_LSFT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;

        case G_RSFT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;

        case G_LALT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LBRC);
                return false;
            }
            break;

        case G_RALT:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RBRC);
                return false;
            }
            break;
        case KC_SPC:
            if (record->event.pressed) {
#ifdef CAPS_WORD_ENABLE
                bool const capsword = is_caps_word_on();
#else
                bool const capsword = false;
#endif

                if ((get_mods() & MOD_MASK_SHIFT) || capsword) {
                    tap_code16(KC_UNDS);
                } else {
                    tap_code16(KC_SPC);
                }
                return false;
                break;
            }
    }

    return true;
}
