#pragma once
#include <random>
#include <assert.h>


namespace game
{
	class Random
	{
	public:
		static int Range(const int begin, const int end);
		static float Range(const float begin, const float end);
		static double Range(const double begin, const double end);

	private:
		static std::random_device rd;;
		static std::mt19937 mt;
	};
};
