#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <string>
#include <map>
#include <SDL.h>
#include <SDL_image.h>
#include "../Core/Engine.h"

class TextureManager
{
public:
	
	static TextureManager* GetInstance() { return sInstance = (sInstance != nullptr) ? sInstance : new TextureManager(); }

	bool Load(std::string id, std::string fileName);
	void Drop(std::string id);
	void Clean();

	void Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);

private:
	TextureManager() {}
	std::map<std::string, SDL_Texture*> mTextureMap;
	static TextureManager* sInstance;
};

#endif // !TEXTUREMANAGER_H