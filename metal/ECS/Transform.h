#include "Components.h"
#include "../Vector2D.h"

class Transform : public Component
{
public:
	Vector2D position;
	Vector2D velocity;

	int speed = 3;

	Transform() {
		position.x = 0;
		position.y = 0;
	}

	Transform(int x, int y) {
		position.x = x;
		position.y = y;
	}

	void init() override {
		velocity.x = 0;
		velocity.y = 0;
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