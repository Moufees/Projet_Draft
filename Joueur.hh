#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include "Ballon.hh"
#include <iostream>
#include <string>
#include <vector>

class Ballon;

class Joueur{
public:
  Joueur(std::string nom, int placement, int passe):_nom(nom), _placement(placement), _passe(passe){};
  Joueur(const Joueur& J):_nom(J._nom), _placement(J._placement), _passe(J._passe){};
  virtual ~Joueur(){};

  std::string getNom() const {return _nom;};
  int getPlacement() const {return _placement;};
  void setPlacement(int placement) {_placement = placement;};
  int getPasse() const {return _passe;};
  void passer(Joueur& coequipier, Ballon ballon);
  virtual std::string poste() const = 0;
  virtual int getVitesse() const = 0;
  static Joueur* creerJoueur(std::vector<std::string> param);

private:
  std::string  _nom;
  int _placement;
  int _passe;
};

#endif
