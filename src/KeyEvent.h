#pragma once
#include "using.h"

namespace game
{

	class KeyEvent: public cocos2d::Layer
	{
	public:
		bool init();

		CREATE_FUNC(KeyEvent);

		// �L�[���������u�Ԃ𒲂ׂ�
		static bool isClick(const KeyCode event);

		// �L�[�������Ă��邩�𒲂ׂ�
		static bool isPress(const KeyCode event);

		// �L�[���������u�Ԃ𒲂ׂ�
		static bool isRelease(const KeyCode event);

	private:
		//�@�����Ă���
		void PressEvent(const KeyCode event);

		//�@�����Ă���Ƃ�
		void ReleaseEvent(const KeyCode event);

		static std::map<KeyCode, bool> pushState;
		static std::map<KeyCode, bool> pullState;

		void onKeyPressed(KeyCode keyCode, cocos2d::Event* event);
		void onKeyReleased(KeyCode keyCode, cocos2d::Event* event);

	};

};