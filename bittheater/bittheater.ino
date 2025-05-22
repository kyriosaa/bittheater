#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "AnimateIntro.h"
#include "AnimateHelloWorld.h"
#include "AnimateJpGreeting.h"
#include "AnimateBlocks.h"

// ----------- hardware -----------
#define LCD_ADDRESS 0x27
#define CHANGE_BUTTON 4
#define SELECT_BUTTON 5
// --------------------------------

// ------ func declarations -------
void greetings();
void printMenu(int menuState);
void playAnimation(int menuState);
// --------------------------------

LiquidCrystal_I2C lcd(LCD_ADDRESS, 16, 2);
int menuState = 1;
unsigned long lastPressTime = 0;
const int debounceDelay = 200;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  pinMode(CHANGE_BUTTON, INPUT);
  pinMode(SELECT_BUTTON, INPUT);

  greetings();
}

void loop() {
  printMenu(menuState);

  if(digitalRead(CHANGE_BUTTON) == HIGH && millis() - lastPressTime > debounceDelay) {
    lastPressTime = millis();
    menuState = (menuState % 4) + 1;
  }

  if(digitalRead(SELECT_BUTTON) == HIGH) {
    playAnimation(menuState);
  }
}

void greetings() {
  lcd.setCursor(0, 0);
  lcd.print("Hello!");
  delay(1500);
  lcd.setCursor(0, 0);
  lcd.print("Please select");
  lcd.setCursor(0, 1);
  lcd.print("an animation.");
  delay(1500);
}

void printMenu(int menuState) {
  switch(menuState) {
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("1    2    3    4");
      lcd.setCursor(0, 1);
      lcd.print("^               ");
      break;
    case 2:
      lcd.setCursor(0, 0);
      lcd.print("1    2    3    4");
      lcd.setCursor(0, 1);
      lcd.print("     ^          ");
      break;
    case 3:
      lcd.setCursor(0, 0);
      lcd.print("1    2    3    4");
      lcd.setCursor(0, 1);
      lcd.print("          ^     ");
      break;
    case 4:
      lcd.setCursor(0, 0);
      lcd.print("1    2    3    4");
      lcd.setCursor(0, 1);
      lcd.print("               ^");
      break;
  }
}

void playAnimation(int menuState) {
  switch(menuState) {
    case 1:
      lcd.clear();
      animateIntro();
      break;
    case 2:
      lcd.clear();
      animateHelloWorld();
      break;
    case 3:
      lcd.clear();
      animateJpGreeting();
      break;
    case 4:
      lcd.clear();
      animateBlocks();
      break;
  }
}