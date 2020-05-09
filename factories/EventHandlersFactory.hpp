#pragma once

#include <vector>

#include "../events/core/EventHandler.hpp"
#include "../events/Includes.hpp"

class EventHandlersFactory
{
public:
	static void factory(std::vector<EventHandler*>& accumulator);
};