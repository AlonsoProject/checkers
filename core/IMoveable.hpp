#pragma once

#include <SFML/Graphics.hpp>

class IMoveable
{
public:
	virtual ~IMoveable() {}

	virtual void move(const sf::Vector2f& offset) = 0;
	virtual void setPosition(const sf::Vector2f& position) = 0;
};