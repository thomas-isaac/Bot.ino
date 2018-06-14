#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#define i2c_add 0x0f

int Left, Mid, Right;

int signalPin2 = 2;
int signalPin3 = 3;
int signalPin4 = 4;

void setup() {
  pinMode(signalPin2, INPUT); // Init each pin with INPUT mode
  pinMode(signalPin3, INPUT); // (default mode)
  pinMode(signalPin4, INPUT);

  Motor.begin(i2c_add);
}

void loop() {
  Left = 0;
  Mid = 0;
  Right = 0;
  
  if(digitalRead(2) == HIGH) Left = 1;
  if(digitalRead(3) == HIGH) Mid = 1;
  if(digitalRead(4) == HIGH) Right = 1;
  
  if(Left == 0 && Mid == 0 && Right == 0) upSpeed(80, 80);
  
  else if(Left == 0 && Mid == 0 && Right == 1) {
    while(digitalRead(3) != HIGH)
      upSpeed(-50, 80);
  }
  
  else if(Left == 0 && Mid == 1 && Right == 0) upSpeed(80, 80);
  
  else if(Left == 0 && Mid == 1 && Right == 1) {
    upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      upSpeed(-50, 80);
  }
  
  else if(Left == 1 && Mid == 0 && Right == 0) {
    while(digitalRead(3) != HIGH)
     upSpeed(80, -50);
  }
  
  else if(Left == 1 && Mid == 0 && Right == 1) upSpeed(80, 80);
  
  else if(Left == 1 && Mid == 1 && Right == 0) {
    upSpeed(0, 0);
     while(digitalRead(3) != HIGH)
       upSpeed(100, -50);
  }
  
  else if(Left == 1 && Mid == 1 && Right == 1) {
    upSpeed(0, 0);
     while(digitalRead(3) != HIGH)
       upSpeed(-50, 100);
  }
  
}

void upSpeed(int M1, int M2) {
  Motor.speed(MOTOR1, M1);
  Motor.speed(MOTOR2, -M2);
}
