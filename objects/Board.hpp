#pragma once

#include "Checker.hpp"
#include "../core/Config.hpp"
#include "../core/IDrawable.hpp"
#include "../graphics/TileContainer.hpp"
#include "../factories/CheckersFactory.hpp"
#include "../factories/CellsTileFactory.hpp"

#define GREEN_HIGHLIGHTED 0
#define RED_HIGHLIGHTED 1

class Board : public IDrawable
{
private:
	/**
	 * Cells
	 */
	TileContainer* cells;
	/**
	 * Checkers
	 */
	std::vector<Checker*> checkers;
	/**
	 * Highlighted cells
	 */
	TileContainer* highlightedCells;
public:
	Board();
	~Board();

	void highlightedCellsByChecker(Checker* checker, int mode = RED_HIGHLIGHTED);
	void clearHighlightedCells();

	Checker* findCheckerByPosition(float x, float y);
	Tile* findCellByPosition(float x, float y);

	virtual void draw() override;
};

