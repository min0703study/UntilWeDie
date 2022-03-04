#pragma once
#include "GameObject.h"

#define MAX_WEAPON_COUNT 5
#define MAX_UI_WEAPON_COUNT 4

struct Weapon {
	float x, y;
	float width;
	float height;
};

class ShopStalkers : public GameObject
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

	void giveWeaponCommand();
	void autoCreate();
	void intoNpc();

	void Monstertrue();

private:
	vector<Weapon*> mWeapons;
	vector<Weapon*>::iterator mItWeapons;

	ImageBase* mImg;

	int mCurWeaponCount;
	int mCreateCount;

	int mBuildHp;

	bool isNpcIn;
};