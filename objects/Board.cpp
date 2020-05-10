#include "Board.hpp"

Board::Board() : cells(new TileContainer())
{
	CellsTileFactory cellsTileFactory;
	cellsTileFactory.factory(cells);

	CheckersFactory checkersFactory;
	checkersFactory.factory(checkers);
}

Board::~Board()
{
	if (cells) delete cells;
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