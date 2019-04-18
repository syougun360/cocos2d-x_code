#include "BGMPlayer.h"

namespace game
{

	void BGMPlayer::play(const std::string& assetName,bool loop)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->
			playBackgroundMusic(assetName.c_str(), loop);
	}

	void BGMPlayer::setVolume(const float volume)
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(volume);
	}

	void BGMPlayer::stop()
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
	}

	void BGMPlayer::pause()
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
	}

	void BGMPlayer::resume()
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
	}


}