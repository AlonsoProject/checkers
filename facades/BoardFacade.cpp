#include "BoardFacade.hpp"
#include "../core/GameObjectManager.hpp"

void BoardFacade::clearSelectedCells()
{
	GameObjectManager::get()->getBoard()->clearSelectedCells();
}

Checker* BoardFacade::findChecker(float x, float y)
{
	return GameObjectManager::get()->getBoard()->findCheckerByPosition(x, y);
}

Tile* BoardFacade::findCell(float x, float y)
{
	return GameObjectManager::get()->getBoard()->findCellByPosition(x, y);
}
