// ----------------------------------------------
// コンポーネント
// 
// 追加、削除、取得、親の取得ができる
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

		// 追加
		void addComponent(std::shared_ptr<EntityBehavior> gameObject);

		// 削除
		void destroy();

		// 名前で削除
		void destroy(const std::string &name);

		// 親を取得
		std::shared_ptr<Component> getComponentInParent()const;

		// 取得
		template<typename Type>
		std::shared_ptr<Type> getComponent(const std::string& name)
		{
			auto findObject = childrenList.find(name);
			if (findObject == childrenList.end()) return nullptr;

			return std::dynamic_pointer_cast<Type>(findObject->second);
		}

		// 配列を取得
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

		// 取得
		template<typename Type>
		std::shared_ptr<Type> getComponent()
		{
			return std::dynamic_pointer_cast<Type>(gameObject);
		}

		// 取得
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