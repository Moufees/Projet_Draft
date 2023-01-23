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
    std::vector <Attaquant*> getAttaquantEquipe1() const {return attaquantEquipe1;};
    std::vector <Attaquant*> getAttaquantEquipe2() const {return attaquantEquipe2;};
    std::vector <Milieu*> getMilieuEquipe1() const {return milieuEquipe1;};
    std::vector <Milieu*> getMilieuEquipe2() const {return milieuEquipe2;};
    std::vector <Defenseur*> getDefenseurEquipe1() const {return defenseurEquipe1;};
    std::vector <Defenseur*> getDefenseurEquipe2() const {return defenseurEquipe2;};
    Gardien* getGardienEquipe1() const {return gardienEquipe1;};
    Gardien* getGardienEquipe2() const {return gardienEquipe2;};
    void setGardienEquipe1(Gardien* g) {gardienEquipe1=g;};
    void setGardienEquipe2(Gardien* g) {gardienEquipe2=g;};
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
    void ajoutAttaquantEquipe1(Attaquant* j);
    void ajoutAttaquantEquipe2(Attaquant* j);
    void ajoutMilieuEquipe1(Milieu* j);
    void ajoutMilieuEquipe2(Milieu* j);
    void ajoutDefenseurEquipe1(Defenseur* j);
    void ajoutDefenseurEquipe2(Defenseur* j);
    void supprimerJoueur(std::string nom);
    void melangerListe();

    private:
    std::vector <Attaquant*> listeAttaquant;
    std::vector <Milieu*> listeMilieu;
    std::vector <Defenseur*> listeDefenseur;
    std::vector <Gardien*> listeGardien;
    std::vector <Attaquant*> attaquantEquipe1;
    std::vector <Attaquant*> attaquantEquipe2;
    std::vector <Milieu*> milieuEquipe1;
    std::vector <Milieu*> milieuEquipe2;
    std::vector <Defenseur*> defenseurEquipe1;
    std::vector <Defenseur*> defenseurEquipe2;
    Gardien* gardienEquipe1;
    Gardien* gardienEquipe2;
    /*std::vector <Joueur*> Equipe1;
    std::vector <Joueur*> Equipe2;*/
    int scoreequipe1;
    int scoreequipe2;
};

#endif