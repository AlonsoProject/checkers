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

/**
 * Hostile color indicating impossibility of action
 */
#define HOSTILE_COLOR 0
/**
 * Friendly color indicating a possibility of action
 */
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

	/**
	 * Select cell by position
	 */
	void selectCellByPosition(float x, float y, int mode = HOSTILE_COLOR);
	/**
	 * Clear selected cells
	 */
	void clearSelectedCells();
	/**
	 * Cell is selected
	 */
	bool cellIsSelected(Tile* cell);
	/**
	 * Find selected checker
	 */
	Checker* findSelectedChecker();

	/**
	 * Show moves
	 */
	void showMoves(Checker* checker);
	/**
	 * Move checker to cell
	 */
	void moveCheckerToCell(Checker* checker, Tile* cell);

	/**
	 * Find checker by position
	 */
	Checker* findCheckerByPosition(float x, float y);
	Checker* findCheckerByPosition(const sf::Vector2f& position);

	/**
	 * Find checker on cell
	 */
	Checker* findCheckerOnCell(Tile* cell);

	/**
	 * Checker exists on cell
	 */
	bool checkerExistsOnCell(Tile* cell);

	bool checkerInTop(Checker* checker);
	bool checkerInBottom(Checker* checker);

	/**
	 * Find cell by position
	 */
	Tile* findCellByPosition(float x, float y);
	Tile* findCellByPosition(const sf::Vector2f& position);

	virtual void draw() override;
};