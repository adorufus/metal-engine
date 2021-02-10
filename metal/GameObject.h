#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* textureSheet, int _height, int _width, int _xPos, int _yPos);
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
};

