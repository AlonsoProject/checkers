#include "EventController.hpp"

void EventController::handle(sf::Event& event)
{
	EventHandler* eventHandler = eventStorage.findByEventType(event.type);
	if (eventHandler) eventHandler->handle(event);
}
