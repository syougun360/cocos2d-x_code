#include "TitleManager.h"
#include "Application.h"
#include "SceneManager.h"
#include "GameManager.h"
#include "TextureAssets.h"
#include "Sprite.h"
#include "iTween.h"
#include "Resources.h"
#include "KeyEvent.h"
#include "TouchEvent.h"
#include "TouchesEvent.h"
#include "Random.h"
#include "Screen.h"
#include "BGMPlayer.h"
#include "SEPlayer.h"
#include "Player.h"

namespace game
{
	bool TitleManager::init()
	{
		if (!Layer::init())
		{
			return false;
		}

		hierarchy = std::make_unique<Hierarchy>();
		hierarchy->registerHierachy(std::make_shared<Player>(this));

		//BGMPlayer::play(AudioAssets::getBGM(Resources::BGMID::TestBGM),true);

		return true;
	}

	void TitleManager::update(float delta)
	{
		hierarchy->update();

		if (KeyEvent::isClick(KeyCode::KEY_N))
		{
			auto scene = SceneManager::getInstance();
			scene->changeScene<GameManager>();
			hierarchy->clear();
		}

		if (TouchEvent::isMove())
		{

		}

		if (TouchEvent::isBegin())
		{
			SEPlayer::play(AudioAssets::getSE(Resources::SEID::TestSE));
		}

		if (TouchEvent::isEnd())
		{
			SEPlayer::stop(AudioAssets::getSE(Resources::SEID::TestSE));
		}


	}


}