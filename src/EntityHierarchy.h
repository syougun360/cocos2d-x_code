// ----------------------------------------------
// 実態の階層
// 
// 階層に入るクラスに継承するもの
// アクティブ・非アクティブを設定できる
//
// ----------------------------------------------

#pragma once
#include <memory>
#include "Component.h"
#include "Hierarchy.h"

namespace game
{
	class Releaser;
	class Hierarchy;

	class EntityHierarchy :public Component
	{
	public:
		EntityHierarchy(NodePtr node,const std::string& name, const Transform& transform);
		EntityHierarchy(NodePtr node, const std::string& name, const Tags tag);
		EntityHierarchy(NodePtr node, const std::string& name, const SortingLayer sortingLayer);
		EntityHierarchy(NodePtr node, const std::string& name, const Tags tag, const SortingLayer sortingLayer);

		// 描画
		void updatable();

		// 親取得
		std::shared_ptr<EntityHierarchy> getEntityParent()
		{
			return parent;
		}

		// 親を設定
		void setEntityParent(std::shared_ptr<EntityHierarchy> entityHierarchy);

	protected:
		
		// 子オブジェクトを追加
		void addChild(std::shared_ptr<EntityHierarchy> entityHierarchy);

		// 子オブジェクトを削除
		void destroyChild(std::shared_ptr<EntityHierarchy> entityHierarchy);

		// Startの前に処理が実行させる
		virtual void awake(){}

		// Updateの前に処理が実行させる
		virtual void start(){}

		// アップデート
		virtual void update(){}

		// アクティブ・非アクティブ
		void setActive(bool isActive);

		// アクティブを取得
		bool isActive()const{ return active; }
		
	private:
		std::shared_ptr<EntityHierarchy> parent;

		enum class UpdateState
		{
			Awake,
			Start,
			Update,
		};
		NodePtr node;
		UpdateState state;
		bool active;
	};

	using EntityHierarchyPtr = std::shared_ptr < EntityHierarchy > ;
};