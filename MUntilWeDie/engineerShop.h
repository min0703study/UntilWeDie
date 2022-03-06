#pragma once
#include "GameObject.h"

#define MAX_WRENCH_COUNT 5
#define MAX_UI_WRENCH_COUNT 4

struct Wrench {
	float x, y;
	float width;
	float height;
};

class engineerShop : public GameObject
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

	void giveWrenchCommand();
	void autoCreate();
	void intoNpc();

	void startBuild();

	void Monstertrue();

	void getWrenchCount();

	inline bool getIsBuild() {
		return mBuildType == eBuildingType::stand;
	}

private:
	vector<Wrench*> mWrenchs;
	vector<Wrench*>::iterator mItWrenchs;

	eBuildingType mBuildType;

	int mAniCount;
	int mBuildCount;

	bool isStartBuild;

	ImageBase* mImg;
	ImageBase* mImg_Tool;

	int mCurWrenchCount;
	int mCreateCount; 

	int mBuildHp;
	int setWrenchCount;

	bool isNpcIn;
};