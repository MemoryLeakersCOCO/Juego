#include "App.h"
#include "Scene.h"
#include <iostream>

bool App::_programIsExecuting, App::_shoulDeleteScene;
SDL_Window* App::_surfDisplay = nullptr;
int App::_width;
int App::_height;
Scene* App::_currentScene,*App::_nextScene;
SDL_Surface* App::_drawSurface, *App::_clearSurface;

void App::StartApp(int ScreenSizeX, int ScreenSizeY, Scene* startScene)
{
	_width = ScreenSizeX;
	_height = ScreenSizeY;
	_currentScene = startScene;
	_nextScene = nullptr;
	Init();
	while (_programIsExecuting) {
		Update();
		DeleteScene();
	}
	Cleanup();
}

void App::KillProgram()
{
	_programIsExecuting = false;
}

void App::ChangeScene(Scene* newScene)
{
	_currentScene->OnEnd();
	_shoulDeleteScene = true;
	if (newScene != nullptr)
	{
		_nextScene = newScene;
	}
}

SDL_Surface* App::GetScreenSurface()
{
	return _drawSurface;
}

void App::Init()
{
	_programIsExecuting = true;
	_programIsExecuting = !SDL_Init(SDL_INIT_EVERYTHING);
	if (!_programIsExecuting)
		return;
	_surfDisplay = SDL_CreateWindow("Juego mamalon", SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, _width, _height, SDL_WINDOW_RESIZABLE);
	if (_surfDisplay == nullptr) {
		_programIsExecuting = false;
		return;
	}
	_drawSurface = SDL_GetWindowSurface(_surfDisplay);
	_clearSurface = SDL_CreateRGBSurface(SDL_SWSURFACE, _width, _height,
		32, 0,0, 0, 0);
	if (!_clearSurface) {
		std::cout << "ERROR" << SDL_GetError()
			<< std::endl;
	}
	SDL_FillRect(_clearSurface, NULL, 0xFFFF00FF);
}

void App::Update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) 
		EventPolling(&e);
	SDL_BlitSurface(_clearSurface, NULL, _drawSurface, NULL);
	if (_currentScene == nullptr)
		return;
	if (!_currentScene->hasStarted)
		_currentScene->Start();
	_currentScene->Update();
	SDL_UpdateWindowSurface(_surfDisplay);
	SDL_Delay(16);
}

void App::Cleanup()
{
	SDL_DestroyWindow(_surfDisplay);
	SDL_Quit();
}

void App::DeleteScene() 
{
	if (_shoulDeleteScene){
		delete _currentScene;
		_currentScene = _nextScene;
		_nextScene = nullptr;
	}
}

void App::EventPolling(SDL_Event* events)
{
	switch (events->type) {
	case SDL_QUIT:
		_programIsExecuting = false;
		break;
	case SDL_KEYDOWN:
		if (events->key.keysym.scancode == SDLK_ESCAPE) {
			_programIsExecuting = false;
		}
	}
}
