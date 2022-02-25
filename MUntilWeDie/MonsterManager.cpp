#include "Stdafx.h"
#include "MonsterManager.h"

void MonsterManager::init(void)
{
	mWorldTime = TIMEMANAGER->getWorldTime();
	mNumberOfEgg = mNumberOfMonster = 3;
	mbIsEggRespawn = false;
}

void MonsterManager::release(void)
{
	mviMonster = mvMonster.begin();
	for (; mviMonster != mvMonster.end(); ++mviMonster) {
		(*mviMonster)->release();
		SAFE_DELETE((*mviMonster));
	}
}

void MonsterManager::update(void)
{
	mviMonster = mvMonster.begin();
	for (; mviMonster != mvMonster.end(); ++mviMonster) {
		(*mviMonster)->update();
	}
}

void MonsterManager::render(void)
{
	mviMonster = mvMonster.begin();
	for (; mviMonster != mvMonster.end(); ++mviMonster) {
		(*mviMonster)->render();
	}
}

void MonsterManager::setMonsterEgg(float x, float y, int number)
{
	cout << "egg respawn" << endl;
	for (int i = 0; i < number; i++) {
	}
	mbIsEggRespawn = true;
}

void MonsterManager::setMonster(float x, float y, int finalX, int finalY, int number)
{
	cout << "mon respawn" << endl;
	char* key;
	int monsterNumber;
	int worldTime = TIMEMANAGER->getWorldTime();

	if(number < 3) monsterNumber = 0;
	else {
		if (worldTime < 300) {
			monsterNumber = 0;
		}
		else if (worldTime >= 300 && worldTime < 600) {
			monsterNumber = RND->getInt(2);
		}
		else if (worldTime >= 600 && worldTime < 900) {
			monsterNumber = RND->getInt(3);
		}
		else if (worldTime >= 900) {
			monsterNumber = RND->getInt(4);
		}
	}

	Monster* monster = new Monster;
	switch (monsterNumber)
	{
	case 0:
		monster->init
		(
			"MonsterNormal", static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_NORMAL_SEARCH_RANGE_X, MON_NORMAL_SEARCH_RANGE_Y, 
			MON_NORMAL_ATTACK_RANGE_X, MON_NORMAL_ATTACK_RANGE_Y,
			MON_NORMAL_COLL_RANGE_X, MON_NORMAL_COLL_RANGE_Y, 
			finalX, finalY
		);
		break;
	case 1:
		monster->init
		(
			"MonsterSuicide", static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_SUICIDE_SEARCH_RANGE_X, MON_SUICIDE_SEARCH_RANGE_Y,
			MON_SUICIDE_ATTACK_RANGE_X, MON_SUICIDE_ATTACK_RANGE_Y,
			MON_SUICIDE_COLL_RANGE_X, MON_SUICIDE_COLL_RANGE_Y, 
			finalX, finalY
		);
		break;
	case 2:
		monster->init
		(
			"MonsterFrog", static_cast<eMonsterType>(monsterNumber),
			x, y, 
			MON_FROG_SEARCH_RANGE_X, MON_FROG_SEARCH_RANGE_Y,
			MON_FROG_ATTACK_RANGE_X, MON_FROG_ATTACK_RANGE_Y,
			MON_FROG_COLL_RANGE_X, MON_FROG_COLL_RANGE_Y, 
			finalX, finalY
		);
		break;
	case 3:
		monster->init
		(
			"MonsterCannon", static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_CANNON_SEARCH_RANGE_X, MON_CANNON_SEARCH_RANGE_Y,
			MON_CANNON_ATTACK_RANGE_X, MON_CANNON_ATTACK_RANGE_Y,
			MON_CANNON_COLL_RANGE_X, MON_CANNON_COLL_RANGE_Y, 
			finalX, finalY
		);
		break;
	default:
		break;
	}

	mvMonster.push_back(monster);
}
