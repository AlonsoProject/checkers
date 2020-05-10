#include "GameObjectManager.hpp"

GameObjectManager::~GameObjectManager()
{
	if (playerController) delete playerController;
	if (board) delete board;
	if (gameSession) delete gameSession;
}

/**
 * Init objects
 */
GameObjectManager* GameObjectManager::init()
{
	if (!instance)
	{
		instance = new GameObjectManager();
		instance->getPlayerController();
	}
	return instance;
}

/**
 * Get instance of the component manager
 */
GameObjectManager* GameObjectManager::get()
{
	if (!instance)
	{
		init();
	}
	return instance;
}

/**
 * Free instance of the component manager
 */
void GameObjectManager::free()
{
	if (instance) delete instance;
}

Board* GameObjectManager::getBoard()
{
	if (!board) board = new Board();
	return board;
}

PlayerController* GameObjectManager::getPlayerController()
{
	if (!playerController) playerController = new PlayerController();
	return playerController;
}

GameSession* GameObjectManager::getGameSession()
{
	if (!gameSession) gameSession = new GameSession();
	return gameSession;
}
