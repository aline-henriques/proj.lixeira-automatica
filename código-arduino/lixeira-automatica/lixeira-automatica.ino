#include <Servo.h>

int distancia = 0;

// Função para ler a distância do sensor ultrassônico
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
  // Calcula a distância em cm
  distancia = 0.01723 * readUltrasonicDistance(7, 6);
  servo_9.write(0); // Fecha a tampa da lixeira
  delay(300); // Aguarda 300 ms

  while (distancia <= 20) {
    servo_9.write(180); // Abre a tampa
    delay(6000); // Mantém a tampa aberta por 6 segundos
    distancia = 0.01723 * readUltrasonicDistance(7, 6); // Atualiza a distância
  }
}
