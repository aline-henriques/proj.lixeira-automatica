#include <Servo.h>

int distancia = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_9;

void setup() {
  servo_9.attach(9, 500, 2500);
}

void loop() {
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
  servo_9.write(0);
  delay(300);

  while (distancia <= 20) {
    servo_9.write(180);
    delay(6000);
    distancia = 0.01723 * readUltrasonicDistance(7, 6);
  }
}
