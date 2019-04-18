#pragma once
#include "GraphicNode.h"

namespace game
{
	class Box :public GraphicNode
	{
	public:
		Box(NodePtr node, const Color4F& color = Color4F::WHITE);
		Box(NodePtr node, const float borderWidth, const Color4F& color = Color4F::WHITE, const Color4F& colorBorder = Color4F::WHITE);
	
	private:
		void draw(const Vec2& pos, const Vec2& size, const Color4F& color);
		void drawBorder(const Vec2& pos, const Vec2& size, const float borderWidth,
			const Color4F& color, const Color4F& colorBorder);
	};
};