#include "Jeu.hh"

Jeu::Jeu(std::ifstream& f){
    
    std::string ligne;
    std::vector <std::string> temporaire;
    while (std::getline(f, ligne)){
        temporaire=split(ligne, ',');
        if (temporaire[0] ==  "Attaquant"){
            listeattaquant.push_back((dynamic_cast<Attaquant*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Milieu"){
            listemilieu.push_back((dynamic_cast<Milieu*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Defenseur"){
            listedefenseur.push_back((dynamic_cast<Defenseur*>(Joueur::creerJoueur(temporaire))));
        }
        else if (temporaire[0] ==  "Gardien"){
            listegardien.push_back((dynamic_cast<Gardien*>(Joueur::creerJoueur(temporaire))));
        }
    }
   
}

void Jeu::deleteJoueurs(){
    for (auto it = listeattaquant.begin(); it != listeattaquant.end(); it++){
        delete *it;
    }
    for (auto it = listemilieu.begin(); it != listemilieu.end(); it++){
        delete *it;
    }
    for (auto it = listedefenseur.begin(); it != listedefenseur.end(); it++){
        delete *it;
    }
    for (auto it = listegardien.begin(); it != listegardien.end(); it++){
        delete *it;
    }
}