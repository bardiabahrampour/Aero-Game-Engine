//Aero Engine is a an easy to use 3d C++ game engine with chai script implementaition
#include "Application.h"
#ifdef DEBUG
int main()
{
	App::Engine engine;

	engine.InitScripts();
	engine.start();
}
#endif

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	App::Engine engine;

	engine.InitScripts();
	engine.start();

	return 0;
}