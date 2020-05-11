#pragma once

#include <iostream>

#include "core/EventHandler.hpp"
#include "../facades/BoardFacade.hpp"
#include "../core/GameObjectManager.hpp"
#include "../core/ServiceObjectManager.hpp"
#include "../facades/GameSessionFacade.hpp"
#include "../facades/PlayerControllerFacade.hpp"

class MouseButtonPressedEvent : public EventHandler
{
private:
    void clickOnChecker(Checker* checker, sf::Event& event);
    void clickOnCell(Tile* cell, sf::Event& event);

    void leftButtonPressed(sf::Event& event);
public:
    MouseButtonPressedEvent();

    /**
     * Handle an event
     */
    virtual void handle(sf::Event& event) override;
};