#pragma once

#include <SFML/Graphics.hpp>

#include <string>

#include "../core/IDrawable.hpp"
#include "../core/IMoveable.hpp"
#include "../core/ComponentManager.hpp"

class Text : public IDrawable, public IMoveable
{
private:
	sf::Text* text;
	sf::Font* font;
	sf::Color* color;
public:
	Text(const std::string& data, const std::string& pathToFont);
	~Text();

	sf::Text* getInstance();

	virtual void draw() override;

	virtual void move(const sf::Vector2f& offset) override;
	virtual void setPosition(const sf::Vector2f& position) override;
};