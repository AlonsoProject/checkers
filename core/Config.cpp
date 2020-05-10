#include "Config.hpp"

float Config::getCellWidth()
{
	return width / colomnBoardNumber;
}

float Config::getCellHeight()
{
	return height / rowBoardNumber;
}
