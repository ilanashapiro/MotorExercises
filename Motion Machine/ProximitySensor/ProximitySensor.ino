int LOWER_SENSOR_PIN = 57;
int UPPER_SENSOR_PIN = 56;
int valLower = 0;
int valUpper = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LOWER_SENSOR_PIN, INPUT);
  pinMode(UPPER_SENSOR_PIN, INPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  
  /*Serial.println(ballAtUpperSensor()); 
  Serial.println(ballAtLowerSensor());
  Serial.println();*/
  //delay(400);
  ballAtUpperSensor();
  ballAtLowerSensor();
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
