#ifndef __GARDIEN_H__
#define __GARDIEN_H__
#include "Joueur.hh"

class Gardien : public Joueur{
public:
  Gardien(std::string nom, int placement, int passe, int arret, int sortie):Joueur(nom, placement, passe), _arret(arret), _sortie(sortie){};
  std::string poste() const {return "Gardien";};
  int getVitesse() const {return 0;};
  int getArret() const {return _arret;};
  int getSortie() const {return _sortie;};
  
private:
  int _arret;
  int _sortie;
};

#endif
