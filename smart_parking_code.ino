//#include <Wire.h> 
#include<Servo.h>
#include <LiquidCrystal_I2C.h>
// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo ser;                                                                                      
int ir_car1=6;
int ir_car2=7;
int ir_p1 = 3;
int ir_p2 = 4;
int x1;
int x2;
int x3;                                                                 
int x4;                                          
int c1 =0;
int c2 =0;
int total;
int slot =2;
int ledr =13;
int ledy =12;
int buzz=11;

void setup()
{
  Serial.begin(9600);
	// initialize the LCD
	lcd.init();
  lcd.setCursor(0,0);
  lcd.backlight();
  lcd.display();
  pinMode(ledr,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(buzz,OUTPUT);
  ser.attach(5);

  
}

void loop()
{
  x1 =digitalRead(ir_car1);
  x2 =digitalRead(ir_car2);
  x3 =digitalRead(ir_p1);
  x4 =digitalRead(ir_p2);
  if (x1==0){
    c1=1;
  }
  else{
    c1=0;
  }
  if (x2==0){
    c2=1;
  }
  else{
    c2=0;
  }
  total = c1+c2;

  if ((slot-total)==0){

    lcd.setCursor(0,0);
    lcd.print("Parking is full");
     delay(2000);
  	 lcd.clear();


  }
  else{
    lcd.setCursor(0,0);
    lcd.print("The slot left");
    lcd.setCursor(6,1);
    lcd.print(slot-total);
    delay(2000);
    lcd.clear();
    
  }
  if ((slot-total) <= 0){
    ser.write(0);
    delay(20);
  }
  else if (x3==0 or x4==0){
    ser.write(90);
    delay(10);
    digitalWrite(ledr,1);

  }
  else{
    ser.write(0);
    delay(10);
    digitalWrite(ledr,0);

  }


}



