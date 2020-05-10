#pragma once

#include <SFML/Graphics.hpp>

#include "Config.hpp"
#include "../widgets/Text.hpp"
#include "ServiceObjectManager.hpp"
#include "GameObjectManager.hpp"
#include "../events/core/EventController.hpp"

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