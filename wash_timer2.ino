#include <Servo.h>

const int Pin9 = 9;
const int echoPin = 10;

float duration;
float distance;

int threshold = 200;
Servo myServo;

void setup() {

  Serial.begin(9600);
  
  // 7 to servo 
  myServo.attach(7);
  myServo.write(180);
  delay(700);
  myServo.write(0);
  delay(700);
  myServo.write(180);
}

void loop() {
  digitalWrite(Pin9, LOW);
  delayMicroseconds(2);
  digitalWrite(Pin9, HIGH);
  delayMicroseconds(10);
  digitalWrite(Pin9, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.println(distance);

  if (distance < threshold) {
    countdownServo();
  }
  delay(100);
}

void countdownServo() {
  Serial.println("Counting down");
  int halfseconds = 40;

  for (int i = halfseconds; i >= 0; i--) {

    myServo.write((int)(i * 4.5));
    delay(500);
  }

  // reset
  myServo.write(180);
  delay(700);
}
