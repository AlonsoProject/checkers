#pragma once

#include <vector>

#include "Player.hpp"

class PlayerController
{
private:
	/**
	 * Player storage
	 */
	std::vector<Player*> playerStorage;
	/**
	 * Index of current player in game session
	 */
	int currentPlayer;
public:
	PlayerController();
	~PlayerController();

	void togglePlayer();

	Player* getCurrentPlayer();

	std::vector<Player*> getPlayerStorage();
};