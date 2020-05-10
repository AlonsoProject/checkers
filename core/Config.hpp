#pragma once

#include <string>

class Config
{
public:
	static inline int width = 800;
	static inline int height = 600;
	static inline std::string appName = "Game";

	static inline int rowBoardNumber = 9;
	static inline int colomnBoardNumber = 9;
	static inline std::string blackCellTile = "resources/tiles/board-black.png";
	static inline std::string whiteCellTile = "resources/tiles/board-white.png";

	static inline std::string defaultFont = "resources/fonts/Arial.ttf";
};