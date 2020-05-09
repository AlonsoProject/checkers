#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "EventHandler.hpp"
#include "../../factories/EventHandlersFactory.hpp"

class EventStorage
{
private:
	std::vector<EventHandler*> eventHandlers;
public:
	EventStorage();
	~EventStorage();

	EventHandler* findByEventType(sf::Event::EventType eventType);
};