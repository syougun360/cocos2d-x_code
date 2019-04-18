#pragma once
#include <unordered_map>
#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	class SEPlayer
	{
	public:

		// ‰¹—Ê‚ğİ’è
		static void setVolume(const float volume);

		// Ä¶
		static void play(const std::string& assetName, bool loop = false);

		// ’â~
		static void stop(const std::string& assetName);

	private:
		static std::unordered_map<std::string, int> soundID;
	};

};