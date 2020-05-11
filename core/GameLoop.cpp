#include "GameLoop.hpp"

void GameLoop::run()
{
	GameObjectManager::init();

	sf::Event event;

	std::string currentUserName = GameObjectManager::get()->
												 getPlayerController()->
												 getCurrentPlayer()->
												 getName();

	Text userInGame(currentUserName, Config::defaultFont);
	userInGame.setPosition(sf::Vector2f(
		10,
		10
	));
	userInGame.getInstance()->setFillColor(sf::Color::Blue);

	GameObjectManager::get()->getGameSession()->resetTimer();

	int time = GameObjectManager::get()->getGameSession()->getCountdown();
	Text timer(std::to_string(time), Config::defaultFont);
	timer.setPosition(sf::Vector2f(
		Config::width * 0.93,
		10
	));
	timer.getInstance()->setFillColor(sf::Color::Blue);

	while (true)
	{
		if (GameObjectManager::get()->getGameSession()->isExpired())
		{
			GameObjectManager::get()->getBoard()->clearHighlightedCells();
			GameObjectManager::get()->getPlayerController()->togglePlayer();
			GameObjectManager::get()->getGameSession()->resetTimer();

			currentUserName = GameObjectManager::get()->
											 getPlayerController()->
											 getCurrentPlayer()->
											 getName();

			userInGame.getInstance()->setString(currentUserName);
		}

		while (ServiceObjectManager::get()->getWindow()->pollEvent(event))
		{
			eventController.handle(event);
		}

		time = GameObjectManager::get()->getGameSession()->getCountdown();
		timer.getInstance()->setString(std::to_string(time));

		GameObjectManager::get()->getBoard()->draw();
		userInGame.draw();
		timer.draw();
		ServiceObjectManager::get()->getWindow()->display();
		ServiceObjectManager::get()->getWindow()->clear();
	}
}