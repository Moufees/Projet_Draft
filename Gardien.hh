#ifndef __GARDIEN_HH__
#define __GARDIEN_HH__
#include "Joueur.hh"

class Gardien : public Joueur{
public:
  Gardien(std::string nom, int passe, std::string path, int arret, int sortie):Joueur(nom, 10, passe, path), _arret(arret), _sortie(sortie){};
  ~Gardien() {};
  std::string poste() const {return "Gardien";};
  int getVitesse() const {return 0;};
  int getArret() const {return _arret;};
  int getSortie() const {return _sortie;};
  
private:
  int _arret;
  int _sortie;
};

#endif
