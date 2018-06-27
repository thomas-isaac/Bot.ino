#ifndef ROBOT_H
#define ROBOT_H

#include "define.h"
#include "capteur.h"
#include "moteur.h"

// Quelques defines pour simplifier "etatCapteur.capteur[Droit|Gauche|Central]"
#define CD etatCapteur.capteurDroit
#define CG etatCapteur.capteurGauche
#define CC etatCapteur.capteurCentral

typedef struct
{
  bool capteurDroit;
  bool capteurGauche;
  bool capteurCentral;
} etat_capteurs;

class Robot
{
  public:
    Robot();
    ~Robot();

    void init();
    
    void go();
    void turnRight();
    void turnLeft();
    void stopNow();

    etat_capteurs getInfoCapteurs();

  private:
    Capteur *capteurDroit;
    Capteur *capteurGauche;
    Capteur *capteurCentral;

    Moteurs *moteurs;

    etat_capteurs etatCapteur;
};



#endif
