#pragma once
#include <iostream>
#include <string>
#include "Joueur.hh"
#include "JoueurDeChamp.hh"
#include "Gardien.hh"
#include "Attaquant.hh"
#include "Defenseur.hh"
#include "Milieu.hh"

Attaquant choixattaquant1(uint32_t choix){
    if (choix == 1) {
        Attaquant Atq1= Attaquant("Sofiane Bouffal", 1, 75, 82, 80, 95, 85);
    }
    if (choix == 2){
        Attaquant Atq1= Attaquant("Kylian Mbappe", 1, 80, 99, 80, 91, 90);
    }
    if (choix == 3){
        Attaquant Atq1= Attaquant("Phil Foden", 1, 85, 80, 76, 92, 95);
    }
    return Atq1;
}

Attaquant choixattaquant2(uint32_t choix){
    if (choix == 1) {
        Attaquant Atq2= Attaquant("Youssef En-Nesyri", 2, 70, 75, 88, 80, 80);
    }
    if (choix == 2){
        Attaquant Atq2= Attaquant("Harry Kane", 2, 90, 65, 90, 80, 97);
    }
    if (choix == 3){
        Attaquant Atq2= Attaquant("Cristiano Ronaldo", 2, 90, 75, 97, 88, 95);
    }
    return Atq2;
}

Attaquant choixattaquant3(uint32_t choix){
    if (choix == 1) {
        Attaquant Atq3= Attaquant("Hakim Ziyech", 3, 97, 85, 82, 90, 90);
    }
    if (choix == 2){
        Attaquant Atq3= Attaquant("Ousmane Dembele", 3, 85, 95, 73, 90, 88);
    }
    if (choix == 3){
        Attaquant Atq3= Attaquant("Matheus Antony", 3, 83, 85, 70, 97, 86);
    }
    return Atq3;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
Milieu choixmilieu1(uint32_t choix){
    if (choix == 1) {
        Milieu Mil1= Milieu("Azzedine Ounahi", 4, 85, 85, 75, 88, 75, 85);
    }
    if (choix == 2){
        Milieu Mil1= Milieu("Frenkie De Jong", 4, 88, 85, 78, 80, 78, 82);
    }
    if (choix == 3){
        Milieu Mil1= Milieu("Bernardo Silva", 4, 84, 88, 80, 90, 90, 76);
    }
    return Mil1;
}

Milieu choixmilieu2(uint32_t choix){
    if (choix == 1) {
        Milieu Mil2= Milieu("Sofyan Amrabat", 5, 85, 80, 93, 80, 75, 99);
    }
    if (choix == 2){
        Milieu Mil2= Milieu("Luka Modric", 5, 99, 74, 79, 84, 93, 80);
    }
    if (choix == 3){
        Milieu Mil2= Milieu("Neymar Jr", 5, 93, 85, 65, 99, 93, 65);
    }
    return Mil2;
}

Milieu choixmilieu3(uint32_t choix){
    if (choix == 1) {
        Milieu Mil3= Milieu("Selim Amallah", 6, 80, 70, 80, 72, 74, 84);
    }
    if (choix == 2){
        Milieu Mil3= Milieu("Sergio Busquets", 6, 95, 65, 90, 83, 70, 80);
    }
    if (choix == 3){
        Milieu Mil3= Milieu("Jamal Musiala", 6, 80, 80, 68, 97, 90, 75);
    }
    return Mil3;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Defenseur choixdefenseur1(uint32_t choix){
    if (choix == 1) {
        Defenseur Def1= Defenseur("Noussair Mazraoui", 7, 80, 85, 80, 90);
    }
    if (choix == 2){
        Defenseur Def1= Defenseur("Theo Hernandez", 7, 75, 80, 87, 93);
    }
    if (choix == 3){
        Defenseur Def1= Defenseur("Rafael Guerreiro", 7, 85, 70, 73, 90);
    }
    return Def1;
}

Defenseur choixdefenseur2(uint32_t choix){
    if (choix == 1) {
        Defenseur Def2= Defenseur("Nayef Aguerd", 8, 85, 68, 88, 99);
    }
    if (choix == 2){
        Defenseur Def2= Defenseur("Harry Maguire", 8, 55, 57, 95, 93);
    }
    if (choix == 3){
        Defenseur Def2= Defenseur("Virgil Van Dijk", 8, 88, 65, 99, 88);
    }
    return Def2;
}

Defenseur choixdefenseur3(uint32_t choix){
    if (choix == 1) {
        Defenseur Def3= Defenseur("Achraf Hakimi", 9, 88, 95, 85, 90);
    }
    if (choix == 2){
        Defenseur Def3= Defenseur("Joao Cancelo", 9, 90, 87, 87, 83);
    }
    if (choix == 3){
        Defenseur Def3= Defenseur("Kyle Walker", 9, 70, 92, 90, 80);
    }
    return Def3;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Gardien choixgardien(uint32_t choix){
    if (choix == 1) {
        Gardien grd= Gardien("Yassine Bounou", 10, 99,99, 99);
    }
    if (choix == 2){
        Gardien grd= Gardien("Thibault Courtois", 10, 95, 80, 89);
    }
    if (choix == 3){
        Gardien grd= Gardien("Alisson Becker", 10, 97, 92, 89);
    }
    return grd;
}