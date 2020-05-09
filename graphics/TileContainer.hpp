#pragma once

#include <vector>
#include <sys/types.h>

#include "Tile.hpp"

class TileContainer
{
private:
	std::vector<Tile*> tiles;
public:
	TileContainer();
	~TileContainer();

	void add(Tile* tile);
	Tile* get(uint32_t index);

	uint32_t getSize();
};