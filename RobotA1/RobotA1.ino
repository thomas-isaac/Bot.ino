#include <Grove_I2C_Motor_Driver.h>
#include <StackArray.h>
#include <VirtualWire.h>
#include <Wire.h>

#include "robot.h"
#include "controleur.h"
#include "protocol.h"

vecteur positionActuelle = {POINT_A, POINT_B};

Robot *robot = new Robot();
Controleur *controleur = new Controleur(robot, positionActuelle);
Protocol *protocol = new Protocol();
Capteur *capteur = new Capteur(CAPTEUR_SPEED);

void setup()
{
  Serial.begin(9600);
  protocol->init();
  capteur->init();
  robot->init();
  controleur->trouveChemin(POINT_I);
}


void loop()
{
  //controleur->go();
  robot->go();
  capteur->wheelSpeed();
  vecteur positionActuelle = controleur->getPos();
  protocol->sendFrame(capteur->getSpeed(), positionActuelle.a, positionActuelle.b);

}

