void setup() {
  // put your setup code here, to run once:
  initDCMotor();
  startSteps()
  delay(500);
  stopSteps();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void initDCMotor(){
  pinMode(DC_MOTOR_PIN, OUTPUT);
}

void startSteps(){
  analogWrite(DC_MOTOR_PIN, 225);  
}

void stopSteps(){
  analogWrite(DC_MOTOR_PIN, 0);
}
