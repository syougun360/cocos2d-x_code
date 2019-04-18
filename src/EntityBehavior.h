// ----------------------------------------------
// ���Ԃ̋���
// 
// �����n
// �\ or �s�\ ���ݒ�ł���
// 
// ----------------------------------------------

#pragma once
#include <memory>
#include <string>
#include "Component.h"

namespace game
{
	class EntityBehavior :public Component
	{
	public:
		EntityBehavior(const std::string& name);
		EntityBehavior(const std::string& name, const std::string& parentName);

		// Start�̑O�ɏ��������s������
		// 1�x�̂ݎ��s
		virtual void awake(){}

		// Update�̑O�ɏ��������s������
		// 1�x�̂ݎ��s
		virtual void start(){}

		// �A�b�v�f�[�g
		virtual void update(){}

		// ���s�\�E�s�\�ɂ���
		void setEnable(bool isEnable);

		// ���s�\���ǂ������擾
		bool isEnable()const{ return enable; }

	protected:

	private:
		bool enable;

	};
}