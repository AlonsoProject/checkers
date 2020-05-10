#include "GameLoop.hpp"

void GameLoop::run()
{
	GameObjectManager::init();

	sf::Event event;

	GameObjectManager::get()->getGameSession()->resetTimer();
	while (true)
	{
		if (GameObjectManager::get()->getGameSession()->isExpired())
		{
			GameObjectManager::get()->getPlayerController()->togglePlayer();
			GameObjectManager::get()->getGameSession()->resetTimer();
		}

		while (ServiceObjectManager::get()->getWindow()->pollEvent(event))
		{
			eventController.handle(event);
		}

		GameObjectManager::get()->getBoard()->draw();
		ServiceObjectManager::get()->getWindow()->display();
		ServiceObjectManager::get()->getWindow()->clear();
	}
}