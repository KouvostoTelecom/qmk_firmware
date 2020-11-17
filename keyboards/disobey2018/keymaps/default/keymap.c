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
#include <../../shared_keyboard_utils.c>
#include <../../led_utils.c>
#include <../../oled_utils.c>
#include <sendstring_finnish.h>


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_0;
}

void keyboard_pre_init_user(void) {
  // Call the keyboard pre init code.
  // Set our LED pins as output
  setPinOutput(A7);
  setPinOutput(B4);
  setPinOutput(B15);
  setPinOutput(A10);
  setPinOutput(A4);
  setPinOutput(A8);
  setPinOutput(A15);
  setPinOutput(A9);
  setPinOutput(A3);
  setPinOutput(B9);
  setPinOutput(A2);
  setPinOutput(B10);
  setPinOutput(B8);
  setPinOutput(B0);

  writePinLow(B4);
  writePinLow(B15);
  writePinLow(A10);
  writePinLow(A4);
  writePinLow(A8);
  writePinLow(A15);
  writePinLow(A9);
  writePinLow(A3);
  writePinLow(B9);
  writePinLow(A2);
  writePinLow(B10);
  writePinLow(B8);
  writePinLow(A7);
  writePinLow(B0);
}

static uint16_t key_timer_from_boot;
static bool boot_logo_shown = false;

void oled_task_user(void) {
  if(timer_elapsed(key_timer_from_boot) < 3000 && !boot_logo_shown) {
    render_kt_logo();
  } else  {
    if(!boot_logo_shown){
      render_empty();
      boot_logo_shown = true;
    }
    uint8_t selected_layer = get_highest_layer(layer_state);
    set_leds_for_layer(selected_layer);
    render_layer_ui(selected_layer);
  }
}

void keyboard_post_init_quantum(void) {
  key_timer_from_boot = timer_read();
}

unsigned char layer = 0;

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
      if (!clockwise && layer < MAX_LAYERS-1) {
        layer++;
      } else if (clockwise && layer > 0){
        layer--;
      }
      layer_move(layer);
      clear_leds();
    }
}

