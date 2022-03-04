#pragma once
#include "GameObject.h"
#include "ObjectManager.h"

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

	//float getCenterX() { return CAMERA->getX() + ( / 2.0f); }; //∏ ¿« ∞°øÓµ• x
	//float getGoundY() { return 400.0f; }; //∂•¿« ≥Ù¿Ã

	IObject* getObjectManager() { return (IObject*)mObjects; };


private:
	ImageBase* mBgImg;
	ImageBase* mBgGrassImg;
	ImageBase* mItems;

	ObjectManager* mObjects;
};

