#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "SquareCollision.h"


Map* map;
Manager manager;

SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;

std::vector<Collider*> Game::colliders;

auto& player(manager.addEntity());
auto& enemy(manager.addEntity());
auto& wall(manager.addEntity());

enum groupLabels : std::size_t {
	groupMap,
	groupPlayer,
	groupEnemies,
	groupColliders
};

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

	Map::LoadMap("Assets/okta.map", 16, 16);

	player.addComponent<Transform>(1);
	player.addComponent<Sprite>("Assets/slime-animated.png", true);
	player.addComponent<KeyboardController>();
	player.addComponent<Collider>("enemy");
	player.assignGroup(groupPlayer);

	wall.addComponent<Transform>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<Sprite>("Assets/dirt.png");
	wall.addComponent<Collider>("wall");
	wall.assignGroup(groupMap);
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

	for (auto cc : colliders) {
		if (cc->tag != player.getComponent<Collider>().tag) {
			SquareCollision::AABB(player.getComponent<Collider>(), *cc);
		}
	}
	
	//std::cout << "newPlayerPos: " << playerTransform.position.x << ", " << playerTransform.position.y << std::endl;
}

auto& tiles(manager.getGroup(groupMap));
auto& players(manager.getGroup(groupPlayer));
auto& enemies(manager.getGroup(groupEnemies));

void Game::render(){
	SDL_RenderClear(renderer);
	//map->DrawMap();

	for (auto& t : tiles) {
		t->draw();
	}
	
	for (auto& p : players) {
		p->draw();
	}
	
	for (auto& e : enemies) {
		e->draw();
	}

	SDL_RenderPresent(renderer);
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::AddTile(int id, int x, int y) {
	auto& tile(manager.addEntity());

	tile.addComponent<Tile>(x, y, 32, 32, id);
	tile.assignGroup(groupMap);
}