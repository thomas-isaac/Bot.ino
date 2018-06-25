#include <Grove_I2C_Motor_Driver.h> // Library containing the Motor Driver functionalities
#include <Wire.h>
#include <VirtualWire.h>
#include <VirtualWire_Config.h>
#include "robot.h" // Library containing the robot functionalities


Robot robot; // Create a new robot object

void setup() {
  Serial.begin(9600);
  robot.init(); // Call the initialization
}

void loop() {
  robot.run(); // Call the run
  robot.wheelSpeed(); // Call the speed sensor
}



