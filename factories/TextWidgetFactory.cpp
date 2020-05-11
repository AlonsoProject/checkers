#include "TextWidgetFactory.hpp"

Text* TextWidgetFactory::factory(const std::string& content, int position)
{
	Text* text = new Text(content, Config::defaultFont);
	sf::Vector2f vPosition;

	if (position == UPPER_LEFT_CORNER)
	{
		vPosition.x = Config::width * UPPER_LEFT_CORNER_OFFSET;
		vPosition.y = Config::height * UPPER_LEFT_CORNER_OFFSET;
	}

	if (position == UPPER_RIGHT_CORNER)
	{
		vPosition.x = Config::width * UPPER_RIGHT_CORNER_OFFSET;
		vPosition.y = Config::height * UPPER_LEFT_CORNER_OFFSET;
	}

	text->setPosition(vPosition);
	text->getInstance()->setCharacterSize(18);
	text->getInstance()->setFillColor(sf::Color::Blue);

	return text;
}
