#include "Checker.hpp"

Checker::Checker(std::string pathToCheckerTile, sf::Vector2f position) :
checkerTile(new Tile(pathToCheckerTile))
{
	checkerTile->setPosition(position);
}

Checker::~Checker()
{
	if (checkerTile) delete checkerTile;
}

Tile* Checker::getCheckerTile()
{
	return checkerTile;
}

void Checker::draw()
{
	checkerTile->draw();
}
