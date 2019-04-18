#pragma once
#include "IScene.h"
#include "Transform.h"
#include "Hierarchy.h"

namespace game
{
	class TitleManager :public IScene
	{
	public:
		TitleManager() = default;

		bool init();

		CREATE_FUNC(TitleManager);

		void update(float delta);

	private:
		std::unique_ptr<Hierarchy> hierarchy;
	};

}