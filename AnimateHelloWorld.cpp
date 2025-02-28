#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "AnimateHelloWorld.h"

// ----- ASCII char in memory -----
#define LESS_THAN_SYMBOL 0x3C
#define GREATER_THAN_SYMBOL 0x3E
// --------------------------------

extern LiquidCrystal_I2C lcd;

int textAnimPos = 9;
int helloTextPos = 5;
int worldTextPos = 10;

void animateHelloWorld() {
  for(int i = 0; i < 7; i++) {
    int leftPosition = 6 - i;
    int rightPosition = 9 + i;

    lcd.clear();

    if(leftPosition >= 0) {
      lcd.setCursor(leftPosition, 0);
      lcd.write(LESS_THAN_SYMBOL);
      lcd.setCursor(leftPosition, 1);
      lcd.write(LESS_THAN_SYMBOL);
    }

    if(rightPosition <= 16) {
      lcd.setCursor(rightPosition, 0);
      lcd.write(GREATER_THAN_SYMBOL);
      lcd.setCursor(rightPosition, 1);
      lcd.write(GREATER_THAN_SYMBOL);
    }

    delay(100);
  }

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
  textAnimPos--;
  helloTextPos++;
  worldTextPos--;
  
  delay(2000);
}