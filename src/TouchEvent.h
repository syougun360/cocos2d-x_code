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
		
		// 押した座標
		static Vec2 getPosition(){ return position; }

		// タッチが押されていない時
		static bool isNone(){ return state == State::None; }

		// タッチが押された瞬間
		static bool isBegin(){ return state == State::Begin; }

		// タッチがそこの場所で押されているとき
		static bool isPress(){ return state == State::Press; }

		// タッチが移動中の時
		static bool isMove(){ return state == State::Move; }
		
		// タッチが離れた瞬間
		static bool isEnd(){ return state == State::End; }

	private:
		//タッチ開始
		bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

		// タッチが移動した場合
		void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

		// タッチが終了した場合
		void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

		// タッチが処理がキャンセルした場合
		void onTouchCancelled(cocos2d::Touch* touch, cocos2d::Event* event);

		static State state;
		static Vec2 position;
	};

};