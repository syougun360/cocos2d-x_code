#pragma once
#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	class BGMPlayer
	{
	public:
		// ‰¹—Ê‚ğİ’è
		static void setVolume(const float volume );

		// Ä¶
		static void play(const std::string& assetName, bool loop = false);

		// ’â~
		static void stop();

		// ˆê’â~
		static void pause();

		// ÄŠJ
		static void resume();
	private:
	};
};
