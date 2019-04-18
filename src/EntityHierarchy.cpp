#include "EntityHierarchy.h"
#include "Hierarchy.h"

using namespace game;

EntityHierarchy::EntityHierarchy(NodePtr node, const std::string& name, const Tags tag) :
Component(name, tag),
active(true),
state(UpdateState::Awake)
{
	node->addChild(this,0);
}

EntityHierarchy::EntityHierarchy(NodePtr node, const std::string& name, const Transform& transform) :
Component(name, transform),
active(true),
state(UpdateState::Awake)
{
	node->addChild(this, 0);
}

EntityHierarchy::EntityHierarchy(NodePtr node, const std::string& name, const SortingLayer sortingLayer) :
Component(name, sortingLayer),
active(true),
state(UpdateState::Awake)
{
	node->addChild(this, 0);

}

EntityHierarchy::EntityHierarchy(NodePtr node, const std::string& name, const Tags tag, const SortingLayer sortingLayer) :
Component(name, tag, sortingLayer),
active(true),
state(UpdateState::Awake)
{
	node->addChild(this, 0);
}


// 子オブジェクトを追加
void EntityHierarchy::addChild(EntityHierarchyPtr entityHierarchy)
{
	Hierarchy::registerHierachy(entityHierarchy,parent);
}

// 子オブジェクトを削除
void EntityHierarchy::destroyChild(EntityHierarchyPtr entityHierarchy)
{
	Hierarchy::deregistration(entityHierarchy->getName());
}

void EntityHierarchy::setEntityParent(std::shared_ptr<EntityHierarchy> entityHierarchy)
{
	parent = entityHierarchy;
}

void EntityHierarchy::setActive(bool isActive)
{
	active = isActive;
}

void EntityHierarchy::updatable()
{
	if (!active) return;

	switch (state)
	{
	case EntityHierarchy::UpdateState::Awake:
		awake();
		componentsAwake();
		state = UpdateState::Start;
		break;

	case EntityHierarchy::UpdateState::Start:
		start();
		componentsStart();
		state = UpdateState::Update;
		break;
	
	case EntityHierarchy::UpdateState::Update:
		update();
		componentsUpdate();

		break;
	
	default:
		break;
	}

}