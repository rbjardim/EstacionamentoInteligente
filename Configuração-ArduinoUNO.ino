#include <Servo.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 20, 4);

Servo Servo;
int ir_sensor = 2;
int volta_sensor = 3;
int servo_motor = 9;

int S1 = 0, S2 = 0;

void setup() {
  pinMode(ir_sensor, INPUT);
  pinMode(volta_sensor, INPUT);
  Servo.attach(servo_motor);

  Serial.begin(9600);

  lcd.init();
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print(" TCC - CC8P07 ");
  lcd.setCursor(0, 1);
  lcd.print(" GRUPO 14");
  delay(5000);

}
  
void loop() {
Read_Sensor();
Serial.println(S1);

}

void Read_Sensor() {

  if (digitalRead(ir_sensor) == 0) {
  Servo.write(90);
  delay(2000);
  Servo.write(0);
  }
    if (digitalRead(volta_sensor) == 0) {
  Servo.write(90);
  delay(2000);
  Servo.write(0);
  }

}
