#include "EventController.hpp"

void EventController::handle(sf::Event& event)
{
	Event* concreteEvent = eventStorage.findByEventType(event.type);
	if (concreteEvent) concreteEvent->handle();
}
