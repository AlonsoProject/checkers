#include "GameSession.hpp"

GameSession::GameSession() : sessionDuration(60)
{
	
}

int GameSession::getSessionDuration()
{
	return sessionDuration;
}

int GameSession::getElapsedTime()
{
	return timer.getElapsedTime().asSeconds();
}

int GameSession::getCountdown()
{
	return getSessionDuration() - getElapsedTime();
}

bool GameSession::isExpired()
{
	return timer.getElapsedTime().asSeconds() >= sessionDuration;
}

void GameSession::resetTimer()
{
	timer.restart();
}