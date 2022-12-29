#ifndef __JOUEUR_DE_CHAMP_H__
#define __JOUEUR_DE_CHAMP_H__
#include "Joueur.hh"

class JoueurDeChamp : public Joueur{
public:
  JoueurDeChamp(std::string nom, int placement, int passe, int vitesse, int physique):Joueur(nom, placement, passe), _vitesse(vitesse), _physique(physique){} 
  int getVitesse() const {return _vitesse;};
  int getPhysique() const {return _physique;};
  
private:
  int _vitesse;
  int _physique;
};

#endif
