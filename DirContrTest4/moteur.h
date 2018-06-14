#ifndef MOTEUR_H
#define MOTEUR_H

#include <Grove_I2C_Motor_Driver.h>
#define i2c_add 0x0f

class Moteur
{
  public:
    Moteur();
    ~Moteur();
    
    void init();
    void upSpeed(const int &moteurA, const int &moteurB);
  
};


#endif
