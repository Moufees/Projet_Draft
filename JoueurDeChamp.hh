#ifndef __JOUEUR_DE_CHAMP_H__
#define __JOUEUR_DE_CHAMP_H__
#include "Joueur.hh"

class JoueurDeChamp : public Joueur{
public:
  JoueurDeChamp(std::string nom, int placement, int passe, std::string path, int vitesse, int physique):Joueur(nom, placement, passe, path), _vitesse(vitesse), _physique(physique){}
  ~JoueurDeChamp() {};
  int getVitesse() const {return _vitesse;};
  int getPhysique() const {return _physique;};
  
private:
  int _vitesse;
  int _physique;
};

#endif
