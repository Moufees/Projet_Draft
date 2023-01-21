#ifndef __MILIEU_H__
#define __MILIEU_H__
#include "Attaquant.hh"
#include "Defenseur.hh"

class Milieu : public Defenseur, public Attaquant{
public:
  Milieu(std::string nom, int placement, int passe, int vitesse, int physique, int dribble, int tir, int defense): Defenseur(nom, placement, passe, vitesse, physique, defense), Attaquant(nom, placement, passe, vitesse, physique, dribble, tir){};
  std::string poste() const {return "Milieu";};
  int getVitesse() const {return Attaquant::getVitesse();};
};

#endif
