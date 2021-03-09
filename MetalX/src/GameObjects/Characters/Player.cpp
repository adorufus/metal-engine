#include "Player.h"
#include "../../Graphics/TextureManager.h"
#include <SDL.h>

TextureManager* textureMgr = TextureManager::GetInstance();

Player::Player(Properties* props) {
	SDL_Log("initialize player");
	mRow = 1;
	mFrameCount = 3;
	animSpeed = 80;
}

void Player::Update(float dt) {
	mFrame = (SDL_GetTicks() / animSpeed) % mFrameCount;
}

void Player::Draw() {
	SDL_Log("drawing sprite");
	textureMgr->DrawFrame(mTextureID, mTransform->x, mTransform->y, mWidth, mHeight, mRow, mFrame);
}

void Player::Clean() {
	textureMgr->Clean();
}