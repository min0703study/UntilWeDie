#include "Stdafx.h"
#include "MainScene.h"
#include "Player.h"
#include "MonsterManager.h"

HRESULT MainScene::init(void)
{
	mPlayer = new Player;
	mPlayer->init(CAMERA_X / 2 - 20 ,CAMERA_Y - 190, PLAYER_X_SIZE, PLAYER_X_SIZE);

	mMonsterMng = new MonsterManager;
	mMonsterMng->init();

	mTempBkImg = IMAGEMANAGER->findImage(IMGCLASS->TempBkImg);
	
	mEggRespawnTime = TIMEMANAGER->getWorldTime();
	mMonsterRespawnTime = 0;

	respPos.x = mPlayer->getX() - 300;
	respPos.y = mPlayer->getY();

	return S_OK;
}

void MainScene::update(void)
{
	/*mEggRespawnTime += TIMEMANAGER->getElapsedTime();
	if (mMonsterMng->getIsEggRespwan()) mMonsterRespawnTime += TIMEMANAGER->getElapsedTime();*/

	// 리스폰 시간 되면
	if (isEggRespawn() && !(mMonsterMng->getIsEggRespwan())) {
		mMonsterMng->setMonsterEgg(respPos.x, respPos.y, mMonsterMng->getNumberOfEgg());
		mMonsterRespawnTime = 0;
	}
	else if (isMonsterRespawn()) {
		for (int i = 0; i < mMonsterMng->getNumberOfMonster(); i++) {
			mMonsterMng->setMonster(respPos.x - i * 50, respPos.y, mPlayer->getX() + 300, mPlayer->getY(), i);
		}
		mEggRespawnTime = 0;
	}

	mPlayer->update();
	mMonsterMng->update();
}

void MainScene::release(void)
{
	mPlayer->release();
	mMonsterMng->release();
}

void MainScene::render(void)
{
	mTempBkImg->render(getMemDc(), 0,0, CAMERA->getX(), CAMERA->getY(), CAMERA->getWidth(), CAMERA->getHeight());
	mPlayer->render();
	mMonsterMng->render();
}

bool MainScene::isEggRespawn(void)
{
	if (mEggRespawnTime + 3.0f <= TIMEMANAGER->getWorldTime()) {
		mEggRespawnTime = TIMEMANAGER->getWorldTime();
		return true;
	}
	return false;
}

bool MainScene::isMonsterRespawn(void)
{
	if (mMonsterRespawnTime + 3.0f <= TIMEMANAGER->getWorldTime()) {
		mMonsterRespawnTime = TIMEMANAGER->getWorldTime();
		return true;
	}
	return false;
}
