#ifndef JEU_H
#define JEU_H

#include <iostream>
#include <string>
#include <list>
#include "utility.h"
#include "Joueur.hh"
#include "JoueurDeChamp.hh"
#include "Gardien.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"

class Jeu
{
    public:
    Jeu(std::ifstream& f);

    private:
    std::list <Attaquant*> listeattaquant;
    std::list <Milieu*> listemilieu;
    std::list <Defenseur*> listedefenseur;
    std::list <Gardien*> listegardien;
};


Jeu:: Jeu(std::ifstream& f){
     std::string ligne;
     std::vector <std::string> temporaire;
     while (std::getline(f, ligne)){
        temporaire=split(ligne, ',');
        if (temporaire[0] ==  "Attaquant"){
            listeattaquant.push_back(Joueur::creerJoueur(temporaire));
        }
        if (temporaire[0] ==  "Milieu"){
            listemilieu.push_back(Joueur::creerJoueur(temporaire));
        }
        if (temporaire[0] ==  "Defenseur"){
            listedefenseur.push_back(Joueur::creerJoueur(temporaire));
        }
        if (temporaire[0] ==  "Gardien"){
            listegardien.push_back(Joueur::creerJoueur(temporaire));
        }
    }
}
#endif