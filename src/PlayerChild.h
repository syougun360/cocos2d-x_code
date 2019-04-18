#pragma once
#include "EntityHierarchy.h"

class PlayerChild :public game::EntityHierarchy
{
public:
	PlayerChild(NodePtr node, std::string name = "PlayerChild");

	void awake();
	void start();
	void update();

private:
};

