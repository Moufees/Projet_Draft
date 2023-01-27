#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>

class Input
{
	struct Button { bool left, right, up, down, escape, tirer, passer, dribbler, next, devant, restart; };

public:
	// Proto du constructeur
	Input();
	// Proto GetBtn
	Button GetButton(void) const;
	// Proto
	void InputHandler(sf::Event event, sf::RenderWindow& window);


private:
	Button button;
};

#endif
