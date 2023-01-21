#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"
#include "JoueurDeChamp.hh"
#include "Gardien.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"
#include <list>
#include "utility.h"

/*
Attaquant choixattaquant1(uint32_t choix){
    if (choix == 1) {
        return Attaquant("Sofiane Bouffal", 1, 75, 82, 80, 95, 85);
    }
    if (choix == 2){
        return Attaquant("Kylian Mbappe", 1, 80, 99, 80, 91, 90);
    }
    if (choix == 3){
        return Attaquant("Phil Foden", 1, 85, 80, 76, 92, 95);
    }
}

Attaquant choixattaquant2(uint32_t choix){
    if (choix == 1) {
        return Attaquant("Youssef En-Nesyri", 2, 70, 75, 88, 80, 80);
    }
    if (choix == 2){
        return Attaquant("Harry Kane", 2, 90, 65, 90, 80, 97);
    }
    if (choix == 3){
        return Attaquant("Cristiano Ronaldo", 2, 90, 75, 97, 88, 95);
    }
}

Attaquant choixattaquant3(uint32_t choix){
    if (choix == 1) {
        return Attaquant("Hakim Ziyech", 3, 97, 85, 82, 90, 90);
    }
    if (choix == 2){
        return Attaquant("Ousmane Dembele", 3, 85, 95, 73, 90, 88);
    }
    if (choix == 3){
        return Attaquant("Matheus Antony", 3, 83, 85, 70, 97, 86);
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
Milieu choixmilieu1(uint32_t choix){
    if (choix == 1) {
        return Milieu("Azzedine Ounahi", 4, 85, 85, 75, 88, 75, 85);
    }
    if (choix == 2){
        return Milieu("Frenkie De Jong", 4, 88, 85, 78, 80, 78, 82);
    }
    if (choix == 3){
        return Milieu("Bernardo Silva", 4, 84, 88, 80, 90, 90, 76);
    }
}

Milieu choixmilieu2(uint32_t choix){
    if (choix == 1) {
        return Milieu("Sofyan Amrabat", 5, 85, 80, 93, 80, 75, 99);
    }
    if (choix == 2){
        return Milieu("Luka Modric", 5, 99, 74, 79, 84, 93, 80);
    }
    if (choix == 3){
        return Milieu("Neymar Jr", 5, 93, 85, 65, 99, 93, 65);
    }
}

Milieu choixmilieu3(uint32_t choix){
    if (choix == 1) {
        return Milieu("Selim Amallah", 6, 80, 70, 80, 72, 74, 84);
    }
    if (choix == 2){
        return Milieu("Sergio Busquets", 6, 95, 65, 90, 83, 70, 80);
    }
    if (choix == 3){
        return Milieu("Jamal Musiala", 6, 80, 80, 68, 97, 90, 75);
    }
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Defenseur choixdefenseur1(uint32_t choix){
    if (choix == 1) {
        return Defenseur("Noussair Mazraoui", 7, 80, 85, 80, 90);
    }
    if (choix == 2){
        return Defenseur("Theo Hernandez", 7, 75, 80, 87, 93);
    }
    if (choix == 3){
        return Defenseur("Rafael Guerreiro", 7, 85, 70, 73, 90);
    }
}

Defenseur choixdefenseur2(uint32_t choix){
    if (choix == 1) {
        return Defenseur("Nayef Aguerd", 8, 85, 68, 88, 99);
    }
    if (choix == 2){
        return Defenseur("Harry Maguire", 8, 55, 57, 95, 93);
    }
    if (choix == 3){
        return Defenseur("Virgil Van Dijk", 8, 88, 65, 99, 88);
    }
}

Defenseur choixdefenseur3(uint32_t choix){
    if (choix == 1) {
        return Defenseur("Achraf Hakimi", 9, 88, 95, 85, 90);
    }
    if (choix == 2){
        return Defenseur("Joao Cancelo", 9, 90, 87, 87, 83);
    }
    if (choix == 3){
        return Defenseur("Kyle Walker", 9, 70, 92, 90, 80);
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Gardien choixgardien(uint32_t choix){
    if (choix == 1) {
        return Gardien("Yassine Bounou", 10, 99,99, 99);
    }
    if (choix == 2){
        return Gardien("Thibault Courtois", 10, 95, 80, 89);
    }
    if (choix == 3){
        return Gardien("Alisson Becker", 10, 97, 92, 89);
    }
}*/

std::list <std::string> choixjoueur(std::ifstream& f){
    std::string ligne;
    std::list <std::string> listejoueur;
     while (std::getline(f, ligne)){
        listejoueur.push_back(Joueur::creerJoueur(split(ligne, ',')));
    }
    return listejoueur;
}

std::list <std::string> choixmilieu(std::ifstream& f){
    std::string ligne;
    std::list <std::string> listemilieu;
     while (std::getline(f, ligne)){
        listeattaquant.push_back(Joueur::creerJoueur(split(ligne, ';')));
    }
    return listemilieu;
}

std::list <std::string> choixattaquant(std::ifstream& f){
    std::string ligne;
    std::list <std::string> listeattaquant;
     while (std::getline(f, ligne)){
        listeattaquant.push_back(Joueur::creerJoueur(split(ligne, ';')));
    }
    return listeattaquant;
}

std::list <std::string> choixdefenseur(std::ifstream& f){
    std::string ligne;
    std::list <std::string> listeattaquant;
     while (std::getline(f, ligne)){
        listeattaquant.push_back(Joueur::creerJoueur(split(ligne, ';')));
    }
    return listeattaquant;
}

std::list <std::string> choixmilieu(std::ifstream& f){
    std::string ligne;
    std::list <std::string> listeattaquant;
     while (std::getline(f, ligne)){
        listeattaquant.push_back(Joueur::creerJoueur(split(ligne, ';')));
    }
    return listeattaquant;
}