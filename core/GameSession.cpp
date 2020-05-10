#include "GameSession.hpp"

GameSession::GameSession() : sessionDuration(60)
{
	
}

int GameSession::getElapsedTime()
{
	return timer.getElapsedTime().asSeconds();
}

bool GameSession::isExpired()
{
	return timer.getElapsedTime().asSeconds() >= sessionDuration;
}

void GameSession::resetTimer()
{
	timer.restart();
}