#include "App.hpp"

App::~App()
{
    ServiceObjectManager::free();
    GameObjectManager::free();
}

/**
 * Run the application
 */
void App::run()
{
    gameLoop.run();
}