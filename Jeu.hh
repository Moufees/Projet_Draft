#ifndef __JEU_HH__
#define __JEU_HH__

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "utility.h"
#include "Ballon.hh"
#include "Gardien.hh"
#include "Milieu.hh"

class Jeu
{
    public:
    Jeu(std::ifstream& f);
    void deleteJoueurs();
    std::list <Attaquant*> getListeAttaquant() const {return listeattaquant;};
    std::list <Milieu*> getListeMilieu() const {return listemilieu;};
    std::list <Defenseur*> getListeDefenseur() const {return listedefenseur;};
    std::list <Gardien*> getListeGardien() const {return listegardien;};


    private:
    std::list <Attaquant*> listeattaquant;
    std::list <Milieu*> listemilieu;
    std::list <Defenseur*> listedefenseur;
    std::list <Gardien*> listegardien;
};

#endif