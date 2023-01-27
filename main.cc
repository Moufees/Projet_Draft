// Inclusion des fonctionnalit�s
#include "Application.hh"


// Fonction main, point de d�part du programme
int main()
{
	// Lancement de l'application
	Application app;
	app.Run();
	//Jeu jeu;

	//On affiche tous les joueurs
	//jeu.afficherJoueurs();

    
    return 0;
}

TEST_CASE("1: Web")
{
  CoursWeb css("Learn W3.CSS",50.0,0.89, 9777);
  css.setTitre("Learn W3.CSS - Part 1");
  CHECK(css.getTitre() == "Learn W3.CSS - Part 1" );
  CHECK(css.getId() == 0);
  CHECK(css.getPrix() == 50.0);
  CHECK(css.getNote() == 0.89f);
  css.vote(1);
  CHECK(css.getAvis() == 9778);
  css.setPrix(55.5);
  std::stringstream ss;
  ss << css;
  CHECK(ss.str()=="Learn W3.CSS - Part 1,55.500000,0.890011,9778, WEB, -1,-1");
}