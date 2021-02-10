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

	/**
	*initialize the window
	*@param title the title of your game window
	*@param xPos the x position of your game window
	*@param yPos the y position of your game window
	*@param width the width of your game window
	*@param height the height of your game window
	*@param fullscreen define if the game window is fullscreen or not
	*@return nothing
	*/
	void init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen);

	/**
	*this is for handling some events
	*@params nothing
	*@return nothing
	*/
	void handleEvents();
	/**
	*this is for updating game states
	*@params nothing
	*@return nothing
	*/
	void update();
	/**
	*this is for rendering
	*@params nothing
	*@return nothing
	*/
	void render();
	/**
	*this is for cleaning if application destroyed
	*@params nothing
	*@return nothing
	*/
	void clean();

	/**
	*check if the application is running
	*@params nothing
	*@return bool isRunning
	*/
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

