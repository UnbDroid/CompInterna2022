#include <Arduino.h>
#include <MotorDC.h>

// Motor 1
#define pin1A 5
#define pin1B 6
#define pin1pwm 7
#define pin1Enc A0

// Motor 2
#define pin2A 8
#define pin2B 9
#define pin2pwm 10
#define pin2Enc A1

MotorDC MotorRight(pin1A, pin1B, pin1pwm, pin1Enc);
MotorDC MotorLeft(pin2A, pin2B, pin2pwm, pin2Enc);

void setup() {
  Serial.begin(9600);

}

void loop() {
  MotorRight.fwd(70);
  MotorLeft.fwd(70);
  delay(5000);
  MotorRight.stop();
  MotorLeft.stop();
  delay(5000);
  MotorRight.rev(70);
  MotorLeft.rev(70);
  delay(5000);
}