#pragma once

#include "../core/Config.hpp"
#include "../graphics/TileContainer.hpp"

class CellsTileFactory
{
private:
	/**
	 * Cell width
	 */
	float cellWidth;
	/**
	 * Cell height
	 */
	float cellHeight;
	/**
	 * Total cells
	 */
	int totalCells;

	/**
	 * Offset for factory cells
	 */
	sf::Vector2f currentOffset;
	/**
	 * Tile for cell
	 */
	std::string currentTile;
public:
	CellsTileFactory();
	
	void toggleTile();
	std::string getTile();

	void shiftOffsetToColumn();
	void shiftOffsetToRow();
	sf::Vector2f getOffset();

	void factory(TileContainer* tileContainer);
};