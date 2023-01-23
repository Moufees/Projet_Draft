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
    Jeu(){initList();};
    void deleteJoueurs();
    void initList();
    void melangerListe();

    // Liste des joueurs
    std::vector <Attaquant*> getListeAttaquant() const {return listeAttaquant;};
    std::vector <Milieu*> getListeMilieu() const {return listeMilieu;};
    std::vector <Defenseur*> getListeDefenseur() const {return listeDefenseur;};
    std::vector <Gardien*> getListeGardien() const {return listeGardien;};
    void supprimerJoueur(std::string nom);

    // Ajoute à la liste selon le poste du joueur
    void ajouterJoueur(Joueur* j);

    // Liste des joueurs de chaque équipe
    std::vector <Attaquant*> getAttaquant(int numEquipe) const {if (numEquipe == 1) return attaquantEquipe1;
                                                                else return attaquantEquipe2;};

    std::vector <Milieu*> getMilieu(int numEquipe) const {  if (numEquipe == 1) return milieuEquipe1;
                                                            else return milieuEquipe2;};

    std::vector <Defenseur*> getDefenseur(int numEquipe) const {if (numEquipe == 1) return defenseurEquipe1;
                                                                else return defenseurEquipe2;};

    Gardien* getGardien(int numEquipe) const {  if (numEquipe == 1) return gardienEquipe1;
                                                else return gardienEquipe2;};

    
    //
    void setGardien(Gardien* g, int numEquipe) {if (numEquipe == 1) gardienEquipe1 = g;
                                                else gardienEquipe2 = g;};
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
    
    void ajoutAttaquant(Attaquant* j, int numEquipe);
    void ajoutMilieu(Milieu* j, int numEquipe);
    void ajoutDefenseur(Defenseur* j, int numEquipe);

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