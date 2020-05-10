#include "PlayerController.hpp"

PlayerController::PlayerController()
{
	playerStorage.push_back(new Player(0, "Artem"));
	playerStorage.push_back(new Player(1, "Mike"));
	currentPlayer = 0;
}

PlayerController::~PlayerController()
{
	for (auto player : playerStorage)
	{
		if (player) delete player;
	}
}

void PlayerController::togglePlayer()
{
	if (currentPlayer < playerStorage.size() - 1)
	{
		currentPlayer++;
	}
	else
	{
		currentPlayer = 0;
	}
}

Player* PlayerController::getCurrentPlayer()
{
	return playerStorage[currentPlayer];
}

std::vector<Player*> PlayerController::getPlayerStorage()
{
	return playerStorage;
}
