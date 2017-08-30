#include "RCServo.h"

RCServo lowerServo;
//RCServo upperServo;

void setup() {
  // put your setup code here, to run once:
  lowerServo.connectToPin(A3);
//  upperServo.connectToPin(UPPER_SERVO_PIN, 600, 2200, 0.0);
  
}

void loop() {
  // put your main code here, to run repeatedly:
lowerServo.setServoPosition(-0.5);
  delay(200);
  lowerServo.setMoveToServoPosition(0.25, 40);
  delay(200);
}
