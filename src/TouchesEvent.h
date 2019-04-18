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

		// ƒ^ƒbƒ`‚Ì”
		static int touchCount(){ return touches.size(); }

		// •¡”‚ÌTouchEvent‚ğæ“¾
		static std::vector<std::shared_ptr<TouchEvent>> getTouches(){ return touches; }

	private:
		void onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event);
		static std::vector<std::shared_ptr<TouchEvent>> touches;

	};

};