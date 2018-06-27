#ifndef CAPTEUR_H
#define CAPTEUR_H

#include <Arduino.h>

#define WCIRCONF 396

class Capteur
{
public: 
  Capteur(const int &pin);
  ~Capteur();


  void init();
  bool isSeeingAnything();
  void wheelSpeed();
  float getSpeed();

private:
  const int _pin;
  bool wPrevState;
  byte wTime;
  float wSpeed;
};


#endif

