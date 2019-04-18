#pragma once
#include <memory>
#include "using.h"
#include "Transform.h"

namespace game
{
	class Sprite
	{
	public:
		Sprite(NodePtr node, cocos2d::Texture2D* texture,const Rect& partRect);
		Sprite(NodePtr node, cocos2d::Texture2D* texture);
		Sprite(NodePtr node, const Rect& partRect, const Color3& color = Color3::WHITE);

		// �폜����B
		void destroy(NodePtr node){ node->removeChild(sprite); }

		// �ړ��E�X�P�[���E��]
		void setTransform(const Transform& transform);

		void setFlip(bool x, bool y);

		// �\���E��\���̐ݒ�
		void setVisible(const bool isVisible);

		// �����x��ݒ�
		// 0 �` 255
		void setOpacity(const unsigned int opacity);

		// Rect�^��Ԃ��܂��B
		Rect getBoundingBox()const{ return sprite->getBoundingBox(); }

		// �\������Ă��邩�ǂ���
		bool isVisible()const;

		// �m�[�h�̏����擾
		NodePtr GetNode()const{ return sprite; }
	private:
		cocos2d::Sprite* sprite;
	};

};