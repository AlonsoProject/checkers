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

	static inline std::string blackCheckerTile = "resources/tiles/black.png";
	static inline std::string whiteCheckerTile = "resources/tiles/white.png";
	static inline std::string blackCheckerKingTile = "resources/tiles/black-king.png";
	static inline std::string whiteCheckerKingTile = "resources/tiles/white-king.png";
	static inline int numberCheckerRows = 3;

	static float getCellWidth();
	static float getCellHeight();
};