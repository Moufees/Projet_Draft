#include "Ballon.hh"
#include "Gardien.hh"
#include "Milieu.hh"
#include "Attaquant.hh"
#include <random>
#include <chrono>
#include <fstream>
#include <iostream>

int Attaquant::dribbler(Joueur& adversaire){

    int dribble = this->getDribble() + this->getVitesse() + this->getPhysique();
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, 9);
    int choix = dis(gen);
    std::cout << "aleatoire : " << choix << std::endl;
    if (dynamic_cast<Defenseur*>(&adversaire) != nullptr) {
      Defenseur* d = dynamic_cast<Defenseur*>(&adversaire);
      int defense = d->getDefense() + d->getVitesse() + d->getPhysique();
      int diff = dribble - defense;
      //std::cout<<choix<< std::endl;
      if(diff > 0){
        if (choix> 0){
          return 1;
        }
        else {
          return 0;
        }
      }
      else if(diff == 0){
        if (choix >= 5){
          return 1;
        }
        else {
          return 0;
        }
      }
      else{
        if (choix == 9){
          return 1;
        }
        else {
          return 0;
        }
      }
    }
    else if (dynamic_cast<Gardien*>(&adversaire) != nullptr) {
      Gardien* g = dynamic_cast<Gardien*>(&adversaire);
      int sortie = g->getSortie();
      int diff = dribble - sortie;
      if(diff > 0){
        if (choix > 0){
          return 2;
        }
        else {
          return 0;
        }
      }
      else if(diff == 0){
        if (choix >= 5){
          return 2;
        }
        else {
          return 0;
        }
      }
      else{
        if (choix == 9){
          return 2;
        }
        else {
          return 0;
        }
      }
    }
    return 1;
}

int Attaquant::tirer(Gardien& gardien){
    int arret = gardien.getArret();
    int tir = this->getTir();
    int diff = tir - arret;
    std::mt19937 gen(std::chrono::system_clock::now().time_since_epoch().count());
    std::uniform_int_distribution<> dis(0, 9);
    int choix = dis(gen);
    if(diff > 0){
        if (choix > 0){
            return 2;
        }
        else {
            return 0;
        }
    }
    else if(diff == 0){
        if (choix >= 5){
            return 2;
        }
        else {
            return 0;
        }
    }
    else{
          if (choix== 9){
            return 2;
        }
        else {
            return 0;
        }
    }
}