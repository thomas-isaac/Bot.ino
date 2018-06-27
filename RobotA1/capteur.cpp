#include "capteur.h"

Capteur::Capteur(const int &pin) : _pin(pin)
{
}

Capteur::~Capteur()
{
}

void Capteur::init()
{
  pinMode(this->_pin, INPUT);
}

bool Capteur::isSeeingAnything()
{
  return digitalRead(this->_pin);
}

void Capteur::wheelSpeed() { // Get the speed of the vehicule based its wheel rotation
  bool wNewState;
  byte wTrans;

  wNewState = digitalRead(this->_pin); // Read the sensor state
  
  if(wPrevState != wNewState) { // If the state has changed, assume it is a new transition (rotation of the wheel from one hole to another)
    if(wTrans == 0) // If it's the first transition
      wTime = millis(); // Get the time at which the transition happens
      
    wTrans++; // Increment the transitions count
    wPrevState = wNewState; // The previous state is updated to new state (in preparation of the next turn of the loop)

    if(wTrans == 40) { // If 20 transitions have occured a full rotation was completed (there are 20 holes in the wheel)
      wTime = millis() - wTime; // Process the full rotation time by substracting the first transition time to the current time
      wTrans = 0; // Reinitialize the number of transitions (in preparation of the next turn of the loop)
      wSpeed = WCIRCONF / (float)wTime; // Process the speed by dividing the circonference of the wheel by its full rotation time
    }
  }
}

float Capteur::getSpeed()
{
  return wSpeed;
}
