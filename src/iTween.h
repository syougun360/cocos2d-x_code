#pragma once
#include "using.h"

namespace game
{
	class iTween
	{
	public:

		// 指定した場所に移動
		static ActionPtr MoveTo(NodePtr node, const Vec2& pos, const float time);
		
		// 指定した方向に移動
		static ActionPtr MoveBy(NodePtr node, const Vec2& pos, const float time);
		
		// 指定した大きさにスケーリング
		static ActionPtr ScaleTo(NodePtr node, const Vec2& scale, const float time);
		
		// 指定した大きさの距離をスケーリング
		static ActionPtr ScaleBy(NodePtr node, const Vec2& scale, const float time);
		
		// 指定した回転量に回転
		static ActionPtr RotateTo(NodePtr node, const float rotate, const float time);
		
		// 指定した回転量の大きさを回転
		static ActionPtr RotateBy(NodePtr node, const float rotate, const float time);

		// 停止
		static void Stop(NodePtr node, ActionPtr action);
		static void Stop(NodePtr node);

	};

}