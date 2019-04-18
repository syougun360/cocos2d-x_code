// ----------------------------------------------
// Hierarchy(�K�w)
// 
// �o�^�E�폜�E�S�폜
// �K�w�̎��Ԏ擾
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

		// �o�^
		static void registerHierachy(std::shared_ptr<EntityHierarchy> entity);
		static void registerHierachy(std::shared_ptr<EntityHierarchy> entity, std::shared_ptr<EntityHierarchy> parent);

		// �폜
		static void deregistration(const std::string& name);

		// �S�폜
		static void clear();

		void update();

		// ���O�ŒT��
		static std::shared_ptr<EntityHierarchy> find(const std::string& name);

		// Tag�ł̃Q�[���I�u�W�F�N�g���擾
		static std::shared_ptr<EntityHierarchy> findWithTag(const Tags tag);

		// Tag�ł̃Q�[���I�u�W�F�N�g��z��Ŏ擾
		static std::vector<std::shared_ptr<EntityHierarchy>> findGameObjectsWithTag(const Tags tag);

		// ���O�ŒT��
		template<typename Type>
		static std::shared_ptr<Type> find(const std::string& name)
		{
			auto findObject = hierarchyList.find(name);
			if (findObject == hierarchyList.end()) return nullptr;

			return std::dynamic_pointer_cast<Type>(findObject->second);
		}

		// �z����擾
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

		// Tag�ł̃Q�[���I�u�W�F�N�g���擾
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

		// Tag�ł̃Q�[���I�u�W�F�N�g��z��Ŏ擾
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

		// �`�揇�̃\�[�g
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