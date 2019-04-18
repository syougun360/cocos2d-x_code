#pragma once
#include "cocos2d.h"

namespace game
{
	class TextureAssets
	{
	public:
		// �e�N�X�`����o�^
		// ���O�A�p�X��
		static void registerTexture(const int id, const std::string& pathName);

		// �e�N�X�`�����擾
		// �o�^�������O�������ɓ����
		static cocos2d::Texture2D* getTexture(const int registerID);
	private:
		static std::map<int, cocos2d::Texture2D*> assets;
	};

}