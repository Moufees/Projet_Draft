#include "Ballon.hh"
#include "Joueur.hh"

void Joueur::passer(Joueur& coequipier, Ballon ballon){
    ballon.setJoueur(coequipier);
}

Joueur* Joueur::creerJoueur(std::vector<std::string> param)
{
   if (param[0] == "Attaquant"){
        return new Attaquant(param[1], std::stod(param[2]), std::stod(param[3]), std::stoi(param[4]), std::stod(param[5]), std::stod(param[6]));
    }
    if (param[0] == "Milieu"){
        return new Milieu(param[1], std::stod(param[2]), std::stod(param[3]), std::stoi(param[4]), std::stod(param[5]), std::stod(param[6]), std::stod(param[7]));
    }
    if (param[0] == "Defenseur"){
        return new Defenseur(param[1],std::stod(param[1]), std::stod(param[2]), std::stoi(param[3]), std::stoi(param[5]));
    }
    if (param[0] == "Gardien"){
        return new Gardien(param[1],std::stod(param[1]), std::stod(param[2]), std::stoi(param[3]));
    }
    return NULL;
}