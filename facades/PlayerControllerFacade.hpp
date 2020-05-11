#pragma once

#include <string>

#include "../players/Player.hpp"

class GameObjectManager;

class PlayerControllerFacade
{
public:
	static Player* getCurrentPlayer();
	static std::string getNameCurrentUserName();
	static int getCurrentUserId();
};