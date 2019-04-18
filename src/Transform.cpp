#include "Transform.h"

namespace game
{
	Transform::Transform() :
		position(Vec2(0, 0)), scale(1),size(Vec2(1, 1)), rotation(0)
	{

	}

	Transform::Transform(const Vec2& pos, const Vec2& size, const float rotation) :
		position(pos), size(size), scale(1), rotation(rotation)
	{
	}

	Transform::Transform(const Vec2& pos, const float scale, const  float rotation) :
		position(pos), scale(scale), size(Vec2(1,1)), rotation(rotation)
	{
	}

	Transform::Transform(const Vec2& pos, const Vec2& size) :
		position(pos), scale(1), size(size), rotation(0)
	{
	}

	Transform::Transform(const Vec2& pos, const float scale) :
		position(pos), scale(scale), size(Vec2(1,1)), rotation(0)
	{
	}
	
	Transform::Transform(const Vec2& pos) :
		position(pos), scale(1), size(Vec2(1, 1)), rotation(0)
	{
	}
	

	///	座標平行移動
	void Transform::translate(const Vec2& value)
	{
		position += value;
	}

	///	指定位置に変換
	void Transform::transformPoint(const Vec2& value)
	{
		position = value;
	}

	///	回転軸を移動
	void Transform::rotate(const float value)
	{
		rotation += value;
	}

	///	指定軸に変換
	void Transform::lookAt(const float value)
	{
		rotation = value;
	}

	///	スケールを大きくする
	void Transform::scaling(const float value)
	{
		scale += value;
	}

	///	指定スケールに変換
	void Transform::transformScale(const float value)
	{
		scale = value;
	}

	///	スケールを大きくする
	void Transform::sizing(const Vec2& value)
	{
		size += value;
	}

	///	指定スケールに変換
	void Transform::transformSize(const Vec2& value)
	{
		size = value;
	}
};