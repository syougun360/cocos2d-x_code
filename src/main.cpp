#include "main.h"
#include "../../proj.win32/Application.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                       HINSTANCE hPrevInstance,
                       LPTSTR    lpCmdLine,
                       int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	// create the application instance
	game::Application app("My Game",Size(800,600));

    return cocos2d::Application::getInstance()->run();
}
