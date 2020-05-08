#pragma once

#include "Event.hpp"

#include "../core/ComponentManager.hpp"

class CloseEvent : public Event
{
public:
	CloseEvent();

	virtual void handle() override;
};