#pragma once
#include <string>
#include <map>

namespace game
{
	class AudioAssets
	{
	public:

		// BGM��o�^
		// ���O�A�p�X��
		static void registerBGM(const int id, const std::string& bgmName);

		// SE��o�^
		// ���O�A�p�X��
		static void registerSE(const int id, const std::string& seName);

		// BGM���擾
		// �o�^�������O�������ɓ����
		static const std::string& getBGM(const int id);

		// SE���擾
		// �o�^�������O�������ɓ����
		static const std::string& getSE(const int id);

	private:
		static std::map<int, std::string> assetsBGM;
		static std::map<int, std::string> assetsSE;


	};

};