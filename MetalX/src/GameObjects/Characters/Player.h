#pragma once
#include "../Character.h"

class Player : public Character
{
public:
	Player();
	Player(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:
	int mRow, mFrame, mFrameCount;
	int animSpeed;
};

