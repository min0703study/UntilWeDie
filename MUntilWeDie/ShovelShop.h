#pragma once
#include "GameObject.h"

#define MAX_SHOVEL_COUNT 5
#define MAX_UI_SHOVEL_COUNT 4

struct Shovel {

};

class ShovelShop: public GameObject
{
public:
	void init(float x, float y, float width, float height);
	void release(void);

	void update(void)
	{
		move();
		action();
	};

	void render(void)
	{
		draw();
		animation();
	};

	void draw();
	void animation();
	void move();
	void action();

	void giveShovelCommand();
	void autoGenerator();
	void intoNpc();
private:
	vector<Shovel*> mShovels;
	vector<Shovel*>::iterator mItShovels;

	ImageBase* mImg;

	int mCurShovelCount;
	int mGeneratorCount;

	bool isNpcIn;
};

