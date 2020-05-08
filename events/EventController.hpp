#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "EventStorage.hpp"

/**
 * Task of the class is defining a handler for an event
 */
class EventController
{
private:
    EventStorage eventStorage;
public:
    void handle(sf::Event& event);
};