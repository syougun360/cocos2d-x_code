#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	std::map<int, std::string> AudioAssets::assetsBGM;
	std::map<int, std::string> AudioAssets::assetsSE;

	// BGM��o�^
	// ���O�A�p�X��
	void AudioAssets::registerBGM(const int id, const std::string& bgmName)
	{
		assetsBGM.insert(std::make_pair(id, bgmName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic(bgmName.c_str());
	}

	// SE��o�^
	// ���O�A�p�X��
	void AudioAssets::registerSE(const int id, const std::string& seName)
	{
		assetsSE.insert(std::make_pair(id, seName));
		CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect(seName.c_str());
	}

	// BGM���擾
	// �o�^�������O�������ɓ����
	const std::string& AudioAssets::getBGM(const int id)
	{
		auto asset = assetsBGM.find(id);
		if (asset == assetsBGM.end()) return "null";

		return asset->second;
	}

	// SE���擾
	// �o�^�������O�������ɓ����
	const std::string& AudioAssets::getSE(const int id)
	{
		auto asset = assetsSE.find(id);
		if (asset == assetsSE.end()) return "null";

		return asset->second;
	}

}