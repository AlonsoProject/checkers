#include "CloseEvent.hpp"

CloseEvent::CloseEvent()
{
	eventType = sf::Event::Closed;
}

void CloseEvent::handle()
{
	ComponentManager::get()->getWindow()->close();
}