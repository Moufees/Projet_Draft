#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"
#include "JoueurDeChamp.hh"

class Defenseur : public JoueurDeChamp{
public:
  Defenseur(std::string nom, int placement, int passe, int vitesse, int physique, int defense):JoueurDeChamp(nom, placement, passe, vitesse, physique), _defense(defense){} 
  virtual std::string poste() const {return "Defenseur";};
  int getDefense() const {return _defense;};

private :
    int _defense;
};
