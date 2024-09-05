
#include<Encoder.h>




void motorSetup(){
  pinMode(AIN1,OUTPUT);
  pinMode(AIN2,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(BIN1,OUTPUT);
  pinMode(BIN2,OUTPUT);
  pinMode(PWMB,OUTPUT);

  pinMode(ENCODER_LEFT_A, INPUT_PULLUP);
  pinMode(ENCODER_LEFT_B, INPUT_PULLUP);

  pinMode(ENCODER_RIGHT_A, INPUT_PULLUP);
  pinMode(ENCODER_RIGHT_B, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_LEFT_A), countLeft, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_RIGHT_A), countRight, CHANGE);
}


void moveForward(){
  digitalWrite(AIN1,HIGH);
  digitalWrite(AIN2,LOW);
  digitalWrite(BIN1,HIGH);
  digitalWrite(BIN2,LOW);
  float error = normal_steering_error();
  float adjustment=calculate_steering_adjustment(error);
  update_motor_controllers(adjustment);
  
  
}

void turnRight(){
  delay(200);
  stopMotors();
  delay(3000);
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  enc_l = 0;
  enc_r = 0;
  while(enc_l<targetCounts && enc_r<targetCounts){
    analogWrite(PWMA,100);
    analogWrite(PWMB,100);
  }
  stopMotors();
  delay(1000);
}

void turnLeft(){
  delay(200);
  stopMotors();
  delay(3000);
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  enc_l = 0;
  enc_r = 0;
  while(enc_l<targetCounts && enc_r<targetCounts){
    analogWrite(PWMA,70);
    analogWrite(PWMB,70);
  }
  stopMotors();
  delay(1000);
}
void stopMotors(){
  digitalWrite(AIN1,LOW);
  digitalWrite(AIN2,LOW);
  digitalWrite(PWMA,0);

  digitalWrite(BIN1,LOW);
  digitalWrite(BIN2,LOW);
  digitalWrite(PWMB,0);
}


void countLeft() {
  enc_l++;
  
}

void countRight() {
  enc_r++;
  
}