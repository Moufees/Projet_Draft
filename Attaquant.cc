#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"
#include "JoueurDeChamp.hh"

class Attaquant : public JoueurDeChamp{
public:
  Attaquant(std::string nom, int placement, int passe, int vitesse, int physique, int dribble, int tir):JoueurDeChamp(nom, placement, passe, vitesse, physique), _dribble(dribble), _tir(tir){} 
  virtual std::string poste() const {return "Attaquant";};
  int getTir() const {return _tir;};
  int tirer(Joueur adversaire);
  int getdribble() const {return _dribble;};
  int dribbler(Joueur adversaire);

private :
    int _dribble;
    int _tir;
};
