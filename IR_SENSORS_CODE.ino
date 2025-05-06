#define SENSOR_PIN 25
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SENSOR_PIN , INPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  int state = digitalRead(SENSOR_PIN);

  if(state == HIGH)
    Serial.println("THE OBSTACLE IS PRESENT");
    Serial.println(state);
  else
    Serial.println("THE OBSTACLE IS NOT PRESENT");

  delay(100);

}
