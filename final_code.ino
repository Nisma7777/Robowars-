// #include <Wire.h>
// #include <SparkFun_VL53L1X.h>

// SFEVL53L1X distanceSensor;

//wheels variables

//code for the wheels
#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define CHA 0
#define ENA 19 // this pin must be PWM enabled pin if Arduino board is used
#define IN1 18
#define IN2 5

// motor 2 settings
#define IN3 4
#define IN4 17
#define ENB 16// this pin must be PWM enabled pin if Arduino board is used
#define CHB 1

const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB, true);


void setup() {
  Serial.begin(115200);
  robot.begin();
  // Wire.begin(21, 22); // Default ESP32 I2C pins
  
}

//   if (distanceSensor.begin() == false) {
//     Serial.println("VL53L1X not found");
//     while (1);
//   }

//   distanceSensor.setDistanceModeLong(); // Optional: Short/Medium/Long
//   distanceSensor.setTimingBudgetInMs(50); // Optional: in ms
//   distanceSensor.startRanging(); // Start continuous measurements
// }

//wheel methods
void moveForward(){
  Serial.print("START");
   robot.rotate(motor1, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    delay(100);

}

void moveBackward(){
  Serial.print("START");
   robot.rotate(motor1, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    delay(100);

}

void moveRight(){
  Serial.print("START");
  robot.rotate(motor1, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    delay(100);

}

void moveLeft(){
  Serial.print("START");
  robot.rotate(motor1, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i)
  robot.rotate(motor2, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
  Serial.print("STOP");
  delay(100);

}


void loop() {
  // if (distanceSensor.checkForDataReady()) {
  //   int distance = distanceSensor.getDistance(); // in mm
  //   Serial.print("Distance: ");
  //   Serial.print(distance);
  //   Serial.println(" mm");
  //   distanceSensor.clearInterrupt();
  // }
  // delay(50);

  Serial.print("MOVE FORWARD");
  moveForward();

  Serial.print("MOVE BACKWARD");
  moveBackward();

  Serial.print("MOVE RIGHT");
  moveRight();

  Serial.print("MOVE LEFT");
  moveLeft();
}





// fore two motors with debut information
//Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA, IN3, IN4, ENB, CHB, true);

// void setup() {
//   Serial.begin(115200);
//   robot.begin();
//   //L298N DC Motor by Robojax.com

// }



