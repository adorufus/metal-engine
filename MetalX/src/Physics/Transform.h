#pragma once
#include "Vector2D.h"

class Transform
{
public:
	float x, y;

public:
	Transform(float xPos = 0, float yPos = 0) : x (xPos), y(yPos){}
	void Log(std::string msg = "") {
		std::cout << msg << "(x y) = [" << x << " " << y << "]" << std::endl;
	}

private:
	inline void TranslateX(float xPos) { x += xPos; }
	inline void TranslateY(float yPos) { y += yPos; }
	inline void Translate(Vector2D v) { x += v.x; y += v.y; }
};

