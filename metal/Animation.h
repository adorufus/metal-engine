#pragma once
struct Animation {
	int index;
	int frameCount;
	int speed;

	Animation() {}
	Animation(int i, int f, int s) {
		index = i;
		frameCount = f;
		speed = s;
	}
};