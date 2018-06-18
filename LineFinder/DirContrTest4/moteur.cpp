#include "moteur.h"

Moteur::Moteur()
{
}

Moteur::~Moteur()
{
}

void Moteur::init() // Initialize the robot
{
// Motor Driver function to start the I2C component
// Each I2C component uses an address in the form 0xFF
  Motor.begin(i2c_add);
}

// Moteur function to update the speed of the robot
// Takes two values in input for motor 1 and 2
void Moteur::upSpeed(const int &moteurA, const int &moteurB)
{
// Motor Driver functions to modify the speed of each motor
  Motor.speed(MOTOR1, moteurA); // Update MOTOR1 speed
  Motor.speed(MOTOR2, -moteurB); // Update MOTOR2 speed (engines were mounted in reverse so value has to be reversed also)
}
