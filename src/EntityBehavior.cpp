#include "EntityBehavior.h"
#include "Component.h"

using namespace game;

EntityBehavior::EntityBehavior(const std::string& name) :
Component(name),
enable(true)
{
	
}

EntityBehavior::EntityBehavior(const std::string& name, const std::string& parentName) :
Component(name, parentName),
enable(true)
{

}
void EntityBehavior::setEnable(bool isEnable)
{
	enable = isEnable;
}
