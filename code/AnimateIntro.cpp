#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include "ASCIISymbols.h"
#include "AnimateIntro.h"

// ------ func declarations -------
void title();
// --------------------------------

extern LiquidCrystal_I2C lcd;

void animateIntro() {
  title();
}

void title() {
  String title = "BitTheater";
  String desc1 = "A Digital";
  String desc2 = "Pocket Theater";

  // BitTheater
  for(int i = 0; i < title.length(); i++) {
    lcd.setCursor(i + 3, 0);
    if(i < title.length()) {
      lcd.print(title.charAt(i));
    }
    delay(100);
  }
  delay(500);
  lcd.clear();

  for(int i = 0; i < desc1.length(); i++) {
    lcd.setCursor(i, 0);
    if(i < desc1.length()) {
      lcd.print(desc1.charAt(i));
    }
    delay(100);
  }
  for(int i = 0; i < desc2.length(); i++) {
    lcd.setCursor(i, 1);
    if(i < desc2.length()) {
      lcd.print(desc2.charAt(i));
    }
    delay(100);
  }
  delay(500);
}