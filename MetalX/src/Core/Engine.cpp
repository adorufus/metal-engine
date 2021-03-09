#include "Engine.h"
#include <stdio.h>
#include "../Physics/Transform.h"
#include "../GameObjects/Characters/Player.h"

Engine* Engine::sInstance = nullptr;
Player* player = nullptr;

TextureManager* textureManager = TextureManager::GetInstance();

bool Engine::Init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0) {
		SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
		return false;
	}
	else {
		SDL_Log("Engine Initialized!");
		SDL_Log("Creating window, please wait..");
		mWindow = SDL_CreateWindow("MetalX", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);

		if (mWindow == nullptr) {
			SDL_Log("Failed to create window: %s", SDL_GetError());
			return false;
		}
		else {
			SDL_Log("Window created! preparing for renderer... please wait....");
		}

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (mRenderer == nullptr) {
			SDL_Log("Failed to create renderer: %s", SDL_GetError());
			return false;
		}
		else {
			SDL_Log("Renderer Created!");
		}

		textureManager->Load("player", "src/Assets/character.png");

		player = new Player(new Properties("player", 100, 200, 96, 128));

		mIsRunning = true;
		return true;
	}
}

bool Engine::Clean() {
	textureManager->Clean();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	IMG_Quit();
	SDL_Quit();
	return NULL;
}

void Engine::Quit() {
	mIsRunning = false;
}

void Engine::Update() {
	player->Update(0);
}

void Engine::Render() {
	SDL_SetRenderDrawColor(mRenderer, 124, 218, 254, 255);
	SDL_RenderClear(mRenderer);

	player->Draw();
	SDL_RenderPresent(mRenderer);
}

void Engine::Events() {
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) {
	case SDL_QUIT:
		Quit();
	}
}