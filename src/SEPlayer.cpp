#include "SEPlayer.h"

namespace game
{
	std::unordered_map<std::string, int> SEPlayer::soundID;

	void SEPlayer::play(const std::string& assetName, bool loop)
	{
		auto id = CocosDenshion::SimpleAudioEngine::getInstance()->
			playEffect(assetName.c_str(), loop);

		soundID.insert(std::make_pair(assetName,id));
	}

	void SEPlayer::setVolume(const float volume)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(volume);
	}

	void SEPlayer::stop(const std::string& assetName)
	{
		auto asset = soundID.find(assetName);
		if (asset == soundID.end()) return;

		CocosDenshion::SimpleAudioEngine::getInstance()->stopEffect(asset->second);
		soundID.erase(asset);
	}



	
};