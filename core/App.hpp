#pragma once

#include <SFML/Graphics.hpp>

#include "GameLoop.hpp"
#include "ServiceObjectManager.hpp"

/**
 * Entity of the application
 */
class App
{
private:
	/**
	 * Entity of the game loop
	 */
	GameLoop gameLoop;
public:
	~App();
	/**
	 * Run the application
	 */
	void run();
};