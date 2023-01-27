#ifndef __MILIEU_H__
#define __MILIEU_H__
#include "Attaquant.hh"
#include "Defenseur.hh"

class Milieu : public Defenseur, public Attaquant{
public:
  Milieu(std::string nom, int placement, int passe, std::string path, int vitesse, int physique, int dribble, int tir, int defense): JoueurDeChamp(nom, placement, passe, path, vitesse, physique), Defenseur(nom, placement, passe, path, vitesse, physique, defense), Attaquant(nom, placement, passe, path, vitesse, physique, dribble, tir){};
  ~Milieu() {};
  std::string poste() const {return "Milieu";};
  int getVitesse() const {return Attaquant::getVitesse();};
  std::string toCSV() const{
    std::string csv = Attaquant::toCSV();
    csv += "Defense : " + std::to_string(Defenseur::getDefense()) + "\n";
    return csv;
  }
};

#endif
