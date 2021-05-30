#include <NewPing.h>
#define trigPin 12
#define echoPin 11
#define MAX_DISTANCE 500

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
int ENA = 13;
int ENB = 13;
int Links_1 =5;
int Links_2 = 6;
int Rechts_1 = 3;
int Rechts_2 = 4;
int greenLed = 7;
int yellowLed = 8;
int redLed = 9;

int sensor_R = A3;
int sensor_L = A2;

void setup() {
  
pinMode(ENA, OUTPUT);
pinMode(ENB, OUTPUT);
pinMode(Rechts_1, OUTPUT);
pinMode(Rechts_2, OUTPUT);
pinMode(Links_1, OUTPUT);
pinMode(Links_2, OUTPUT);
pinMode(sensor_R, INPUT);
pinMode(sensor_L, INPUT);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

}

void loop() {
 
  if (analogRead(sensor_R)<=255 && analogRead(sensor_L)<=255)
{
  //Rechtdoor
  
  analogWrite(ENA, 100);
  analogWrite(ENB, 100);
  
  
  digitalWrite(Links_1, LOW);
  digitalWrite(Links_2, HIGH);
  digitalWrite(Rechts_1, HIGH);
  digitalWrite(Rechts_2, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}
else if (analogRead(sensor_R)<=255 && !analogRead(sensor_L)<=255)
{
  //Rechts
  
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  
  
  digitalWrite(Links_1, HIGH);
  digitalWrite(Links_2, LOW);
  digitalWrite(Rechts_1, HIGH);
  digitalWrite(Rechts_2, LOW);
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}
else if (!analogRead(sensor_L)<=255 && analogRead(sensor_R)<=255)
{ 
  //Links
  
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  digitalWrite(Links_1, LOW);
  digitalWrite(Links_2, HIGH);
  digitalWrite(Rechts_1, LOW);
  digitalWrite(Rechts_2, HIGH);
  digitalWrite(greenLed, HIGH);
  digitalWrite(yellowLed, LOW);
  digitalWrite(redLed, LOW);
}
else if (!analogRead(sensor_R)<=255 && !analogRead(sensor_L)<=255);
{ 
  //Stop
  
  
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  
  digitalWrite(Rechts_1, LOW);
  digitalWrite(Rechts_2, LOW);
  digitalWrite(Links_1, LOW);
  digitalWrite(Links_2, LOW);

  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  digitalWrite(yellowLed, LOW);
  }

  
  int duration, distance, pos = 0, i;
  
 digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);  
  distance = (duration / 2) / 29.1;

  if (distance <= 15)       
  {
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);

  digitalWrite(Rechts_1, LOW);
  digitalWrite(Rechts_2, LOW);
  digitalWrite(Links_1, LOW);
  digitalWrite(Links_2, LOW);
  
    digitalWrite(greenLed, LOW); 
    digitalWrite(yellowLed, HIGH);  
    delay(450);
    digitalWrite(yellowLed, LOW);
    delay(450);
    digitalWrite(yellowLed, HIGH);
    delay(450);
    digitalWrite(yellowLed, LOW);
    digitalWrite(greenLed, HIGH);
  }
}
