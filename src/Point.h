#pragma once
#include "GraphicNode.h"

namespace game
{
	class Point :public GraphicNode
	{
	public:
		Point(NodePtr node, const Color4F& color = Color4F::WHITE);

	private:
		// 描画
		// 座標・半径・色
		void draw(const Vec2& pos, const float radius, const Color4F& color = Color4F::WHITE);
	};

}