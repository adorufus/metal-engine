#pragma once
#include <string>
#include <iostream>
class Vector2D
{
public:
	float x, y;

public:
	Vector2D(float xPos = 0, float yPos = 0) : x(xPos), y(yPos) {

	}

public:
	inline Vector2D operator+(const Vector2D& v2) const {
		return Vector2D(x + v2.x, y + v2.y);
	}

	inline Vector2D operator-(const Vector2D& v2) const {
		return Vector2D(x - v2.x, y - v2.y);
	}

	inline Vector2D operator*(const float scalar) const {
		return Vector2D(x * scalar, y * scalar);
	}

	inline Vector2D operator/(const float scalar) const {
		return Vector2D(x / scalar, y / scalar);
	}

	void Log(std::string msg = "") {
		std::cout << msg << "X Y = [" << x << " " << y << "]" << std::endl;
	}
};

