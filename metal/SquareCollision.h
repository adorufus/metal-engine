#pragma once
#include <SDL.h>

class Collider;

class SquareCollision
{
public:
	static bool AABB(const SDL_Rect& recA, const SDL_Rect& recB);
	static bool AABB(const Collider& colA, const Collider& colB);
};

