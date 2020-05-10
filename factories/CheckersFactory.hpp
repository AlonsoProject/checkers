#pragma once

#include <vector>

#include "../core/Config.hpp"
#include "../objects/Checker.hpp"

class CheckersFactory
{
private:
	/**
	 * Checker width
	 */
	float checkerWidth;
	/**
	 * Checker height
	 */
	float checkerHeight;
	/**
	 * Position for top a checker
	 */
	sf::Vector2f positionTopCheckers;
	/**
	 * Position for bottom a checker
	 */
	sf::Vector2f positionBottomChecker;
	/**
	 * Number of checkers rows
	 */
	int numberCheckerRows;
	/**
	 * Number of checkers in a row
	 */
	int numberCheckersInRow;
public:
	CheckersFactory();

	/**
	 * Get a number of checkers in a row
	 */
	int getNumberCheckersInRow();
	/**
	 * Set a number of checkers in a row
	 */
	void setNumberCheckersInRow(int number);
	/**
	 * Symmetric shift of a positions to a row
	 */
	void shiftPostionToRow();
	/**
	 * Factory row
	 */
	void factoryRow(std::vector<Checker*>& checkers);
	/**
	 * Factory
	 */
	void factory(std::vector<Checker*>& checkers);
};