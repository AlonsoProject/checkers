#include "MouseButtonPressedEvent.hpp"

MouseButtonPressedEvent::MouseButtonPressedEvent()
{
	eventType = sf::Event::MouseButtonPressed;
}

void MouseButtonPressedEvent::leftButtonPressed(sf::Event& event)
{
	BoardFacade::clearSelectedCells();

	Checker* checker = BoardFacade::findChecker(event.mouseButton.x, event.mouseButton.y);
	Player* currentPlayer = PlayerControllerFacade::getCurrentPlayer();
	
	if (!checker) return;
	if (currentPlayer->getId() != checker->getIdOwner())
	{
		GameObjectManager::get()->getBoard()->selectCellByChecker(checker, RED_HIGHLIGHTED);
		return;
	}
}

void MouseButtonPressedEvent::handle(sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		leftButtonPressed(event);
	}
}
