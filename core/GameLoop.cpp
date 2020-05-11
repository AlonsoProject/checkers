#include "GameLoop.hpp"

void GameLoop::run()
{
	GameObjectManager::init();

	sf::Event event;

	/**
	 * Widgets
	 */
	Text* username = TextWidgetFactory::factory(
		PlayerControllerFacade::getNameCurrentUserName(),
		UPPER_LEFT_CORNER
	);
	Text* timer = TextWidgetFactory::factory("0", UPPER_RIGHT_CORNER);

	GameObjectManager::get()->getGameSession()->resetTimer();
	while (true)
	{
		if (GameSessionFacade::isExpired())
		{
			GameSessionFacade::userToggle();
			username->getInstance()->setString(PlayerControllerFacade::getNameCurrentUserName());
		}

		while (ServiceObjectManager::get()->getWindow()->pollEvent(event))
		{
			eventController.handle(event);
		}

		timer->getInstance()->setString(
			std::to_string(GameSessionFacade::getCountdown())
		);

		GameObjectManager::get()->getBoard()->draw();
		username->draw();
		timer->draw();

		ServiceObjectManager::get()->getWindow()->display();
		ServiceObjectManager::get()->getWindow()->clear();
	}

	delete username;
	delete timer;
}