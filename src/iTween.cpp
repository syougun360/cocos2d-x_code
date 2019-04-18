#include "iTween.h"


namespace game
{
	ActionPtr iTween::MoveTo(NodePtr node,const Vec2& pos, const float time)
	{
		return node->runAction(cocos2d::MoveTo::create(time, pos));
	}

	ActionPtr iTween::MoveBy(NodePtr node, const Vec2& pos, const float time)
	{
		return node->runAction(cocos2d::MoveBy::create(time, pos));
	}

	ActionPtr iTween::ScaleTo(NodePtr node, const Vec2& scale, const float time)
	{
		return node->runAction(cocos2d::ScaleTo::create(time, scale.x, scale.y));
	}

	ActionPtr iTween::ScaleBy(NodePtr node, const Vec2& scale, const float time)
	{
		return node->runAction(cocos2d::ScaleBy::create(time, scale.x, scale.y));
	}

	ActionPtr iTween::RotateTo(NodePtr node, const float rotate, const float time)
	{
		return node->runAction(cocos2d::RotateTo::create(time, rotate));
	}

	ActionPtr iTween::RotateBy(NodePtr node, const float rotate, const float time)
	{
		return node->runAction(cocos2d::RotateBy::create(time, rotate));
	}

	void iTween::Stop(NodePtr node, ActionPtr action)
	{
		node->stopAction(action);
	}

	void iTween::Stop(NodePtr node)
	{
		node->stopAllActions();
	}

}