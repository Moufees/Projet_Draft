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
    Gardien g("Yassine Bounou", 1,1,1);
    Milieu m1("Sofyan Amrabat", 5,1,1,1,1,1,1);
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
    /*std::cout << a1.poste() << std::endl;
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

    //Choisir un attaquant au hasard et on enleve le joueur choisi de la liste
    Attaquant* attaquant = cat.choixAttaquant();
    cat.ajoutEquipe1(attaquant);
    std::cout << "Attaquant choisi au hasard :" << std::endl;
    std::cout << attaquant->getNom() << std::endl;
    cat.supprimerJoueur(attaquant->getNom());


    std::cout << std::endl;

    //Choisir un milieu au hasard et on enleve le joueur choisi de la liste
    Milieu* milieu = cat.choixMilieu();
    cat.ajoutEquipe1(milieu);
    std::cout << "Milieu choisi au hasard :" << std::endl;
    std::cout << milieu->getNom() << std::endl;
    cat.supprimerJoueur(milieu->getNom());

    std::cout << std::endl;

    //Choisir un defenseur au hasard et on enleve le joueur choisi de la liste
    Defenseur* defenseur = cat.choixDefenseur();
    cat.ajoutEquipe2(defenseur);
    std::cout << "Defenseur choisi au hasard :" << std::endl;
    std::cout << defenseur->getNom() << std::endl;
    cat.supprimerJoueur(defenseur->getNom());

    std::cout << std::endl;

    //Choisir un gardien au hasard et on enleve le joueur choisi de la liste
    Gardien* gardien = cat.choixGardien();
    cat.ajoutEquipe2(gardien);
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
    for (auto& e : cat.getEquipe1()) {
        std::cout << e->getNom() << std::endl;
    }

    std::cout << std::endl;

    //afficher les joueurs de l'equipe 2
    std::cout << "Equipe 2 :" << std::endl; 
    for (auto& e : cat.getEquipe2()) {
        std::cout << e->getNom() << std::endl;
    }

    std::cout << std::endl;
    cat.deleteJoueurs();

    return 0;
}