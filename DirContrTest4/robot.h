#ifndef ROBOT_H
#define ROBOT_H

#include "moteur.h"

class Robot // The Robot class
{
public:
  Robot();
  ~Robot();

  void init(); // The initializiation function
  void run(); // The main run function

private:
  Moteur moteurs; // The moteurs object
};


#endif


