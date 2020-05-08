#pragma once

#include <SFML/Graphics.hpp>

#include "GameLoop.hpp"

/**
 * Entity of the application
 */
class App
{
private:
	/**
	 * Current window
	 */
	sf::RenderWindow window;
	/**
	 * Entity of the game loop
	 */
	GameLoop gameLoop;
public:
	App();
	/**
	 * Run the application
	 */
	void run();
};