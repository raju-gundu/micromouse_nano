
#include<VL53L0X.h>

VL53L0X leftSensor;
VL53L0X frontSensor;
VL53L0X rightSensor;


void sensorsSetup(){
  pinMode(LEFT_SENSOR_PIN, OUTPUT);
  pinMode(FRONT_SENSOR_PIN, OUTPUT);
  pinMode(RIGHT_SENSOR_PIN, OUTPUT);
  digitalWrite(LEFT_SENSOR_PIN, LOW);
  digitalWrite(FRONT_SENSOR_PIN, LOW);
  digitalWrite(RIGHT_SENSOR_PIN, LOW);

  // Initialize each sensor with a unique address
  initializeSensor(&leftSensor, LEFT_SENSOR_PIN, leftSensorAddress);
  initializeSensor(&frontSensor, FRONT_SENSOR_PIN, frontSensorAddress);
  initializeSensor(&rightSensor, RIGHT_SENSOR_PIN, rightSensorAddress);
}

void initializeSensor(VL53L0X *sensor, int xshutPin, uint8_t newAddress)
{
  digitalWrite(xshutPin, LOW);
  delay(10);
  digitalWrite(xshutPin, HIGH);
  delay(10);

  sensor->setTimeout(500);
  if (!sensor->init())
  {
    Serial.print("Failed to detect and initialize sensor at address ");
    Serial.println(newAddress, HEX);
    while (1);
  }

  sensor->setAddress(newAddress);
  sensor->startContinuous();
}

int frontSensorValue(){
  return frontSensor.readRangeContinuousMillimeters();
}

int leftSensorValue(){
  return leftSensor.readRangeContinuousMillimeters();
}

int rightSensorValue(){
  return rightSensor.readRangeContinuousMillimeters();
}

boolean leftWall(){
  return (leftSensorValue()<=leftWallThreshold);
}

boolean rightWall(){
  return (rightSensorValue()<=rightWallThreshold);
}

boolean frontWall(){
  return (frontSensorValue()<=frontWallThreshold);
}