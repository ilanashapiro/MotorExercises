#include "SpeedyStepper.h"
#include "RCServo.h"

SpeedyStepper armStepper;
RCServo servo;
const int DC_MOTOR_PIN = 4;
const byte ARM_HOMING_PIN = 28;
const byte LOWER_SENSOR_PIN = 57;
const byte UPPER_SENSOR_PIN = 56;

const byte microstepping = 4;
const float stepperAccelInRmpSecSec = 0.5;
const float stepperSpeedInRpmSec = 0.25;



//STEPPER
void homeStepper() {
  armStepper.moveToHomeInMillimeters(-1, stepperSpeedInRpmSec, 40, ARM_HOMING_PIN);
}

void moveStepperToTop() {
  armStepper.moveToPositionInMillimeters(30);
}

void initStepper() {
  armStepper.connectToPort(1);
  armStepper.setStepsPerMillimeter(microstepping * 200);
  armStepper.setSpeedInMillimetersPerSecond(stepperSpeedInMmpersec);
  armStepper.setAccelerationInMillimetersPerSecondPerSecond(stepperAccelInMmpersec);
}



//PROXIMITY SENSORS
void initProximitySensors() {
  pinMode(LOWER_SENSOR_PIN, INPUT_PULLUP);
  pinMode(UPPER_SENSOR_PIN, INPUT_PULLUP);
}

bool ballAtUpperSensor() {
  if(digitalRead(UPPER_SENSOR_PIN) == 0) {
    Serial.print("upper sensor is at ");
    Serial.println(digitalRead(UPPER_SENSOR_PIN));
    Serial.println();
    return true;
  }
  return false;
}

bool ballAtLowerSensor() {
  if(digitalRead(LOWER_SENSOR_PIN) == 0)
  {
    Serial.print("lower sensor is at ");
    Serial.println(digitalRead(LOWER_SENSOR_PIN));
    Serial.println();
    return true;
  }
  return false;
}

//SERVO
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

void initServo() {
    servo.connectToPin(A1);
}

//DC MOTOR
void initDCMotor(){
  pinMode(DC_MOTOR_PIN, OUTPUT);
}

void startSteps(){
  analogWrite(DC_MOTOR_PIN, 225);  
}

void stopSteps(){
  analogWrite(DC_MOTOR_PIN, 0);
}



void setup() {
  Serial.begin(9600);
  initProximitySensors();
  
  initStepper();
  homeStepper();

  initServo();
  //moveServoToHome();
  setServoLeft();

  initDCMotor();
}


void loop() { 
  if(ballAtLowerSensor()) {

    moveStepperToTop();
    delay(500);
    startSteps();
    homeStepper();
    delay(600);
    setServoRight();
    stopSteps();
    delay(800);
    setServoLeft();
  }
}

