#pragma once

#include <SFML/Graphics.hpp>

#include "Config.hpp"
#include "../widgets/Text.hpp"
#include "GameObjectManager.hpp"
#include "ServiceObjectManager.hpp"
#include "../facades/GameSessionFacade.hpp"
#include "../factories/TextWidgetFactory.hpp"
#include "../events/core/EventController.hpp"
#include "../facades/PlayerControllerFacade.hpp"

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