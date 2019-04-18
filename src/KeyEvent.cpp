#include "KeyEvent.h"
#include "Application.h"

namespace game
{

	std::map<KeyCode, bool> KeyEvent::pushState;
	std::map<KeyCode, bool> KeyEvent::pullState;


	bool KeyEvent::init()
	{
		if (!Layer::init())
		{
			return false;
		}

		auto listener = cocos2d::EventListenerKeyboard::create();
		listener->onKeyPressed = CC_CALLBACK_2(KeyEvent::onKeyPressed, this);
		listener->onKeyReleased = CC_CALLBACK_2(KeyEvent::onKeyReleased, this);

		Application::getDirectorInstance()->
			getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);

		return true;
	}

	void KeyEvent::onKeyPressed(KeyCode keyCode, cocos2d::Event* event)
	{
		PressEvent(keyCode);
	}

	void KeyEvent::onKeyReleased(KeyCode keyCode, cocos2d::Event* event)
	{
		ReleaseEvent(keyCode);
	}

	// キーが押した瞬間を調べる
	bool KeyEvent::isClick(const KeyCode event)
	{
		auto it = pushState.find(event);
		if (it != pushState.end())
		{
			pushState.erase(event);
			return true;
		}

		return false;
	}

	// キーを押しているかを調べる
	bool KeyEvent::isPress(const KeyCode event)
	{
		auto it = pushState.find(event);
		if (it != pushState.end())
		{
			return true;
		}

		return false;
	}

	// キーが離した瞬間を調べる
	bool KeyEvent::isRelease(const KeyCode event)
	{
		auto it = pullState.find(event);
		if (it != pullState.end())
		{
			return true;
		}

		return false;
	}

	//　押している
	void KeyEvent::PressEvent(const KeyCode event)
	{
		pushState.insert(std::make_pair(event, true));
		pullState.erase(event);
	}

	//　離しているとき
	void KeyEvent::ReleaseEvent(const KeyCode event)
	{
		pullState.insert(std::make_pair(event, true));
		pushState.erase(event);
	}


}