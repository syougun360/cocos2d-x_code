#pragma once
#include "GraphicNode.h"

namespace game
{
	class Line :public GraphicNode
	{
	public:
		Line(NodePtr node, const Vec2& beginPos, const Vec2& endPos, const Color4F& color = Color4F::WHITE);
		Line(NodePtr node, const Vec2& beginPos, const Vec2& endPos, const float weight, const Color4F& color = Color4F::WHITE);

	private:
		void draw(const Vec2& beginPos, const Vec2& endPos,const float weight, const Color4F& color);
	};

};