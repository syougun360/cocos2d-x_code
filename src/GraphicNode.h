#pragma once
#include "using.h"
#include "Transform.h"

namespace game
{

	class GraphicNode
	{
	public:
		GraphicNode(NodePtr node) :
			drawNode(cocos2d::DrawNode::create())
		{
			node->addChild(drawNode);
		}

		// 削除する。
		void destroy(NodePtr node){ node->removeChild(drawNode); }

		// RECT型を返す
		Rect getBoundingBox()const{ return drawNode->getBoundingBox(); }

		// 座標・スケール・回転を設定
		void setTransform(const Transform& transform)
		{
			drawNode->setPosition(transform.getPos());
			drawNode->setScale(transform.getSize().x, transform.getSize().y);
			drawNode->setRotation(transform.getRotation());
		}

	protected:
		DrawNodePtr drawNode;

	};

}