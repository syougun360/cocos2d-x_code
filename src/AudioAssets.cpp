#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	std::map<int, std::string> AudioAssets::assetsBGM;
	std::map<int, std::string> AudioAssets::assetsSE;

	// BGMを登録
	// 名前、パス名
	void AudioAssets::registerBGM(const int id, const std::string& bgmName)
	{
		assetsBGM.insert(std::make_pair(id, bgmName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bgmName.c_str());
	}

	// SEを登録
	// 名前、パス名
	void AudioAssets::registerSE(const int id, const std::string& seName)
	{
		assetsSE.insert(std::make_pair(id, seName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(seName.c_str());
	}

	// BGMを取得
	// 登録した名前を引数に入れる
	const std::string& AudioAssets::getBGM(const int id)
	{
		auto asset = assetsBGM.find(id);
		if (asset == assetsBGM.end()) return "null";

		return asset->second;
	}

	// SEを取得
	// 登録した名前を引数に入れる
	const std::string& AudioAssets::getSE(const int id)
	{
		auto asset = assetsSE.find(id);
		if (asset == assetsSE.end()) return "null";

		return asset->second;
	}

}