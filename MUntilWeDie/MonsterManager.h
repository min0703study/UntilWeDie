#pragma once
#include "Monster.h"

class MonsterManager
{
public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);

	vector<Monster*> getMonster(void) { return mvMonster; }
	int getNumberOfEgg(void) { return mNumberOfEgg; }
	int getNumberOfMonster(void) { return mNumberOfMonster; }
	bool getIsEggRespwan(void) { return mbIsEggRespawn; }

	void setMonsterEgg(float x, float y, int number);
	void setMonster(float x, float y, int finalX, int finalY, int number);
	void setNumberOfMonster(int number) { mNumberOfMonster = number; }

	MonsterManager() {}
	~MonsterManager() {}
private:
	vector<MonEgg> mvMonsterEgg;
	vector<Monster*> mvMonster;
	vector<Monster*>::iterator mviMonster;

	int mNumberOfEgg;
	int mNumberOfMonster;

	float mWorldTime;
	bool mbIsEggRespawn;
};

