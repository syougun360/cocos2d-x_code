#pragma once
#include "GraphicNode.h"

namespace game
{
	class Triangle:public GraphicNode
	{
	public:
		Triangle(NodePtr node, const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const Color4F& color = Color4F::WHITE);
	
	private:
		void draw(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const Color4F& color = Color4F::WHITE);
	};
};