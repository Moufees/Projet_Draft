#include "Jeu.hh"
#include "Joueur.hh"
#include "Attaquant.hh"

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

//Retourne un pointeur vers un attaquant choisi aléatoirement dans la liste
Attaquant* Jeu::choixAttaquant() const{
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, listeAttaquant.size()-1);
    return listeAttaquant[dis(gen)];
}

//Retourne un pointeur vers un milieu choisi aléatoirement dans la liste et l'enlève de la liste
Milieu* Jeu::choixMilieu() const{
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, listeMilieu.size()-1);
    return listeMilieu[dis(gen)];
}

//Retourne un pointeur vers un defenseur choisi aléatoirement dans la liste
Defenseur* Jeu::choixDefenseur() const{
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, listeDefenseur.size()-1);
    return listeDefenseur[dis(gen)];
}

//Retourne un pointeur vers un gardien choisi aléatoirement dans la liste
Gardien* Jeu::choixGardien() const{
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, listeGardien.size()-1);
    return listeGardien[dis(gen)];
}

//Supprime un joueur de la liste en fonction de son nom
void Jeu::supprimerJoueur(std::string nom){
    for (auto it = listeAttaquant.begin(); it != listeAttaquant.end(); it++){
        if ((*it)->getNom() == nom){
            listeAttaquant.erase(it);
            return;
        }
    }
    for (auto it = listeMilieu.begin(); it != listeMilieu.end(); it++){
        if ((*it)->getNom() == nom){
            listeMilieu.erase(it);
            return;
        }
    }
    for (auto it = listeDefenseur.begin(); it != listeDefenseur.end(); it++){
        if ((*it)->getNom() == nom){
            listeDefenseur.erase(it);
            return;
        }
    }
    for (auto it = listeGardien.begin(); it != listeGardien.end(); it++){
        if ((*it)->getNom() == nom){
            listeGardien.erase(it);
            return;
        }
    }
}

void Jeu::ajoutAttaquant(Attaquant* j, int equipe){
    if (equipe == 1){
        attaquantEquipe1.push_back(j);
    }
    else{
        attaquantEquipe2.push_back(j);
        j->setPlacement(j->getPlacement()*-1);
    }
}

void Jeu::ajoutMilieu(Milieu* j, int equipe){
    if (equipe == 1){
        milieuEquipe1.push_back(j);
    }
    else{
        milieuEquipe2.push_back(j);
        j->setPlacement(j->getPlacement()*-1);
    }
}

void Jeu::ajoutDefenseur(Defenseur* j, int equipe){
    if (equipe == 1){
        defenseurEquipe1.push_back(j);
    }
    else{
        defenseurEquipe2.push_back(j);
        j->setPlacement(j->getPlacement()*-1);
    }
}

void Jeu::gererscore(int valeur){
    if (valeur == 2){
        marquerEquipe1();
    }
    else if (valeur == -2){
        marquerEquipe2();
    }
}