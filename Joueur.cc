#include "Ballon.hh"
#include "Joueur.hh"
#include "Gardien.hh"
#include "Milieu.hh"

void Joueur::passer(Joueur& coequipier, Ballon& ballon){
    //std::cout << getNom() << " passe a " << coequipier.getNom() << std::endl;
    ballon.setJoueur(coequipier);
}

Joueur* Joueur::creerJoueur(std::vector<std::string> param)
{
   if (param[0] == "Attaquant"){
        param[7].pop_back();
        return new Attaquant(param[1], 0, std::stoi(param[2]), param[7], std::stoi(param[3]), std::stoi(param[4]), std::stoi(param[5]), std::stoi(param[6]));
    }
    if (param[0] == "Milieu"){
        param[8].pop_back();
        return new Milieu(param[1], 0, std::stoi(param[2]), param[8], std::stoi(param[3]), std::stoi(param[4]), std::stoi(param[5]), std::stoi(param[6]), std::stoi(param[7]));
    }
    if (param[0] == "Defenseur"){
        param[6].pop_back();
        return new Defenseur(param[1], 0, std::stoi(param[2]), param[6], std::stoi(param[3]), std::stoi(param[4]), std::stoi(param[5]));
    }
    if (param[0] == "Gardien"){
        param[5].pop_back();
        return new Gardien(param[1], std::stoi(param[2]), param[5], std::stoi(param[3]), std::stoi(param[4]));
    }
    return NULL;
}