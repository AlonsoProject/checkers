#pragma once

#include "Checker.hpp"
#include "../core/Config.hpp"
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

	Checker* findCheckerByPosition(float x, float y);

	virtual void draw() override;
};