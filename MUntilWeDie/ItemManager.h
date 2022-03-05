#pragma once
#include "GameNode.h"
#include "GameObject.h"

class DropItem: public GameObject {
public:
	void Init(string id, float x, float y, float width, float height, ImageBase* dropItem, eDirection dropDirection) {
		GameObject::Init(id, x, y, width, height);
		mImg = dropItem;
		mGravity = 0.0;
		mX = x;
		mY = y;
		mDropDirection = dropDirection;
		isEndDrop = false;
		isDropToPlayer = false;
	};


	void update(void) {
		move();
		action();
	};

	void render(void) {
		draw();
		animation();
	};

	void draw() {
		mImg->render(getMemDc(), getRc().left, getRc().top);
	};
	void animation() {};
	void move() {};
	void action() {};

	const int _dropSpeed = 2;

	ImageBase* mImg;

	float mGravity;
	eDirection mDropDirection;

	bool isEndDrop;
	bool isDropToPlayer;

	float mX;
	float mY;
};

class ItemManager: public GameNode
{
public:
	vector<DropItem*> mDropItems;

	HRESULT init();
	void release();
	void update();
	void render();

	void createDropItem(ImageBase* img, float x, float y, eDirection direction);
	void collisionCheckForDropItem(RECT& playerAbsRc);

};

