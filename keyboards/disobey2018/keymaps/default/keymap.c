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
#include "oled_driver.h"
#include <print.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
/*	----  ----  ----  ----  ----  ----*/
	      KC_0,             KC_1, 
	KC_2,       KC_3, KC_4,       KC_5,
	      KC_6,             KC_7
   )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_0;
}

void oled_task_user(void) {
  xprintf("🍆");
  oled_write_P(PSTR("From: KouvostoTelecomTo: Hackers\n"), false);
  oled_write_P(PSTR("\nHave you considered\ntrying HARDER?"), false);
}
#endif

void keyboard_post_init_user(void) {
  wait_ms(2000);
  xprintf("heikki");
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
