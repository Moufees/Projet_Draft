#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"

class JoueurDeChamp : public Joueur{
public:
  JoueurDeChamp(std::string nom, int placement, int passe, int vitesse, int physique):Joueur(nom, placement, passe), _vitesse(vitesse), _physique(physique){} 
  virtual std::string poste() const = 0; 
  int getVitesse() const {return _vitesse;}
  int getPhysique() const {return _physique;}
  
private:
  int _vitesse;
  int _physique;
};
