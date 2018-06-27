#ifndef ALGO_H
#define ALGO_H

#include "robot.h"
#include "parcours.h"
#include <Arduino.h>
#include <StackArray.h>

#define INFINITE 9999

typedef struct 
{
  int x, y;
} vecteur_2_points;

class Controleur
{
  public:
    Controleur(Robot *bot, vecteur positionActuelle);
    ~Controleur();

    void trouveChemin(const nomPoints &destination);

    void go();

    void showPath();
    
    vecteur getPos();

  private:
    Robot *robot;
    vecteur _positionActuelle;
    int itineraire[10];
    int etat;

    StackArray<nomPoints> _itineraire;
    nomPoints nextPoint;

    char points[16][2] = {
      { 0, 0 },
      { 1, 0 },
      { 2, 0 },
      { 3, 0 },
      { 4, 0 },
      { 4, 2 },
      { 4, 4 },
      { 1, 4 },
      { 1, 3 },
      { 3, 3 },
      { 3, 2 },
      { 0, 2 },
      { 0, 4 },
      { 0, 1 },
      { 1, 1 },
      { 2, 1 }
    };

    char chemins[16][16] = {
      { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
      { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
      { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
      { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
      { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
      { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
      { 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 }
    };

};



#endif
