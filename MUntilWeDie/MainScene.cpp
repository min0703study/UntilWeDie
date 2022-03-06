#include "Stdafx.h"
#include "MainScene.h"

HRESULT MainScene::init(void)
{
	mMap = new Map;
	mMap->init(0,0, MAP::SIZE::CAMERA_X, MAP::SIZE::CAMERA_X);

	mPlayer = new Player;
	mPlayer->init(MAP::POS::PLAYER_X, GROUND, MAP::SIZE::PLAYER_X, MAP::SIZE::PLAYER_Y);

	mBuildManager = new BuildManager;
	mBuildManager->init(100, 100, 100, 100);

	mMonsterManager = new MonsterManager;
	mMonsterManager->init();
	mMonsterManager->setIPlayer(mPlayer);

	mPlayer->setIBuilding(mBuildManager);
	mPlayer->setIObject(mMap->getObjectManager());
	mMap->setIPlayer(mPlayer);
	mPlayer->setIMonster(mMonsterManager);

	mEggRespawnTime = TIMEMANAGER->getWorldTime();
	mMonsterRespawnTime = 0;

	respPos.x = mPlayer->getAbsX() - 300;
	respPos.y = mPlayer->getAbsY();


	isEndGame = false;

	isOn = false;

	mBgImg = IMAGEMANAGER->findImage(IMGCLASS->EndSecene);

	return S_OK;
}

void MainScene::update(void)
{
	mMonsterManager->setIPlayer(mPlayer);

	mMap->update();
	mBuildManager->update();
	mPlayer->update();

	/*mEggRespawnTime += TIMEMANAGER->getElapsedTime();
	if (mMonsterMng->getIsEggRespwan()) mMonsterRespawnTime += TIMEMANAGER->getElapsedTime();*/

	// 리스폰 시간 되면
	//if (isEggRespawn() && !(mMonsterManager->getIsEggRespwan())) {
	//	mMonsterManager->setMonsterEgg(respPos.x, GROUND, mMonsterManager->getNumberOfEgg());
	//	mMonsterRespawnTime = 0;
	//}
	//else if (isMonsterRespawn() && !isOn) {
	//	//mMonsterManager->setMonster(respPos.x - 100, GROUND, mPlayer->getAbsX() + 600, mPlayer->getAbsY(), 0);
	//	for (int i = 0; i < mMonsterManager->getNumberOfMonster(); i++) {
	//		mMonsterManager->setMonster(29520.3125f, GROUND, MAP::POS::GENERATOR_X, GROUND, i);
	//	}
	//	mEggRespawnTime = 0;
	//	isOn = true;
	//}
	if (KEYMANAGER->isOnceKeyDown('P')) {
		for (int i = 0; i < mMonsterManager->getNumberOfMonster(); i++) {
			mMonsterManager->setMonster(37000, GROUND, MAP::POS::GENERATOR_X, GROUND, i);
		}
	}
	
	if (!isEndGame && mPlayer->isDeath()) {
		this->isEndGame = true;
	}

	mMonsterManager->update();
	EFFECTMANAGER->update();
}

void MainScene::release(void)
{
	mMap->release();
	mBuildManager->release();
	mPlayer->release();
	mMonsterManager->release();
	EFFECTMANAGER->update();
}

void MainScene::render(void)
{
	mMap->render();
	mBuildManager->render();
	mMap->objectRender();
	mPlayer->render();
	mMonsterManager->render();
	EFFECTMANAGER->render();
	mMap->frontRender();

	if (isEndGame) {
		mBgImg->alphaRender(getMemDc(), 255);
	}
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
