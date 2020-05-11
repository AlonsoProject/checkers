#pragma once

#include "../core/Config.hpp"
#include "../widgets/Text.hpp"

#define UPPER_LEFT_CORNER 0
#define UPPER_RIGHT_CORNER 1

#define UPPER_LEFT_CORNER_OFFSET 0.03
#define UPPER_RIGHT_CORNER_OFFSET 0.95

class TextWidgetFactory
{
public:
	static Text* factory(const std::string& content, int position);
};