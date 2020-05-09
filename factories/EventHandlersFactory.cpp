#include "EventHandlersFactory.hpp"

void EventHandlersFactory::factory(std::vector<EventHandler*>& accumulator)
{
	accumulator.push_back(new CloseEvent);
	accumulator.push_back(new MouseButtonPressedEvent);
}
