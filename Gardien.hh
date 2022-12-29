#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"
#include "JoueurDeChamp.hh"

class Gardien : public Joueur{
public:
  Gardien(std::string nom, int placement, int passe, int arret, int sortie):Joueur(nom, placement, passe), _arret(arret), _sortie(sortie){};
  virtual std::string poste() const {return "Gardien";}; 
  int getArret() const {return _arret;};
  int getSortie() const {return _sortie;};
  
private:
  int _arret;
  int _sortie;
};
