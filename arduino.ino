#include <Servo.h>

Servo servo1;
Servo servo2;

const int LED1_PIN = 2;
const int LED2_PIN = 3;
const int SERVO1_PIN = 9;
const int SERVO2_PIN = 10;

void setup() {
  Serial.begin(9600);

  // Configuração dos Pinos dos LEDs
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);

  // Associação dos Servos
  servo1.attach(SERVO1_PIN);
  servo2.attach(SERVO2_PIN);

  // Posição inicial centralizada (90 graus)
  servo1.write(90);
  servo2.write(90);
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim();

    int separatorIndex = data.indexOf(':');
    if (separatorIndex != -1) {
      int servoNum = data.substring(0, separatorIndex).toInt();
      int angle = data.substring(separatorIndex + 1).toInt();
      angle = constrain(angle, 0, 180);

      if (servoNum == 1) {
        digitalWrite(LED1_PIN, HIGH);
        servo1.write(angle);
        delay(150); // Sinaliza a movimentação do LED
        digitalWrite(LED1_PIN, LOW);
      } 
      else if (servoNum == 2) {
        digitalWrite(LED2_PIN, HIGH);
        servo2.write(angle);
        delay(150); // Sinaliza a movimentação do LED
        digitalWrite(LED2_PIN, LOW);
      }
    }
  }
}