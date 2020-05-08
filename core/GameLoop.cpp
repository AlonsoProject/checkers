#include "GameLoop.hpp"

void GameLoop::run(sf::RenderWindow& window)
{
	while (true)
	{
		window.clear();
		window.display();
	}
}