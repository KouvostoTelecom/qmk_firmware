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
#ifdef OLED_DRIVER_ENABLE
#  include <../../oled_utils.c>
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
/*	----  ----  ----  ----  ----  ----*/
	      KC_0,             KC_1, 
	KC_2,       KC_3, KC_4,       KC_5,
	      KC_6,             KC_7
   ),
   [1] = LAYOUT(
	      KC_U,             KC_X, 
	KC_L,       KC_R, KC_Y,       KC_A,
	      KC_D,             KC_B
   ),
   [2] = LAYOUT(
	      KC_A,             KC_B, 
	KC_C,       KC_D, KC_E,       KC_F,
	      KC_G,             KC_H
   ),
   [3] = LAYOUT(
	      KC_W,             KC_T, 
	KC_A,       KC_D, KC_F,       KC_H,
	      KC_S,             KC_G
   )
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_0;
}


static uint16_t key_timer_from_boot;
void oled_task_user(void) {
  if(timer_elapsed(key_timer_from_boot) > 3000) {
    oled_write_P(PSTR("From: KouvostoTelecomTo: Hackers\n"), false);
    oled_write_P(PSTR("\nHave you considered\ntrying HARDER?\n"), false);
  } else  {
    render_qmk_logo();
  }
}
#endif

void keyboard_post_init_user(void) {
  key_timer_from_boot = timer_read();
}

unsigned char layer = 0;
const unsigned char MAX_LAYERS = 4;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      if (!clockwise && layer < MAX_LAYERS-1) {
        layer++;
      } else if (clockwise && layer > 0){
        layer--;
      }
      layer_move(layer);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch (get_highest_layer(state)) {
    case 0:
      oled_write_P(PSTR("Layer: 0\n"), false);
      break;
    case 1:
      oled_write_P(PSTR("Layer: 1\n"), false);
      break;
    case 2:
      oled_write_P(PSTR("Layer: 2\n"), false);
      break;
    case 3:
      oled_write_P(PSTR("Layer: 3\n"), false);
      break;
    default:
      oled_write_P(PSTR("Layer: Unknown\n"), false);
  }
  return state;
}
