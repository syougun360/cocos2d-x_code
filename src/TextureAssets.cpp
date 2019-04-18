#include "TextureAssets.h"

namespace game
{
	std::map<int, cocos2d::Texture2D*> TextureAssets::assets;

	void TextureAssets::registerTexture(const int id, const std::string& pathName)
	{
		assets.insert(std::make_pair(id, cocos2d::SpriteBatchNode::create(pathName)->getTexture()));
	}

	cocos2d::Texture2D* TextureAssets::getTexture(const int registerID)
	{
		auto asset = assets.find(registerID);
		if (asset == assets.end()) return nullptr;

		return asset->second;
	}
};