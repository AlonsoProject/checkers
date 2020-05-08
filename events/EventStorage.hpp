#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "Event.hpp"
#include "CloseEvent.hpp"

class EventStorage
{
private:
	std::vector<Event*> events;
public:
	EventStorage();
	~EventStorage();

	Event* findByEventType(sf::Event::EventType eventType);
};