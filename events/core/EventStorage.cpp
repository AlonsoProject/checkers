#include "EventStorage.hpp"

EventStorage::EventStorage()
{
	EventHandlersFactory::factory(eventHandlers);
}

EventStorage::~EventStorage()
{
	for (auto eventHandler : eventHandlers)
	{
		if (eventHandler) delete eventHandler;
	}
}

EventHandler* EventStorage::findByEventType(sf::Event::EventType eventType)
{
	for (auto eventHandler : eventHandlers)
	{
		if (eventHandler->getEventType() == eventType)
		{
			return eventHandler;
		}
	}
	return nullptr;
}
