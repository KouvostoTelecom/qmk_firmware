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
        CHAT1,
        CHAT2,
        CHAT3
    };
	
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	case CHAT1:
          if (record->event.pressed) {
            SEND_STRING("hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu hekekeEetu hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu hekekeEetu hekekeEetu hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu hekekeEetu hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("hekekeEetu");
          	SEND_STRING(SS_TAP(X_ENTER));
        }
        return false;
	case CHAT2:
          if (record->event.pressed) {
            SEND_STRING("Hey chat!");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Have you seen Joakim's latest video?");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("If not, here is a link!");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("https://youtu.be/dQw4w9WgXcQ");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Remember to like and subscribe!");
          	SEND_STRING(SS_TAP(X_ENTER));
        }
        return false;
	case CHAT3:
          if (record->event.pressed) {
            SEND_STRING("Thank you HelSec for having us");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("If you are interested about RubberHeikki, please follow;");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("KouvostoTelecom https://twitter.com/KouvostoTelecom");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Heikki https://twitter.com/heikkistark");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Heikki https://twitter.com/HJuva");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Joni https://twitter.com/jonihasanen");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Also stay tuned for...");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Drum roll please");
          	SEND_STRING(SS_TAP(X_ENTER));

            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(SS_TAP(X_ENTER));

            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(SS_TAP(X_ENTER));

            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(":drum_with_"); SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING(SS_TAP(X_ENTER));

            SEND_STRING("");
          	SEND_STRING(SS_TAP(X_ENTER));
            SEND_STRING("Stay tuned, stay safe!");
          	SEND_STRING(SS_TAP(X_ENTER));
        }
        return false;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
/*	----  ----  ----  ----  ----  ----*/
	      CHAT1,             KC_1, 
	CHAT2,       KC_3, KC_4,       KC_5,
	      CHAT3,             KC_7
   )
};