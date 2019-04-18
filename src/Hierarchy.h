// ----------------------------------------------
// Hierarchy(階層)
// 
// 登録・削除・全削除
// 階層の実態取得
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include "EntityHierarchy.h"

namespace game
{
	class EntityHierarchy;
	class Component;

	class Hierarchy:public cocos2d::Layer
	{
	public:

		// 登録
		static void registerHierachy(std::shared_ptr<EntityHierarchy> entity);
		static void registerHierachy(std::shared_ptr<EntityHierarchy> entity, std::shared_ptr<EntityHierarchy> parent);

		// 削除
		static void deregistration(const std::string& name);

		// 全削除
		static void clear();

		void update();

		// 名前で探す
		static std::shared_ptr<EntityHierarchy> find(const std::string& name);

		// Tagでのゲームオブジェクトを取得
		static std::shared_ptr<EntityHierarchy> findWithTag(const Tags tag);

		// Tagでのゲームオブジェクトを配列で取得
		static std::vector<std::shared_ptr<EntityHierarchy>> findGameObjectsWithTag(const Tags tag);

		// 名前で探す
		template<typename Type>
		static std::shared_ptr<Type> find(const std::string& name)
		{
			auto findObject = hierarchyList.find(name);
			if (findObject == hierarchyList.end()) return nullptr;

			return std::dynamic_pointer_cast<Type>(findObject->second);
		}

		// 配列を取得
		template<typename Type>
		static std::vector<std::shared_ptr<Type>> findGameObjects(const std::string& name)
		{
			auto findObjects = hierarchyList.equal_range(name);
			std::vector<std::shared_ptr<Type>> components;

			components.clear();

			for (auto iterator = findObjects.first; iterator != findObjects.second; iterator++)
			{
				auto target = *iterator;
				components.push_back(std::dynamic_pointer_cast<Type>(target.second));
			}

			return components;

		}

		// Tagでのゲームオブジェクトを取得
		template<typename Type>
		static std::shared_ptr<Type> findWithTag(const Tags tag)
		{
			for (auto& hierarchy : hierarchyList)
			{
				if (hierarchy.second->Tag() != tag) continue;

				auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

				return tagObject;
			}
		}

		// Tagでのゲームオブジェクトを配列で取得
		template<typename Type>
		static std::vector<std::shared_ptr<Type>> findGameObjectsWithTag(const Tags tag)
		{
			std::vector<std::shared_ptr<Type>> gameObjects;

			for (auto& hierarchy : hierarchyList)
			{
				if (hierarchy.second->Tag() != tag) continue;

				auto tagObject = std::dynamic_pointer_cast<Type>(hierarchy->second);

				gameObjects.push_back(tagObject);
			}

			return gameObjects;
		}

		// 描画順のソート
		static void sortingLayerSort();

	private:
		enum class UpdateState
		{
			Awake,
			Start,
			Update,
		};
		UpdateState state;

		static std::unordered_multimap<std::string, std::shared_ptr<EntityHierarchy>> hierarchyList;

	};
};