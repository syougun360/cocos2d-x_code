#pragma once
#include <string>

namespace game
{
	class Debug
	{
	public:
		static void Log(const std::string& string);
		static void LogError(const std::string& string);

	};

};

