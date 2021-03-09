#pragma once
#include "IObject.h"
#include "../Physics/Transform.h"
#include <SDL.h>

struct Properties {

	Properties(std::string _textureID, int xPos, int yPos, int _width, int _height, SDL_RendererFlip _flip = SDL_FLIP_NONE) {
		textureID = _textureID;
		xPos = x;
		yPos = y;
		width = _width;
		height = _height;
		flip = _flip;
	}

public:
	std::string textureID;
	int width, height;
	float x, y;
	SDL_RendererFlip flip;
};

class GameObject : public IObject
{
public:
	GameObject() {}
	GameObject(Properties* props) : mTextureID(props->textureID), mWidth(props->width), mHeight(props->height), mFlip(props->flip) {
		mTransform = new Transform(props->x, props->y);
	}

	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;

protected:
	Transform* mTransform;
	int mWidth, mHeight;
	std::string mTextureID;
	SDL_RendererFlip mFlip;
};

