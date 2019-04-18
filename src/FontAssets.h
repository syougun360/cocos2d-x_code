#pragma once
#include "cocos2d.h"

namespace game
{
	class FontAssets
	{
	public:

		// �t�H���g��o�^
		// ���O�A�p�X��
		static void registerFont(const int id,const std::string& fontName);

		// �t�H���g���擾
		// �o�^�������O�������ɓ����
		static const std::string& getFont(const int id);

	private:
		static std::map<int, std::string> assets;

	};

}
