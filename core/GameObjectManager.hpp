#pragma once

#include "GameSession.hpp"
#include "../core/Config.hpp"
#include "../objects/Board.hpp"
#include "../players/PlayerController.hpp"

/**
 * Game object manager
 * This class is singelton
 * This class storage components for the application
 */
class GameObjectManager
{
private:
    /**
     * Instance
     */
    inline static GameObjectManager* instance = nullptr;

    /**
     * Board
     */
    Board* board = nullptr;
    /**
     * Player controller
     */
    PlayerController* playerController = nullptr;
    /**
     * Game session
     */
    GameSession* gameSession = nullptr;

    /**
     * Implements the singelton
     */
    GameObjectManager() {}
    ~GameObjectManager();
public:
    /**
     * Init objects
     */
    static GameObjectManager* init();

    /**
     * Get instance of the component manager
     */
    static GameObjectManager* get();
    /**
     * Free instance of the component manager
     */
    static void free();

    Board* getBoard();

    PlayerController* getPlayerController();

    GameSession* getGameSession();
};