#include "SpeedyStepper.h"

SpeedyStepper armStepper;

const byte ARM_HOMING_PIN = 28;

const byte PROXIMITY_PIN = 8;

const byte microstepping = 8;
const float accelerationInMmpersec = 5;
const float speedInMmpersec = 5;

void setup() {
  pinMode(PROXIMITY_PIN, INPUT_PULLUP);

  armStepper.connectToPort(1);

  const int transmissionRatio = 2;
  armStepper.setStepsPerMillimeter(microstepping * 200);
  armStepper.setSpeedInMillimetersPerSecond(speedInMmpersec);
  armStepper.setAccelerationInMillimetersPerSecondPerSecond(accelerationInMmpersec);

  homeStepper();
  moveStepperToTop();
}

void homeStepper() {
  armStepper.moveToHomeInMillimeters(1, speedInMmpersec, 40, ARM_HOMING_PIN);
}

void moveStepperToTop() {
  armStepper.moveToPositionInMillimeters(-30);
}

void loop() {
  //bool sensorDoesNotSeeMetal = digitalRead(PROXIMITY_PIN);

  //if(sensorDoesNotSeeMetal)
  //{
    
      
    //armStepper.moveRelativeInRevolutions(0.5);
    //delay(100);
  //}
}

