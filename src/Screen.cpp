#include "Screen.h"
#include "Application.h"

namespace game
{
	Size Screen::getVisibleSize()
	{
		return Application::getDirectorInstance()->getVisibleSize();
	}

	Vec2 Screen::getVisibleOriginPosition()
	{
		return Application::getDirectorInstance()->getVisibleOrigin();
	}
	
}