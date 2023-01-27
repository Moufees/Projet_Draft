#ifndef __BALLON_H__
#define __BALLON_H__
#include "Joueur.hh"

class Ballon{
public:
  Ballon(int position, Joueur* joueur):_position(position),_joueur(joueur){};
  int getPosition() const {return _position;};
  void setPosition(int position){_position = position;};
  Joueur* getJoueur() const {return _joueur;};
  void setJoueur(Joueur& joueur){
      _joueur = &joueur;
      //std::cout << "Le ballon est passe a " << _joueur->getNom() << std::endl;
  };

private:
    int _position;
    Joueur* _joueur;
};

#endif
