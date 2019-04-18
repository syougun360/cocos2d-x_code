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
	

	///	���W���s�ړ�
	void Transform::translate(const Vec2& value)
	{
		position += value;
	}

	///	�w��ʒu�ɕϊ�
	void Transform::transformPoint(const Vec2& value)
	{
		position = value;
	}

	///	��]�����ړ�
	void Transform::rotate(const float value)
	{
		rotation += value;
	}

	///	�w�莲�ɕϊ�
	void Transform::lookAt(const float value)
	{
		rotation = value;
	}

	///	�X�P�[����傫������
	void Transform::scaling(const float value)
	{
		scale += value;
	}

	///	�w��X�P�[���ɕϊ�
	void Transform::transformScale(const float value)
	{
		scale = value;
	}

	///	�X�P�[����傫������
	void Transform::sizing(const Vec2& value)
	{
		size += value;
	}

	///	�w��X�P�[���ɕϊ�
	void Transform::transformSize(const Vec2& value)
	{
		size = value;
	}
};