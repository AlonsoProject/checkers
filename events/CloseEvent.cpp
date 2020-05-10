#include "CloseEvent.hpp"

CloseEvent::CloseEvent()
{
	eventType = sf::Event::Closed;
}

void CloseEvent::handle(sf::Event& event)
{
	ServiceObjectManager::get()->getWindow()->close();
}