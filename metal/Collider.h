#pragma once
#include <string>
#include <SDL.h>
#include "ECS/Components.h"

class Collider : public Component {

public:

	SDL_Rect collider;
	std::string tag;

	Transform* transform;

	Collider(std::string t) {
		tag = t;
	}

	void init() override {
		if (!entity->hasComponent<Transform>()) {
			entity->addComponent<Transform>();
		}

		transform = &entity->getComponent<Transform>();

		Game::colliders.push_back(this);
	}

	void update() override {
		collider.x = static_cast<int>(transform->position.x);
		collider.y = static_cast<int>(transform->position.y);
		collider.w = transform->width * transform->scale;
		collider.h = transform->height * transform->scale;
	}
};