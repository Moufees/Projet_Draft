#pragma once
#include <iostream>
#include <string>
#include "joueur.hh"
#include "joueurdechamp.hh"
#include "Gardien.hh"
#include "Dribbler.hh"
#include "Tirer.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"

class Defendre : public Joueurdechamp{
public:
  Defendre(std::string nom, unint32_t placement, uint32_t passe, uint32_t vitesse, uint32_t physique, uint32_t defendre):Joueurdechamp(nom, placement, passe, vitesse, physique), _statdefense(defense){} 
  virtual std::string poste() const = 0; 
  uint32_t getdefense() const {return _statdefense;}

private :
    uint32_t _statdefense;
};