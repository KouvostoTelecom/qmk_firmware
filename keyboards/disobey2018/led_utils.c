#include "led_utils.h"

void clear_leds(void) {
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

void set_leds_for_layer(uint8_t laayer) {
  switch (get_highest_layer(layer_state)) {
    case 0:
      writePinHigh(A7);
      writePinHigh(B0);
      break;
    case 1:
      writePinHigh(A4);
      writePinHigh(B10);
      break;
    case 2:
      writePinHigh(A3);
      writePinHigh(A8);
      break;
    case 3:
      writePinHigh(A10);
      writePinHigh(A15);
      break;
  }
}
