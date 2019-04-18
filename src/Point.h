#pragma once
#include "GraphicNode.h"

namespace game
{
	class Point :public GraphicNode
	{
	public:
		Point(NodePtr node, const Color4F& color = Color4F::WHITE);

	private:
		// �`��
		// ���W�E���a�E�F
		void draw(const Vec2& pos, const float radius, const Color4F& color = Color4F::WHITE);
	};

}