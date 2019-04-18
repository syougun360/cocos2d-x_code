#pragma once

#include "cocos2d.h"

namespace game
{
	class IScene :public cocos2d::Layer
	{
	public:
		IScene() = default;
		virtual ~IScene() = default;
		static cocos2d::Scene* createScene(){ return nullptr; }
		virtual void update(float delta) = 0;

	private:
	};

}