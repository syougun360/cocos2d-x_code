#include "Resources.h"


namespace game
{

	Resources::Resources()
	{
		fontLoad();
		textureLoad();
		audioLoad();
	}

	void Resources::textureLoad()
	{
		TextureAssets::registerTexture(TextureID::HelloWorld, "HelloWorld.png");
	}

	void Resources::fontLoad()
	{
		FontAssets::registerFont(FontID::Arial, "arial");
		FontAssets::registerFont(FontID::MarkerFelt, "Marker Felt");
		
	}

	void Resources::audioLoad()
	{
		AudioAssets::registerBGM(BGMID::TestBGM, "bgm.mp3");
		AudioAssets::registerSE(SEID::TestSE, "se.mp3");
	}


}
