#include "Random.h"

namespace game
{

	std::random_device Random::rd;
	std::mt19937 Random::mt(rd());

	int Random::Range(const int begin, const int end)
	{
		assert(begin < end);
		std::uniform_int_distribution<int> random(begin, end);

		return random(mt);
	}

	double Random::Range(const double begin, const double end)
	{
		assert(begin < end);
		std::uniform_real_distribution<double> random(begin, end);

		return random(mt);
	}

	float Random::Range(const float begin, const float end)
	{
		assert(begin < end);
		std::uniform_real_distribution<float> random(begin, end);

		return random(mt);
	}
}