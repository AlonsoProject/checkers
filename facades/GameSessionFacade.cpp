#include "GameSessionFacade.hpp"
#include "../core/GameObjectManager.hpp"

void GameSessionFacade::userToggle()
{
	GameObjectManager::get()->getBoard()->clearSelectedCells();
	GameObjectManager::get()->getPlayerController()->togglePlayer();
	GameObjectManager::get()->getGameSession()->resetTimer();
}

bool GameSessionFacade::isExpired()
{
	return GameObjectManager::get()->getGameSession()->isExpired();
}

int GameSessionFacade::getCountdown()
{
	return GameObjectManager::get()->getGameSession()->getCountdown();
}
