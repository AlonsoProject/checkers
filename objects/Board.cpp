#include "Board.hpp"

Board::Board() : cells(new TileContainer()), selectedCells(new TileContainer())
{
	CellsTileFactory cellsTileFactory;
	cellsTileFactory.factory(cells);

	CheckersFactory checkersFactory;
	checkersFactory.factory(checkers);
}

Board::~Board()
{
	if (cells) delete cells;
	if (selectedCells) delete selectedCells;
	
	for (auto checker : checkers)
	{
		if (checker) delete checker;
	}
}

/**
 * Select cell by position
 */
void Board::selectCellByPosition(float x, float y, int mode)
{
	Tile* cell = findCellByPosition(x, y);

	if (mode == HOSTILE_COLOR)
	{
		cell->updateTexture(Config::redCellTile);
	}
	if (mode == FRIENDLY_COLOR)
	{
		cell->updateTexture(Config::greenCellTile);
	}
	selectedCells->add(cell);
}

/**
 * Clear selected cells
 */
void Board::clearSelectedCells()
{
	for (int i = 0; i < selectedCells->getSize(); i++)
	{
		selectedCells->get(i)->updateTexture(
			selectedCells->get(i)->getOldTexture()
		);
	}
	selectedCells->clear();

	Checker* selectedChecker = findSelectedChecker();
	if (selectedChecker) selectedChecker->setSelected(false);
}

/**
 * Cell is selected
 */
bool Board::cellIsSelected(Tile* cell)
{
	for (int i = 0; i < selectedCells->getSize(); i++)
	{
		if (cell == selectedCells->get(i))
		{
			return true;
		}
	}
	return false;
}

/**
 * Find selected checker
 */
Checker* Board::findSelectedChecker()
{
	for (auto checker : checkers)
	{
		if (checker->isSelected()) return checker;
	}
	return nullptr;
}

/**
 * Show moves
 */
void Board::showMoves(Checker* checker)
{
	std::vector<sf::Vector2f> cellAnglesPositions;
	Math::getTileAnglesPositions(checker->getCheckerTile(), cellAnglesPositions);

	const float shift = 5.0f;
	Math::stretchSquare(cellAnglesPositions, shift);

	for (const auto cellAngle : cellAnglesPositions)
	{
		Tile* cell = findCellByPosition(cellAngle);

		if (cell)
		{
			Checker* checkerOnCell;
			if (checkerOnCell = findCheckerByPosition(cellAngle))
			{
				if (checkerOnCell->checkBelongsToUser(PlayerControllerFacade::getCurrentUserId()))
				{
					cell->updateTexture(Config::redCellTile);
					selectedCells->add(cell);
					continue;
				}
				else
				{
					
				}
			}

			cell->updateTexture(Config::greenCellTile);
			selectedCells->add(cell);
		}
	}
}

/**
 * Move checker to cell
 */
void Board::moveCheckerToCell(Checker* checker, Tile* cell)
{
	sf::Vector2f position;
	cell->getPosition(position);

	checker->setPosition(position);

	if (checkerInTop(checker) || checkerInBottom(checker))
	{
		checker->setKing();
	}
}

/**
 * Find checker by position
 */
Checker* Board::findCheckerByPosition(float x, float y)
{
	sf::Vector2f position;
	for (auto checker : checkers)
	{
		checker->getCheckerTile()->getPosition(position);

		bool result = (position.x < x && x < position.x + Config::getCellWidth()) &&
					  (position.y < y && y < position.y + Config::getCellHeight());

		if (result) return checker;
	}
	return nullptr;
}

Checker* Board::findCheckerByPosition(const sf::Vector2f& position)
{
	return findCheckerByPosition(position.x, position.y);
}

Checker* Board::findCheckerOnCell(Tile* cell)
{
	sf::Vector2f cellPosition;
	cell->getPosition(cellPosition);

	return findCheckerByPosition(cellPosition.x, cellPosition.y);
}

/**
 * Checker exists on cell
 */
bool Board::checkerExistsOnCell(Tile* cell)
{
	return findCheckerOnCell(cell) != nullptr;
}

bool Board::checkerInTop(Checker* checker)
{
	return checker->getCheckerTile()->getY() < Config::getCellHeight();
}

bool Board::checkerInBottom(Checker* checker)
{
	return checker->getCheckerTile()->getY() >= Config::height - Config::getCellHeight();
}

/**
 * Find cell by position
 */
Tile* Board::findCellByPosition(float x, float y)
{
	sf::Vector2f position;
	for (int i = 0; i < cells->getSize(); i++)
	{
		cells->get(i)->getPosition(position);
		
		bool result = (position.x < x && x < position.x + Config::getCellWidth()) &&
					  (position.y < y && y < position.y + Config::getCellHeight());

		if (result) return cells->get(i);
	}
	return nullptr;
}

Tile* Board::findCellByPosition(const sf::Vector2f& position)
{
	return findCellByPosition(position.x, position.y);
}

void Board::draw()
{
	for (int i = 0; i < cells->getSize(); i++)
	{
		cells->get(i)->draw();
	}

	for (int i = 0; i < checkers.size(); i++)
	{
		checkers[i]->draw();
	}
}