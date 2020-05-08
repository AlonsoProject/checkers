#include "App.hpp"

App::~App()
{
    ComponentManager::free();
}

/**
 * Run the application
 */
void App::run()
{
    gameLoop.run();
}