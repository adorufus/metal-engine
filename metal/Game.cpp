#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS.h"
#include "Components.h"

SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
GameObject* player, * enemy;
Map* map;
Transform playerTransform;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& newPlayer(manager.addEntity());

Game::Game() {

}

Game::~Game() {

}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullScreen) {
	int flags = 0;
	if (fullScreen) {
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialized! ..." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);

		if (window) {
			std::cout << "Window created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	//playerTexture = TextureManager::LoadTexture("Assets/character.png", renderer);
	player = new GameObject("Assets/character2.png", 32, 32, 0, 0);
	enemy = new GameObject("Assets/character.png", 32, 32, 15, 15);
	map = new Map();

	newPlayer.addComponent<Transform>();

	newPlayer.getComponent<Transform>().setPos(500, 500);
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {
	count++;
	player->Update();
	enemy->Update();
	manager.update();
	playerTransform = newPlayer.getComponent<Transform>();
	std::cout << "newPlayerPos: " << playerTransform.x() << ", " << playerTransform.y() << std::endl;
}

void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->Render();
	enemy->Render();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}