// ----------------------------------------------
// ���Ԃ̊K�w
// 
// �K�w�ɓ���N���X�Ɍp���������
// �A�N�e�B�u�E��A�N�e�B�u��ݒ�ł���
//
// ----------------------------------------------

#pragma once
#include <memory>
#include "Component.h"
#include "Hierarchy.h"

namespace game
{
	class Releaser;
	class Hierarchy;

	class EntityHierarchy :public Component
	{
	public:
		EntityHierarchy(NodePtr node,const std::string& name, const Transform& transform);
		EntityHierarchy(NodePtr node, const std::string& name, const Tags tag);
		EntityHierarchy(NodePtr node, const std::string& name, const SortingLayer sortingLayer);
		EntityHierarchy(NodePtr node, const std::string& name, const Tags tag, const SortingLayer sortingLayer);

		// �`��
		void updatable();

		// �e�擾
		std::shared_ptr<EntityHierarchy> getEntityParent()
		{
			return parent;
		}

		// �e��ݒ�
		void setEntityParent(std::shared_ptr<EntityHierarchy> entityHierarchy);

	protected:
		
		// �q�I�u�W�F�N�g��ǉ�
		void addChild(std::shared_ptr<EntityHierarchy> entityHierarchy);

		// �q�I�u�W�F�N�g���폜
		void destroyChild(std::shared_ptr<EntityHierarchy> entityHierarchy);

		// Start�̑O�ɏ��������s������
		virtual void awake(){}

		// Update�̑O�ɏ��������s������
		virtual void start(){}

		// �A�b�v�f�[�g
		virtual void update(){}

		// �A�N�e�B�u�E��A�N�e�B�u
		void setActive(bool isActive);

		// �A�N�e�B�u���擾
		bool isActive()const{ return active; }
		
	private:
		std::shared_ptr<EntityHierarchy> parent;

		enum class UpdateState
		{
			Awake,
			Start,
			Update,
		};
		NodePtr node;
		UpdateState state;
		bool active;
	};

	using EntityHierarchyPtr = std::shared_ptr < EntityHierarchy > ;
};