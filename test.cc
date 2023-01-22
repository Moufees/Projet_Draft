#include "Ballon.hh"
#include "Milieu.hh"
#include "Gardien.hh"
#include "Jeu.hh"
#include <fstream>
#include <iostream>

int main()
{
    int aleatoire;
    std::ifstream a("aleatoire.txt");
    a>>aleatoire;
    aleatoire=aleatoire+1;
    std::ofstream b("aleatoire.txt");
    b<<aleatoire<< std::endl;
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
    std::cout << m2.dribbler(static_cast<Defenseur&>(m1)) << std::endl;

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

    //delete all the players
    for (auto& a : cat.getListeAttaquant()) {
        delete a;
    }
    for (auto& m : cat.getListeMilieu()) {
        delete m;
    }
    for (auto& d : cat.getListeDefenseur()) {
        delete d;
    }
    for (auto& g : cat.getListeGardien()) {
        delete g;
    }

    return 0;
}