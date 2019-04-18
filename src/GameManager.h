#pragma once
#include "IScene.h"

namespace game
{
	class GameManager:public IScene
	{
	public:
		GameManager() = default;

		bool init();

		CREATE_FUNC(GameManager);

		void update(float delta);

	private:

	};

}