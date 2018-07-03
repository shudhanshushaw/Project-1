#include<Servo.h>
int trigPin = 2;
int echoPin = 3;
int const buzzPin = 7;
long duration;
int distance;
Servo servo;

void setup()
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
  servo.attach(9);
}

void loop()
{
  for (int i = 15; i <= 165; i++)
  {
    servo.write(i);
    delay(100);
    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
  for (int i = 165; i > 15; i--)
  {
    servo.write(i);
    delay(100);
    distance = calculateDistance();

    Serial.print(i);
    Serial.print(",");
    Serial.print(distance);
    Serial.print(".");
  }
}

int calculateDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
   if (distance <= 40 && distance >= 0) {
      // Buzz
      digitalWrite(buzzPin, HIGH);
    } else {
      // Don't buzz
      digitalWrite(buzzPin, LOW);
    }
    // Waiting 60 ms won't hurt any one
    delay(60);

  return distance;
}

