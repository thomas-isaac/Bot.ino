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

void Robot::run()
{
  byte i, j, dir;
  for(dir=0, i=2, j=1; i<5; i++, j <<= 1) { // Read each pin INPUT (2-5)
    if(digitalRead(i) == HIGH) // Some sort of bit shift logic
      dir += j;
  }

  switch (dir) { // A bit shameful

  case 0: //No line detected - Keep going for some time
    moteurs.upSpeed(80, 80);
    break;

  case 1: // Line on the right - Adjust to the right
    //while(digitalRead(2) != HIGH)
    moteurs.upSpeed(100, 20);
    break;

  case 2: // Line in the middle - Keep going
    moteurs.upSpeed(80, 80);
    //delay(50);
    break;

  case 3: // Line on both right and mid - Turn right
    moteurs.upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      moteurs.upSpeed(100, -50);

    break;

  case 4: // Line on the left - Adjust to the left
    //while(digitalRead(2) != HIGH)
    moteurs.upSpeed(20, 100);
    break;

  case 5: // Line on both right and left - Everything's fine..
    moteurs.upSpeed(80, 80);
    break;

  case 6: // Line on both left and mid - Turn left
    moteurs.upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      moteurs.upSpeed(-50, 100);
    break;

  case 7: // Line on left, right and mid - Merry Christmas
    moteurs.upSpeed(0, 0);
    while(digitalRead(3) != HIGH)
      moteurs.upSpeed(100, -50);
    break;
  }
  // delay(1);

}

