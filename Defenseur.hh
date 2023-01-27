#ifndef __DEFENSEUR_H__
#define __DEFENSEUR_H__
#include "JoueurDeChamp.hh"

class Defenseur : virtual public JoueurDeChamp{
public:
  Defenseur(std::string nom, int placement, int passe, std::string path, int vitesse, int physique, int defense):JoueurDeChamp(nom, placement, passe, path, vitesse, physique), _defense(defense){}
  ~Defenseur() {};
  std::string poste() const {return "Defenseur";};
  int getDefense() const {return _defense;};
  std::string toCSV() const{
    std::string csv = JoueurDeChamp::toCSV();
    csv += "Defense : " + std::to_string(_defense) + "\n";
    return csv;}

private :
    int _defense;
};

#endif
