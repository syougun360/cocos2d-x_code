#pragma once
#include "cocos2d.h"

namespace game
{
	class Object :public cocos2d::Node
	{
	public:
		Object(const std::string &name);
		Object();
		virtual ~Object() = default;


	private:

	};
}

