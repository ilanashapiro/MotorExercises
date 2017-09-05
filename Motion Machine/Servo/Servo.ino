#include "RCServo.h"
int setPos = 0;
RCServo servo;
//RCServo upperServo;

void setup() {
  // put your setup code here, to run once:
  servo.connectToPin(A1);
//  upperServo.connectToPin(UPPER_SERVO_PIN, 600, 2200, 0.0);
  moveServoToHome();
  setServoLeft();
  setServoRight();
 }

void moveServoToHome() {
  servo.setServoPosition(0);
  delay(2000);
}

void setServoLeft() {
  servo.setMoveToServoPosition(-0.9, 30);
  delay(2000);
}

void setServoRight() {
  servo.setMoveToServoPosition(1.2, 30);
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  /*servo.setServoPosition(-0.5);
  delay(200);
  servo.setMoveToServoPosition(0.25, 40);
  delay(200);

  servo.setMoveToServoPosition(setPos - 6, 30);
  delay(2000);
  servo.setMoveToServoPosition(setPos, 30);
  delay(2000);*/
  
}
