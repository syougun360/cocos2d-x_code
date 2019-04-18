// ----------------------------------------------
// �R���|�[�l���g
// 
// �ǉ��A�폜�A�擾�A�e�̎擾���ł���
// 
// ----------------------------------------------

#pragma once
#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include "GameObject.h"


namespace game
{
	class EntityBehavior;

	class Component :public GameObject
	{
	public:
		Component(const std::string &name);
		Component(const std::string &name,const Transform& transform);
		Component(const std::string &name, Tags tag);
		Component(const std::string &name, SortingLayer sortingLayer);
		Component(const std::string &name, Tags tag, SortingLayer sortingLayer);
		Component(const std::string &name, const std::string& parentName);
		Component();

		// �ǉ�
		void addComponent(std::shared_ptr<EntityBehavior> gameObject);

		// �폜
		void destroy();

		// ���O�ō폜
		void destroy(const std::string &name);

		// �e���擾
		std::shared_ptr<Component> getComponentInParent()const;

		// �擾
		template<typename Type>
		std::shared_ptr<Type> getComponent(const std::string& name)
		{
			auto findObject = childrenList.find(name);
			if (findObject == childrenList.end()) return nullptr;

			return std::dynamic_pointer_cast<Type>(findObject->second);
		}

		// �z����擾
		template<typename Type>
		std::vector<std::shared_ptr<Type>> getComponents(const std::string& name)
		{
			auto findObjects = childrenList.equal_range(name);
			std::vector<std::shared_ptr<Type>> components;

			components.clear();

			for (auto iterator = findObjects.first; iterator != findObjects.second; iterator++)
			{
				auto target = *iterator;
				components.push_back(std::dynamic_pointer_cast<Type>(target.second));
			}

			return components;
		}

		// �擾
		template<typename Type>
		std::shared_ptr<Type> getComponent()
		{
			return std::dynamic_pointer_cast<Type>(gameObject);
		}

		// �擾
		std::shared_ptr<GameObject> getGameObject()
		{
			return gameObject;
		}

	protected:
		void componentsAwake();
		void componentsStart();
		void componentsUpdate();

	private:
		std::unordered_multimap<std::string, std::shared_ptr<EntityBehavior>> childrenList;
		std::shared_ptr<GameObject> gameObject;
		std::string parentName;

	};

};