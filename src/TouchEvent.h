#pragma once
#include "using.h"

namespace game
{
	class TouchEvent:public cocos2d::Layer
	{
	public:
		TouchEvent() = default;
		~TouchEvent() = default;

		enum class State
		{
			None,
			Begin,
			Press,
			Move,
			End,
		};

		bool init();

		CREATE_FUNC(TouchEvent);
		
		void update(float delta);
		
		// ���������W
		static Vec2 getPosition(){ return position; }

		// �^�b�`��������Ă��Ȃ���
		static bool isNone(){ return state == State::None; }

		// �^�b�`�������ꂽ�u��
		static bool isBegin(){ return state == State::Begin; }

		// �^�b�`�������̏ꏊ�ŉ�����Ă���Ƃ�
		static bool isPress(){ return state == State::Press; }

		// �^�b�`���ړ����̎�
		static bool isMove(){ return state == State::Move; }
		
		// �^�b�`�����ꂽ�u��
		static bool isEnd(){ return state == State::End; }

	private:
		//�^�b�`�J�n
		bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

		// �^�b�`���ړ������ꍇ
		void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

		// �^�b�`���I�������ꍇ
		void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

		// �^�b�`���������L�����Z�������ꍇ
		void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

		static State state;
		static Vec2 position;
	};

};