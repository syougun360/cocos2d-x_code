#pragma once
#include "EntityBehavior.h"

class Player;

class PlayerMover :public game::EntityBehavior
{
public:
	PlayerMover(const Player& player);

	void awake();
	void update();

private:

};

