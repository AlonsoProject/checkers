#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "../core/IDrawable.hpp"
#include "../core/IMoveable.hpp"

class ServiceObjectManager;

class Tile : public IDrawable, public IMoveable
{
private:
	sf::Texture* tileTexture;
	sf::Sprite* tileSprite;

	std::string currentTilePath;
	std::string oldTilePath;
public:
	Tile(const std::string& pathToTile);
	~Tile();

	void resize(uint32_t width, uint32_t height);

	virtual void draw() override;

	virtual void move(const sf::Vector2f& offset) override;
	virtual void setPosition(const sf::Vector2f& position) override;

	void getPosition(sf::Vector2f& position);

	float getX();
	float getY();

	std::string getCurrentTexture();
	std::string getOldTexture();
	void updateTexture(const std::string& pathToTexture);
};