#include "SpeedyStepper.h"
#include "RCServo.h"

SpeedyStepper armStepper;
RCServo electromagnet;

const byte LOW_TOWER_SENSOR_PIN = 26;
const byte HIGH_TOWER_SENSOR_PIN = 27;
const byte HOMING_SENSOR_PIN = 28;

const byte microstepping = 4;
const float stepperAccelInRPMSecSec = 0.25;
const float stepperSpeedInRPMSec = 0.5;
const byte transmissionRatio = 2;



//PROXIMITY SENSORS
void initProximitySensors() {
  pinMode(LOW_TOWER_SENSOR_PIN, INPUT_PULLUP);
  pinMode(HIGH_TOWER_SENSOR_PIN, INPUT_PULLUP);
  pinMode(HOMING_SENSOR_PIN, INPUT_PULLUP);
}

bool ballAtLowTowerSensor() {
  if(digitalRead(LOW_TOWER_SENSOR_PIN) == 0) {
    Serial.print("low tower sensor is at ");
    Serial.println(digitalRead(LOW_TOWER_SENSOR_PIN));
    Serial.println();
    return true;
  }
  return false;
}

bool ballAtHighTowerSensor() {
  if(digitalRead(HIGH_TOWER_SENSOR_PIN) == 0)
  {
    Serial.print("high tower sensor is at ");
    Serial.println(digitalRead(HIGH_TOWER_SENSOR_PIN));
    Serial.println();
    return true;
  }
  return false;
}

bool ballAtHomingSensor() {
  if(digitalRead(HOMING_SENSOR_PIN) == 0)
  {
    Serial.print("homing sensor is at ");
    Serial.println(digitalRead(HOMING_SENSOR_PIN));
    Serial.println();
    return true;
  }
  return false;
}


//STEPPER
void homeStepper() {
  armStepper.moveToHomeInRevolutions(-1, stepperSpeedInRPMSec, 1.1, HOMING_SENSOR_PIN);
}

void initStepper() {
  armStepper.connectToPort(1);
  //homeStepper();
  armStepper.setStepsPerRevolution(transmissionRatio * microstepping * 200);
  armStepper.setSpeedInRevolutionsPerSecond(stepperSpeedInRPMSec);
  armStepper.setAccelerationInRevolutionsPerSecondPerSecond(stepperAccelInRPMSecSec);
}

void moveStepperToHighTower() {
  armStepper.moveToPositionInRevolutions(0.24);
}

void moveStepperToLowTower() {
  armStepper.moveToPositionInRevolutions(0.4);
}



//ELECTROMAGNET SERVO
void initElectromagnet() {
  electromagnet.connectToPin(24);//, 1000, 2000, 0);
}

void turnOnMagnet() {
  electromagnet.setServoPosition(1);
  Serial.println("magnet on");
}

void turnOffMagnet() {
  electromagnet.setServoPosition(0);
  Serial.println("magnet off");
}


void setup() {
  // put your setup code here, to run once: 
  Serial.begin(9600);
  pinMode(24, OUTPUT);
  initProximitySensors();
  initStepper();
  homeStepper();
  initElectromagnet();

}

void loop() {
  // put your main code here, to run repeatedly:
  if(ballAtHighTowerSensor()) {
    moveStepperToHighTower();
    delay(500);
    turnOnMagnet();
    delay(500);
    moveStepperToLowTower();
    delay(500);
    turnOffMagnet();
    delay(500);
  }
    
  if(ballAtLowTowerSensor()) {
    moveStepperToLowTower();
    delay(500);
    turnOnMagnet();
    delay(500);
    moveStepperToHighTower();
    delay(500);;
    turnOffMagnet();
    delay(500);
  }
    

  /*Serial.print("low tower sensor is at ");
    Serial.println(digitalRead(LOW_TOWER_SENSOR_PIN));
    Serial.println();

    delay(1000);

    Serial.print("high tower sensor is at ");
    Serial.println(digitalRead(HIGH_TOWER_SENSOR_PIN));
    Serial.println();
 delay(1000);
    Serial.print("homing tower sensor is at ");
    Serial.println(digitalRead(HOMING_SENSOR_PIN));
    Serial.println();
     delay(1000);*/

}
