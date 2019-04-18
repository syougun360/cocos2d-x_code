#pragma once
#include "cocos2d.h"

namespace game
{
	class FontAssets
	{
	public:

		// フォントを登録
		// 名前、パス名
		static void registerFont(const int id,const std::string& fontName);

		// フォントを取得
		// 登録した名前を引数に入れる
		static const std::string& getFont(const int id);

	private:
		static std::map<int, std::string> assets;

	};

}
