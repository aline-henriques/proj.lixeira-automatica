# Lixeira Automática com Arduino

A Lixeira Automática foi projetada para abrir e fechar automaticamente ao detectar a presença de um usuário próximo. Utilizando sensores ultrassônicos conectados a um Arduino, o sistema é capaz de reconhecer a proximidade e acionar a tampa da lixeira. Esse projeto visa promover uma solução prática e higiênica para o descarte de resíduos.

# Sumário
- [Componentes](#componentes)
- [Montagem do Circuito](#montagem-do-circuito)
- [Instalação e Configuração](#instalação-e-configuração)
- [Código](#código)
- [Equipe](#equipe)



# Componentes

Para construir este projeto, você precisará dos seguintes componentes:

    •   Arduino Uno R3
    •   Sensor Ultrassônico HC-SR04
    •   Micro Servo Motor
    •   Protoboard
    •   Fios Jumpers
    •   Lixeira de plástico



# Montagem do Circuito

Conecte os componentes conforme abaixo:

	1.	Sensor Ultrassônico HC-SR04
	•	Trigger Pin (TRIG): Conecte ao pino digital 7 no Arduino.
	•	Echo Pin (ECHO): Conecte ao pino digital 6 no Arduino.
	•	VCC: Conecte ao pino de 5V no Arduino.
	•	GND: Conecte ao pino GND no Arduino.
	2.	Servo Motor
	•	Sinal: Conecte ao pino digital 9 no Arduino.
	•	VCC: Conecte ao pino de 5V no Arduino.
	•	GND: Conecte ao pino GND no Arduino.


Descrição do Funcionamento

	•	O sensor ultrassônico utiliza os pinos 7 (Trigger) e 6 (Echo) para medir a distância de objetos à frente da lixeira.
	•	Quando a distância lida pelo sensor é menor ou igual a 20 cm, o servo motor, conectado ao pino 9, abre a tampa da lixeira, movendo-se para 180 graus.
	•	Após alguns segundos, se nenhum objeto for detectado próximo, a tampa retorna à posição inicial (0 graus).




# Instalação e Configuração

	1.	Baixe e Instale o Arduino IDE para escrever e carregar o código.
	2.	Conecte o Arduino ao seu computador através do cabo USB.
	3.	Certifique-se de que todos os componentes estão conectados corretamente de acordo com o esquema do circuito.



# Código

```cpp
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
    delay(2000);
    distancia = 0.01723 * readUltrasonicDistance(7, 6);
  }

}




# Equipe
- **Aline Henriques**: Frontend, criação de vídeos, organização e prototipação.
- **Bruno Henrique Leite Braga**: Hardware
- **Glauco Santos Cerqueira Seixas**: Hardware
- **Pedro Augusto Cavalcanti de Souza**: Auxílio na montagem, organização e testes