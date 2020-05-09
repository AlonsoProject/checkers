#include "CloseEvent.hpp"

CloseEvent::CloseEvent()
{
	eventType = sf::Event::Closed;
}

void CloseEvent::handle(sf::Event& event)
{
	ComponentManager::get()->getWindow()->close();
}