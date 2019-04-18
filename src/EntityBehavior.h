// ----------------------------------------------
// 実態の挙動
// 
// 処理系
// 可能 or 不可能 が設定できる
// 
// ----------------------------------------------

#pragma once
#include <memory>
#include <string>
#include "Component.h"

namespace game
{
	class EntityBehavior :public Component
	{
	public:
		EntityBehavior(const std::string& name);
		EntityBehavior(const std::string& name, const std::string& parentName);

		// Startの前に処理が実行させる
		// 1度のみ実行
		virtual void awake(){}

		// Updateの前に処理が実行させる
		// 1度のみ実行
		virtual void start(){}

		// アップデート
		virtual void update(){}

		// 実行可能・不可能にする
		void setEnable(bool isEnable);

		// 実行可能かどうかを取得
		bool isEnable()const{ return enable; }

	protected:

	private:
		bool enable;

	};
}