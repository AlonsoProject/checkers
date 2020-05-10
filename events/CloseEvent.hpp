#pragma once

#include "core/EventHandler.hpp"

#include "../core/ServiceObjectManager.hpp"

class CloseEvent : public EventHandler
{
public:
	CloseEvent();

	/**
	 * Handle an event
	 */
	virtual void handle(sf::Event& event) override;
};