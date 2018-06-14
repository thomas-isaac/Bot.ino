#include "moteur.h"

Moteur::Moteur()
{
}

Moteur::~Moteur()
{
}

void Moteur::init()
{
  Motor.begin(i2c_add);  
}

void Moteur::upSpeed(const int &moteurA, const int &moteurB)
{
  Motor.speed(MOTOR1, moteurA);
  Motor.speed(MOTOR2, -moteurB);
}
