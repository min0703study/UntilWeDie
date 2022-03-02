#pragma once
#include "Monster.h"
#include "Projectile.h"

class Player;

class MonsterManager
{
public:
	void init(void);
	void release(void);
	void update(void);
	void render(void);

	vector<Monster*> getMonster(void) { return mvMonster; }
	vector<Projectile*> getAttackObject(void) { return mvAttackObject; }
	int getNumberOfEgg(void) { return mNumberOfEgg; }
	int getNumberOfMonster(void) { return mNumberOfMonster; }
	bool getIsEggRespwan(void) { return mbIsEggRespawn; }

	void setMonsterEgg(float x, float y, int number);
	void setMonster(float x, float y, int finalX, int finalY, int number);
	void setNumberOfMonster(int number) { mNumberOfMonster = number; }

	MonsterManager() {}
	~MonsterManager() {}
public:
	void getPlayerRef(Player* p)
	{
		mviMonster = mvMonster.begin();
		for (; mviMonster != mvMonster.end(); ++mviMonster) {
			(*mviMonster)->getPlayerRef(p);
		}
	}
private:
	Player* mPlayer;
private:
	vector<MonEgg> mvMonsterEgg;
	vector<Monster*> mvMonster;
	vector<Monster*>::iterator mviMonster;

	vector<Projectile*> mvAttackObject;
	vector<Projectile*>::iterator mviAttackObject;

	int mNumberOfEgg;
	int mNumberOfMonster;

	float mWorldTime;
	bool mbIsEggRespawn;
};

