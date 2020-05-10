#include "CellsTileFactory.hpp"

CellsTileFactory::CellsTileFactory() : currentOffset(0.0f, 0.0f)
{
	cellWidth	= Config::getCellWidth() + 1;
	cellHeight	= Config::getCellHeight() + 1;
	totalCells	= Config::colomnBoardNumber * Config::rowBoardNumber;
	currentTile = Config::blackCellTile;
}

void CellsTileFactory::toggleTile()
{
	if (currentTile == Config::blackCellTile)
	{
		currentTile = Config::whiteCellTile;
	}
	else
	{
		currentTile = Config::blackCellTile;
	}
}

std::string CellsTileFactory::getTile()
{
	return currentTile;
}

void CellsTileFactory::shiftOffsetToColumn()
{
	currentOffset.x += cellWidth;
}

void CellsTileFactory::shiftOffsetToRow()
{
	currentOffset.x = 0;
	currentOffset.y += cellHeight;
}

sf::Vector2f CellsTileFactory::getOffset()
{
	return currentOffset;
}

void CellsTileFactory::factory(TileContainer* tileContainer)
{
	for (int i = 0; i < totalCells; i++)
	{
		if (i != 0 && i % Config::colomnBoardNumber == 0)
		{
			shiftOffsetToRow();
		}

		tileContainer->add(new Tile(getTile()));
		tileContainer->get(i)->setPosition(getOffset());
		tileContainer->get(i)->resize(cellWidth, cellHeight);

		toggleTile();
		shiftOffsetToColumn();
	}
}