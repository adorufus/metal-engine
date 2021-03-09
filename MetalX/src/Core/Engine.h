#pragma once
#ifndef ENGINE_H
#define ENGINE_H

#include <SDL.h>
#include <SDL_image.h>
#include "../Graphics/TextureManager.h"
#include "../Physics/Vector2D.h"

#define SCREEN_WIDTH 960
#define SCREEN_HEIGHT 640

class Engine
{
public:

	static Engine* GetInstance() {
		return sInstance = (sInstance != nullptr ) ? sInstance : new Engine();
	}

	bool Init();
	bool Clean();
	void Quit();

	void Update();
	void Render();
	void Events();

	inline bool isRunning() { return mIsRunning; };
	inline SDL_Renderer* GetRenderer(){ return mRenderer; }

private:
	Engine(){}
	bool mIsRunning;

	SDL_Window* mWindow;
	SDL_Renderer* mRenderer;
	static Engine* sInstance;
};

#endif