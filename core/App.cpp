#include "App.hpp"

App::App() : window(sf::VideoMode(800, 600), "Game")
{
}

/**
 * Run the application
 */
void App::run()
{
    gameLoop.run(window);
}