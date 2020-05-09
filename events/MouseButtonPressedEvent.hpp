#pragma once

#include <iostream>

#include "core/EventHandler.hpp"

class MouseButtonPressedEvent : public EventHandler
{
private:
    void leftButtonPressed(sf::Event& event);
public:
    MouseButtonPressedEvent();

    /**
     * Handle an event
     */
    virtual void handle(sf::Event& event) override;
};