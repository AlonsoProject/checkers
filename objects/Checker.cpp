#include "Checker.hpp"

Checker::Checker(
	int idOwner,
	const std::string& pathToCheckerTile,
	const std::string& pathToCheckerKingTile,
	sf::Vector2f position,
	uint8_t moveDirection
) :
idOwner(idOwner), 
checkerTile(new Tile(pathToCheckerTile)), 
pathToCheckerKingTile(pathToCheckerKingTile),
moveDirection(moveDirection)
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

uint8_t Checker::getMoveDirection()
{
	return moveDirection;
}

bool Checker::isSelected()
{
	return selected;
}

void Checker::setSelected(bool value)
{
	selected = value;
}

bool Checker::isKing()
{
	return king;
}

void Checker::setKing()
{
	checkerTile->updateTexture(pathToCheckerKingTile);
	king = true;
}

bool Checker::checkBelongsToUser(int idUser)
{
	return idUser == getIdOwner();
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
