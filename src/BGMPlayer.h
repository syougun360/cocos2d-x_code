#pragma once
#include "AudioAssets.h"
#include "SimpleAudioEngine.h"

namespace game
{
	class BGMPlayer
	{
	public:
		// ���ʂ�ݒ�
		static void setVolume(const float volume );

		// �Đ�
		static void play(const std::string& assetName, bool loop = false);

		// ��~
		static void stop();

		// �ꎞ��~
		static void pause();

		// �ĊJ
		static void resume();
	private:
	};
};
