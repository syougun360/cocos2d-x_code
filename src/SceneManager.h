#pragma once
#include <unordered_map>
#include "using.h"

namespace game
{
	class IScene;

	class SceneManager : public cocos2d::LayerColor
	{
	public:
		SceneManager() = default;

		static SceneManager* getInstance()
		{
			return instance;
		}

		static cocos2d::Scene* createScene();

		// 初期化
		bool init();

		CREATE_FUNC(SceneManager);
		
		// シーンを切り替える
		template<typename Type>
		void changeScene()
		{
			removeScene(nowScene);

			auto scene = Type::create();
			addScene(scene);

			isChanged = true;
		}

		void update(float delta);

	private:
		void addEvent();

		// シーン追加
		void addScene(IScene *scene);

		// シーンを削除する。
		void removeScene(IScene *scene);
		static IScene *nowScene;
		static SceneManager *instance;
		static Color4 backGroundColor;
		
		bool isChanged;
	};

}