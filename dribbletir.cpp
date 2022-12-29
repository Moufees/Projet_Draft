#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "joueur.hh"
#include "joueurdechamp.hh"
#include "Gardien.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"

uint32_t fairedribble(Joueur adversaire){
    int valeur = rand()%10;
    int attaque = self.vitesse + self.dribble + self.physique;
    int defense;
    if (adversaire.poste() == "Attaquant"){
        return 1;
    }
    elif(adversaire.poste() == "Milieu" || adversaire.poste() == "Defenseur"){
        defense  = adversaire.vitesse + adversaire.defense + adversaire.physique;
        if(attaque>defense){
            if (valeur > 0){
                return 1;
            }
            else {
                return 0;
            }
        }
        elif(attaque == defense){
            if (valeur >= 5){
                return 1;
            }
            else {
                return 0;
            }
        }
        else{
              if (valeur == 9){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
    else{
        defense = adversaire.sortie
        attaque = adversaire.dribble
        if(attaque>defense){
            if (valeur > 0){
                return 1;
            }
            else {
                return 0;
            }
        }
        elif(attaque == defense){
            if (valeur >= 5){
                return 1;
            }
            else {
                return 0;
            }
        }
        else{
              if (valeur == 9){
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}

uint32_t fairetir(Joueur adversaire){
    
}