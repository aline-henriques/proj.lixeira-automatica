# Lixeira Automática com Arduino

A Lixeira Automática foi projetada para abrir e fechar automaticamente ao detectar a presença de um usuário próximo. Utilizando sensores ultrassônicos conectados a um Arduino, o sistema é capaz de reconhecer a proximidade, acionar a tampa da lixeira e emitir um som de agradecimento. Esse projeto visa promover uma solução prática, higiênica e interativa para o descarte de resíduos.


## Sumário

- [Componentes](#componentes)
- [Montagem do Circuito](#montagem-do-circuito)
- [Instalação e Configuração](#instalacao-e-configuracao)
- [Código](#codigo)
- [Descrição do Funcionamento](#descricao-do-funcionamento)
- [Equipe](#equipe)


## Componentes

Para construir este projeto, você precisará dos seguintes componentes:

        • Arduino Uno R3
        • Sensor Ultrassônico HC-SR04
        • Micro Servo Motor
        • Protoboard
        • Fios Jumpers
        • Lixeira de plástico
        • Buzzer (opcional)


## Montagem do Circuito

Conecte os componentes conforme abaixo:

        1. Sensor Ultrassônico HC-SR04
           - Trigger Pin (TRIG): Conecte ao pino digital 7 no Arduino.  
           - Echo Pin (ECHO): Conecte ao pino digital 6 no Arduino.  
           - VCC: Conecte ao pino de 5V no Arduino.  
           - GND: Conecte ao pino GND no Arduino.

        2. Servo Motor
           - Sinal: Conecte ao pino digital 9 no Arduino.  
           - VCC: Conecte ao pino de 5V no Arduino.  
           - GND: Conecte ao pino GND no Arduino.

        3. Buzzer
           - Pino Positivo (+): Conecte ao pino digital 8 no Arduino.  
           - Pino Negativo (-): Conecte ao pino GND no Arduino.
    

## Instalação e Configuração

        1.	Baixe e instale o Arduino IDE para escrever e carregar o código no Arduino.
        2.	Conecte o Arduino ao seu computador através do cabo USB.
        3.	Certifique-se de que todos os componentes estão conectados corretamente de acordo com o esquema do circuito.
        4.	Carregue o código no Arduino e teste o funcionamento.


### Código

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
  tone(buzzerPin, 1000, 200);
  delay(250);
  tone(buzzerPin, 1200, 200);
  delay(250);
  tone(buzzerPin, 1500, 300);
}
```


## Descrição do Funcionamento

        1. O sensor ultrassônico (HC-SR04) usa os pinos 7 (Trigger) e 6 (Echo) para medir a distância entre o sensor e um objeto próximo.
        2. Se a distância medida for menor ou igual a 20 cm, o sistema ativa o servo motor (conectado ao pino 9) para abrir a tampa da lixeira.
        3. O buzzer, conectado ao pino 8, emite um som de agradecimento quando a tampa é aberta.
        4. Após 2 segundos, se não houver mais objetos detectados, a tampa retorna à posição inicial (0 graus).
        Esse ciclo se repete enquanto o sensor continua detectando objetos próximos.

## Equipe

        • __Aline Henriques__: Frontend, criação de vídeos, organização e prototipação.
        • Bruno Henrique Leite Braga: Hardware.
        • Glauco Santos Cerqueira Seixas: Hardware.
        • Pedro Augusto Cavalcanti de Souza: Auxílio na montagem, organização e testes.