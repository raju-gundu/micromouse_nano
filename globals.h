#include<VL53L0X.h>
#include<Wire.h>

/******************************************************************************Motor Setup****************************************************************************************************/
//Motor Pin Configurations
#define AIN1 6
#define AIN2 5
#define PWMA 9
#define BIN1 7
#define BIN2 4
#define PWMB 10


//motor speeds
int baseLeftMotorSpeed = 255;
int baseRightMotorSpeed = 255;

int targetCounts = 430;


/******************************************************************************Encoder Setup*************************************************************************************************/
//Encoder Pin Configurations
#define ENCODER_LEFT_A 2
#define ENCODER_LEFT_B A2
#define ENCODER_RIGHT_A 3 
#define ENCODER_RIGHT_B A1


volatile unsigned long enc_l = 0;
volatile unsigned long enc_r = 0;

/*******************************************************************************Sensor Setup*************************************************************************************************/
//Senors Pin Configurations
#define LEFT_SENSOR_PIN 8
#define FRONT_SENSOR_PIN 11
#define RIGHT_SENSOR_PIN 12

//Sensors Address Configurations
#define leftSensorAddress 0x30
#define frontSensorAddress 0x31
#define rightSensorAddress 0x32

//Thresholds
const int leftWallThreshold = 130;
const int rightWallThreshold = 130;
const int frontWallThreshold = 100;

/*********************PID***************/

float steering_kP = 2.130;//1.250  // raw 1.370 works  going toward higher value 1.410  1.700-perfect turn at corner 1.900 , at 3 more osscilation 2.2 2.120
float steering_kD = 0.810; //0.799 working good 0.810 best
float I = 0;//0.0025;
float last_error = 0;
float totalError = 0;
//int offset = 5;
const int leftDesiredDistance=93; // for filtered distance l=8.85 and r=8.72
const int rightDesiredDistance=94;

