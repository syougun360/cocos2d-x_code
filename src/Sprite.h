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

		// 削除する。
		void destroy(NodePtr node){ node->removeChild(sprite); }

		// 移動・スケール・回転
		void setTransform(const Transform& transform);

		void setFlip(bool x, bool y);

		// 表示・非表示の設定
		void setVisible(const bool isVisible);

		// 透明度を設定
		// 0 ～ 255
		void setOpacity(const unsigned int opacity);

		// Rect型を返します。
		Rect getBoundingBox()const{ return sprite->getBoundingBox(); }

		// 表示されているかどうか
		bool isVisible()const;

		// ノードの情報を取得
		NodePtr GetNode()const{ return sprite; }
	private:
		cocos2d::Sprite* sprite;
	};

};