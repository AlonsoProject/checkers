#include "GameLoop.hpp"

void GameLoop::run()
{
	sf::Event event;

	while (true)
	{
		while (ComponentManager::get()->getWindow()->pollEvent(event))
		{
			eventController.handle(event);
		}

		ComponentManager::get()->getBoard()->draw();
		ComponentManager::get()->getWindow()->display();
		ComponentManager::get()->getWindow()->clear();
	}
}