#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	std::map<int, std::string> AudioAssets::assetsBGM;
	std::map<int, std::string> AudioAssets::assetsSE;

	// BGM‚ð“o˜^
	// –¼‘OAƒpƒX–¼
	void AudioAssets::registerBGM(const int id, const std::string& bgmName)
	{
		assetsBGM.insert(std::make_pair(id, bgmName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bgmName.c_str());
	}

	// SE‚ð“o˜^
	// –¼‘OAƒpƒX–¼
	void AudioAssets::registerSE(const int id, const std::string& seName)
	{
		assetsSE.insert(std::make_pair(id, seName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(seName.c_str());
	}

	// BGM‚ðŽæ“¾
	// “o˜^‚µ‚½–¼‘O‚ðˆø”‚É“ü‚ê‚é
	const std::string& AudioAssets::getBGM(const int id)
	{
		auto asset = assetsBGM.find(id);
		if (asset == assetsBGM.end()) return "null";

		return asset->second;
	}

	// SE‚ðŽæ“¾
	// “o˜^‚µ‚½–¼‘O‚ðˆø”‚É“ü‚ê‚é
	const std::string& AudioAssets::getSE(const int id)
	{
		auto asset = assetsSE.find(id);
		if (asset == assetsSE.end()) return "null";

		return asset->second;
	}

}