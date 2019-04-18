#include "TouchesEvent.h"
#include "Application.h"

namespace game
{
	std::vector<std::shared_ptr<TouchEvent>> TouchesEvent::touches;

	bool TouchesEvent::init()
	{
		if (!Layer::init())
		{
			return false;
		}
		auto listener = cocos2d::EventListenerTouchAllAtOnce::create();
		listener->onTouchesBegan = CC_CALLBACK_2(TouchesEvent::onTouchesBegan, this);

		Application::getDirectorInstance()->
			getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

		return true;
	}

	void TouchesEvent::onTouchesBegan(const std::vector<cocos2d::Touch*>& touches, cocos2d::Event *event)
	{
		this->touches.push_back(std::make_shared<TouchEvent>());
	}

	void TouchesEvent::update(float delta)
	{
		for (auto& touch : touches)
		{
			touch->update(delta);
		}

		auto it = std::remove_if(touches.begin(), touches.end(), [](std::shared_ptr<TouchEvent> &touch)
		{
			return touch->isNone();
		});

		touches.erase(it, touches.end());
	}

};