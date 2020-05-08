#pragma once

#include <SFML/Graphics.hpp>

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
};