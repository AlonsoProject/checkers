#include "Checker.hpp"

Checker::Checker(int idOwner, std::string pathToCheckerTile, sf::Vector2f position) :
idOwner(idOwner), checkerTile(new Tile(pathToCheckerTile))
{
	setPosition(position);
}

Checker::~Checker()
{
	if (checkerTile) delete checkerTile;
}

int Checker::getIdOwner()
{
	return idOwner;
}

Tile* Checker::getCheckerTile()
{
	return checkerTile;
}

void Checker::draw()
{
	checkerTile->draw();
}

void Checker::move(const sf::Vector2f& offset)
{
	checkerTile->move(offset);
}

void Checker::setPosition(const sf::Vector2f& position)
{
	checkerTile->setPosition(position);
}
