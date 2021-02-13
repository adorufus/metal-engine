#include "Components.h"
#include "../Vector2D.h"

class Transform : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int height = 32;
	int width = 32;
	int scale = 1;

	int speed = 3;

	Transform() {
		position.Zero();
	}

	Transform(int _scale) {
		position.Zero();
		scale = _scale;
	}

	Transform(float x, float y) {
		position.x = x;
		position.y = y;
	}

	Transform(float x, float y, int _width, int _height, int _scale) {
		position.x = x;
		position.y = y;

		height = _height;
		width = _width;
		scale = _scale;
	}

	void init() override {
		velocity.Zero();
	}

	void update() override {
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}

	/*int x() { return xPos; }
	void x(int x) { xPos = x; }
	int y() { return yPos; }
	void y(int y) { yPos = y; }
	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}*/
};