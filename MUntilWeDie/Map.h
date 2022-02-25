#pragma once
#include "GameObject.h"

class Map: public GameObject
{
public:
	void init(float x, float y, float width, float height);
	void release(void);

	void update(void) {
		move();
		action();
	};

	void render(void) {
		draw();
		animation();
	};


	void draw();
	void animation();
	void move();
	void action();

	float getCenterX() { return CAMERA->getX() + (CAMERA_X / 2.0f); }; //맵의 가운데 x
	float getGoundY() { return 400.0f; }; //땅의 높이

private:
	ImageBase* mBckImg;
};

