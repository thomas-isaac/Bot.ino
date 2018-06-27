#include "moteur.h"

Moteurs::Moteurs()
{
}

Moteurs::~Moteurs()
{
}

void Moteurs::init()
{
  Motor.begin(i2c_add);
}

void Moteurs::upSpeed(const int &moteurA, const int &moteurB)
{
  Motor.speed(MOTOR1, moteurA);
  Motor.speed(MOTOR2, -moteurB);
}

