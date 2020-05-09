#pragma once

#include "GameObject.hpp"
#include "../graphics/TileContainer.hpp"
#include "../factories/CellsTileFactory.hpp"

class Board : public GameObject, public IDrawable
{
private:
	TileContainer* cells;
public:
	Board();
	~Board();

	virtual void draw() override;
};