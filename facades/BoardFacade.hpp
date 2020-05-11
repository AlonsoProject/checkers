#pragma once

#include "../objects/Checker.hpp"

class GameObjectManager;

class BoardFacade
{
public:
	static void clearSelectedCells();
	static Checker* findChecker(float x, float y);
	static Tile* findCell(float x, float y);
};