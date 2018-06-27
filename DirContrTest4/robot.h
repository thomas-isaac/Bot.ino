#ifndef ROBOT_H
#define ROBOT_H

#include "moteur.h"

#define WCIRCONF 396 // Circonference of the wheel in mm
#define WSENS 5 // Wheel sensor digital pin


class Robot // The Robot class
{
public:
  Robot();
  ~Robot();

  void init(); // The initializiation function
  void run(); // The main run function
  void wheelSpeed(); // The speed sensor function
  float getSpeed();
  void reInit();

private:
  Moteur moteurs; // The moteurs object
  float wSpeed; 
};


#endif


