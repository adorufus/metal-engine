#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Collider.h"
#include "SquareCollision.h"

SDL_Texture* playerTexture;
SDL_Rect srcR, destR;
Map* map;
Transform playerTransform;
SDL_Event Game::event;

SDL_Renderer* Game::renderer = nullptr;

Manager manager;

//std::vector<Collider*> Game::colliders;

auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& wall(manager.addEntity());

//auto& tile0(manager.addEntity());
//auto& tile1(manager.addEntity());
//auto& tile2(manager.addEntity());

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

	//this line is for adding entity component
	/*player.addComponent<Transform>(0, 0, 32, 32, 1);
	player.addComponent<Sprite>("Assets/character2.png");
	player.addComponent<KeyboardController>();
	player.addComponent<Collider>("player");*/

	/*tile0.addComponent<Tile>(200, 200, 32, 32, 1);
	tile1.addComponent<Tile>(250, 250, 32, 32, 1);
	tile1.addComponent<Collider>("dirt");
	tile2.addComponent<Tile>(150, 150, 32, 32, 1);
	tile2.addComponent<Collider>("grass");*/

	enemy.addComponent<Transform>(1);
	enemy.addComponent<Sprite>("Assets/character.png");
	enemy.addComponent<KeyboardController>();
	enemy.addComponent<Collider>("enemy");

	wall.addComponent<Transform>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<Sprite>("Assets/dirt.png");
	wall.addComponent<Collider>("wall");
}

void Game::handleEvents() {
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
	//Transform playerTransform = player.getComponent<Transform>();
	//Sprite playerSprite = player.getComponent<Sprite>();

	count++;
	manager.refresh();
	manager.update();

	if (SquareCollision::AABB(enemy.getComponent<Collider>().collider, wall.getComponent<Collider>().collider)) {
		enemy.getComponent<Transform>().velocity * -1;
		std::cout << "Wall hit!" << std::endl;
	}
	
	//std::cout << "newPlayerPos: " << playerTransform.position.x << ", " << playerTransform.position.y << std::endl;
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