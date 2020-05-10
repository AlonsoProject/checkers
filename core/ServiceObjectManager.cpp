#include "ServiceObjectManager.hpp"

ServiceObjectManager::~ServiceObjectManager()
{
	if (window) delete window;
}

ServiceObjectManager* ServiceObjectManager::get()
{
	if (!instance) instance = new ServiceObjectManager();
	return instance;
}

void ServiceObjectManager::free()
{
	if (instance) delete instance;
}

sf::RenderWindow* ServiceObjectManager::getWindow()
{
	if (!window)
	{
		window = new sf::RenderWindow(sf::VideoMode(Config::width, Config::height), Config::appName);
	}
	return window;
}