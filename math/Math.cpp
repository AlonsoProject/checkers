#include "Math.hpp"

void Math::getTileAnglesPositions(Tile* tile, std::vector<sf::Vector2f>& anglesPositions)
{
	sf::Vector2f currentPosition;
	tile->getPosition(currentPosition);

	anglesPositions.push_back(currentPosition);

	currentPosition.x += Config::getCellWidth();
	anglesPositions.push_back(currentPosition);

	currentPosition.y += Config::getCellHeight();
	anglesPositions.push_back(currentPosition);

	currentPosition.x -= Config::getCellWidth();
	anglesPositions.push_back(currentPosition);
}

void Math::stretchSquare(std::vector<sf::Vector2f>& anglesPositions, float shift)
{
	if (anglesPositions.size() != 4) return;

	anglesPositions[0].x -= shift;
	anglesPositions[0].y -= shift;

	anglesPositions[1].x += shift;
	anglesPositions[1].y -= shift;

	anglesPositions[2].x += shift;
	anglesPositions[2].y += shift;

	anglesPositions[3].x -= shift;
	anglesPositions[3].y += shift;
}
