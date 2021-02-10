#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"

SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
Map* map;
Transform playerTransform;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;
auto& player(manager.addEntity());
auto& enemy(manager.addEntity());

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

	map = new Map();

	player.addComponent<Transform>(100, 100);
	player.addComponent<Sprite>("Assets/character2.png");

	enemy.addComponent<Transform>(50, 50);
	enemy.addComponent<Sprite>("Assets/character.png");
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
	Transform playerTransform = player.getComponent<Transform>();
	Sprite playerSprite = player.getComponent<Sprite>();

	count++;
	manager.update();
	/*if (playerTransform.x() > 100) {
		player.getComponent<Sprite>().setTexture("Assets/character.png");
	}*/
	std::cout << "newPlayerPos: " << playerTransform.x() << ", " << player.getComponent<Transform>().y() << std::endl;
}

void Game::render(){
	SDL_RenderClear(renderer);
	map->DrawMap();
	//player->Render();
	//enemy->Render();
	manager.draw();
	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}