#include "Application.h"
#include "SceneManager.h"
#include "Resources.h"
namespace game
{
	Application::Application(const char* titleName, const Size& screenSize) :
		titleName(titleName),
		screenSize(screenSize)
	{
	}

	cocos2d::Director* Application::getDirectorInstance()
	{
		static auto director = cocos2d::Director::getInstance();
		return director;
	}

	void Application::initGLContextAttrs()
	{
		GLContextAttrs glContextAttrs = { 8, 8, 8, 8, 24, 8 };

		cocos2d::GLView::setGLContextAttrs(glContextAttrs);
	}

	static int register_all_packages()
	{
		return 0; 
	}

	void Application::frameRateTarget(int frameRate)
	{
		Application::getDirectorInstance()->setAnimationInterval(1.0 / frameRate);
	}
	
	void Application::frameRateStatsView(bool isView)
	{
		Application::getDirectorInstance()->setDisplayStats(isView);
	}
	
	void Application::close()
	{
		game::Application::getDirectorInstance()->end();
	}

	bool Application::applicationDidFinishLaunching() 
	{
		auto director = Application::getDirectorInstance();
		auto glview = director->getOpenGLView();
		if (!glview) {
			glview = cocos2d::GLViewImpl::create(titleName);
			glview->setFrameSize(screenSize.width, screenSize.height);
			director->setOpenGLView(glview);
		}

		frameRateStatsView(true);
		frameRateTarget(60);

		register_all_packages();

		Resources resrouces;

		auto scene = SceneManager::createScene();

		director->runWithScene(scene);

		return true;
	}

	void Application::applicationDidEnterBackground()
	{
		Application::getDirectorInstance()->stopAnimation();
	}

	void Application::applicationWillEnterForeground()
	{
		Application::getDirectorInstance()->startAnimation();
	}

}