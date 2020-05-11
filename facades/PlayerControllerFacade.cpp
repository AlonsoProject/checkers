#include "PlayerControllerFacade.hpp"
#include "../core/GameObjectManager.hpp"

Player* PlayerControllerFacade::getCurrentPlayer()
{
	return GameObjectManager::get()->getPlayerController()->getCurrentPlayer();
}

std::string PlayerControllerFacade::getNameCurrentUserName()
{
	return getCurrentPlayer()->getName();
}

int PlayerControllerFacade::getCurrentUserId()
{
	return getCurrentPlayer()->getId();
}
