#include "input.h"

// Constructeur
Input::Input()
{
	button.left = button.right = button.up = button.down = button.escape = button.tirer = button.passer = button.dribbler = button.next = button.devant = button.restart = false;
}

// Fonction qui acc�de � button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const 
{ 
	return button;
}

// Fonction de gestion des inputs
void Input::InputHandler(sf::Event event, sf::RenderWindow& window)
{
    // Fermer la fen�tre si on clique sur la croix
    if (event.type == sf::Event::Closed)
    {
        // On ferme la fen�tre
        window.close();
    }

    // Gestion des inputs (clavier / souris) 
    // D�tection btn appuy�
    if (event.type == sf::Event::KeyPressed)
    {
		switch (event.key.code) // Code de la touche utilis�e
		{
		case sf::Keyboard::Escape:
			button.escape = true;
			break;
		case sf::Keyboard::Left:
			button.left = true;
			break;
		case sf::Keyboard::Right:
			button.right = true;
			break;
		case sf::Keyboard::Down:
			button.down = true;
			break;
		case sf::Keyboard::Up:
			button.up = true;
			break;
		case sf::Keyboard::T:
			button.tirer = true;
			break;
		case sf::Keyboard::P:
			button.passer = true;
			break;
		case sf::Keyboard::D:
			button.dribbler = true;
			break;
		case sf::Keyboard::N:
			button.next = true;
			break;
		case sf::Keyboard::Space:
			button.devant = true;
			break;
		case sf::Keyboard::R:
			button.restart = true;
			break;
		default:
			break;
		}
    }
	// Test des key released
	if (event.type == sf::Event::KeyReleased)
	{
		// Touche rel�ch�e
		switch (event.key.code)
		{
		case sf::Keyboard::Escape:
			button.escape = false;
			break;
		case sf::Keyboard::Left:
			button.left = false;
			break;
		case sf::Keyboard::Right:
			button.right = false;
			break;
		case sf::Keyboard::Down:
			button.down = false;
			break;
		case sf::Keyboard::Up:
			button.up = false;
			break;
		case sf::Keyboard::T:
			button.tirer = false;
			break;
		case sf::Keyboard::D:
			button.dribbler = false;
			break;
		case sf::Keyboard::P:
			button.passer = false;
			break;
		case sf::Keyboard::N:
			button.next = false;
			break;
		case sf::Keyboard::Space:
			button.devant = false;
			break;
		case sf::Keyboard::R:
			button.restart = false;
			break;
		default:
			break;
		}
	}
}


