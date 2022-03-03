#include "Stdafx.h"
#include "MainScene.h"

HRESULT MainScene::init(void)
{
	mMap = new Map;
	mMap->init(0,0, CAMERA_X, CAMERA_Y);

	mPlayer = new Player;
	mPlayer->init(mMap->getCenterX(), GROUND, PLAYER_X_SIZE, PLAYER_Y_SIZE);

	mBuildManager = new BuildManager;
	mBuildManager->init(100, 100, 100, 100);

	mPlayer->setIBuilding(mBuildManager);
	mPlayer->setIObject(mMap->getObjectManager());

	mMonsterMng = new MonsterManager;
	mMonsterMng->init();
	mMonsterMng->setIPlayer(mPlayer);
	
	mEggRespawnTime = TIMEMANAGER->getWorldTime();
	mMonsterRespawnTime = 0;

	respPos.x = mPlayer->getAbsX() - 300;
	respPos.y = mPlayer->getAbsY();

	isOn = false;

	return S_OK;
}

void MainScene::update(void)
{
	mMap->update();
	mPlayer->update();
	mBuildManager->update();

	/*mEggRespawnTime += TIMEMANAGER->getElapsedTime();
	if (mMonsterMng->getIsEggRespwan()) mMonsterRespawnTime += TIMEMANAGER->getElapsedTime();*/

	// 리스폰 시간 되면
	if (isEggRespawn() && !(mMonsterMng->getIsEggRespwan())) {
		mMonsterMng->setMonsterEgg(respPos.x, respPos.y, mMonsterMng->getNumberOfEgg());
		mMonsterRespawnTime = 0;
	}
	else if (isMonsterRespawn() && !isOn) {
		//mMonsterMng->setMonster(respPos.x - 100, respPos.y, mPlayer->getX() + 600, mPlayer->getY(), 0);
		for (int i = 0; i < mMonsterMng->getNumberOfMonster(); i++) {
			mMonsterMng->setMonster(respPos.x - i * 100, respPos.y, mPlayer->getX() + 600, mPlayer->getY(), i);
		}
		mEggRespawnTime = 0;
		isOn = true;
	}

	mMonsterMng->getPlayerRef(mPlayer);
	mMonsterMng->update();

}

void MainScene::release(void)
{
	mMap->release();
	mPlayer->release();
	mBuildManager->release();
	mMonsterMng->release();
}

void MainScene::render(void)
{
	mMap->render();
	mBuildManager->render();
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
