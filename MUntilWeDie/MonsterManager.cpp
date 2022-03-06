#include "Stdafx.h"
#include "MonsterManager.h"
#include "IPlayer.h"
#include "Player.h"
#include "Npc.h"

void MonsterManager::init(void)
{
	mWorldTime = TIMEMANAGER->getWorldTime();
	mNumberOfEgg = mNumberOfMonster = 4;
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
	deleteMonster();
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
	for (int i = 0; i < number; i++) {
	}
	mbIsEggRespawn = true;
}

void MonsterManager::setMonster(float x, float y, int finalX, int finalY, int number)
{
	int monsterNumber;
	int worldTime = TIMEMANAGER->getWorldTime();

	monsterNumber = number;
	/*if(number < 3) monsterNumber = 3;
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
	}*/

	Monster* monster = new Monster;
	switch (monsterNumber)
	{
	case 0:
		monster->init
		(
			mIPlayer,
			static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_NORMAL_SEARCH_RANGE_X * 2, MON_NORMAL_SEARCH_RANGE_Y * 2,
			MON_NORMAL_ATTACK_RANGE_X * 2, MON_NORMAL_ATTACK_RANGE_Y * 2,
			MON_NORMAL_COLL_RANGE_X * 2, MON_NORMAL_COLL_RANGE_Y * 2,
			MON_NORMAL_IMAGE_RANGE_X * 2, MON_NORMAL_IMAGE_RANGE_Y * 2,
			finalX, finalY
		);
		break;
	case 1:
		monster->init
		(
			mIPlayer,
			static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_SUICIDE_SEARCH_RANGE_X * 2, MON_SUICIDE_SEARCH_RANGE_Y * 2,
			MON_SUICIDE_ATTACK_RANGE_X * 2, MON_SUICIDE_ATTACK_RANGE_Y * 2,
			MON_SUICIDE_COLL_RANGE_X * 2, MON_SUICIDE_COLL_RANGE_Y * 2,
			MON_SUICIDE_IMAGE_RANGE_X * 2, MON_SUICIDE_IMAGE_RANGE_Y * 2,
			finalX, finalY
		);
		break;
	case 2:
		monster->init
		(
			mIPlayer,
			static_cast<eMonsterType>(monsterNumber),
			x, y, 
			MON_FROG_SEARCH_RANGE_X * 2, MON_FROG_SEARCH_RANGE_Y * 2,
			MON_FROG_ATTACK_RANGE_X * 2, MON_FROG_ATTACK_RANGE_Y * 2,
			MON_FROG_COLL_RANGE_X * 2, MON_FROG_COLL_RANGE_Y * 2,
			MON_FROG_IMAGE_RANGE_X * 2, MON_FROG_IMAGE_RANGE_Y * 2,
			finalX, finalY
		);
		break;
	case 3:
		monster->init
		(
			mIPlayer,
			static_cast<eMonsterType>(monsterNumber), 
			x, y, 
			MON_CANNON_SEARCH_RANGE_X * 2, MON_CANNON_SEARCH_RANGE_Y * 2,
			MON_CANNON_ATTACK_RANGE_X * 2, MON_CANNON_ATTACK_RANGE_Y * 2,
			MON_CANNON_COLL_RANGE_X * 2, MON_CANNON_COLL_RANGE_Y * 2,
			MON_CANNON_IMAGE_RANGE_X * 2, MON_CANNON_IMAGE_RANGE_Y * 2,
			finalX, finalY
		);
		break;
	default:
		break;
	}

	mvMonster.push_back(monster);
}

void MonsterManager::deleteMonster(void)
{
	for (int i = 0; i < mvMonster.size(); i++) {
		if (mvMonster[i]->getCurrentHp() <= 0) {
			mvMonster[i]->addEffect(eMonsterEffectType::Death);
			mvMonster[i]->deleteAttack();
			mvMonster[i]->release();
			SAFE_DELETE(mvMonster[i]);
			mvMonster.erase(mvMonster.begin() + i);
		}
	}
}

void MonsterManager::setIPlayer(IPlayer * player)
{
	if (!mIPlayer) mIPlayer = player;
}

vector<RECT> MonsterManager::getMonstersAbsRc()
{
	vector<RECT> tmpVecRc;
	for (mviMonster = mvMonster.begin(); mviMonster != mvMonster.end(); ++mviMonster) {
		tmpVecRc.push_back((*mviMonster)->getAbsRc());
	}
	return tmpVecRc;
}

void MonsterManager::attackDamage(int damage, int arrNum)
{
	mvMonster[arrNum]->attackDamage(damage);
}
