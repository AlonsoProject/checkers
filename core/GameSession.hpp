#pragma once

#include <SFML/Graphics.hpp>

#include "../players/Player.hpp"

class GameSession
{
private:
	/**
	 * Session duration
	 */
	int sessionDuration;
	/**
	 * Timer
	 */
	sf::Clock timer;
public:
	GameSession();

	int getElapsedTime();
	bool isExpired();
	void resetTimer();
};