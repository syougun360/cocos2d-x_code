#pragma once
#include <unordered_map>
#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	class SEPlayer
	{
	public:

		// ���ʂ�ݒ�
		static void setVolume(const float volume);

		// �Đ�
		static void play(const std::string& assetName, bool loop = false);

		// ��~
		static void stop(const std::string& assetName);

	private:
		static std::unordered_map<std::string, int> soundID;
	};

};