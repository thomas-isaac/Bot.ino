#include <Grove_I2C_Motor_Driver.h> // Library containing the Motor Driver functionalities
#include <Wire.h>
#include "robot.h" // Library containing the robot functionalities

// Define which pin should be used to get the sensors input
int signalPin2 = 2;
int signalPin3 = 3;
int signalPin4 = 4;

Robot robot; // Create a new robot object

void setup() 
{
  pinMode(signalPin2, INPUT); // Init each pin with INPUT mode
  pinMode(signalPin3, INPUT); // (default mode)
  pinMode(signalPin4, INPUT);

  robot.init(); // Call the initialization
}

void loop() 
{
  robot.run(); // Call the run
}


