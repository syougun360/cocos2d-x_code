#include "TouchEvent.h"
#include "Application.h"

namespace game
{
	TouchEvent::State TouchEvent::state = TouchEvent::State::None;
	Vec2 TouchEvent::position = Vec2::ZERO;

	bool TouchEvent::init()
	{
		if (!Layer::init())
		{
			return false;
		}

		auto listener = cocos2d::EventListenerTouchOneByOne::create();
		listener->onTouchBegan = CC_CALLBACK_2(TouchEvent::onTouchBegan, this);
		listener->onTouchMoved = CC_CALLBACK_2(TouchEvent::onTouchMoved, this);
		listener->onTouchEnded = CC_CALLBACK_2(TouchEvent::onTouchEnded, this);
		listener->onTouchCancelled = CC_CALLBACK_2(TouchEvent::onTouchCancelled, this);

		Application::getDirectorInstance()->
			getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

		return true;
	}


	//タッチ開始
	bool TouchEvent::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
	{
		position = touch->getLocation();
		state = State::Begin;
		return true;
	}

	// タッチが移動した場合
	void TouchEvent::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
	{
		position = touch->getLocation();
		state = State::Move;
	}

	// タッチが終了した場合
	void TouchEvent::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
	{
		position = touch->getLocation();
		state = State::End;
	}

	// タッチが処理がキャンセルした場合
	void TouchEvent::onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event)
	{
		state = State::None;
	}

	void TouchEvent::update(float delta)
	{
		if (state == State::Begin) state = State::Press;
		if (state == State::End) state = State::None;
		
	}

}