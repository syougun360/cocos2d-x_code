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

		// �폜����B
		void destroy(NodePtr node){ node->removeChild(drawNode); }

		// RECT�^��Ԃ�
		Rect getBoundingBox()const{ return drawNode->getBoundingBox(); }

		// ���W�E�X�P�[���E��]��ݒ�
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