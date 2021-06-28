#include "Application.h"


//------- Initialize The Scripts ------
void App::Engine::InitScripts( void ) {

	using namespace chaiscript;

	ChaiStart.add(fun(&App::Engine::StartScript), "Start");
	ChaiStart.add(var(&Alpha::Window::width), "width");

}

//------- Start the Engine ------
void App::Engine::start( void ) {

	Alpha::Renderer renderer;
	Alpha::Window   window;
	
	renderer.Init();
	window.SetTitle("Test");
	StartScript();
	window.InitWindow(window.window);
	window.DeInitWindow(window.window);
	renderer.DeInit();

}

//------ Start Script-------------
void App::Engine::StartScript( void ){

	ChaiStart.eval_file( "start.chai" );
	
}