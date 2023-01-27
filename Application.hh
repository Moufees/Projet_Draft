#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include <ctime>
#include <iostream>
#include "input.h"
#include "Jeu.hh"

// Constantes du programme
const int WIN_WIDTH = 1600;
const int WIN_HEIGHT = 968;
const float COEF_ECRAN = 0.75;
const int TAILLE_POLICE_JOUEUR = 12;

class Application
{
public:
	Application();
	~Application() {};
	void Run();
	void LoadFont();
	void SetText(sf::Text& txt, sf::Font& font, std::string str, int size);
	void CheckBtn(sf::Event event);
	void CheckAction(sf::Event event);
	void actionTirer(std::string poste);
	void actionPasserCote(std::string poste, int direction);
	void actionPasserDevant(std::string poste);
	void actionDribbler(std::string poste);
	void LoadSprite(sf::Sprite& sprite, sf::Texture& texture, std::string path);
	void initSprite();
	void initCircleShape();
	void initPositionBlank();
	void drawGame();
	void drawEnd();
	void updatePositionCircle();
	
private:
	sf::RenderWindow window;
	Input input;
	sf::Font fontCom, fontScore, fontJoueur;
	sf::Text commentaire, scoreEquipe1, scoreEquipe2;
	sf::Text nomJoueur[20];
	// Image
	sf::Sprite terrain, terrain_flou, blank[20], joueur, ball, choixCarte, instruction, terrainWin, confetti, menu, txtDraft, txtAvMatch;
	sf::Texture textureTerrain, textureFlou, textureJoueur[20], textureBall, textureChoix, textureInstruction, textureWin, textureConfetti, textureMenu, textureTxtDraft, textureTxtAvMatch;
	// Tableau de 20 circleShape
	sf::CircleShape circle[20];
	int next = 0;
	// Diff�rentes valeurs d'ecran
	int ecran = 0;
	int choix = 0;
	bool passeON = false;
	int equipe = 1;
	Jeu jeu;
	Ballon ballon;
};

#endif
