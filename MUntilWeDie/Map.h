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

	float getCenterX() { return CAMERA->getX() + (CAMERA_X / 2.0f); }; //���� ��� x
	float getGoundY() { return 400.0f; }; //���� ����

private:
	ImageBase* mBckImg;
};

