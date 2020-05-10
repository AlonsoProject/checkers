#include "Text.hpp"

Text::Text(const std::string& data, const std::string& pathToFont) :
text(new sf::Text()), font(new sf::Font())
{
	font->loadFromFile(pathToFont);
	text->setString(data);
	text->setFont(*font);
}

Text::~Text()
{
	if (text) delete text;
	if (font) delete font;
}

sf::Text* Text::getInstance()
{
	return text;
}

void Text::draw()
{
	ServiceObjectManager::get()->getWindow()->draw(*text);
}

void Text::move(const sf::Vector2f& offset)
{
	text->move(offset);
}

void Text::setPosition(const sf::Vector2f& position)
{
	text->setPosition(position);
}
