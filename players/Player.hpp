#pragma once

#include <string>

class Player
{
private:
	int id;
	std::string name;
public:
	Player(int id, std::string name);

	int getId();
	std::string getName();
};