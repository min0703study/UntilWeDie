#pragma once
#include "GameObject.h"
class ObjectManager;
class Map: public GameObject
{
public:
	void init(float x, float y, float width, float height);
	void release(void);

	void update(void) {
		GameObject::update();

		move();
		action();
	};

	void render(void) {
		GameObject::render();

		draw();
		animation();
	};


	void draw();
	void animation();
	void move();
	void action();

	float getCenterX() { return CAMERA->getX() + (CAMERA_X / 2.0f); }; //∏ ¿« ∞°øÓµ• x
	float getGoundY() { return 400.0f; }; //∂•¿« ≥Ù¿Ã


private:
	ImageBase* mBgImg;
	ImageBase* mBgGrassImg;
	ImageBase* mShroomImg_01, * mShroomImg_02, * mShroomImg_03,*  mShroomImg_04,*  mShroomImg_05, * mShroomImg_06;
	ImageBase* mItems;
	RECT rcShroom_01, rcShroom_02, rcShroom_03, rcShroom_04, rcShroom_05, rcShroom_06;

	ObjectManager* mObjects;
};

