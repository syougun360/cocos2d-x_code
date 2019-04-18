#pragma once
#include <string>
#include <map>

namespace game
{
	class AudioAssets
	{
	public:

		// BGM‚ğ“o˜^
		// –¼‘OAƒpƒX–¼
		static void registerBGM(const int id, const std::string& bgmName);

		// SE‚ğ“o˜^
		// –¼‘OAƒpƒX–¼
		static void registerSE(const int id, const std::string& seName);

		// BGM‚ğæ“¾
		// “o˜^‚µ‚½–¼‘O‚ğˆø”‚É“ü‚ê‚é
		static const std::string& getBGM(const int id);

		// SE‚ğæ“¾
		// “o˜^‚µ‚½–¼‘O‚ğˆø”‚É“ü‚ê‚é
		static const std::string& getSE(const int id);

	private:
		static std::map<int, std::string> assetsBGM;
		static std::map<int, std::string> assetsSE;


	};

};