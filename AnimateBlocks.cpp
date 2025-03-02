#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ASCIISymbols.h"
#include "AnimateBlocks.h"

// ------ func declarations -------
void curtain();
void purge();
void teeth();
void strobe();
void pong();
void snake();
void wipe();
// --------------------------------

extern LiquidCrystal_I2C lcd;

void animateBlocks() {
  curtain();
  purge();
  teeth();
  strobe();
  
  lcd.clear();
  delay(400);

  pong();
  snake();
  wipe();
}

void curtain() {
  for(int i = 0; i < 8; i++) {
    int leftPos = 0 + i;
    int rightPos = 15 - i;

    if(leftPos <= 7) {
      lcd.setCursor(leftPos, 0);
      lcd.write(FILL_SYMBOL);
      lcd.setCursor(leftPos, 1);
      lcd.write(FILL_SYMBOL);
    }

    if(rightPos >= 8) {
      lcd.setCursor(rightPos, 0);
      lcd.write(FILL_SYMBOL);
      lcd.setCursor(rightPos, 1);
      lcd.write(FILL_SYMBOL);
    }

    delay(100);
  }
  delay(500);
}

void purge() {
  bool purged[16] = {false};

  for(int i = 0; i < 16; i++) {
    int columnPurge;
    do {
      columnPurge = random(0, 16);
    } while(purged[columnPurge]);

    purged[columnPurge] = true;

    lcd.setCursor(columnPurge, 0);
    lcd.write(EMPTY_SYMBOL);
    lcd.setCursor(columnPurge, 1);
    lcd.write(EMPTY_SYMBOL);

    delay(300);
  }
}

void teeth() {
  for(int i = 0; i < 16; i++) {
    if(i % 2 == 0) {
      lcd.setCursor(i, 0);
      lcd.write(FILL_SYMBOL);
    }
    if(i % 2 == 1) {
      lcd.setCursor(i, 1);
      lcd.write(FILL_SYMBOL);
    }
    delay(150);
  }
}

void strobe() {
  int strobeState = 0;

  for(int i = 0; i < 10; i++) {
    lcd.clear();
    if(strobeState == 0) {
      for(int j = 0; j < 16; j += 2) {
        lcd.setCursor(j + 1, 0);
        lcd.write(FILL_SYMBOL);
        lcd.setCursor(j, 1);
        lcd.write(FILL_SYMBOL);
      }
      strobeState = 1;
      delay(100);
      continue;
    }
    if(strobeState == 1) {
      for(int j = 0; j < 16; j += 2) {
        lcd.setCursor(j, 0);
        lcd.write(FILL_SYMBOL);
        lcd.setCursor(j + 1, 1);
        lcd.write(FILL_SYMBOL);
      }
      strobeState = 0;
      delay(100);
      continue;
    }
  }
}

void pong() {
  int pongPos = 0;

  if(pongPos == 0) {
    for(int j = 0; j < 16; j++) {
      lcd.setCursor(j - 1, 0);
      lcd.write(EMPTY_SYMBOL);
      lcd.setCursor(j - 1, 1);
      lcd.write(EMPTY_SYMBOL);
      lcd.setCursor(j, 0);
      lcd.write(FILL_SYMBOL);
      lcd.setCursor(j, 1);
      lcd.write(FILL_SYMBOL);
      delay(75);
    }
    pongPos = 1;
  }
  if(pongPos == 1) {
    for(int j = 16; j > 0; j--) {
      lcd.setCursor(j, 0);
      lcd.write(FILL_SYMBOL);
      lcd.setCursor(j, 1);
      lcd.write(FILL_SYMBOL);
      lcd.setCursor(j + 1, 0);
      lcd.write(EMPTY_SYMBOL);
      lcd.setCursor(j + 1, 1);
      lcd.write(EMPTY_SYMBOL);
      delay(75);
    }
    pongPos = 0;
  }
}

void snake() {
  // snake start
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(0, 1);
  lcd.write(FILL_SYMBOL);
  delay(100);

  // snake corner (bottom left)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(0, 1);
  lcd.write(FILL_SYMBOL);
  lcd.write(FILL_SYMBOL);
  delay(100);

  // snake left -> right (bottom)
  for(int i = 0; i < 14; i++) {
    lcd.clear();
    lcd.setCursor(i, 1);
    lcd.write(FILL_SYMBOL);
    lcd.write(FILL_SYMBOL);
    lcd.write(FILL_SYMBOL);
    delay(100);
  }

  // snake corner (bottom right)
  lcd.clear();
  lcd.setCursor(16, 0);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(15, 1);
  lcd.write(FILL_SYMBOL);
  lcd.write(FILL_SYMBOL);
  delay(100);

  // snake corner (top right)
  lcd.clear();
  lcd.setCursor(15, 0);
  lcd.write(FILL_SYMBOL);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(16, 1);
  lcd.write(FILL_SYMBOL);
  delay(100);

  // snake right -> left (top)
  for (int i = 14; i > 0; i--) {
    lcd.clear();
    lcd.setCursor(i, 0);
    lcd.write(FILL_SYMBOL);
    lcd.write(FILL_SYMBOL);
    lcd.write(FILL_SYMBOL);
    delay(100);
  }

  // snake corner (top left)
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(FILL_SYMBOL);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(0, 1);
  lcd.write(FILL_SYMBOL);
  delay(100);

  // snake end
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(FILL_SYMBOL);
  lcd.setCursor(0, 1);
  lcd.write(FILL_SYMBOL);
  delay(100);
}

void wipe() {
  for(int i = 0; i < 16; i++) {
    lcd.setCursor(i, 0);
    lcd.write(FILL_SYMBOL);
    lcd.setCursor(i, 1);
    lcd.write(FILL_SYMBOL);
    delay(100);
  }
}