#include "CellsTileFactory.hpp"

void CellsTileFactory::factory(TileContainer* tileContainer)
{
	const float cellWidth		= Config::width / Config::colomnBoardNumber;
	const float cellHeight		= Config::height / Config::rowBoardNumber;
	int totalCells				= Config::colomnBoardNumber * Config::rowBoardNumber;
	sf::Vector2f currentOffset(0.0f, 0.0f);
	
	std::string whiteCellTile   = "resources/tiles/board-white.png";
	std::string blackCellTile   = "resources/tiles/board-black.png";
	std::string currentTile		= blackCellTile;

	for (int i = 0; i < totalCells + 1; i++)
	{
		tileContainer->add(new Tile(currentTile));
		tileContainer->get(i)->setPosition(currentOffset);
		tileContainer->get(i)->resize(cellWidth, cellHeight);

		if (currentTile == whiteCellTile) currentTile = blackCellTile;
		else currentTile = whiteCellTile;

		if (i != 0 && i % Config::colomnBoardNumber == 0)
		{
			currentOffset.x = 0;
			currentOffset.y += cellHeight;
			continue;
		}
		currentOffset.x += cellWidth;
	}
}