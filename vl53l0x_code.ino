#include <Wire.h>
#include <SparkFun_VL53L1X.h>

SFEVL53L1X distanceSensor;

void setup() {
  Serial.begin(115200);
  Wire.begin(21, 22); // Default ESP32 I2C pins

  if (distanceSensor.begin() == false) {
    Serial.println("VL53L1X not found");
    while (1);
  }

  distanceSensor.setDistanceModeLong(); // Optional: Short/Medium/Long
  distanceSensor.setTimingBudgetInMs(50); // Optional: in ms
  distanceSensor.startRanging(); // Start continuous measurements
}

void loop() {
  if (distanceSensor.checkForDataReady()) {
    int distance = distanceSensor.getDistance(); // in mm
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
    distanceSensor.clearInterrupt();
  }
  delay(50);
}
