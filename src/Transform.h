// -------------------------------------------
// Transform
//
// 座標・回転・スケール
// 
// code by yamada masamitsu
// -------------------------------------------

#pragma once
#include "using.h"

namespace game
{
	class Transform
	{
	public:
		Transform(const Vec2& pos, const Vec2& size, const float rotation);
		Transform(const Vec2& pos, const float scale, const  float rotation);
		Transform(const Vec2& pos, const Vec2& size);
		Transform(const Vec2& pos, const float scale);
		Transform(const Vec2& pos);
		Transform();

		const Vec2& getPos()const{ return position; }
		const Vec2& getSize()const{ return size; }
		float getScale()const{ return scale; }
		float getRotation()const{ return rotation; }

		///	座標平行移動
		void translate(const Vec2& value);

		///	指定位置に変換
		void transformPoint(const Vec2& value);

		///	回転軸を移動
		void rotate(const float value);

		///	指定軸に変換
		void lookAt(const float value);

		///	スケールを大きくする
		void scaling(const float value);

		///	指定スケールに変換
		void transformScale(const float value);

		///	大きさを大きくする
		void sizing(const Vec2& value);

		///	指定の大きさに変換
		void transformSize(const Vec2& value);


	private:

		Vec2 position;
		Vec2 size;
		float scale;
		float rotation;

	};

};