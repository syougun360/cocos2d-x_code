#pragma once
#include "EntityHierarchy.h"
#include "Sprite.h"
#include "Label.h"
#include "Point.h"
#include "Triangle.h"
#include "Box.h"

class Player :public game::EntityHierarchy
{
public:
	Player(NodePtr node, std::string name = "Player");

	void awake();
	void start();
	void update();

private:
	std::unique_ptr<game::Sprite> sprite;
	std::unique_ptr<game::Label> label;
	std::unique_ptr<game::Point> point;
	std::unique_ptr<game::Triangle> triangle;
	std::unique_ptr<game::Box> box;

};

