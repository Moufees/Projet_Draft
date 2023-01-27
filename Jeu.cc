#include "Jeu.hh"
#include "Joueur.hh"
#include "Attaquant.hh"

void Jeu::initList(){

    std::ifstream f("cartes/basedejoueurs.csv");

    //Suppression des joueurs précédents
    this->deleteJoueurs();
    
    listeAttaquant.clear();
    listeMilieu.clear();
    listeDefenseur.clear();
    listeGardien.clear();
    std::string ligne;
    //std::cout << "Initialisation des joueurs" << std::endl;
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

void Jeu::deleteEquipe() {
    // Suppression des joueurs précédents
	for (auto it = attaquantEquipe1.begin(); it != attaquantEquipe1.end(); it++){
        delete *it;
    }
    for (auto it = attaquantEquipe2.begin(); it != attaquantEquipe2.end(); it++){
        delete *it;
    }
    for (auto it = milieuEquipe1.begin(); it != milieuEquipe1.end(); it++){
        delete *it;
    }
    for (auto it = milieuEquipe2.begin(); it != milieuEquipe2.end(); it++){
        delete *it;
    }
    for (auto it = defenseurEquipe1.begin(); it != defenseurEquipe1.end(); it++){
        delete *it;
    }
    for (auto it = defenseurEquipe2.begin(); it != defenseurEquipe2.end(); it++){
        delete *it;
    }
    // Suppression des gardiens précédents s'il y en a
    if (gardienEquipe1 != nullptr)  gardienEquipe1 = nullptr;
    if (gardienEquipe2 != nullptr)  gardienEquipe2 = nullptr;
	attaquantEquipe1.clear();
	attaquantEquipe2.clear();
	milieuEquipe1.clear();
	milieuEquipe2.clear();
	defenseurEquipe1.clear();
	defenseurEquipe2.clear();
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
	listeAttaquant.clear();
	listeMilieu.clear();
	listeDefenseur.clear();
	listeGardien.clear();
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

//Ajoute un joueur à la liste en fonction de son poste
void Jeu::ajouterJoueur(Joueur* j){
    if (j->poste() == "Attaquant"){
        listeAttaquant.push_back((dynamic_cast<Attaquant*>(j)));
    }
    else if (j->poste() == "Milieu"){
        listeMilieu.push_back((dynamic_cast<Milieu*>(j)));
    }
    else if (j->poste() == "Defenseur"){
        listeDefenseur.push_back((dynamic_cast<Defenseur*>(j)));
    }
    else if (j->poste() == "Gardien"){
        listeGardien.push_back((dynamic_cast<Gardien*>(j)));
    }
}

//Initialiser les placements des joueurs
void Jeu::initPlacement() {
    getGardien(1)->setPlacement(1);
    getGardien(1)->setPosX(170);
	getGardien(1)->setPosY(364);
    getGardien(2)->setPlacement(-1);
    getGardien(2)->setPosX(1390);
	getGardien(2)->setPosY(364);
    int i = 0;
    for (auto& e : getAttaquant(1)) {
        e->setPlacement(30 + i);
		e->setPosY(164 + i * 200);
		if (i % 2) e->setPosX(1120);
		else e->setPosX(1095);
        i++;
    }
    i = 0;
    for (auto& e : getAttaquant(2)) {
        e->setPlacement(-30 - i);
		e->setPosY(164 + i * 200);
		if (i % 2) e->setPosX(440);
		else e->setPosX(465);
        i++;
    }
	i = 0;
	for (auto& e : getMilieu(1)) {
		e->setPlacement(20 + i);
		e->setPosX(720);
		e->setPosY(194 + i * 170);
		i++;
	}
	i = 0;
	for (auto& e : getMilieu(2)) {
		e->setPlacement(-20 - i);
		e->setPosX(840);
		e->setPosY(194 + i * 170);
		i++;
	}
	i = 0;
	for (auto& e : getDefenseur(1)) {
		e->setPlacement(10 + i);
		e->setPosY(164 + i * 200);
		if (i % 2) e->setPosX(350);
		else e->setPosX(375);
		i++;
	}
	i = 0;
	for (auto& e : getDefenseur(2)) {
		e->setPlacement(-10 - i);
		e->setPosY(164 + i * 200);
		if (i % 2) e->setPosX(1220);
		else e->setPosX(1195);
		i++;
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
