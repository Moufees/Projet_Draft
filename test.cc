#include "Ballon.hh"
#include "Milieu.hh"
#include "Gardien.hh"
#include "Jeu.hh"
#include <fstream>
#include <iostream>

int main()
{
    std::ifstream f("basedejoueurs.csv");
    Jeu cat(f);
    /*Gardien g("Yassine Bounou", 1,1,1);
    Milieu m1("Sofyan Amrabat", 5,1,1,1,1,1,1);
    Ballon championsleague(1, &m1);
    Milieu m2("Neymar Jr", 5, 1,1,1,1,1,1);
    Attaquant a1("Sofiane Bouffal", 1, 1,1,1,1,1);
    Attaquant a2("Kylian Mbappe", 1, 1,1,1,1,1);
    Attaquant a3("Hakim Ziyech", 3, 1,1,1,1,1);
    Defenseur d("Virgil Van Dijk", 8, 1,1,1,1);
    a1.dribbler(d);
    a1.dribbler(d);
    a1.dribbler(d);
    a1.dribbler(d);
    a1.dribbler(d);
    a1.dribbler(d);
    a1.dribbler(d);
    std::cout << a1.poste() << std::endl;
    std::cout << g.poste() << std::endl;
    std::cout << m1.poste() << std::endl;
    std::cout << m2.poste() << std::endl;
    std::cout << m2.getVitesse() << std::endl;
    std::cout << d.poste() << std::endl;
    std::cout << a1.dribbler(d) << std::endl;
    std::cout << a2.dribbler(d) << std::endl;
    std::cout << a3.dribbler(d) << std::endl;
    std::cout << a1.dribbler(g) << std::endl;
    std::cout << a1.tirer(g) << std::endl;
    std::cout << a2.tirer(g) << std::endl;
    std::cout << a3.tirer(g) << std::endl;
    std::cout << a1.dribbler(static_cast<Defenseur&>(m1)) << std::endl;
    std::cout << m2.dribbler(static_cast<Defenseur&>(m1)) << std::endl;*/

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

    //Choisir un attaquant au hasard et on enleve le joueur choisi de la liste pour l'équipe 1
    Attaquant* attaquant = cat.choixAttaquant();
    cat.ajoutAttaquant(attaquant, 1);
    Ballon b(1, attaquant);
    std::cout << "Attaquant choisi au hasard :" << std::endl;
    std::cout << attaquant->getNom() << std::endl;
    cat.supprimerJoueur(attaquant->getNom());

    attaquant = cat.choixAttaquant();
    cat.ajoutAttaquant(attaquant, 1);
    std::cout << "Attaquant choisi au hasard :" << std::endl;
    std::cout << attaquant->getNom() << std::endl;
    cat.supprimerJoueur(attaquant->getNom());

    attaquant = cat.choixAttaquant();
    cat.ajoutAttaquant(attaquant, 1);
    std::cout << "Attaquant choisi au hasard :" << std::endl;
    std::cout << attaquant->getNom() << std::endl;
    cat.supprimerJoueur(attaquant->getNom());

    //Choisir un attaquant au hasard et on enleve le joueur choisi de la liste pour l'équipe 2
    attaquant = cat.choixAttaquant();
    cat.ajoutAttaquant(attaquant, 2);
    std::cout << "Attaquant choisi au hasard :" << std::endl;
    std::cout << attaquant->getNom() << std::endl;
    cat.supprimerJoueur(attaquant->getNom());



    std::cout << std::endl;

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

    //aficher le possesseur du ballon
    std::cout << "Possesseur du ballon :" << std::endl;
    std::cout << b.getJoueur()->getNom() << std::endl;

    //faire la passe
    std::cout << "Passe :" << std::endl;

    //aficher le possesseur du ballon
    std::cout << "Possesseur du ballon :" << std::endl;
    //std::cout << championsleague.getJoueur()->getNom() << std::endl;
    //std::cout << cat.getAttaquantEquipe1[0]->getNom()<< std::endl;
    std::cout << cat.getAttaquant(2)[0]->dribbler(*cat.getAttaquant(1)[0]) << std::endl;
    std::cout << cat.getAttaquant(1)[0]->tirer(*cat.getGardien(2))   << std::endl;
    cat.deleteJoueurs();

    return 0;
}