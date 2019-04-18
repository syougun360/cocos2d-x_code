#include "FontAssets.h"


namespace game
{
	std::map<int, std::string> FontAssets::assets;

	// �t�H���g��o�^
	// ���O�A�p�X��
	void FontAssets::registerFont(const int id, const std::string& fontName)
	{
		assets.insert(std::make_pair(id, fontName));
	}

	// �t�H���g���擾
	// �o�^�������O�������ɓ����
	const std::string& FontAssets::getFont(const int id)
	{
		auto asset = assets.find(id);
		if (asset == assets.end()) return "null";

		return asset->second;
	}

}