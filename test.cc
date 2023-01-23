#include "Ballon.hh"
#include "Milieu.hh"
#include "Gardien.hh"
#include "Jeu.hh"
#include <fstream>
#include <iostream>

int main()
{
    Jeu cat;

    //Afficher tous les attaquants
    std::cout << "Attaquants :" << std::endl;
    for (auto& a : cat.getListeAttaquant()) {
        std::cout << a->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Afficher tous les milieux
    std::cout << "Milieux :" << std::endl;
    for (auto& m : cat.getListeMilieu()) {
        std::cout << m->getNom() << std::endl; 
    }

    std::cout << std::endl;

    //Afficher tous les defenseurs
    std::cout << "Defenseurs :" << std::endl;
    for (auto& d : cat.getListeDefenseur()) {
        std::cout << d->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Afficher tous les gardiens
    std::cout << "Gardiens :" << std::endl;
    for (auto& g : cat.getListeGardien()) {
        std::cout << g->getNom() << std::endl;
    }

    std::cout << std::endl;


    //Melanger les listes
    cat.melangerListe();
    int choix;

    std::cout << "----------------Listes mélangées--------------------" << std::endl;

    std::cout << std::endl;

    //Choisir un attaquant au hasard et on enleve le joueur choisi de la liste pour l'équipe 1
    Attaquant* attaquant1 = cat.choixAttaquant();
    std::cout << "Attaquant1 choisi au hasard :" << std::endl;
    std::cout << attaquant1->getNom() << std::endl;
    cat.supprimerJoueur(attaquant1->getNom());
    

    Attaquant* attaquant2 = cat.choixAttaquant();
    std::cout << "Attaquant2 choisi au hasard :" << std::endl;
    std::cout << attaquant2->getNom() << std::endl;
    cat.supprimerJoueur(attaquant2->getNom());
    

    Attaquant* attaquant3 = cat.choixAttaquant();
    std::cout << "Attaquant3 choisi au hasard :" << std::endl;
    std::cout << attaquant3->getNom() << std::endl;
    cat.supprimerJoueur(attaquant3->getNom());

    std::cout << "Choisissez votre attaquant" << std::endl;
    scanf ( "%d" ,&choix);
    if (choix == 1){
        cat.ajoutAttaquant(attaquant1, 1);
        cat.ajouterJoueur(attaquant2);
        cat.ajouterJoueur(attaquant3);
    }
    else if (choix == 2){
        cat.ajoutAttaquant(attaquant2, 1);
        cat.ajouterJoueur(attaquant1);
        cat.ajouterJoueur(attaquant3);
    }
    else if (choix == 3){
        cat.ajoutAttaquant(attaquant3, 1);
        cat.ajouterJoueur(attaquant1);
        cat.ajouterJoueur(attaquant2);
    }
    else{
        std::cout << "Choix invalide" << std::endl;
    }

    std::cout << std::endl;

    std::cout << "Attaquants :" << std::endl;
    for (auto& a : cat.getListeAttaquant()) {
        std::cout << a->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Réinitialiser toutes les listes
    cat.initList();

    //Choisir un attaquant au hasard et on enleve le joueur choisi de la liste pour l'équipe 2
    attaquant1 = cat.choixAttaquant();
    std::cout << "Attaquant1 choisi au hasard :" << std::endl;
    std::cout << attaquant1->getNom() << std::endl;
    cat.supprimerJoueur(attaquant1->getNom());
    

    attaquant2 = cat.choixAttaquant();
    std::cout << "Attaquant2 choisi au hasard :" << std::endl;
    std::cout << attaquant2->getNom() << std::endl;
    cat.supprimerJoueur(attaquant2->getNom());
    

    attaquant3 = cat.choixAttaquant();
    std::cout << "Attaquant3 choisi au hasard :" << std::endl;
    std::cout << attaquant3->getNom() << std::endl;
    cat.supprimerJoueur(attaquant3->getNom());

    std::cout << "Choisissez votre attaquant" << std::endl;
    scanf ( "%d" ,&choix);
    if (choix == 1){
        cat.ajoutAttaquant(attaquant1, 2);
        cat.ajouterJoueur(attaquant2);
        cat.ajouterJoueur(attaquant3);
    }
    else if (choix == 2){
        cat.ajoutAttaquant(attaquant2, 2);
        cat.ajouterJoueur(attaquant1);
        cat.ajouterJoueur(attaquant3);
    }
    else if (choix == 3){
        cat.ajoutAttaquant(attaquant3, 2);
        cat.ajouterJoueur(attaquant1);
        cat.ajouterJoueur(attaquant2);
    }
    else{
        std::cout << "Choix invalide" << std::endl;
    }

    //Choisir un milieu au hasard et on enleve le joueur choisi de la liste pour l'équipe 1
    Milieu* milieu = cat.choixMilieu();
    cat.ajoutMilieu(milieu, 1);
    std::cout << "Milieu choisi au hasard :" << std::endl;
    std::cout << milieu->getNom() << std::endl;
    cat.supprimerJoueur(milieu->getNom());

    //Choisir un milieu au hasard et on enleve le joueur choisi de la liste pour l'équipe 2

    milieu = cat.choixMilieu();
    cat.ajoutMilieu(milieu, 2);
    std::cout << "Milieu choisi au hasard :" << std::endl;
    std::cout << milieu->getNom() << std::endl;
    cat.supprimerJoueur(milieu->getNom());

    std::cout << std::endl;

    //Choisir un defenseur au hasard et on enleve le joueur choisi de la liste pour l'équipe 1
    Defenseur* defenseur = cat.choixDefenseur();
    cat.ajoutDefenseur(defenseur, 1);
    std::cout << "Defenseur choisi au hasard :" << std::endl;
    std::cout << defenseur->getNom() << std::endl;
    cat.supprimerJoueur(defenseur->getNom());

    //Choisir un defenseur au hasard et on enleve le joueur choisi de la liste pour l'équipe 2
    defenseur = cat.choixDefenseur();
    cat.ajoutDefenseur(defenseur, 2);
    std::cout << "Defenseur choisi au hasard :" << std::endl;
    std::cout << defenseur->getNom() << std::endl;
    cat.supprimerJoueur(defenseur->getNom());


    std::cout << std::endl;

    //Choisir un gardien au hasard et on enleve le joueur choisi de la liste pour l'équipe 1
    Gardien* gardien = cat.choixGardien();
    cat.setGardien(gardien, 1);
    std::cout << "Gardien choisi au hasard :" << std::endl;
    std::cout << gardien->getNom() << std::endl;
    cat.supprimerJoueur(gardien->getNom());

    //Choisir un gardien au hasard et on enleve le joueur choisi de la liste pour l'équipe 2
    gardien = cat.choixGardien();
    cat.setGardien(gardien, 2);
    std::cout << "Gardien choisi au hasard :" << std::endl;
    std::cout << gardien->getNom() << std::endl;
    cat.supprimerJoueur(gardien->getNom());

    std::cout << std::endl;

    //Afficher tous les attaquants
    std::cout << "Attaquants :" << std::endl;
    for (auto& a : cat.getListeAttaquant()) {
        std::cout << a->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Afficher tous les milieux
    std::cout << "Milieux :" << std::endl;
    for (auto& m : cat.getListeMilieu()) {
        std::cout << m->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Afficher tous les defenseurs
    std::cout << "Defenseurs :" << std::endl;
    for (auto& d : cat.getListeDefenseur()) {
        std::cout << d->getNom() << std::endl;
    }

    std::cout << std::endl;

    //Afficher tous les gardiens
    std::cout << "Gardiens :" << std::endl;
    for (auto& g : cat.getListeGardien()) {
        std::cout << g->getNom() << std::endl;
    }

    std::cout << std::endl;

    //afficher les joueurs de l'equipe 1
    std::cout << "Equipe 1 :" << std::endl;
    for (auto& e : cat.getAttaquant(1)) {
        std::cout << e->getNom() << std::endl;
    }
    for (auto& e : cat.getMilieu(1)) {
        std::cout << e->getNom() << std::endl;
    }
    for (auto& e : cat.getDefenseur(1)) {
        std::cout << e->getNom() << std::endl;
    }
    std::cout<<cat.getGardien(1)->getNom()<<std::endl;

    std::cout << std::endl;

    //afficher les joueurs de l'equipe 2
    std::cout << "Equipe 2 :" << std::endl; 
    for (auto& e : cat.getAttaquant(2)) {
        std::cout << e->getNom() << std::endl;
    }
    for (auto& e : cat.getMilieu(2)) {
        std::cout << e->getNom() << std::endl;
    }
    for (auto& e : cat.getDefenseur(2)) {
        std::cout << e->getNom() << std::endl;
    }
    std::cout << cat.getGardien(2)->getNom() << std::endl;
    std::cout << std::endl;

    Ballon b(0, cat.getGardien(1));

    //aficher le possesseur du ballon
    std::cout << "Possesseur du ballon :" << std::endl;
    std::cout << b.getJoueur()->getNom() << std::endl;

    //faire la passe
    std::cout << "Passe au defenseur :" << std::endl;
    b.getJoueur()->passer(*cat.getDefenseur(1)[0], b);

    //aficher le possesseur du ballon
    std::cout << "Possesseur du ballon :" << std::endl;
    std::cout << b.getJoueur()->getNom() << std::endl;

    //faire la passe
    std::cout << "Passe au milieu :" << std::endl;
    b.getJoueur()->passer(*cat.getMilieu(1)[0], b);

    //aficher le possesseur du ballon
    std::cout << "Possesseur du ballon :" << std::endl;
    std::cout << b.getJoueur()->getNom() << std::endl;

    //dribbler le milieu adverse
    int go = 0;
    std::cout << "Dribble du milieu adverse :" << std::endl;
    if(dynamic_cast<Attaquant*>(b.getJoueur())->dribbler(*cat.getMilieu(2)[0])) {
        std::cout << "Dribble reussi" << std::endl;
        go = 1;
    }
    else {
        std::cout << "Dribble echoue" << std::endl;
    }

    //faire la passe
    if (go) {
        std::cout << "Passe a l'attaquant :" << std::endl;
        b.getJoueur()->passer(*cat.getAttaquant(1)[0], b);
        //aficher le possesseur du ballon
        std::cout << "Possesseur du ballon :" << std::endl;
        std::cout << b.getJoueur()->getNom() << std::endl;
        std::cout << std::endl;
        go = 0;
        std::cout << "Dribble du defenseur adverse :" << std::endl;
        if (dynamic_cast<Attaquant*>(b.getJoueur())->dribbler(*cat.getDefenseur(2)[0])) {
            std::cout << "Dribble reussi" << std::endl;
            go = 1;
        }
        else {
            std::cout << "Dribble echoue" << std::endl;
        }

        if(go){
            std::cout << "Tirer ou dribbler :" << std::endl;
            scanf("%d", &choix);
            if (choix == 1) {
                std::cout << "Tirer :" << std::endl;
                if (dynamic_cast<Attaquant*>(b.getJoueur())->tirer(*cat.getGardien(2))) {
                    std::cout << "Tir reussi" << std::endl;
                }
                else {
                    std::cout << "Tir echoue" << std::endl;
                    go = 0;
                }
            }
            else {
                std::cout << "Dribble :" << std::endl;
                if (dynamic_cast<Attaquant*>(b.getJoueur())->dribbler(*cat.getGardien(2))) {
                    std::cout << "Dribble reussi" << std::endl;
                }
                else {
                    std::cout << "Dribble echoue" << std::endl;
                    go = 0;
                }
            }
        }
    }

    if(go){
        std::cout << "Gagne !!" << std::endl;
    }
    else {
        std::cout << "Perdu !!" << std::endl;
    }

    cat.deleteJoueurs();

    return 0;
}