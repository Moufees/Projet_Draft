#ifndef __BALL_H__
#define __BALL_H__
#include "Joueur.hh"

class Ball{
public:
  Ball(int position, Joueur* joueur):_position(position),_joueur(joueur){} 
  int getposition() const {return _position;};
  void setposition(int position){_position = position;};
  Joueur* getjoueur() const {return _joueur;};
  void setjoueur(Joueur* joueur){_joueur = joueur;};

private :
    int _position;
    Joueur* _joueur;
};

#endif
