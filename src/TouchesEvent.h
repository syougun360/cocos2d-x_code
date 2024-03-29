#pragma once
#include "using.h"
#include "TouchEvent.h"

namespace game
{
	
	class TouchesEvent :public cocos2d::Layer
	{
	public:
		bool init();

		CREATE_FUNC(TouchesEvent);

		void update(float delta);

		// タッチの数
		static int touchCount(){ return touches.size(); }

		// 複数のTouchEventを取得
		static std::vector<std::shared_ptr<TouchEvent>> getTouches(){ return touches; }

	private:
		void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
		static std::vector<std::shared_ptr<TouchEvent>> touches;

	};

};