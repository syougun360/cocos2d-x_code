#include "GameManager.h"
#include "Application.h"
#include "Label.h"
#include "Screen.h"

namespace game
{

	bool GameManager::init()
	{
		if (!Layer::init())
		{
			return false;
		}

		auto label = std::make_unique<Label>(this, "Game Manager", FontAssets::getFont(Resources::FontID::MarkerFelt), 60);

		cocos2d::Size visibleSize = Screen::getVisibleSize();
		cocos2d::Vec2 origin = Screen::getVisibleOriginPosition();

		label->setTransform(Transform(Vec2(origin.x + visibleSize.width / 2,
			origin.y + visibleSize.height - label->getContentSize().y)));

		return true;
	}


	void GameManager::update(float delta)
	{

	}

}