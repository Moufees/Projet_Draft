#ifndef __DEFENSEUR_H__
#define __DEFENSEUR_H__
#include "JoueurDeChamp.hh"

class Defenseur : virtual public JoueurDeChamp{
public:
  Defenseur(std::string nom, int placement, int passe, int vitesse, int physique, int defense):JoueurDeChamp(nom, placement, passe, vitesse, physique), _defense(defense){} 
  std::string poste() const {return "Defenseur";};
  int getDefense() const {return _defense;};

private :
    int _defense;
};

#endif
