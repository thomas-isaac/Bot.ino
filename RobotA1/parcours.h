#ifndef PARCOURS_H
#define PARCOURS_H

#include <Arduino.h>

typedef enum
{
    POINT_A = 0,
    POINT_B,
    POINT_C,
    POINT_D,
    POINT_E,
    POINT_F,
    POINT_G,
    POINT_H,
    POINT_I,
    POINT_J,
    POINT_K,
    POINT_L,
    POINT_M,
    POINT_N,
    POINT_O,
    POINT_P,
    NB_POINTS
} nomPoints;


typedef struct
{
  int x, y;
} point;

typedef struct
{
  nomPoints a, b;
} vecteur;



#endif
