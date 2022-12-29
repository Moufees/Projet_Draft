#include "Defenseur.hh"
#include "Gardien.hh"
#include "Milieu.hh"
#include "Attaquant.hh"

int Attaquant::dribbler(Joueur& adversaire){

    int dribble = this->getDribble() + this->getVitesse() + this->getPhysique();

    if (dynamic_cast<Defenseur*>(&adversaire) != nullptr) {
      Defenseur* d = dynamic_cast<Defenseur*>(&adversaire);
      int defense = d->getDefense() + d->getVitesse() + d->getPhysique();
      int diff = dribble - defense;
      if(diff > 0){
        if (rand()%10 > 0){
          return 1;
        }
        else {
          return 0;
        }
      }
      else if(diff == 0){
        if (rand()%10 >= 5){
          return 1;
        }
        else {
          return 0;
        }
      }
      else{
        if (rand()%10 == 9){
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
        if (rand()%10 > 0){
          return 1;
        }
        else {
          return 0;
        }
      }
      else if(diff == 0){
        if (rand()%10 >= 5){
          return 1;
        }
        else {
          return 0;
        }
      }
      else{
        if (rand()%10 == 9){
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
        if (rand()%10 > 0){
            return 1;
        }
        else {
            return 0;
        }
    }
    else if(diff == 0){
        if (rand()%10 >= 5){
            return 1;
        }
        else {
            return 0;
        }
    }
    else{
          if (rand()%10 == 9){
            return 1;
        }
        else {
            return 0;
        }
    }
}