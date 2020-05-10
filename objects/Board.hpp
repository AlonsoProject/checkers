#pragma once

#include "Checker.hpp"
#include "../core/IDrawable.hpp"
#include "../graphics/TileContainer.hpp"
#include "../factories/CheckersFactory.hpp"
#include "../factories/CellsTileFactory.hpp"

class Board : public IDrawable
{
private:
	TileContainer* cells;
	std::vector<Checker*> checkers;
public:
	Board();
	~Board();

	virtual void draw() override;
};