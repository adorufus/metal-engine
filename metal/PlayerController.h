#pragma once
#include "Game.h"
#include "ECS/ECS.h"
#include "ECS/Components.h"
#include "Utils.h"

class KeyboardController : public Component {
public:
	Transform* transform;
	Sprite* sprite;
	PhysicsBody* pb;

	//bool mapContainsKey()

	void init() override {
		transform = &entity->getComponent<Transform>();
		sprite = &entity->getComponent<Sprite>();
		pb = &entity->getComponent<PhysicsBody>();
	}

	void update() override {
		pb->update();
		transform->velocity.y = pb->Position().y;
		/*if (Game::event.type == SDL_KEYDOWN) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = -1;
				if (Utils::animContainsKey(sprite->animations, "Walk")) {
					sprite->Play("Walk");
				}
				break;
			case SDLK_s:
				transform->velocity.y = 1;
				if (Utils::animContainsKey(sprite->animations, "Walk")) {
					sprite->Play("Walk");
				}
				break;
			case SDLK_a:
				transform->velocity.x = -1;
				if (Utils::animContainsKey(sprite->animations, "Walk")) {
					sprite->Play("Walk");
				}
				break;
			case SDLK_d:
				transform->velocity.x = 1;
				if (Utils::animContainsKey(sprite->animations, "Walk")) {
					sprite->Play("Walk");
				}
				break;
			default:
				break;
			}
		}

		if (Game::event.type == SDL_KEYUP) {
			switch (Game::event.key.keysym.sym) {
			case SDLK_w:
				transform->velocity.y = 0;
				if (Utils::animContainsKey(sprite->animations, "Idle")) {
					sprite->Play("Idle");
				}
				break;
			case SDLK_s:
				transform->velocity.y = 0;
				if (Utils::animContainsKey(sprite->animations, "Idle")) {
					sprite->Play("Idle");
				}
				break;
			case SDLK_a:
				transform->velocity.x = 0;
				if (Utils::animContainsKey(sprite->animations, "Idle")) {
					sprite->Play("Idle");
				}
				break;
			case SDLK_d:
				transform->velocity.x = 0;
				if (Utils::animContainsKey(sprite->animations, "Idle")) {
					sprite->Play("Idle");
				}
				break;
			default:
				break;
			}
		}*/
	}
};
