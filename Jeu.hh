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
	void deleteEquipe();
    void melangerListe();
    void afficherJoueurs() const;

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

    Gardien* getGardien(int numEquipe) const {  if (numEquipe == 1) return gardienEquipe1.back();
                                                else return gardienEquipe2.back();};

    
    //
    void setGardien(Gardien* g, int numEquipe) {if (numEquipe == 1) gardienEquipe1.push_back(g);
                                                else gardienEquipe2.push_back(g);};

    void initPlacement();
    Ballon* getBallon() const { return ballon; };
    void setBallon(Ballon* b) { ballon = b; };
    void initScore() { scoreEquipe1 = 0; scoreEquipe2 = 0; etatJeu = true; };
    int getScoreEquipe1() const {return scoreEquipe1;};
    int getScoreEquipe2() const {return scoreEquipe2;};
    void setScoreEquipe1(int s) {scoreEquipe1=s;};
    void setScoreEquipe2(int s) {scoreEquipe2=s;};
	void marquerEquipe(int numEquipe) {
		if (numEquipe == 1) scoreEquipe1++;
		else scoreEquipe2++;
	};
	void majEtatJeu() {
		if (scoreEquipe1 == 5 || scoreEquipe2 == 5) etatJeu = false;
	};
	bool getEtatJeu() const { return etatJeu; };

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
    std::list <Gardien*> gardienEquipe1;
    std::list <Gardien*> gardienEquipe2;
	bool etatJeu = true;
    int scoreEquipe1;
    int scoreEquipe2;
	Ballon* ballon;
};

#endif