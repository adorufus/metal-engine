#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, SDL_Renderer* _renderer, int _height, int _width);
	~GameObject();

	void Update();
	void Render();

private:
	int xPos;
	int yPos;
	int height;
	int width;
	SDL_Texture* objectTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};

