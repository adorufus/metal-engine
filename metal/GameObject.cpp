#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, SDL_Renderer* _renderer, int _height, int _width) {
	renderer = _renderer;
	height = _height;
	width = _width;
	objectTexture = TextureManager::LoadTexture(texturesheet, renderer);
}

void GameObject::Update() {
	xPos = 0;
	yPos = 0;

	srcRect.h = height;
	srcRect.w = width;
	srcRect.y = 0;
	srcRect.x = 0;

	destRect.y = yPos;
	destRect.x = xPos;
	destRect.h = srcRect.h;
	destRect.w = srcRect.w;
}

void GameObject::Render() {
	SDL_RenderCopy(renderer, objectTexture, &srcRect, &destRect);
}