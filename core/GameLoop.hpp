#pragma once

#include <SFML/Graphics.hpp>

/**
 * Entity of the game loop
 */
class GameLoop
{
public:
    /**
     * Run game loop
     */
    void run(sf::RenderWindow& window);
};