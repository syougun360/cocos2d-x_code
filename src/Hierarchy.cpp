#include "Hierarchy.h"
#include <algorithm>


using namespace game;

std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> Hierarchy::hierarchyList;

void Hierarchy::sortingLayerSort()
{
	std::vector<std::shared_ptr<EntityHierarchy>> ehList;

	for (auto& hierarchy : hierarchyList)
	{
		ehList.push_back(hierarchy.second);
	}

	clear();

	std::sort(ehList.begin(), ehList.end(), 
		[](const std::shared_ptr<EntityHierarchy> left, const std::shared_ptr<EntityHierarchy> right)
	{
		return left->getSortingLayer() < right->getSortingLayer();
	});

	for (auto& eh : ehList)
	{
		hierarchyList.insert(std::make_pair(eh->getName(), eh));
	}
}


void Hierarchy::registerHierachy(std::shared_ptr<EntityHierarchy> entity)
{
	entity->setEntityParent(entity);
	hierarchyList.insert(std::make_pair(entity->getName(), entity));
}

void Hierarchy::registerHierachy(std::shared_ptr<EntityHierarchy> entity, std::shared_ptr<EntityHierarchy> parent)
{
	entity->setEntityParent(parent);
	hierarchyList.insert(std::make_pair(entity->getName(), entity));
}

void Hierarchy::deregistration(const std::string& name)
{
	auto itr = hierarchyList.find(name);
	if (itr != hierarchyList.end()) return;

	hierarchyList.erase(itr);
}

void Hierarchy::clear()
{
	hierarchyList.clear();
}

void Hierarchy::update()
{
	for (auto& hierarchy : hierarchyList)
	{
		hierarchy.second->updatable();
	}
}

std::shared_ptr<EntityHierarchy> Hierarchy::find(const std::string& name)
{
	auto findObject = hierarchyList.find(name);
	if (findObject == hierarchyList.end()) return nullptr;

	return findObject->second;
}


// Tagでのゲームオブジェクトを取得
std::shared_ptr<EntityHierarchy> Hierarchy::findWithTag(const Tags tag)
{
	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->getTag() != (int)tag) continue;

		return hierarchy.second;
	}

	return nullptr;
}

// Tagでのゲームオブジェクトを配列で取得
std::vector<std::shared_ptr<EntityHierarchy>> Hierarchy::findGameObjectsWithTag(const Tags tag)
{
	std::vector<std::shared_ptr<EntityHierarchy>> gameObjects;
	gameObjects.clear();

	for (auto& hierarchy : hierarchyList)
	{
		if (hierarchy.second->getTag() != (int)tag) continue;

		gameObjects.push_back(hierarchy.second);
	}
	
	return gameObjects;
}
