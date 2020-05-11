#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "../core/Config.hpp"
#include "../graphics/Tile.hpp"

class Math
{
public:
	static void getTileAnglesPositions(Tile* tile, std::vector<sf::Vector2f>& anglesPositions);
	static void stretchSquare(std::vector<sf::Vector2f>& anglesPositions, float shift);
};