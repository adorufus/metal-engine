#include "Components.h"

class Transform : public Component
{
private:
	int xPos;
	int yPos;

public:

	Transform() {
		xPos = 0;
		yPos = 0;
	}

	Transform(int x, int y) {
		xPos = x;
		yPos = y;
	}

	void update() override {
		xPos++;
		yPos++;
	}

	int x() { return xPos; }
	void x(int x) { xPos = x; }
	int y() { return yPos; }
	void y(int y) { yPos = y; }
	void setPos(int x, int y) {
		xPos = x;
		yPos = y;
	}
};