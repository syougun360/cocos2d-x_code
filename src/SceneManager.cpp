#include "SceneManager.h"
#include "Application.h"
#include "IScene.h"
#include "TitleManager.h"
#include "GameManager.h"
#include "KeyEvent.h"
#include "TouchEvent.h"
#include "TouchesEvent.h"


namespace game
{
	SceneManager *SceneManager::instance = nullptr;
	IScene *SceneManager::nowScene = nullptr;
	Color4 SceneManager::backGroundColor = Color4(100,100,100,255);

	void SceneManager::addScene(IScene *scene)
	{
		addChild(scene);
		nowScene = scene;
	}

	void SceneManager::removeScene(IScene *scene)
	{
		removeChild(scene);
		nowScene = nullptr;
	}

	cocos2d::Scene* SceneManager::createScene()
	{
		auto scene = cocos2d::Scene::create();
		auto layer = SceneManager::create();

		scene->addChild(layer);

		return scene;
	}


	bool SceneManager::init()
	{
		if (!Layer::init()) return false;
		if (!initWithColor(backGroundColor)) return false;

		scheduleUpdate();

		changeScene<TitleManager>();

		addEvent();

		instance = this;
		isChanged = false;

		return true;
	}
	
	void SceneManager::addEvent()
	{
		auto key = KeyEvent::create();
		auto touch = TouchEvent::create();
		auto touches = TouchesEvent::create();
		this->addChild(key, 0);
		this->addChild(touch, 0);
		this->addChild(touches, 0);
	}

	void SceneManager::update(float delta)
	{
		for (auto& child : this->getChildren())
		{
			child->update(delta);
			if (isChanged) break;
		}
		
		isChanged = false;

		if (KeyEvent::isPress(KeyCode::KEY_ESCAPE))
			Application::close();
	}


}