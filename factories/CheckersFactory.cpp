#include "CheckersFactory.hpp"

CheckersFactory::CheckersFactory() :
checkerWidth(Config::getCellWidth() + 1),
checkerHeight(Config::getCellHeight() + 1),
positionTopCheckers(0.0f, 0.0f), 
positionBottomChecker(0.0f, Config::height - checkerHeight),
numberCheckerRows(Config::numberCheckerRows)
{

}

/**
 * Get a number of checkers in a row
 */
int CheckersFactory::getNumberCheckersInRow()
{
	return numberCheckersInRow;
}

/**
 * Set a number of checkers in a row
 */
void CheckersFactory::setNumberCheckersInRow(int number)
{
	numberCheckersInRow = number;
}

/**
 * Symmetric shift of a positions to a row
 */
void CheckersFactory::shiftPostionToRow()
{
	positionTopCheckers.x = 0;
	positionTopCheckers.y += checkerHeight;

	positionBottomChecker.x = 0;
	positionBottomChecker.y -= checkerHeight;
}

/**
 * Factory row
 */
void CheckersFactory::factoryRow(std::vector<Checker*>& checkers)
{
	for (int i = 0; i < getNumberCheckersInRow(); i++)
	{
		checkers.push_back(new Checker(Config::whiteCheckerTile, positionTopCheckers));
		checkers.push_back(new Checker(Config::blackCheckerTile, positionBottomChecker));

		checkers[checkers.size() - 2]->getCheckerTile()->resize(checkerWidth, checkerHeight);
		checkers[checkers.size() - 1]->getCheckerTile()->resize(checkerWidth, checkerHeight);

		positionTopCheckers.x += checkerWidth * 2;
		positionBottomChecker.x += checkerWidth * 2;
	}
}

/**
 * Factory
 */
void CheckersFactory::factory(std::vector<Checker*>& checkers)
{
	for (int i = 0; i < numberCheckerRows; i++)
	{
		setNumberCheckersInRow(Config::colomnBoardNumber / 2 + 1);

		if (i % 2 != 0)
		{
			positionTopCheckers.x += checkerWidth;
			positionBottomChecker.x += checkerWidth;
			setNumberCheckersInRow(Config::colomnBoardNumber / 2);
		}

		factoryRow(checkers);

		shiftPostionToRow();
	}
}
