#pragma once
#include "GameObject.h"

#define MAX_SHOVEL_COUNT 5
#define MAX_UI_SHOVEL_COUNT 4

struct Shovel {
	float x, y;
	float width;
	float height;
};

class ShovelShop: public GameObject
{
public:
	enum class eBuildingType {
		off,
		off_2,
		stand,
		open,
		close
	};

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
	void autoCreate();
	void intoNpc();

	void Monstertrue();

private:
	vector<Shovel*> mShovels;
	vector<Shovel*>::iterator mItShovels;

	ImageBase* mImg;

	int mCurShovelCount; //삽 생성 갯수
	int mCreateCount;  //삽이 생성되기까지 걸리는 시간

	int mBuildHp; //건물 체력

	bool isNpcIn; //NPC가 들어갔는지 안들어갔는지
};

