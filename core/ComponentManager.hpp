#pragma once

#include <SFML/Graphics.hpp>

#include "../core/Config.hpp"
#include "../objects/Board.hpp"

/**
 * Component manager
 * This class is singelton
 * This class storage components for the application
 */
class ComponentManager
{
private:
    /**
     * Instance
     */
    inline static ComponentManager* instance = nullptr;

    /**
     * Window
     */
    sf::RenderWindow* window = nullptr;

    /**
     * Board
     */
    Board* board = nullptr;

    /**
     * Implements the singelton
     */
    ComponentManager() {}
    ~ComponentManager();
public:
    /**
     * Get instance of the component manager
     */
    static ComponentManager* get();
    /**
     * Free instance of the component manager
     */
    static void free();

    sf::RenderWindow* getWindow();

    Board* getBoard();
};