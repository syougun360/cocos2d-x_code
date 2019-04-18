#include "Component.h"
#include "EntityBehavior.h"
#include "Hierarchy.h"

using namespace game;

Component::Component(const std::string &name) :
GameObject(name),
gameObject(std::make_shared<GameObject>(name)),
parentName(name)
{
}
Component::Component(const std::string &name, const Transform& transform) :
GameObject(name, transform),
gameObject(std::make_shared<GameObject>(name, transform)),
parentName(name)
{
}

Component::Component(const std::string &name,Tags tag) :
GameObject(name, tag),
gameObject(std::make_shared<GameObject>(name,tag)),
parentName(name)
{
}

Component::Component(const std::string &name, SortingLayer sortingLayer) :
GameObject(name, sortingLayer),
gameObject(std::make_shared<GameObject>(name, sortingLayer)),
parentName(name)
{
}

Component::Component(const std::string &name, Tags tag, SortingLayer sortingLayer) :
GameObject(name, tag, sortingLayer),
gameObject(std::make_shared<GameObject>(name, tag, sortingLayer)),
parentName(name)
{
}


Component::Component(const std::string &name, const std::string& parentName) :
GameObject(name),
gameObject(std::make_shared<GameObject>(name)),
parentName(parentName)
{

}


Component::Component() :
GameObject("null"),
gameObject(std::make_shared<GameObject>("null")),
parentName("null")
{
}

void Component::componentsAwake()
{
	for (auto& children : childrenList)
	{
		if (!children.second->isEnable()) continue;

		children.second->awake();
	}

}

void Component::componentsStart()
{
	for (auto& children : childrenList)
	{
		if (!children.second->isEnable()) continue;

		children.second->start();
	}
}

void Component::componentsUpdate()
{
	for (auto& children : childrenList)
	{
		if (!children.second->isEnable()) continue;

		children.second->update();
	}
}

void Component::addComponent(std::shared_ptr<EntityBehavior> gameObject)
{
	childrenList.insert(std::make_pair(gameObject->getName(), gameObject));
}

void Component::destroy()
{
	auto itr = childrenList.find(getName());
	if (itr == childrenList.end()) return;

	childrenList.erase(itr);
}

// çÌèú
void Component::destroy(const std::string &name)
{
	auto itr = childrenList.find(name);
	if (itr == childrenList.end()) return;

	childrenList.erase(itr);
}

std::shared_ptr<Component> Component::getComponentInParent()const
{
	auto parent = Hierarchy::find<Component>(parentName);
	if (!parent) return nullptr;

	return parent;
}
