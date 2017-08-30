int sensorPin = A2;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(sensorPin); 
  Serial.println(val);
  delay(400);
}
