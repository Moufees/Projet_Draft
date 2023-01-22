#include "Jeu.hh"

void Jeu::initList(std::ifstream& f){
    
    listeAttaquant.clear();
    listeMilieu.clear();
    listeDefenseur.clear();
    listeGardien.clear();
    std::string ligne;
    std::vector <std::string> temporaire;
    while (std::getline(f, ligne)){
        temporaire=split(ligne, ',');
        if (temporaire[0] ==  "Attaquant"){
            listeAttaquant.push_back((dynamic_cast<Attaquant*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Milieu"){
            listeMilieu.push_back((dynamic_cast<Milieu*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Defenseur"){
            listeDefenseur.push_back((dynamic_cast<Defenseur*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Gardien"){
            listeGardien.push_back((dynamic_cast<Gardien*>(Joueur::creerJoueur(temporaire))));
        }
    }
   
}

void Jeu::deleteJoueurs(){
    for (auto it = listeAttaquant.begin(); it != listeAttaquant.end(); it++){
        delete *it;
    }
    for (auto it = listeMilieu.begin(); it != listeMilieu.end(); it++){
        delete *it;
    }
    for (auto it = listeDefenseur.begin(); it != listeDefenseur.end(); it++){
        delete *it;
    }
    for (auto it = listeGardien.begin(); it != listeGardien.end(); it++){
        delete *it;
    }
}

void Jeu::melangerListe()
{
    std::mt19937 generator(std::random_device{}());
    std::shuffle(listeAttaquant.begin(), listeAttaquant.end(), generator);
    std::shuffle(listeDefenseur.begin(), listeDefenseur.end(), generator);
    std::shuffle(listeMilieu.begin(), listeMilieu.end(), generator);
    std::shuffle(listeGardien.begin(), listeGardien.end(), generator);
}