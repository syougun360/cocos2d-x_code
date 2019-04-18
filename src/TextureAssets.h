#pragma once
#include "cocos2d.h"

namespace game
{
	class TextureAssets
	{
	public:
		// テクスチャを登録
		// 名前、パス名
		static void registerTexture(const int id, const std::string& pathName);

		// テクスチャを取得
		// 登録した名前を引数に入れる
		static cocos2d::Texture2D* getTexture(const int registerID);
	private:
		static std::map<int, cocos2d::Texture2D*> assets;
	};

}