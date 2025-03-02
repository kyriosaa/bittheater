#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ASCIISymbols.h"
#include "AnimateJpGreeting.h"

// ------ func declarations -------
void konnichiwa();
void genki();
void ramen();
void sukidesu();
void exclaimation();
// --------------------------------

extern LiquidCrystal_I2C lcd;

void animateJpGreeting() {
  konnichiwa();
  genki();
  ramen();
  sukidesu();
  exclaimation();
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

void ramen() {
  int symbolsCount = 0;

  for(int i = 0; i < 9; i++) {
    lcd.setCursor(i, 0);
    lcd.write(ramenSymbols[symbolsCount]);
    lcd.write(EMPTY_SYMBOL);
    delay(100);
    symbolsCount++;
  }
  delay(100);
}

void sukidesu() {
  int symbolsCount = 0;

  for(int i = 0; i < 12; i++) {
    lcd.setCursor(i, 1);
    lcd.write(sukidesuSymbols[symbolsCount]);
    lcd.write(EMPTY_SYMBOL);
    delay(100);
    symbolsCount++;
  }
  delay(300);
}

void exclaimation() {
  for(int i = 15; i >= 0; i--) {
    lcd.setCursor(i, 0);
    lcd.print("!");
    lcd.setCursor(i, 1);
    lcd.print("!");
    delay(100);
  }
  delay(500);
}