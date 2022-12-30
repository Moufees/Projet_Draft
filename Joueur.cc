#include "Ballon.hh"
#include "Joueur.hh"

void Joueur::passer(Joueur& coequipier, Ballon ballon){
    ballon.setJoueur(coequipier);
}