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

void set_leds_for_layer(uint8_t layer) {
  switch (layer) {
    case 7:
      writePinHigh(A15);
    case 6:
      writePinHigh(A10);
    case 5:
      writePinHigh(A8);
    case 4:
      writePinHigh(A3);
    case 3:
      writePinHigh(B10);
    case 2:
      writePinHigh(A4);
    case 1:
      writePinHigh(B0);
    case 0:
      writePinHigh(A7);
      break;
  }
}
