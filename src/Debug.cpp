#include "Debug.h"
#include "cocos2d.h"

namespace game
{
	void Debug::Log(const std::string& string)
	{
		CCLOG(string.c_str());
	}

	void Debug::LogError(const std::string& string)
	{
		CCLOGERROR(string.c_str());
	}

};