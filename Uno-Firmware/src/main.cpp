#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

const int push_button_1 =  3;
const int push_button_2 = 4;
const int push_button_3 = 5;

const int relay_pin = 6;
const int ledPin = 7;

const int numCols = 16;
const int numRows = 2;

LiquidCrystal_I2C lcd(0x27, numCols, numRows);

bool state(int pin1, int pin2, int pin3);

void setup() {
  pinMode (push_button_1, OUTPUT);
  pinMode (push_button_2, OUTPUT);
  pinMode (push_button_3, OUTPUT);
  pinMode (relay_pin, OUTPUT);
  pinMode (ledPin, OUTPUT);

  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("PHASE DETECTION");
  lcd.setCursor(3, 1);
  lcd.print("SYSTEM");

  delay(1000);
   
   lcd.clear();
}

void loop() {

  int pin1_state = digitalRead(push_button_1);
  int pin2_state = digitalRead(push_button_2);
  int pin3_state = digitalRead(push_button_3);

  int voltage_state = state(pin1_state, pin2_state, pin3_state);
  if (voltage_state)
  {
    lcd.setCursor(4,0);
    lcd.print("ALL ");
    lcd.setCursor(0,1);
    lcd.print("PHASES WORKING");
  }
  else
  {
    if (!pin1_state)
    {
      lcd.setCursor(0,0);
      lcd.print("PHASE 1 failed!");
    }
    else if(!pin2_state)
    {
      lcd.setCursor(0,0);
      lcd.print("PHASE 2 failed!");
    }
    else if(!pin3_state)
    {
      lcd.setCursor(0,0);
      lcd.print("PHASE 3 failed!");
    }
  }
  
}

bool state(int pin1, int pin2, int pin3)
{
  bool state = LOW;

  if(!pin1 && !pin2 && !pin3)
  {
    state = HIGH;

  }
  else
  {
    state = LOW;
  }

  return state;
}