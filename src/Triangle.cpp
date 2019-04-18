#include "Triangle.h"


namespace game
{
	Triangle::Triangle(NodePtr node, 
		const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const Color4F& color):
		GraphicNode(node)
	{
		draw(pos1,pos2,pos3,color);
	}

	void Triangle::draw(const Vec2& pos1, const Vec2& pos2, const Vec2& pos3, const Color4F& color)
	{
		drawNode->drawTriangle(pos1, pos2, pos3, color);
	}

}