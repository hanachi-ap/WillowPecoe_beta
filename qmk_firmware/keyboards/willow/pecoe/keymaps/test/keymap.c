/* Copyright 2021 hanachi-ap
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    SW_ENCODER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]=LAYOUT(   //QWERTY (for test)
			KC_ESC	,	KC_Q	,	KC_W	,	KC_E	,	KC_R	,	KC_T	,							KC_Y	,	KC_U	,	KC_I	,	KC_O	,	KC_P	,	KC_LBRC	,	KC_RBRC	,
			KC_TAB	,	KC_A	,	KC_S	,	KC_D	,	KC_F	,	KC_G	,							KC_H	,	KC_J	,	KC_K	,	KC_L	,	KC_SCLN	,	KC_MINS	,	KC_ENT	,
			KC_LSFT	,	KC_Z	,	KC_X	,	KC_C	,	KC_V	,	KC_B	,	KC_DEL	,			KC_RGUI	,	KC_N	,	KC_M	,	KC_COMM	,	KC_DOT	,	KC_SLSH	,	KC_RSFT	,
	SW_ENCODER	,					        KC_LEFT	,	KC_RIGHT,	KC_SPC	,	KC_LCTL	,	KC_LALT,	KC_ENT	,	KC_BSPC	,	KC_DOWN	,	KC_UP
)
};

static int encoder_mode = 0;

void keyboard_post_init_user(void) {
    // Turn on RGBLIGHT with test mode, without writing EEPROM.
    rgblight_enable_noeeprom();
    rgblight_mode_noeeprom(RGBLIGHT_MODE_RGB_TEST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SW_ENCODER:
            if (record->event.pressed) {
                if (encoder_mode == 0) {
                    encoder_mode = 1;
                    rgblight_disable_noeeprom();
                } else {
                    encoder_mode = 0;
                    rgblight_enable_noeeprom();
                }
            }
            return false;
    }
    return true;
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (encoder_mode == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else {
        if (clockwise) {
            tap_code(KC_END);
        } else {
            tap_code(KC_HOME);
        }
    }
}

void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_update_user(index, clockwise);
}
