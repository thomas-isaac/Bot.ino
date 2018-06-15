#include "robot.h"

Robot::Robot()
{
}


Robot::~Robot()
{
}

void Robot::init()
{
  moteurs.init();
}

void Robot::run() // The main function to run the robot
{
  byte i, j, dir; // i and j are our incrementation vars for the loop
		  // dir is the "direction" variable, it contains information about the sensors state
		  // The sensors state is represented by a binary state, one bit per sensor, for a total of 3 bits
 
  for(dir=0, i=2, j=1; i<5; i++, j <<= 1) { // Read each pin INPUT (2-5) 
    if(digitalRead(i) == HIGH) // If the sensor detects BLACK, then update the dir var
      dir += j; // j is added to dir. For each turn of the loop, j is bit-shifted to the left
  }

  switch (dir) { // Defines the behavior of the robot depending on the sensors state
		 // To make it clearer, each case will be associated to its binary value

  case 0: // 000 : No line detected - Keep going for some time
    moteurs.upSpeed(80, 80);
    break;

  case 1: // 001 : Line on the right - Adjust to the right
    moteurs.upSpeed(100, -60);
    break;

  case 2: // 010 : Line in the middle - Keep going
    moteurs.upSpeed(80, 80);
    break;

  case 3: // 011 : Line on both right and mid - Turn right
    moteurs.upSpeed(0, 0); // Stop the robot
    while(digitalRead(3) != HIGH) // While the middle sensor is not on the line
      moteurs.upSpeed(100, -50); // Turn right by decreasing the right wheels speed
    break;

  case 4: // 100 : Line on the left - Adjust to the left
    moteurs.upSpeed(-60, 100);
    break;

  case 5: // 101 : Line on both right and left - Not yet handled, keep going forward
    moteurs.upSpeed(80, 80);
    break;

  case 6: // 110 : Line on both left and mid - Turn left
    moteurs.upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      moteurs.upSpeed(-50, 100);
    break;

  case 7: // 111 : Line on left, right and mid - Not yet handled, turn left
    moteurs.upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      moteurs.upSpeed(100, -50);
    break;
  }

}
