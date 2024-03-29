// ----------------------------------------------
// GameObject
// 
// オブジェクトのデータ
// 
// ----------------------------------------------

#pragma once
#include <string>
#include <memory>
#include <unordered_map>
#include "Tag.h"
#include "Layer.h"
#include "Object.h"
#include "Transform.h"


namespace game
{
	class Component;
	class EntityHierarchy;

	class GameObject :public Object
	{
	public:
		GameObject(const std::string &name);
		GameObject(const std::string &name, Tags tag);
		GameObject(const std::string &name, Tags tag, SortingLayer sortingLayer);
		GameObject(const std::string &name, SortingLayer sortingLayer);
		GameObject(const std::string &name,const Transform& transform);
		GameObject();
		
		SortingLayer getSortingLayer()const
		{
			return sortingLayer;
		}

		// 描画順を設定
		void setSortingLayer(SortingLayer sortingLayer);

		// ゲームオブジェクトをHierarchyに登録して、生成する
		// 戻り値としては、登録したゲームオブジェクト
		static std::shared_ptr<GameObject> instantiate(std::shared_ptr<EntityHierarchy> gameObject);

	protected:
		Transform transform;

	private:
		SortingLayer sortingLayer; // 描画順レイヤー

	};

}