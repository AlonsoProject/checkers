#include "MouseButtonPressedEvent.hpp"

MouseButtonPressedEvent::MouseButtonPressedEvent()
{
	eventType = sf::Event::MouseButtonPressed;
}

void MouseButtonPressedEvent::leftButtonPressed(sf::Event& event)
{
	std::string name = GameObjectManager::get()->
										 getPlayerController()->
										 getCurrentPlayer()->
										 getName();

	int time = GameObjectManager::get()->getGameSession()->getElapsedTime();

	std::cout << "Current user: " << name << std::endl;
	std::cout << "Time: " << time << std::endl;
}

void MouseButtonPressedEvent::handle(sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		leftButtonPressed(event);
	}
}
