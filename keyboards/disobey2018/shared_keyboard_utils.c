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
 * 
 *
 *************** NOTE!!!! ***************************************************************
 * This file be overridden when firmware is compiled with https://github.com/KouvostoTelecom/badgepad.
 *
 *
 */
const unsigned char MAX_LAYERS = 2;
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
};

void render_layer_ui(uint8_t layer) {
  switch(layer) {
    case 0:
      oled_write_P(PSTR("1: 0\n"), false);
      oled_write_P(PSTR("2: 1\n"), false);
      oled_write_P(PSTR("3: 2\n"), false);
      oled_write_P(PSTR("4: 3\n"), false);
      oled_write_P(PSTR("5: 4\n"), false);
      oled_write_P(PSTR("6: 5\n"), false);
      oled_write_P(PSTR("7: 6\n"), false);
      oled_write_P(PSTR("8: 7\n"), false);
      break;
    case 1:
      oled_write_P(PSTR("1: u\n"), false);
      oled_write_P(PSTR("2: x\n"), false);
      oled_write_P(PSTR("3: l\n"), false);
      oled_write_P(PSTR("4: r\n"), false);
      oled_write_P(PSTR("5: y\n"), false);
      oled_write_P(PSTR("6: a\n"), false);
      oled_write_P(PSTR("7: d\n"), false);
      oled_write_P(PSTR("8: b\n"), false);
      break;
  }
}
