#include <LiquidCrystal.h>

//LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
LiquidCrystal lcd(22, 23, 24, 25, 26, 27);

int IRSensorIN = 28; // connect ir sensor to arduino pin 28
int flagIN=0;
int IRSensorOUT = 29; // connect ir sensor to arduino pin 29
int flagOUT=0;

int capacity=40;


void setup() {
  pinMode (IRSensorIN, INPUT); // sensor pin INPUT
  pinMode (IRSensorOUT, INPUT); // sensor pin INPUT
  
  lcd.begin(16, 2);
  lcd.setCursor(0,0);
  lcd.clear();
  lcd.print("Capacity : ");
  lcd.setCursor(0,1);
  lcd.print(capacity);
  
}

void loop() {

  int sensor_statusIN = digitalRead (IRSensorIN);

  if (sensor_statusIN == 1 && flagIN==0) {
    capacity--;
    lcd.setCursor(0,1);
    lcd.print(capacity);
    flagIN=1;
  }
  else if(sensor_statusIN == 0 && flagIN==1)
  {
    flagIN=0;
  }


  int sensor_statusOUT = digitalRead (IRSensorOUT);

  if (sensor_statusOUT == 1 && flagOUT==0) {
    capacity++;
    lcd.setCursor(0,1);
    lcd.print(capacity);
    flagOUT=1;
  }
  else if(sensor_statusOUT == 0 && flagOUT==1)
  {
    flagOUT=0;
  }
  
  
  
}
