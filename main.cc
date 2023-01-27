// Inclusion des fonctionnalit�s
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include "Application.hh"



// Fonction main, point de d�part du programme
/*int main()
{
	// Lancement de l'application
	Application app;
	app.Run();
	//Jeu jeu;

	//On affiche tous les joueurs
	//jeu.afficherJoueurs();

    
    return 0;
}*/

/*TEST_CASE("1: Attaquant")
{
  Attaquant att("CR7", 99, 99, "none", 99, 99, 99, 99);
  Defenseur def("Pique", 89, 89, "none", 89, 89, 89);
  att.setPlacement(98);
  CHECK(att.getPlacement() == 98);
  CHECK(att.poste() == "Attaquant");
  CHECK(att.getVitesse() == 99);
  CHECK(att.getTir() == 99);
  CHECK(att.getPhysique() == 99);
  
  CHECK(def.getDefense() == 89);
  std::stringstream ss;
  ss << att;
  CHECK(ss.str() == "CR7 (Attaquant)\nPasse : 99\nVitesse : 99\nVitesse : 99\nPhysique : 99\nDribble : 99\nTir : 99\n");
  if(att.dribbler(def)) std::cout << "CR7 dribble Pique" << std::endl;
  else std::cout << "CR7 ne dribble pas Pique" << std::endl;
}*/