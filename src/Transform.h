// -------------------------------------------
// Transform
//
// ���W�E��]�E�X�P�[��
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

		///	���W���s�ړ�
		void translate(const Vec2& value);

		///	�w��ʒu�ɕϊ�
		void transformPoint(const Vec2& value);

		///	��]�����ړ�
		void rotate(const float value);

		///	�w�莲�ɕϊ�
		void lookAt(const float value);

		///	�X�P�[����傫������
		void scaling(const float value);

		///	�w��X�P�[���ɕϊ�
		void transformScale(const float value);

		///	�傫����傫������
		void sizing(const Vec2& value);

		///	�w��̑傫���ɕϊ�
		void transformSize(const Vec2& value);


	private:

		Vec2 position;
		Vec2 size;
		float scale;
		float rotation;

	};

};