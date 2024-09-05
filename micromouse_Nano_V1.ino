#include "globals.h"


void setup() {
  Wire.begin();
  Serial.begin(9600);
  sensorsSetup();
  motorSetup();
}

void loop() {

  if (!frontWall()) {
    moveForward();
    if (rightWall() && leftWall()) {

    } else if (!leftWall() && rightWall()) {
      turnLeft();
    } else if (!rightWall() && leftWall()) {
      turnRight();
    }
     else if (rightWall() && leftWall()) {
      turnRight();
      delay(1000);
      turnRight();
    }

  } else {
    if (!leftWall() && !rightWall()) {
      turnRight();
    } else if (!leftWall() && rightWall()) {
      turnLeft();
    } else if (!rightWall() && leftWall()) {
      turnRight();
    } else if (rightWall() && leftWall()) {
      turnRight();
      delay(1000);
      turnRight();
    }
    else if((leftWall() && (rightSensorValue()>200&&rightSensorValue()<300) && (frontSensorValue()>200&&frontSensorValue()<300)||(rightWall() && (leftSensorValue()>200&&leftSensorValue()<300) && (frontSensorValue()>200&&frontSensorValue()<300)))){
      stopMotors();
      while(1){

      }
    }
  }
}
