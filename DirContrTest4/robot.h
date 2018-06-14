#ifndef ROBOT_H
#define ROBOT_H

#include "moteur.h"

class Robot
{
public:
  Robot();
  ~Robot();

  void init();
  void run();

private:
  Moteur moteurs;
};


#endif


