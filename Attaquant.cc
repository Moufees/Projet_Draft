#include "Ballon.hh"
#include "Gardien.hh"
#include "Milieu.hh"
#include "Attaquant.hh"
#include <random>
#include <chrono>
#include <fstream>
#include <iostream>

int Attaquant::dribbler(Joueur& adversaire){

    //std::cout << getNom() << " dribble " << adversaire.getNom() << std::endl;
	//std::cout << getNom() << " est place " << getPlacement() << std::endl;
	//std::cout << adversaire.getNom() << " est place " << adversaire.getPlacement() << std::endl;

    int dribble = this->getDribble() + this->getVitesse() + this->getPhysique();
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, 9);
    int choix = dis(gen);
    if (dynamic_cast<Defenseur*>(&adversaire) != nullptr) {
      Defenseur* d = dynamic_cast<Defenseur*>(&adversaire);
      int defense = d->getDefense() + d->getVitesse() + d->getPhysique();
      int diff = dribble - defense;
      if(diff > 0){
        if (choix> 2){
          //std::cout << "Reussi" << std::endl;
          return 1;
        }
        else {
			//std::cout << "Rate" << std::endl;
            return 0;
        }
      }
      else if(diff == 0){
        if (choix >= 5){
			//std::cout << "Reussi" << std::endl;
            return 1;
        }
        else {
			//std::cout << "Rate" << std::endl;
            return 0;
        }
      }
      else{
        if (choix >= 8){
			//std::cout << "Reussi" << std::endl;
            return 1;
        }
        else {
			//std::cout << "Rate" << std::endl;
            return 0;
        }
      }
	  delete d;
    }
    return 1;
}

int Attaquant::tirer(Gardien& gardien, Ballon& ballon){

    //std::cout << getNom() << " tire sur " << gardien.getNom() << std::endl;

    int arret = gardien.getArret();
    int tir = this->getTir();
    int diff = tir - arret;
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, 9);
    int choix = dis(gen);
    ballon.setJoueur(gardien);
    if(diff > 0){
        if (choix > 2){
			//std::cout << "Reussi" << std::endl;
            return 2;
        }
        else {
			//std::cout << "Rate" << std::endl;
            return 0;
        }
    }
    else if(diff == 0){
        if (choix >= 5){
			//std::cout << "Reussi" << std::endl;
            return 2;
        }
        else {
			//std::cout << "Rate" << std::endl;
            return 0;
        }
    }
    else{
          if (choix >= 8){
			  //std::cout << "Reussi" << std::endl;
              return 2;
        }
        else {
			  //std::cout << "Rate" << std::endl;
              return 0;
        }
    }
}

std::string Attaquant::toCSV() const{
    std::string csv = JoueurDeChamp::toCSV();
    csv += "Dribble : " + std::to_string(_dribble) + "\n";
    csv += "Tir : " + std::to_string(_tir) + "\n";  
    return csv;
}