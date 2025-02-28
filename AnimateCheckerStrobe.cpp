#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "AnimateCheckerStrobe.h"

// ----- ASCII char in memory -----
#define FILL_SYMBOL 0xFF
// --------------------------------

extern LiquidCrystal_I2C lcd;

int strobeState = 0;

void animateCheckerStrobe() {
  for(int i = 0; i < 10; i++) {
    lcd.clear();
    if(strobeState == 0) {
      for(int j = 0; j < 16; j += 2) {
        lcd.setCursor(j, 0);
        lcd.write(FILL_SYMBOL);
        lcd.setCursor(j + 1, 1);
        lcd.write(FILL_SYMBOL);
      }
      strobeState = 1;
      delay(100);
      continue;
    }
    if(strobeState == 1) {
      for(int j = 0; j < 16; j += 2) {
        lcd.setCursor(j + 1, 0);
        lcd.write(FILL_SYMBOL);
        lcd.setCursor(j, 1);
        lcd.write(FILL_SYMBOL);
      }
      strobeState = 0;
      delay(100);
      continue;
    }
  }
}