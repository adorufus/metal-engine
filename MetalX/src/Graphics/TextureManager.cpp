#include "TextureManager.h"

TextureManager* TextureManager::sInstance = nullptr;

Engine* engineInstance = Engine::GetInstance();

bool TextureManager::Load(std::string id, std::string fileName) {
	SDL_Surface* surface = IMG_Load(fileName.c_str());

	if (surface == nullptr) {
		SDL_Log("Failed To Load Texture: %s, Error: %s", fileName.c_str(), SDL_GetError());
		return false;
	}
	else {
		SDL_Log("Texture %s Loaded", fileName.c_str());
	}

	SDL_Texture* texture = SDL_CreateTextureFromSurface(engineInstance->GetRenderer(), surface);

	if (texture == nullptr) {
		SDL_Log("could not add the texture %s", SDL_GetError());
		return false;
	}
	else {
		SDL_Log("Texture Loaded!");
	}

	mTextureMap[id] = texture;
	return true;
}
void TextureManager::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip) {
	SDL_Rect srcRect = { 0, 0, width, height };
	SDL_Rect dstRect = { x, y, width, height };

	SDL_RenderCopyEx(engineInstance->GetRenderer(), mTextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip) {
	SDL_Rect srcRect = { width * frame, height * (row - 1), width, height };
	SDL_Rect dstRect = { x, y, width, height };

	SDL_RenderCopyEx(engineInstance->GetRenderer(), mTextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager::Drop(std::string id) {
	SDL_DestroyTexture(mTextureMap[id]);
	mTextureMap.erase(id);
}

void TextureManager::Clean() {
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = mTextureMap.begin(); it != mTextureMap.end(); it++)
		SDL_DestroyTexture(it->second);

	mTextureMap.clear();

	SDL_Log("Texture map cleaned");
}