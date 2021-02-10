#pragma once
#ifndef Game_h
#define Game_h

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running() {
		return isRunning;
	};

private:
	int count = 0;
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
};
#endif /*Game_h*/

