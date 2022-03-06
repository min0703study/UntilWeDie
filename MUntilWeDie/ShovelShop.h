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

	void startBuild();

	void Monstertrue();

	void getShovelCount(); //�� �߰�


	inline bool getIsBuild() {
		return mBuildType == eBuildingType::stand;
	}

private:
	vector<Shovel*> mShovels;
	vector<Shovel*>::iterator mItShovels;

	eBuildingType mBuildType;

	int mAniCount;
	int mBuildCount;

	bool isStartBuild;

	ImageBase* mImg;
	ImageBase* mImg_Tool;

	int mCurShovelCount; //�� ���� ����
	int mCreateCount;  //���� �����Ǳ���� �ɸ��� �ð�

	int mBuildHp; //�ǹ� ü��
	int setShovelCount; //���� �� ����

	bool isNpcIn; //NPC�� ������ �ȵ�����

};

