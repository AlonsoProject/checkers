#include "Tile.hpp"
#include "../core/ServiceObjectManager.hpp"

Tile::Tile(const std::string& pathToTile) :
tileTexture(new sf::Texture), tileSprite(new sf::Sprite)
{
	tileTexture->loadFromFile(pathToTile);
	tileSprite->setTexture(*tileTexture);
	currentTilePath = pathToTile;
}

Tile::~Tile()
{
	if (tileTexture) delete tileTexture;
	if (tileSprite) delete tileSprite;
}

void Tile::resize(uint32_t width, uint32_t height)
{
	tileSprite->setScale(
		width	/ tileSprite->getLocalBounds().width,
		height	/ tileSprite->getLocalBounds().height
	);
}

void Tile::draw()
{
	ServiceObjectManager::get()->getWindow()->draw(*tileSprite);
}

void Tile::move(const sf::Vector2f& offset)
{
	tileSprite->move(offset);
}

void Tile::setPosition(const sf::Vector2f& position)
{
	tileSprite->setPosition(position);
}

void Tile::getPosition(sf::Vector2f& position)
{
	position.x = tileSprite->getPosition().x;
	position.y = tileSprite->getPosition().y;
}

float Tile::getX()
{
	return tileSprite->getPosition().x;
}

float Tile::getY()
{
	return tileSprite->getPosition().y;
}

std::string Tile::getCurrentTexture()
{
	return currentTilePath;
}

std::string Tile::getOldTexture()
{
	return oldTilePath;
}

void Tile::updateTexture(const std::string& pathToTexture)
{
	oldTilePath = currentTilePath;
	tileTexture->loadFromFile(pathToTexture);
	tileSprite->setTexture(*tileTexture);
	currentTilePath = pathToTexture;
}
