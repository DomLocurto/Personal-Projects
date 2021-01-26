void setup() {
 Serial.begin(9600);
 pinMode(2,OUTPUT);
 pinMode(3,INPUT);
 pinMode(5, OUTPUT);

}

void loop() {
long duration, distance; //declaring variables used later on
digitalWrite(2, LOW); 
delayMicroseconds(2);
digitalWrite(2, HIGH);
delayMicroseconds(10);
digitalWrite(2, LOW);
//sending out a pulse from the sesnor for 10 milliseconds
duration = pulseIn(3, HIGH);
distance = (duration/2) / 29.1; //converts distance taken in by sesnor to cm (not particularly accurate)
if (distance < 10); {
  digitalWrite(5, HIGH);
}
else {
  digitalWrite(5, LOW)
}
Serial.print(distance);
Serial.println("cm");
delay(500);
//using the serial monitor to find distance every time step
}
