#pragma once
#include "using.h"

namespace game
{

	class KeyEvent: public cocos2d::Layer
	{
	public:
		bool init();

		CREATE_FUNC(KeyEvent);

		// キーが押した瞬間を調べる
		static bool isClick(const KeyCode event);

		// キーを押しているかを調べる
		static bool isPress(const KeyCode event);

		// キーが離した瞬間を調べる
		static bool isRelease(const KeyCode event);

	private:
		//　押している
		void PressEvent(const KeyCode event);

		//　離しているとき
		void ReleaseEvent(const KeyCode event);

		static std::map<KeyCode, bool> pushState;
		static std::map<KeyCode, bool> pullState;

		void onKeyPressed(KeyCode keyCode, cocos2d::Event* event);
		void onKeyReleased(KeyCode keyCode, cocos2d::Event* event);

	};

};