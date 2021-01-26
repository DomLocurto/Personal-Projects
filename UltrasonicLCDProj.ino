#include <LiquidCrystal.h>

LiquidCrystal lcd(2,13,3,4,5,6);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,INPUT);
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
digitalWrite(11, LOW);
delayMicroseconds(2);
digitalWrite(11, HIGH);
delayMicroseconds(10);
digitalWrite(11, LOW);
duration = pulseIn(12, HIGH);
distance = (duration/2) / 29.1;
if (distance < 10) {
  lcd.setCursor(0,0);
  lcd.print("too close");
}
else {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("safe");
}
Serial.print(distance);
Serial.println("cm");
delay(500);
}
