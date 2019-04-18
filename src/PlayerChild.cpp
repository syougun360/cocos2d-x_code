#include "PlayerChild.h"
#include "Player.h"
#include "Random.h"

using namespace game;


PlayerChild::PlayerChild(NodePtr node,std::string name) :
EntityHierarchy(node,name, Tags::Player, SortingLayer::Player)
{
}


void PlayerChild::awake()
{
}

void PlayerChild::start()
{
	auto p = getEntityParent();
	auto name = p->getName();

	auto fp = Hierarchy::find(name);
	auto play = fp;
}


void PlayerChild::update()
{

}

