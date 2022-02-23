#include "Stdafx.h"
#include "MainScene.h"
#include "Player.h"

HRESULT MainScene::init(void)
{
	mPlayer = new Player;
	mPlayer->init(CAMERA_X / 2 - 20 ,CAMERA_Y - 190, PLAYER_X_SIZE, PLAYER_X_SIZE);

	mTempBkImg = IMAGEMANAGER->findImage(IMGCLASS->TempBkImg);
	

	return S_OK;
}

void MainScene::update(void)
{
	mPlayer->update();
}

void MainScene::release(void)
{
	mPlayer->release();
}

void MainScene::render(void)
{
	mTempBkImg->render(getMemDc(), 0,0, CAMERA->getX(), CAMERA->getY(), CAMERA->getWidth(), CAMERA->getHeight());
	mPlayer->render();
}
