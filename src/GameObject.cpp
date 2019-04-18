#include "GameObject.h"
#include "Hierarchy.h"
#include "EntityHierarchy.h"
#include "Component.h"

using namespace game;

GameObject::GameObject(const std::string &name):
Object(name),
sortingLayer(SortingLayer::Default),
transform(Transform())
{
	setTag((int)Tags::Default);
}

GameObject::GameObject(const std::string &name, Tags tag) :
Object(name),
sortingLayer(SortingLayer::Default),
transform(Transform())
{
	setTag((int)tag);
}


GameObject::GameObject(const std::string &name, SortingLayer sortingLayer) :
Object(name),
sortingLayer(sortingLayer),
transform(Transform())
{
	setTag((int)Tags::Default);
}



GameObject::GameObject(const std::string &name, Tags tag, SortingLayer sortingLayer) :
Object(name),
sortingLayer(sortingLayer),
transform(Transform())
{
	setTag((int)tag);
}

GameObject::GameObject(const std::string &name, const Transform& transform) :
Object(name),
sortingLayer(SortingLayer::Default),
transform(transform)
{
	setTag((int)Tags::Default);
}

GameObject::GameObject():
Object("GameObject"),
sortingLayer(SortingLayer::Default),
transform(Transform())
{
	setTag((int)Tags::Default);
}


// ゲームオブジェクトをHierarchyに登録して、生成する
// 戻り値としては、登録したゲームオブジェクト
std::shared_ptr<GameObject> GameObject::instantiate(std::shared_ptr<EntityHierarchy> gameObject)
{
	Hierarchy::registerHierachy(gameObject);
	auto object = Hierarchy::find(gameObject->getName());
	return object;
}


// 描画順を設定
void GameObject::setSortingLayer(SortingLayer sortingLayer)
{
	this->sortingLayer = sortingLayer;
	Hierarchy::sortingLayerSort();
}
