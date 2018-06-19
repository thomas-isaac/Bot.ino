#ifndef MOTEUR_H
#define MOTEUR_H

#include <Grove_I2C_Motor_Driver.h>
#define i2c_add 0x0f // Define the address of the I2C Motor Driver Component

class Moteur
{
  public:
    Moteur();
    ~Moteur();
    
    void init(); // The initialization
    void upSpeed(const int &moteurLmoteurL, const int &moteurR); // The speed update
  
};


#endif
