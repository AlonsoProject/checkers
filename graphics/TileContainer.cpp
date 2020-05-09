#include "TileContainer.hpp"

TileContainer::TileContainer() : tiles(std::vector<Tile*>())
{
}

TileContainer::~TileContainer()
{
	for (auto tile : tiles)
	{
		if (tile) delete tile;
	}
}

void TileContainer::add(Tile* tile)
{
	tiles.push_back(tile);
}

Tile* TileContainer::get(uint32_t index)
{
	return tiles[index];
}

uint32_t TileContainer::getSize()
{
	return tiles.size();
}
