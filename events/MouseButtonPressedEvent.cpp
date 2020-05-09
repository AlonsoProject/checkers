#include "MouseButtonPressedEvent.hpp"

MouseButtonPressedEvent::MouseButtonPressedEvent()
{
	eventType = sf::Event::MouseButtonPressed;
}

void MouseButtonPressedEvent::leftButtonPressed(sf::Event& event)
{
	std::cout << "The left button was pressed" << std::endl;
	std::cout << "Mouse x: " << event.mouseButton.x << std::endl;
	std::cout << "Mouse y: " << event.mouseButton.y << std::endl;
}

void MouseButtonPressedEvent::handle(sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Left)
	{
		leftButtonPressed(event);
	}
}
