#include "Label.h"

namespace game
{
	Label::Label(NodePtr node, const std::string& string, const std::string& assetName, const int fontSize)
	{
		label = cocos2d::Label::createWithSystemFont(string, assetName, fontSize);

		node->addChild(label, 1);
	}

	Label::Label(NodePtr node, const std::string& string, const int fontSize)
	{
		label = cocos2d::Label::createWithSystemFont(string, FontAssets::getFont(Resources::FontID::Arial), fontSize);

		node->addChild(label, 1);
	}

	void Label::setTransform(const Transform& transform)
	{
		label->setPosition(transform.getPos());
		label->setScale(transform.getScale());
		label->setRotation(transform.getRotation());
	}

	void Label::setString(const std::string& string)
	{
		label->setString(string);
	}

	void Label::setColor(const Color4& color)
	{
		label->setTextColor(color);
	}

	Vec2 Label::getContentSize()const
	{
		return Vec2(label->getContentSize().width, label->getContentSize().height);
	}

};