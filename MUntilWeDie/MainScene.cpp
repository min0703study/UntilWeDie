#include "Stdafx.h"
#include "MainScene.h"

HRESULT MainScene::init(void)
{

	mMap = new Map;
	mMap->init(0,0, CAMERA_X, CAMERA_Y);

	mPlayer = new Player;
	mPlayer->init(mMap->getCenterX(),mMap->getGoundY() + 280, 100.0f, 100.0f);

	return S_OK;
}

void MainScene::update(void)
{
	mMap->update();
	mPlayer->update();
}

void MainScene::release(void)
{
	mMap->release();
	mPlayer->release();
}

void MainScene::render(void)
{
	mMap->render();
	mPlayer->render();
}