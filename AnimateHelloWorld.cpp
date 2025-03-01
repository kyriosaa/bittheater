#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ASCIISymbols.h"
#include "AnimateHelloWorld.h"

// ------ func declarations -------
void expandArrows();
void slide1();
void slide2();
void slide3();
void slide4();
void slide5();
// --------------------------------

extern LiquidCrystal_I2C lcd;
int textAnimPos = 9;
int helloTextPos = 5;
int worldTextPos = 10;

void animateHelloWorld() {
  expandArrows();
  slide1();
  slide2();
  slide3();
  slide4();
  slide5();
  delay(2000);
}

void expandArrows() {
  for(int i = 0; i < 7; i++) {
    int leftPos = 6 - i;
    int rightPos = 9 + i;

    lcd.clear();

    if(leftPos >= 0) {
      lcd.setCursor(leftPos, 0);
      lcd.write(LESS_THAN_SYMBOL);
      lcd.setCursor(leftPos, 1);
      lcd.write(LESS_THAN_SYMBOL);
    }

    if(rightPos <= 16) {
      lcd.setCursor(rightPos, 0);
      lcd.write(GREATER_THAN_SYMBOL);
      lcd.setCursor(rightPos, 1);
      lcd.write(GREATER_THAN_SYMBOL);
    }

    delay(100);
  }
}

void slide1() {
  for(int i = 0; i < textAnimPos; i++) {
    int helloText = 13 - i;
    int worldText = 1 + i;

    if(helloText >= helloTextPos) {
      lcd.setCursor(helloText, 0);
      lcd.print("H ");
    }
    if(worldText <= worldTextPos) {
      lcd.setCursor(worldText, 1);
      lcd.print(" d");
    }

    delay(100);
  }
  textAnimPos--;
  helloTextPos++;
  worldTextPos--;
}

void slide2() {
  for(int i = 0; i < textAnimPos; i++) {
    int helloText = 13 - i;
    int worldText = 1 + i;

    if(helloText >= helloTextPos) {
      lcd.setCursor(helloText, 0);
      lcd.print("e ");
    }
    if(worldText <= worldTextPos) {
      lcd.setCursor(worldText, 1);
      lcd.print(" l");
    }

    delay(100);
  }
  textAnimPos--;
  helloTextPos++;
  worldTextPos--;
}

void slide3() {
  for(int i = 0; i < textAnimPos; i++) {
    int helloText = 13 - i;
    int worldText = 1 + i;

    if(helloText >= helloTextPos) {
      lcd.setCursor(helloText, 0);
      lcd.print("l ");
    }
    if(worldText <= worldTextPos) {
      lcd.setCursor(worldText, 1);
      lcd.print(" r");
    }

    delay(100);
  }
  textAnimPos--;
  helloTextPos++;
  worldTextPos--;
}

void slide4() {
  for(int i = 0; i < textAnimPos; i++) {
    int helloText = 13 - i;
    int worldText = 1 + i;

    if(helloText >= helloTextPos) {
      lcd.setCursor(helloText, 0);
      lcd.print("l ");
    }
    if(worldText <= worldTextPos) {
      lcd.setCursor(worldText, 1);
      lcd.print(" o");
    }

    delay(100);
  }
  textAnimPos--;
  helloTextPos++;
  worldTextPos--;
}

void slide5() {
  for(int i = 0; i < textAnimPos; i++) {
    int helloText = 13 - i;
    int worldText = 1 + i;

    if(helloText >= helloTextPos) {
      lcd.setCursor(helloText, 0);
      lcd.print("o ");
    }
    if(worldText <= worldTextPos) {
      lcd.setCursor(worldText, 1);
      lcd.print(" W");
    }

    delay(100);
  }
  
  // return to default values
  textAnimPos = 9;
  helloTextPos = 5;
  worldTextPos = 10;
}