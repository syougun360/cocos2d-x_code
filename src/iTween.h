#pragma once
#include "using.h"

namespace game
{
	class iTween
	{
	public:

		// �w�肵���ꏊ�Ɉړ�
		static ActionPtr MoveTo(NodePtr node, const Vec2& pos, const float time);
		
		// �w�肵�������Ɉړ�
		static ActionPtr MoveBy(NodePtr node, const Vec2& pos, const float time);
		
		// �w�肵���傫���ɃX�P�[�����O
		static ActionPtr ScaleTo(NodePtr node, const Vec2& scale, const float time);
		
		// �w�肵���傫���̋������X�P�[�����O
		static ActionPtr ScaleBy(NodePtr node, const Vec2& scale, const float time);
		
		// �w�肵����]�ʂɉ�]
		static ActionPtr RotateTo(NodePtr node, const float rotate, const float time);
		
		// �w�肵����]�ʂ̑傫������]
		static ActionPtr RotateBy(NodePtr node, const float rotate, const float time);

		// ��~
		static void Stop(NodePtr node, ActionPtr action);
		static void Stop(NodePtr node);

	};

}