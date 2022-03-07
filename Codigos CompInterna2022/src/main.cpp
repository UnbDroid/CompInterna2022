#include <Arduino.h>
#include <MotorDC.h>
#include <SensorColor.h>
#include <Ultrasonic.h>

// Motor Direita
#define pin1A 5
#define pin1B 6
#define pin1pwm 7
#define pin1Enc A0

// Motor Esquerda
#define pin2A 8
#define pin2B 9
#define pin2pwm 10
#define pin2Enc A1

//Ultrassom Frente
#define pinFrontTrigger 52
#define pinFrontEcho 53

//Ultrassom Esquerda
#define pinLeftTrigger 50
#define pinLeftEcho 51

//Ultrassom Direita
#define pinRightTrigger 48
#define pinRightEcho 49

// Sensor de cor esquerda
#define pinColorLeftS0 44
#define pinColorLeftS1 45
#define pinColorLeftS2 46
#define pinColorLeftS3 47
#define pinColorLeftOut 43


MotorDC MotorRight(pin1A, pin1B, pin1pwm, pin1Enc);
MotorDC MotorLeft(pin2A, pin2B, pin2pwm, pin2Enc);

Ultrasonic SensorUltraFront(pinFrontTrigger, pinFrontEcho);
Ultrasonic SensorUltraLeft(pinLeftTrigger, pinLeftEcho);
Ultrasonic SensorUltraRight(pinRightTrigger, pinRightEcho);

SensorColor SensorColorLeft(pinColorLeftS0, pinColorLeftS1, pinColorLeftS2, pinColorLeftS3, pinColorLeftOut);


void setup() {
  Serial.begin(9600);

}


void loop() {
  // MotorRight.fwd(70);
  // MotorLeft.fwd(70);
  // delay(5000);
  // MotorRight.stop();
  // MotorLeft.stop();
  // delay(5000);
  // MotorRight.rev(70);
  // MotorLeft.rev(70);
  // delay(5000);

  //Le as informacoes do sensor, em cm e pol
  // float cmMsecFront, cmMsecLeft, cmMsecRight;
  // long microsecFront = SensorUltraFront.timing();
  // long microsecLeft = SensorUltraLeft.timing();
  // long microsecRight = SensorUltraRight.timing();
  // cmMsecFront = SensorUltraFront.convert(microsecFront, Ultrasonic::CM);
  // cmMsecLeft = SensorUltraLeft.convert(microsecLeft, Ultrasonic::CM);
  // cmMsecRight = SensorUltraRight.convert(microsecRight, Ultrasonic::CM);
  // //Exibe informacoes no serial monitor
  // Serial.print("Distancia frente em cm: ");
  // Serial.print(cmMsecFront);
  // Serial.print("\n");
  // Serial.print("Distancia esquerda em cm: ");
  // Serial.print(cmMsecLeft);
  // Serial.print("\n");
  // Serial.print("Distancia direita em cm: ");
  // Serial.print(cmMsecRight);
  // Serial.print("\n");
  // Serial.print("\n");
  // delay(1000);

  SensorColorLeft.readColors(); // Chama a rotina que le as cores

  // Verifica se a cor vermelha foi detectada
  if (SensorColorLeft.vermelho < SensorColorLeft.azul && SensorColorLeft.vermelho < SensorColorLeft.verde){
    Serial.print("VERMELHO");
    Serial.print("\n");
  }
  
  if (SensorColorLeft.azul < SensorColorLeft.vermelho && SensorColorLeft.azul < SensorColorLeft.verde) { // Verifica se a cor azul foi detectada
    Serial.print("AZUL");
    Serial.print("\n");
  }
  
  if (SensorColorLeft.verde < SensorColorLeft.vermelho && SensorColorLeft.verde < SensorColorLeft.azul) { // Verifica se a cor verde foi detectada
    Serial.print("VERDE");
    Serial.print("\n");
  }

  delay(1000); // Aguarda 1000 milissegundos
}
