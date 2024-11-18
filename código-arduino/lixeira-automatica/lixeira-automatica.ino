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
const int buzzerPin = 8;

void setup() {
  servo_9.attach(9, 500, 2500);
  pinMode(buzzerPin, OUTPUT); 
}

void loop() {
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
  servo_9.write(0); 
  delay(300);

  while (distancia <= 20) {
    servo_9.write(180);
    playThankYouSound(); 
    delay(2000); 
    distancia = 0.01723 * readUltrasonicDistance(7, 6);
  }
}

void playThankYouSound() {
  tone(buzzerPin, 1000, 200); // Frequência em Hz, duração em ms
  delay(250);
  tone(buzzerPin, 1200, 200);
  delay(250);
  tone(buzzerPin, 1500, 300);
}
