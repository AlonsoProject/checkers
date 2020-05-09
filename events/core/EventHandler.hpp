#pragma once

#include <SFML/Graphics.hpp>

/**
 * Base abstract class for event handlers
 */
class EventHandler
{
protected:
    /**
     * Event type
     */
    sf::Event::EventType eventType;
public:
    virtual ~EventHandler() {}

    sf::Event::EventType getEventType();

    /**
     * Handle an event
     */
    virtual void handle(sf::Event& event) = 0;
};