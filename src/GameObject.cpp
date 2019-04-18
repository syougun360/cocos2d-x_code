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


// �Q�[���I�u�W�F�N�g��Hierarchy�ɓo�^���āA��������
// �߂�l�Ƃ��ẮA�o�^�����Q�[���I�u�W�F�N�g
std::shared_ptr<GameObject> GameObject::instantiate(std::shared_ptr<EntityHierarchy> gameObject)
{
	Hierarchy::registerHierachy(gameObject);
	auto object = Hierarchy::find(gameObject->getName());
	return object;
}


// �`�揇��ݒ�
void GameObject::setSortingLayer(SortingLayer sortingLayer)
{
	this->sortingLayer = sortingLayer;
	Hierarchy::sortingLayerSort();
}
