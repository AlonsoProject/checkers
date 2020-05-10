#include "Board.hpp"

Board::Board() : cells(new TileContainer())
{
	CellsTileFactory cellsTileFactory;
	cellsTileFactory.factory(cells);
}

Board::~Board()
{
	if (cells) delete cells;
}

void Board::draw()
{
	for (int i = 0; i < cells->getSize(); i++)
	{
		cells->get(i)->draw();
	}
}