#pragma once

#include <SFML/Graphics.hpp>

#include "../core/Config.hpp"
#include "../objects/Board.hpp"
#include "../players/PlayerController.hpp"
#include "GameSession.hpp"

/**
 * Servie object manager
 * This class is singelton
 * This class storage components for the application
 */
class ServiceObjectManager
{
private:
    /**
     * Instance
     */
    inline static ServiceObjectManager* instance = nullptr;
    /**
     * Window
     */
    sf::RenderWindow* window = nullptr;

    /**
     * Implements the singelton
     */
    ServiceObjectManager() {}
    ~ServiceObjectManager();
public:
    /**
     * Get instance of the component manager
     */
    static ServiceObjectManager* get();
    /**
     * Free instance of the component manager
     */
    static void free();

    sf::RenderWindow* getWindow();
};