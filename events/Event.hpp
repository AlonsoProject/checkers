#pragma once

#include <SFML/Graphics.hpp>

/**
 * Base abstract class for event handlers
 */
class Event
{
protected:
    /**
     * Event type
     */
    sf::Event::EventType eventType;
public:
    virtual ~Event() {}

    sf::Event::EventType getEventType();

    /**
     * Handle an event
     */
    virtual void handle() = 0;
};