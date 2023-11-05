// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
char ch;
byte pin;

const byte ledPins[4] = {6, 7, 8};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("Ready!");
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    ch = Serial.read();
  }

  for (const byte ledPin : ledPins) {
    digitalWrite(ledPin, LOW);
  }

  switch (ch) {
    case '1':
    pin = 6;
    break;

    case '2':
    pin = 7;
    break;

    case '3':
    pin = A3;
    break;
  }

  digitalWrite(pin, HIGH);

  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print("Take medication");
}
