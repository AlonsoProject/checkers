#include "EventStorage.hpp"

EventStorage::EventStorage()
{
	events.push_back(new CloseEvent());
}

EventStorage::~EventStorage()
{
	for (auto conreteEvent : events)
	{
		if (conreteEvent) delete conreteEvent;
	}
}

Event* EventStorage::findByEventType(sf::Event::EventType eventType)
{
	for (auto concreteEvent : events)
	{
		if (concreteEvent->getEventType() == eventType)
		{
			return concreteEvent;
		}
	}
	return nullptr;
}
