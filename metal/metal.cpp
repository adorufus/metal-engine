// metal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define SDL_MAIN_HANDLED
#include <iostream>
#include "Game.h"

Game* game = nullptr;

int main()
{
	game = new Game();

	game->init("Metal Engine!!!!!!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, false);
	
	while (game->running()) {
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();

	return 0;
}
