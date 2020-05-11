#include "Board.hpp"

Board::Board() : cells(new TileContainer()), highlightedCells(new TileContainer())
{
	CellsTileFactory cellsTileFactory;
	cellsTileFactory.factory(cells);

	CheckersFactory checkersFactory;
	checkersFactory.factory(checkers);
}

Board::~Board()
{
	if (cells) delete cells;
	if (highlightedCells) delete highlightedCells;
}

void Board::highlightedCellsByChecker(Checker* checker, int mode)
{
	sf::Vector2f checkerPosition;
	checker->getCheckerTile()->getPosition(checkerPosition);

	Tile* cell = findCellByPosition(checkerPosition.x, checkerPosition.y);
	if (!cell) return;

	if (mode == RED_HIGHLIGHTED)
	{
		cell->updateTexture(Config::redCellTile);
	}
	highlightedCells->add(cell);
}

void Board::clearHighlightedCells()
{
	for (int i = 0; i < highlightedCells->getSize(); i++)
	{
		highlightedCells->get(i)->updateTexture(
			highlightedCells->get(i)->getOldTexture()
		);
	}
	highlightedCells->clear();
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
		
		if (position.x == x && position.y == y) return cells->get(i);
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