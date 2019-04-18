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

		// ������
		bool init();

		CREATE_FUNC(SceneManager);
		
		// �V�[����؂�ւ���
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

		// �V�[���ǉ�
		void addScene(IScene *scene);

		// �V�[�����폜����B
		void removeScene(IScene *scene);
		static IScene *nowScene;
		static SceneManager *instance;
		static Color4 backGroundColor;
		
		bool isChanged;
	};

}