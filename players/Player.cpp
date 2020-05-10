#include "Player.hpp"

Player::Player(int id, std::string name) : 
id(id), name(name)
{
}

int Player::getId()
{
	return id;
}

std::string Player::getName()
{
	return name;
}