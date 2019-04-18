#include "Point.h"

namespace game
{
	Point::Point(NodePtr node, const Color4F& color) :
		GraphicNode(node)
	{
		draw(Vec2(0,0),1,color);
	}

	void Point::draw(const Vec2& pos, const float radius, const Color4F& color)
	{
		drawNode->drawDot(pos, radius, color);
	}

}