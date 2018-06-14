#include <Grove_I2C_Motor_Driver.h>
#include <Wire.h>
#include "robot.h"

int signalPin2 = 2;
int signalPin3 = 3;
int signalPin4 = 4;

Robot robot;

void setup() 
{
  pinMode(signalPin2, INPUT); // Init each pin with INPUT mode
  pinMode(signalPin3, INPUT); // (default mode)
  pinMode(signalPin4, INPUT);

  robot.init();
}

void loop() 
{
  robot.run();
}


