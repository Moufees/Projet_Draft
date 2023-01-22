#include "Ballon.hh"
#include "Gardien.hh"
#include "Milieu.hh"
#include "Attaquant.hh"
#include <random>
#include <fstream>
#include <iostream>

std::default_random_engine re;
std::uniform_int_distribution<int> distrib{0, 9};

int Attaquant::dribbler(Joueur& adversaire){

    int dribble = this->getDribble() + this->getVitesse() + this->getPhysique();
    int aleatoire;
    int choix;
    std::ifstream a("aleatoire.txt");
    a>>aleatoire;
    for(int i=0; i<=aleatoire; i++){
      choix=distrib(re);
    }
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
    return 1;
}

int Attaquant::tirer(Gardien& gardien){
    int arret = gardien.getArret();
    int tir = this->getTir();
    int diff = tir - arret;
    if(diff > 0){
        if (distrib(re) > 0){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if(diff == 0){
        if (distrib(re) >= 5){
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
          if (distrib(re)== 9){
            return 1;
        }
        else {
            return 0;
        }
    }
}