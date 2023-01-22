#ifndef __JEU_HH__
#define __JEU_HH__

#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <vector>
#include <chrono>
#include <fstream>
#include <iterator>
#include <random>
#include "utility.h"
#include "Ballon.hh"
#include "Gardien.hh"
#include "Milieu.hh"

class Jeu
{
    public:
    Jeu(std::ifstream& f){initList(f);};
    void deleteJoueurs();
    void initList(std::ifstream& f);
    std::vector <Attaquant*> getListeAttaquant() const {return listeAttaquant;};
    std::vector <Milieu*> getListeMilieu() const {return listeMilieu;};
    std::vector <Defenseur*> getListeDefenseur() const {return listeDefenseur;};
    std::vector <Gardien*> getListeGardien() const {return listeGardien;};
    std::vector <Joueur*> getEquipe1() const {return Equipe1;};
    std::vector <Joueur*> getEquipe2() const {return Equipe2;};
    int getScoreEquipe1() const {return scoreequipe1;};
    int getScoreEquipe2() const {return scoreequipe2;};
    void setScoreEquipe1(int s) {scoreequipe1=s;};
    void setScoreEquipe2(int s) {scoreequipe2=s;};
    void marquerEquipe1() {scoreequipe1++;};
    void marquerEquipe2() {scoreequipe2++;};
    void gererscore(int valeur);
    Attaquant* choixAttaquant() const;
    Milieu* choixMilieu() const;
    Defenseur* choixDefenseur() const;
    Gardien* choixGardien() const;
    void ajoutEquipe1(Joueur* j);
    void ajoutEquipe2(Joueur* j);
    void supprimerJoueur(std::string nom);
    void melangerListe();

    private:
    std::vector <Attaquant*> listeAttaquant;
    std::vector <Milieu*> listeMilieu;
    std::vector <Defenseur*> listeDefenseur;
    std::vector <Gardien*> listeGardien;
    std::vector <Joueur*> Equipe1;
    std::vector <Joueur*> Equipe2;
    int scoreequipe1;
    int scoreequipe2;
};

#endif