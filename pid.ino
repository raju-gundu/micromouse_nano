

float normal_steering_error() {
  float error=0;
  float left_error = (leftDesiredDistance - leftSensorValue());
  float right_error = (rightDesiredDistance - rightSensorValue());
  
  if(leftWall() && rightWall()){
    error = left_error - right_error;
  
  
  // float errorD = errorP - oldErrorP;
  // totalError += errorP;
  // totalError = constrain(totalError, -255, 255);  // Avoid integral windup



  // float control = P * errorP + D * errorD + I * totalError;

  // oldErrorP = errorP;

  // LMS = leftSpeed + control;
  // RMS = rightSpeed - control;


  // LMS = constrain(LMS, 0, 255);
  // RMS = constrain(RMS, 0, 255);


  // analogWrite(PWMA, LMS);
  // analogWrite(PWMB, RMS);
  // setDirection(FORWARD);
  }
  else{
    error = 0;
  }
  return error;
}

float calculate_steering_adjustment(float error){
  float pTerm = steering_kP * error;
  float dTerm = steering_kD * (error - last_error);
  // dTerm = dTerm/LOOP_INTERVAL;
  float adjustment = (pTerm + dTerm);
  adjustment = constrain(adjustment,-255,255);
  last_error = error;
  return adjustment;
}

void update_motor_controllers(float steering_adjustment){
  int LMS = baseLeftMotorSpeed+steering_adjustment;
  int RMS = baseRightMotorSpeed-steering_adjustment;

  
  LMS = constrain(LMS, 0, 200);
  RMS = constrain(RMS, 0, 200);
  analogWrite(PWMA, LMS);
  analogWrite(PWMB, RMS);
}