#pragma once
#include <SDL.h>

class Scene;

class App
{
public:
	static void StartApp(int ScreenSizeX, int ScreenSizeY, Scene* startScene);
	static void KillProgram();
	static void ChangeScene(Scene* newScene);
	static SDL_Surface* GetScreenSurface();
private:
	App() = delete;
	~App() = delete;
	static void Init();
	static void EventPolling(SDL_Event* events);
	static void Update();
	static void Cleanup();
	static void DeleteScene();
	static bool _programIsExecuting;
	static bool _shoulDeleteScene;
	static SDL_Window* _surfDisplay;
	static SDL_Surface* _drawSurface, *_clearSurface;
	static int _width, _height;
	static Scene* _currentScene, *_nextScene;
};

