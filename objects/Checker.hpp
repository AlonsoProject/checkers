#pragma once

#include <sys/types.h>

#include "../core/Config.hpp"
#include "../graphics/Tile.hpp"
#include "../core/IDrawable.hpp"
#include "../core/IMoveable.hpp"

#define MOVE_DIRECTION_TO_TOP 0
#define MOVE_DIRECTION_TO_BOTTOM 1

class Checker : public IDrawable, public IMoveable
{
private:
	int idOwner;
	Tile* checkerTile;

	std::string pathToCheckerKingTile;

	bool king = false;
	bool selected = false;

	uint8_t moveDirection;
public:
	Checker(
		int idOwner, 
		const std::string& pathToCheckerTile, 
		const std::string& pathToCheckerKingTile,
		sf::Vector2f position, 
		uint8_t moveDirection
	);
	~Checker();

	int getIdOwner();

	Tile* getCheckerTile();

	uint8_t getMoveDirection();

	bool isSelected();
	void setSelected(bool value);

	bool isKing();
	void setKing();

	bool checkBelongsToUser(int idUser);

	virtual void draw() override;

	virtual void move(const sf::Vector2f& offset) override;
	virtual void setPosition(const sf::Vector2f& position) override;
};