#pragma once

#include <SFML/Graphics.hpp>

#include "ComponentManager.hpp"
#include "../events/EventController.hpp"

/**
 * Entity of the game loop
 */
class GameLoop
{
private:
    EventController eventController;
public:
    /**
     * Run game loop
     */
    void run();
};