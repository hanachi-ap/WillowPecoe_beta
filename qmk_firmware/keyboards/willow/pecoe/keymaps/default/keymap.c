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
    _NUM,
    _FN,
    _SYS,
    _EXT,
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    SW_ENCODER = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY]=LAYOUT(   //QWERTY
			KC_ESC	,	KC_Q	,	KC_W	,	KC_E	,	KC_R	,	KC_T	,							KC_Y	,	KC_U	,	KC_I	,	KC_O	,	KC_P	,	KC_LBRC	,	KC_RBRC	,
			KC_TAB	,	KC_A	,	KC_S	,	KC_D	,	KC_F	,	KC_G	,							KC_H	,	KC_J	,	KC_K	,	KC_L	,	KC_SCLN	,	KC_MINS	,	KC_ENT	,
			KC_LSFT	,	KC_Z	,	KC_X	,	KC_C	,	KC_V	,	KC_B	,	KC_DEL	,			KC_LGUI	,	KC_N	,	KC_M	,	KC_COMM	,	KC_DOT	,	KC_SLSH	,	KC_RSFT	,
	SW_ENCODER	,							WIN_T(KC_LEFT)	,	ALT_T(KC_RIGHT)	,	LT(_NUM,KC_SPC)	,	CTL_T(KC_F13)	,	LT(_NUM, KC_F13)	,	SFT_T(KC_ENT)	,	LT(_FN, KC_BSPC)	,	LT(_NUM, KC_DOWN)	,	LT(_SYS, KC_UP)
),

[_NUM]=LAYOUT(    // NUM (Num pad)
			KC_GRV	,	KC_1	,	KC_2	,	KC_3	,	KC_4	,	KC_5	,							KC_6	,	KC_7	,	KC_8	,	KC_9	,	KC_0	,	S(KC_9)	,	S(KC_0)	,
			_______	,	KC_EXLM	,	KC_AT	,	KC_HASH	,	KC_DLR	,	KC_PERC	,							XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	_______	,	KC_EQL	,	KC_QUOT	,	KC_BSLS	,
			_______	,	KC_CIRC	,	KC_AMPR	,	KC_ASTR	,	KC_LPRN	,	KC_RPRN	,	_______	,			_______	,	XXXXXXX	,	XXXXXXX	,	_______	,	_______	,	_______	,	_______	,
	KC_SPC	,							C(LWIN(KC_LEFT))	,	C(LWIN(KC_RIGHT))	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______
),
[_FN]=LAYOUT(    //FN (additional keys)
			_______	,	KC_F1	,	KC_F2	,	KC_F3	,	KC_F4	,	KC_F5	,							XXXXXXX	,	KC_PGDN	,	KC_UP	,	KC_PGUP	,	XXXXXXX	,	C(LWIN(KC_LEFT))	,	C(LWIN(KC_RIGHT))	,
			KC_CAPS	,	KC_F6	,	KC_F7	,	KC_F8	,	KC_F9	,	KC_F10	,							XXXXXXX	,	KC_LEFT	,	KC_DOWN	,	KC_RIGHT	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			_______	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	_______	,			TO(_NUM)	,	XXXXXXX	,	KC_HOME	,	KC_DOWN	,	KC_END	,	XXXXXXX	,	XXXXXXX	,
	KC_SPC	,							_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______	,	_______
),
[_SYS]=LAYOUT(  //SYS (System utilz)
			RESET	,	RGB_TOG	,	RGB_VAD	,	RGB_VAI	,	KC_ASON	,	KC_ASOFF	,							XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			EEP_RST	,	RGB_MOD	,	RGB_SAD	,	RGB_SAI	,	KC_ASUP	,	KC_ASDN	,							XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
			XXXXXXX	,	RGB_RMOD	,	RGB_HUD	,	RGB_HUI	,	KC_ASRP	,	XXXXXXX	,	XXXXXXX	,			XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,	XXXXXXX	,
	_______	,							_______	,	_______	,	_______	,	_______	,	XXXXXXX	,	_______	,	_______	,	_______	,	_______
)

};
int encoder_mode = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SW_ENCODER:
            if (record->event.pressed) {
                if (encoder_mode == 0) {
                    encoder_mode = 1;
                } else {
                    encoder_mode = 0;
                }
            }
            return false;
    }
    return true;
}

void keyboard_post_init_user(void) {
    //   rgblight_mode(RGBLIGHT_MODE_RGB_TEST);
#ifdef CONSOLE_ENABLE
    debug_enable = true;
    debug_matrix = true;
#endif
}


void encoder_update_user(uint8_t index, bool clockwise) {
    if (encoder_mode == 0) {
        register_code16(KC_LCTL);
        wait_ms(10);
        if (clockwise) {
            tap_code16(KC_MS_WH_DOWN);
        } else {
            tap_code16(KC_MS_WH_UP);
        }
        unregister_code16(KC_LCTL);

    } else {
        register_code16(KC_LALT);
        wait_ms(10);
        if (clockwise) {
            tap_code16(KC_MS_WH_DOWN);
        } else {
            tap_code16(KC_MS_WH_UP);
        }
        unregister_code16(KC_LALT);
    }
}
void encoder_update_kb(uint8_t index, bool clockwise) {
    encoder_update_user(index, clockwise);
}
