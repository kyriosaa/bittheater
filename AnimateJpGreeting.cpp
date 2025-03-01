#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ASCIISymbols.h"
#include "AnimateJpGreeting.h"

// ------ func declarations -------
void konnichiwa();
void genki();
// --------------------------------

extern LiquidCrystal_I2C lcd;

void animateJpGreeting() {
  konnichiwa();
  genki();
}

void konnichiwa() {
  int symbolsCount = 0;

  for(int i = 0; i < 6; i++) {
    for(int j = 1; j >= 0; j--) {
      lcd.setCursor(i, j);
      lcd.write(konnichiwaSymbols[symbolsCount]);
      lcd.setCursor(i, j - 1);
      lcd.write(EMPTY_SYMBOL);
      delay(200);
    }
    symbolsCount++;
  }
  delay(300);
}

void genki() {
  int symbolsCount = 0;

  for(int i = 0; i < 10; i++) {
    for(int j = 15; j >= 0 + i; j--) {
      lcd.setCursor(j, 1);
      lcd.write(genkiSymbols[symbolsCount]);
      lcd.setCursor(j + 1, 1);
      lcd.write(EMPTY_SYMBOL);
      delay(50);
    }
    symbolsCount++;
  }
  delay(800);
}