#include "ComponentManager.hpp"

ComponentManager::~ComponentManager()
{
	if (window) delete window;
}

ComponentManager* ComponentManager::get()
{
	if (!instance) instance = new ComponentManager();
	return instance;
}

void ComponentManager::free()
{
	if (instance) delete instance;
}

sf::RenderWindow* ComponentManager::getWindow()
{
	if (!window)
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 600), "Game");
	}
	return window;
}
