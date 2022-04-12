#include <Arduino.h>
#include <MotorDC.h>
#include <SensorColor.h>
#include <Ultrasonic.h>
#include <Move.h>


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


MotorDC motorRight (5, 7, 8, 12); 
MotorDC motorLeft (6, 4, 9, 13);

Ultrasonic SensorUltraFront(pinFrontTrigger, pinFrontEcho);
Ultrasonic SensorUltraLeft(pinLeftTrigger, pinLeftEcho);
Ultrasonic SensorUltraRight(pinRightTrigger, pinRightEcho);

SensorColor SensorColorLeft(pinColorLeftS0, pinColorLeftS1, pinColorLeftS2, pinColorLeftS3, pinColorLeftOut);


//Declaração de variáveis que serão parâmetros na função moveAllpid.
float soma = 0;
float error [2];
float giro = 0;
float mR;
float mL;

void inc (){

  motorLeft.encSignal();
  
}

void incR (){

	motorRight.encSignal();
}

void setup() {
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(13), inc, RISING);
	attachInterrupt(digitalPinToInterrupt(12), incR, RISING);
  error[0] = 0;
	error[1] = millis();
}


void loop() {

  mL = motorLeft.getCount();
	mR = motorRight.getCount();
	giro = mL - mR;
	soma = 0;

  Serial.print("mL: ");
	Serial.print(mL);
	Serial.print("mR: ");
	Serial.print(mR);

  moveAllpid(50, &motorLeft, &motorRight, &soma, error, giro);
}
