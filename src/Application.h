#pragma once
#include <memory>
#include "using.h"

namespace game
{
	class Application : private cocos2d::Application
	{
	public:
		Application(const char* titleName, const Size& screenSize);
		virtual ~Application() = default;

		virtual void initGLContextAttrs();
		virtual bool applicationDidFinishLaunching();
		virtual void applicationDidEnterBackground();
		virtual void applicationWillEnterForeground();

		static cocos2d::Director* getDirectorInstance();

		static void frameRateTarget(int frameRate);
		static void frameRateStatsView(bool isView);
		static void close();
		const char* getTitleName()const{ return titleName; }

	private:
		const char* titleName;
		const Size screenSize;
	};

}