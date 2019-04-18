#pragma once
#include "FontAssets.h"
#include "TextureAssets.h"
#include "AudioAssets.h"

namespace game
{
	class Resources
	{
	public:
		Resources();
		void fontLoad();
		void textureLoad();
		void audioLoad();

		enum FontID
		{
			Arial,
			MarkerFelt,
		};

		enum TextureID
		{
			HelloWorld,
		};

		enum BGMID
		{
			TestBGM,
		};

		enum SEID
		{
			TestSE,
		};

	private:


	};

}