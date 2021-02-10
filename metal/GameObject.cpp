#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int _height, int _width, int _xPos, int _yPos) {
	height = _height;
	width = _width;
	xPos = _xPos;
	yPos = _yPos;

	objectTexture = TextureManager::LoadTexture(texturesheet);
}

void GameObject::Update() {

	xPos++;
	yPos++;

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
	SDL_RenderCopy(Game::renderer, objectTexture, &srcRect, &destRect);
}