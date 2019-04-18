#pragma once
#pragma execution_character_set("utf-8")

#include "Resources.h"
#include "using.h"
#include "Transform.h"

namespace game
{
	class Label
	{
	public:
		Label(NodePtr node,const std::string& string, const std::string& assetName, const int fontSize);
		Label(NodePtr node, const std::string& string, const int fontSize);

		// �폜����B
		void destroy(NodePtr node){ node->removeChild(label); }

		void setTransform(const Transform& transform);

		// �������ݒ�
		void setString(const std::string& string);

		// �F��ݒ�
		void setColor(const Color4& color);

		// �m�[�h���擾
		NodePtr getNode()const{ return label; }
		
		Vec2 getContentSize()const;
	private:
		cocos2d::Label* label;
	};

};