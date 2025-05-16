#include <Wire.h>
#include "VL53L1X.h"
VL53L1X sensor;

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

//start module
#define StartPin 34


const int CCW = 2; // do not change
const int CW  = 1; // do not change

#define motor1 1 // do not change
#define motor2 2 // do not change

Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA,  IN3, IN4, ENB, CHB, true);

//---------------------IR SENSORS-------------------------------

#define SENSOR_PIN_FRONT 25
#define SENSOR_PIN_BACK 23



void setup() {
  Serial.begin(115200);
  robot.begin();
  // range_mode: VL53L1X::Short, VL53L1X::Medium, or VL53L1X::Long
  sensor_init(VL53L1X::Long, false); 

  
  //ir sensor
  pinMode(SENSOR_PIN_FRONT , INPUT);
  pinMode(SENSOR_PIN_BACK , INPUT);

// startModule
pinMode(StartPin , INPUT);
Serial.print(digitalRead(StartPin));
   
 
}
//wheel methods
void moveForward(){
  Serial.print("START");
   robot.rotate(motor1, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    

}

void moveBackward(){
  Serial.print("START");
   robot.rotate(motor1, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    

}

void moveRight(){
  Serial.print("START");
  robot.rotate(motor1, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i)
    robot.rotate(motor2, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i) 
    Serial.print("STOP");
    

}

void moveLeft(){
  Serial.print("START");
  robot.rotate(motor1, 50, CCW);// turn motor1 with i% speed in CW direction (whatever is i)
  robot.rotate(motor2, 50, CW);// turn motor1 with i% speed in CW direction (whatever is i) 
  Serial.print("STOP");
  

}

//this method is for the eyes
void sensor_init(VL53L1X::DistanceMode range_mode, bool high_speed) {
  Wire.begin();
  sensor.setTimeout(500);
  sensor.init();
  sensor.setDistanceMode(range_mode);  
  int budget = high_speed ? 33000 : 140000;
  sensor.setMeasurementTimingBudget(budget);
}



void loop() {

  while(digitalRead(StartPin) == 0){
    Serial.println("Stuck in a while loop STOPPED");
    robot.brake(1);
    robot.brake(2); 
  
  }
  
  int stateFront = digitalRead(SENSOR_PIN_FRONT);
  int distance = sensor.readRangeSingleMillimeters();
 

  // if(stateFront == LOW){
  //   Serial.println("FRONT - black, robot is safe");
  // }
  // else{
  //   Serial.println("FRONT - white, robot is not safe");
  //   moveBackward();//will go in opposite direction
  // }

  // if(stateBack == LOW){
  //   Serial.println("BACK - black, robot is safe");
  // }
  // else{
  //   Serial.println("BACK - white, robot is not safe");
  //   moveForward();//will go in opposite direction
  // }
  
  if(stateFront == HIGH){
    Serial.println("SEE WHITE BOUNDARY ----- MOVE BACK");
    moveBackward();
  }

  int stateBack = digitalRead(SENSOR_PIN_BACK);
  if(stateBack == HIGH){
    Serial.println("SEE WHITE BOUNDARY ----- MOVE FORWARD");
    moveForward();
  }

  int distance2 = sensor.readRangeSingleMillimeters();

 while(digitalRead(StartPin) == 0){
    Serial.println("Stuck in a while loop STOPPED");
    robot.brake(1);
    robot.brake(2); 

  }


  if(distance2 <= 1400 & (stateFront == LOW && stateBack == LOW) ){
      Serial.println("FORWARDDDDDDDDDDDDDDDD") ;

       moveForward();
      

  }

int distance3 = sensor.readRangeSingleMillimeters();
    if(distance3> 1400 & (stateFront == LOW && stateBack == LOW) ){
    Serial.println("LEFT");
    moveLeft();
   
    }

    int distance4 = sensor.readRangeSingleMillimeters();
    if(distance4 > 1400 & (stateFront == LOW && stateBack == LOW )){
    Serial.println("RIGHT" );
    moveRight();
    
    }
     while(digitalRead(StartPin) == 0){
    Serial.println("Stuck in a while loop STOPPED");
    robot.brake(1);
    robot.brake(2); 
   
  }

int distance5 = sensor.readRangeSingleMillimeters();
while(distance5 > 1400 & (stateFront == LOW && stateBack == LOW )){
Serial.println("SEES DISTANCE GREATER THAN 1400 ---- SPINNNNN");
 moveLeft();
 delay(1000);
 distance5 = sensor.readRangeSingleMillimeters();
 stateFront = digitalRead(SENSOR_PIN_FRONT);
 stateBack = digitalRead(SENSOR_PIN_BACK);

}
Serial.println("STOPS SPINNING");

   
    



  
  

///-------------------------------------------------
}







// fore two motors with debut information
//Robojax_L298N_DC_motor robot(IN1, IN2, ENA, CHA, IN3, IN4, ENB, CHB, true);

// void setup() {
//   Serial.begin(115200);
//   robot.begin();
//   //L298N DC Motor by Robojax.com

// }



