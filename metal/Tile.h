#pragma once
#include "ECS/ECS.h"
//#include "ECS/Transform.h"
#include "Game.h"
//#include "ECS/SpriteComponent.h"
#include <SDL.h>
#include <string>

class Tile : public Component {
public:
	Transform* transform;
	Sprite* sprite;
	SDL_Rect tileRect;

	int tileID;
	const char* path;

	Tile() = default;

	Tile(int x, int y, int w, int h, int id) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.h = h;
		tileRect.w = w;
		tileID = id;

		switch (tileID)
		{
		case 0:
			path = "Assets/water.png";
			break;
		case 1:
			path = "Assets/dirt.png";
			break;
		case 2:
			path = "Assets/grass.png";
			break;
		default:
			break;
		}
	}

	void init() override {
		entity->addComponent<Transform>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<Transform>();

		entity->addComponent<Sprite>(path);
		sprite = &entity->getComponent<Sprite>();
	}
};