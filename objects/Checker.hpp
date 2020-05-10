#pragma once

#include "../graphics/Tile.hpp"
#include "../core/IDrawable.hpp"

class Checker : public IDrawable
{
private:
	int idOwner;
	Tile* checkerTile;
public:
	Checker(std::string pathToCheckerTile, sf::Vector2f position);
	~Checker();

	Tile* getCheckerTile();

	virtual void draw() override;
};