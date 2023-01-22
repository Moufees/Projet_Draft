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
    void melangerListe();

    private:
    std::vector <Attaquant*> listeAttaquant;
    std::vector <Milieu*> listeMilieu;
    std::vector <Defenseur*> listeDefenseur;
    std::vector <Gardien*> listeGardien;
};

#endif