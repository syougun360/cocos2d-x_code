#include "Sprite.h"

namespace game
{

	Sprite::Sprite(NodePtr node, cocos2d::Texture2D* texture, const Rect& partRect) :
		sprite(cocos2d::Sprite::createWithTexture(texture))
	{
		sprite->setTextureRect(partRect);
		sprite->getTexture()->setAntiAliasTexParameters();
		node->addChild(sprite);
	}
	
	Sprite::Sprite(NodePtr node, cocos2d::Texture2D* texture) :
		sprite(cocos2d::Sprite::createWithTexture(texture))
	{
		sprite->getTexture()->setAntiAliasTexParameters();
		node->addChild(sprite);
	}

	Sprite::Sprite(NodePtr node, const Rect& partRect, const Color3& color) :
		sprite(cocos2d::Sprite::create())
	{
		sprite->setTextureRect(partRect);
		sprite->setColor(color);
		node->addChild(sprite);
	}
	
	void Sprite::setTransform(const Transform& transform)
	{
		sprite->setPosition(transform.getPos());
		sprite->setScale(transform.getSize().x, transform.getSize().y);
		sprite->setRotation(transform.getRotation());
	}

	void Sprite::setFlip(bool x, bool y)
	{
		sprite->setFlippedX(x);
		sprite->setFlippedY(y);
	}

	void Sprite::setVisible(const bool isVisible)
	{
		sprite->setVisible(isVisible);
	}

	bool Sprite::isVisible()const
	{
		return sprite->isVisible();
	}

	void Sprite::setOpacity(const unsigned int opacity)
	{
		sprite->setOpacity(opacity);
	}


}