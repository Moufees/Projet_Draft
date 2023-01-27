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
  // On surcharge la méthode toCSV() de Joueur pour ajouter l'arret et la sortie
  std::string toCSV() const{
    std::string csv = Joueur::toCSV();
    csv += "Arret : " + std::to_string(_arret) + "\n";
    csv += "Sortie : " + std::to_string(_sortie) + "\n";  
    return csv;
  }
  
private:
  int _arret;
  int _sortie;
};

#endif
