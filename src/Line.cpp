#include "Line.h"

namespace game
{
	Line::Line(NodePtr node, const Vec2& beginPos, const Vec2& endPos, const Color4F& color ):
		GraphicNode(node)
	{
		draw(beginPos, endPos,1, color);
	}

	Line::Line(NodePtr node, const Vec2& beginPos, const Vec2& endPos,
		const float weight, const Color4F& color) :
		GraphicNode(node)
	{
		draw(beginPos, endPos, weight,color);
	}


	void Line::draw(const Vec2& beginPos, const Vec2& endPos, float weight, const Color4F& color)
	{
		drawNode->drawSegment(beginPos, endPos, weight, Color4F::RED);
	}

}