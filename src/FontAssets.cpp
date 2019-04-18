#include "FontAssets.h"


namespace game
{
	std::map<int, std::string> FontAssets::assets;

	// フォントを登録
	// 名前、パス名
	void FontAssets::registerFont(const int id, const std::string& fontName)
	{
		assets.insert(std::make_pair(id, fontName));
	}

	// フォントを取得
	// 登録した名前を引数に入れる
	const std::string& FontAssets::getFont(const int id)
	{
		auto asset = assets.find(id);
		if (asset == assets.end()) return "null";

		return asset->second;
	}

}