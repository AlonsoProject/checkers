#include "MouseButtonPressedEvent.hpp"

MouseButtonPressedEvent::MouseButtonPressedEvent()
{
	eventType = sf::Event::MouseButtonPressed;
}

void MouseButtonPressedEvent::clickOnChecker(Checker* checker, sf::Event& event)
{
	if (PlayerControllerFacade::getCurrentUserId() != checker->getIdOwner())
	{
		GameObjectManager::get()->getBoard()->selectCellByPosition(
			event.mouseButton.x,
			event.mouseButton.y,
			HOSTILE_COLOR
		);
	}
	else
	{
		GameObjectManager::get()->getBoard()->selectCellByPosition(
			event.mouseButton.x,
			event.mouseButton.y,
			FRIENDLY_COLOR
		);
		GameObjectManager::get()->getBoard()->showMoves(checker);
	}
}

void MouseButtonPressedEvent::clickOnCell(Tile* cell, sf::Event& event)
{
}

void MouseButtonPressedEvent::leftButtonPressed(sf::Event& event)
{
	BoardFacade::clearSelectedCells();
	Checker* checker = BoardFacade::findChecker(event.mouseButton.x, event.mouseButton.y);
	if (checker)
	{
		clickOnChecker(checker, event);
	}
	else
	{
		Tile* cell = BoardFacade::findCell(event.mouseButton.x, event.mouseButton.y);
		clickOnCell(cell, event);
	}
}

void MouseButtonPressedEvent::handle(sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		leftButtonPressed(event);
	}
}
