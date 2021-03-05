#include "Components.h"
#include "SDL.h"
#include "../TextureManager.h"
#include "../Animation.h"
#include <map>

class Sprite : public Component {
private:
	Transform* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

	bool animated = false;
	int frames = 0;
	int speed = 100;

public:
	int animIndex = 0;

	std::map<const char*, Animation> animations;

	Sprite() = default;

	Sprite(const char* path) {
		setTexture(path);
	}

	Sprite(const char* path, bool isAnimated) {
		animated = isAnimated;

		//adding more animation here
		//
		//Animation animName = Animation(animIndex, frameCount, speed);
		Animation idle = Animation(0, 4, 100);
		
		animations.emplace("Idle", idle);

		Play("Idle");
		setTexture(path);
	}

	~Sprite() {
		SDL_DestroyTexture(texture);
	}

	void setTexture(const char* path) {
		texture = TextureManager::LoadTexture(path);
	}

	void init() override {
		transform = &entity->getComponent<Transform>();

		srcRect.x = srcRect.y = 0;
		srcRect.w = transform->width;
		srcRect.h = transform->height;

	}

	void update() override {

		if (animated) {
			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speed) % frames);
		}

		srcRect.y = animIndex * transform->height;

		destRect.x = static_cast<int> (transform->position.x);
		destRect.y = static_cast<int> (transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override {
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void Play(const char* animName) {
		frames = animations[animName].frameCount;
		animIndex = animations[animName].index;
		speed = animations[animName].speed;
	}
};