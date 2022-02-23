#include "Stdafx.h"
#include "MainScene.h"
#include "Player.h"

HRESULT MainScene::init(void)
{
	mPlayer = new Player;
	mPlayer->init(CAMERA_X / 2 - 20 ,CAMERA_Y - 190, 100.0f, 100.0f);

	mTempBkImg = IMAGEMANAGER->findImage(IMGCLASS->TEMP_BK_IMG);
	

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
	mTempBkImg->render(getMemDc(), 0,0, CANERA->GetX(), CANERA->GetY(), CANERA->GetWidth(), CANERA->GetHeight());
	mPlayer->render();
}
