#ifndef __JOUEUR_H__
#define __JOUEUR_H__
#include <SFML/Graphics.hpp>
#include "Ballon.hh"
#include <iostream>
#include <string>
#include <vector>

class Ballon;

class Joueur{
public:
	Joueur(std::string nom, int placement, int passe, std::string path) :_nom(nom), _placement(placement), _passe(passe), _posX(0), _posY(0), _path(path) {};
  virtual ~Joueur(){};

  std::string getNom() const {return _nom;};
  int getPlacement() const {return _placement;};
  std::string getPath() const { return _path; };
  void setPlacement(int placement) {_placement = placement;};
  int getPasse() const {return _passe;};
  int getPosX() const { return _posX; };
  int getPosY() const { return _posY; };
  void setPosX(int x) { _posX = x; };
  void setPosY(int y) { _posY = y; };
  void passer(Joueur& coequipier, Ballon& ballon);
  virtual std::string poste() const = 0;
  virtual int getVitesse() const = 0;
  static Joueur* creerJoueur(std::vector<std::string> param);

private:
  std::string  _nom;
  int _placement;
  int _passe;
  int _posX;
  int _posY;
  std::string _path;
};

#endif
