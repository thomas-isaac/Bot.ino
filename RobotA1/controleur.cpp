#include "controleur.h"

Controleur::Controleur(Robot *bot, vecteur positionActuelle) : robot(bot), _positionActuelle(positionActuelle), etat(0)
{
}

Controleur::~Controleur()
{
}

void Controleur::trouveChemin(const nomPoints &destination)
{
  int cost[NB_POINTS][NB_POINTS], distance[NB_POINTS], pred[NB_POINTS];
  int visited[NB_POINTS], count, mindistance, nextnode, i, j;

  //pred[] stores the predecessor of each node
  //count gives the number of nodes seen so far
  //create the cost matrix
  for (i = 0; i < NB_POINTS; i++)
    for (j = 0; j < NB_POINTS; j++)
      if (this->chemins[i][j] == 0)
        cost[i][j] = INFINITE;
      else
        cost[i][j] = this->chemins[i][j];

  //Serial.println(this->_positionActuelle.b);
  //initialise pred[],distance[] and visited[]
  for (i = 0; i < NB_POINTS; i++)
  {
    distance[i] = cost[this->_positionActuelle.b][i];
    pred[i] = this->_positionActuelle.b;
    visited[i] = 0;
  }

  distance[this->_positionActuelle.b] = 0;
  visited[this->_positionActuelle.b] = 1;
  count = 1;

  while (count < NB_POINTS - 1)
  {
    mindistance = INFINITE;

    //nextnode gives the node at minimum distance
    for (i = 0; i < NB_POINTS; i++)
      if (distance[i] < mindistance && !visited[i])
      {
        mindistance = distance[i];
        nextnode = i;
      }

    //check if a better path exists through nextnode
    visited[nextnode] = 1;
    for (i = 0; i < NB_POINTS; i++)
      if (!visited[i])
        if (mindistance + cost[nextnode][i] < distance[i])
        {
          distance[i] = mindistance + cost[nextnode][i];
          pred[i] = nextnode;
        }
    count++;
  }

  

  //int k = 0;
  //this->itineraire[k++] = destination;

  // Enregistre l'itinéraire
  j = destination;
  do
  {
    j = pred[j];
    //Serial.println(j);
    //this->itineraire[k++] = j;
    _itineraire.push((nomPoints)j);
  } while (j != this->_positionActuelle.b);

  nextPoint = this->_itineraire.peek();
}

void Controleur::showPath()
{
  //itineraire.show();
}

vecteur Controleur::getPos()
{
   return this->_positionActuelle; 
}

void Controleur::go()
{
  etat_capteurs etatCapteur = robot->getInfoCapteurs();
  
  int capteurs = CD + CG + CC;

  Serial.print("capteurs : ");
  Serial.println(capteurs);

// Si intersection
  if (capteurs > 1)
  {
    //if (this->itineraire[this->etat++] == -1) return;
    this->_positionActuelle.a = this->_positionActuelle.b;
    //this->_positionActuelle.b = this->itineraire[etat];
    //Serial.print("next point : ");
    //Serial.println(nextPoint);
    this->_positionActuelle.b = this->nextPoint;
    
    if (!_itineraire.isEmpty())
      this->nextPoint = this->_itineraire.peek();
    else
      robot->stopNow();

    int nvX = this->points[nextPoint][0];
    int nvY = this->points[nextPoint][1];

    int acX = this->points[this->_positionActuelle.b][0];
    int acY = this->points[this->_positionActuelle.b][1];

    int prX = this->points[this->_positionActuelle.a][0];
    int prY = this->points[this->_positionActuelle.a][1];
/*
    vecteur_2_points actual = { this->points[this->_positionActuelle.b][0] - this->points[this->_positionActuelle.a][0], this->points[this->_positionActuelle.b][1] - this->points[this->_positionActuelle.a][1] };
    vecteur_2_points next = {  this->points[this->itineraire[etat]][0] - this->points[this->_positionActuelle.b][0], this->points[this->itineraire[etat]][1] - this->points[this->_positionActuelle.b][1] };
*/


    if (prX == acX && acX > nvX)
    {
      robot->turnRight();
    }
    else if (prX == acX && acX < nvX)
    {
      robot->turnLeft();
    }
    else if (prY == acY && acY > nvY)
    {
      robot->turnRight();
    }
    else if (prY == acY && acY < nvY)
    {
      robot->turnLeft();
    }
  }
  else if (CC)
  {
    robot->go();
  }
  else if (CG)
  {
    robot->turnLeft();
  }
  else if (CD)
  {
    robot->turnRight();
  }
}

