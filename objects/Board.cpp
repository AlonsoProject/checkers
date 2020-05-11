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

Checker* Board::findSelectedChecker()
{
	for (auto checker : checkers)
	{
		if (checker->isSelected()) return checker;
	}
	return nullptr;
}

void Board::showMoves(Checker* checker)
{
	std::vector<sf::Vector2f> cellAnglesPositions;
	Math::getTileAnglesPositions(checker->getCheckerTile(), cellAnglesPositions);

	const float shift = 5.0f;
	Math::stretchSquare(cellAnglesPositions, shift);

	for (const auto cellAngle : cellAnglesPositions)
	{
		Tile* cell = findCellByPosition(cellAngle.x, cellAngle.y);

		if (cell)
		{
			Checker* checkerOnCell = findCheckerByPosition(cellAngle.x, cellAngle.y);
			if (checkerOnCell && checkerOnCell->getIdOwner() == PlayerControllerFacade::getCurrentUserId())
			{
				continue;
			}

			cell->updateTexture(Config::greenCellTile);
			selectedCells->add(cell);
		}
	}
}

void Board::moveCheckerToCell(Checker* checker, Tile* cell)
{
	sf::Vector2f position;
	cell->getPosition(position);

	checker->setPosition(position);
}

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