#pragma once

#include "../graphics/Tile.hpp"
#include "../core/IDrawable.hpp"
#include "../core/IMoveable.hpp"

class Checker : public IDrawable, public IMoveable
{
private:
	int idOwner;
	Tile* checkerTile;
public:
	Checker(int idOwner, std::string pathToCheckerTile, sf::Vector2f position);
	~Checker();

	int getIdOwner();

	Tile* getCheckerTile();

	virtual void draw() override;

	virtual void move(const sf::Vector2f& offset) override;
	virtual void setPosition(const sf::Vector2f& position) override;
};