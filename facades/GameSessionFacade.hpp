#pragma once

class GameObjectManager;

class GameSessionFacade
{
public:
	static void userToggle();
	static bool isExpired();
	static int getCountdown();
};