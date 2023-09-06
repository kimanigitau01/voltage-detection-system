#include <Arduino.h>
#include <LiquidCrystal.h>

#define TEST_PROTOTYPE

const int numCols = 16;
const int numRows = 2;

const int push_button_1 =  3;
const int push_button_2 = 4;
const int push_button_3 = 5;

const int relay_pin = 6;
const int ledPin = 7;


const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 =9, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// function prototype
int state(int pin1, int pin2, int pin3);

void setup()
{
  pinMode (relay_pin, OUTPUT);
  pinMode (ledPin, OUTPUT);
  pinMode (push_button_1, INPUT);
  pinMode (push_button_2, INPUT);
  pinMode (push_button_3, INPUT);
  
  digitalWrite(relay_pin, LOW);
  digitalWrite(ledPin, LOW);
  
  #ifdef TEST_PROTOTYPE
  Serial.begin(9600);
  Serial.println("PHASE FAILURE DETECTION SYSTEM FOR THREE PHASE INDUCTION MOTORS");
  #endif
  
  lcd.begin(numCols, numRows);
  lcd.setCursor(0, 0);
  lcd.print("PHASE FAILURE");
  lcd.setCursor(0, 1);
  lcd.print("DETECTION SYSTEM");
  
  delay(1000);
  lcd.clear();
  
}

void loop()
{
  int pin1_state = digitalRead(push_button_1);
  int pin2_state = digitalRead(push_button_2);
  int pin3_state = digitalRead(push_button_3);
  
  #ifdef TEST_PROTOTYPE
  Serial.println(pin1_state);
  Serial.println(pin2_state);
  Serial.println(pin3_state);
  #endif
  
  int voltage_state = state(pin1_state, pin2_state, pin3_state);
  
  #ifdef TEST_PROTOTYPE
  Serial.println(voltage_state);
  #endif
  if (voltage_state == 1)
  {
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("ALL ");
    lcd.setCursor(0,1);
    lcd.print("PHASES WORKING");
    digitalWrite(relay_pin, HIGH);
    digitalWrite(ledPin, LOW);
  }
  else
  {
    digitalWrite(relay_pin, LOW);
    digitalWrite(ledPin, HIGH);
    if (!pin1_state)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PHASE 1 failed!");
    }
    else if(!pin2_state)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PHASE 2 failed!");
    }
    else if(!pin3_state)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PHASE 3 failed!");
    }
    else if( !pin1_state && !pin2_state)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PHASE 1 & 2 failed!");
    }
    else if(!pin3_state && !pin2_state)
    {
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PHASE 2 & 3 failed!");
    }
    else if(!pin1_state && pin3_state)
    {
      lcd.setCursor(0,0);
      lcd.print("PHASE 1 & 3 failed!");
    }
    else
    {
      	lcd.clear();
      	lcd.setCursor(4,0);
    	lcd.print("ALL ");
    	lcd.setCursor(0,1);
    	lcd.print("PHASES FAILED");
    }
  }
  delay(1000);
}
int state(int pin1, int pin2, int pin3)
{
  int state = LOW;

  if(!pin1 && !pin2 && !pin3)
  {
    state = 1;

  }
  else
  {
    state = 0;
  }

  return state;
}