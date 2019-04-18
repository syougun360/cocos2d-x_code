#include "Box.h"
#include <array>

namespace game
{
	Box::Box(NodePtr node, const Color4F& color) :
		GraphicNode(node)
	{
		draw(Vec2(0, 0), Vec2(1, 1), color);
	}

	Box::Box(NodePtr node, const float borderWidth, const Color4F& color, const Color4F& colorBorder) :
		GraphicNode(node)
	{
		drawBorder(Vec2(0, 0), Vec2(1, 1), borderWidth, color, colorBorder);
	}
	

	void Box::draw(const Vec2& pos, const Vec2& size, const Color4F& color)
	{
		std::array<Vec2, 4> vertexes = {
			Vec2(pos.x, pos.y),
			Vec2(pos.x + size.x, pos.y),
			Vec2(pos.x + size.x, pos.y + size.y),
			Vec2(pos.x, pos.y + size.y),
		};

		drawNode->drawPolygon(vertexes.data(), vertexes.size(), color, 0, color);
	}


	void Box::drawBorder(const Vec2& pos, const Vec2& size, const float borderWidth, const Color4F& color, const Color4F& colorBorder)
	{
		std::array<Vec2, 4> vertexes = {
			Vec2(pos.x, pos.y),
			Vec2(pos.x + size.x, pos.y),
			Vec2(pos.x + size.x, pos.y + size.y),
			Vec2(pos.x, pos.y + size.y),
		};

		drawNode->drawPolygon(vertexes.data(), vertexes.size(), color, borderWidth, colorBorder);

	}

}
