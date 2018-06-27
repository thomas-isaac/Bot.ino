#include "robot.h"

Robot::Robot()
{
  capteurDroit = new Capteur(CAPTEUR_DROIT);
  capteurGauche = new Capteur(CAPTEUR_GAUCHE);
  capteurCentral = new Capteur(CAPTEUR_CENTRAL);

  moteurs = new Moteurs();
}

Robot::~Robot()
{
}

void Robot::init()
{
  Serial.println("init");
  capteurDroit->init();
  capteurGauche->init();
  capteurCentral->init();

  moteurs->init();
}

void Robot::go()
{
  if(capteurDroit->isSeeingAnything())
  {
    turnLeft();
  }
  if(capteurGauche->isSeeingAnything())
  {
    turnRight();
  }
  moteurs->upSpeed(80, 80);
}

void Robot::turnRight()
{
  while (capteurCentral->isSeeingAnything())
    moteurs->upSpeed(-50, 100);
}

void Robot::turnLeft()
{
  while (capteurCentral->isSeeingAnything())
    moteurs->upSpeed(100, -50);
}

void Robot::stopNow()
{
  moteurs->upSpeed(0, 0);
}

etat_capteurs Robot::getInfoCapteurs()
{
  // Sauvegarde des états des capteurs à cet instant
  CD = capteurDroit->isSeeingAnything();
  CG = capteurGauche->isSeeingAnything();
  CC = capteurCentral->isSeeingAnything();

  return this->etatCapteur;
}

