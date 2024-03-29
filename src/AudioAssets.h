#pragma once
#include <string>
#include <map>

namespace game
{
	class AudioAssets
	{
	public:

		// BGMを登録
		// 名前、パス名
		static void registerBGM(const int id, const std::string& bgmName);

		// SEを登録
		// 名前、パス名
		static void registerSE(const int id, const std::string& seName);

		// BGMを取得
		// 登録した名前を引数に入れる
		static const std::string& getBGM(const int id);

		// SEを取得
		// 登録した名前を引数に入れる
		static const std::string& getSE(const int id);

	private:
		static std::map<int, std::string> assetsBGM;
		static std::map<int, std::string> assetsSE;


	};

};