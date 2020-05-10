#include "App.hpp"

App::~App()
{
    ServiceObjectManager::free();
}

/**
 * Run the application
 */
void App::run()
{
    gameLoop.run();
}