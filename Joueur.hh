#pragma once
#include <iostream>
#include <string>
#include "JoueurDeChamp.hh"
#include "Gardien.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"

class Joueur{
public:
  Joueur(std::string nom, int placement, int passe):_nom(nom), _placement(placement), _passe(passe){};
  Joueur(const Joueur& J):_nom(J._nom), _placement(J._placement){};

  std::string getNom() const {return _nom;};
  int getPlacement() const {return _placement;};
  int getPasse() const {return _passe;};
  int passer(Joueur adversaire);
  virtual std::string poste() const = 0;

private:
  std::string  _nom;
  int _placement;
  int _passe;
};
