#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "Checker.hpp"
#include "../math/Math.hpp"
#include "../core/Config.hpp"
#include "../core/IDrawable.hpp"
#include "../graphics/TileContainer.hpp"
#include "../factories/CheckersFactory.hpp"
#include "../factories/CellsTileFactory.hpp"
#include "../facades/PlayerControllerFacade.hpp"

#define HOSTILE_COLOR 0
#define FRIENDLY_COLOR 1

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
	 * Selected cells
	 */
	TileContainer* selectedCells;
public:
	Board();
	~Board();

	void selectCellByPosition(float x, float y, int mode = HOSTILE_COLOR);
	void clearSelectedCells();

	void showMoves(Checker* checker);

	Checker* findCheckerByPosition(float x, float y);
	Tile* findCellByPosition(float x, float y);

	virtual void draw() override;
};

