#include "Stdafx.h"
#include "MainGame.h"
#include "MainScene.h"

HRESULT MainGame::init(void)
{
	GameNode::init(true);

	SCENEMANAGER->addScene("main", new MainScene);
	SCENEMANAGER->changeScene("main");

	return S_OK;
}

void MainGame::update(void)
{
	GameNode::update();
	SCENEMANAGER->update();
}

void MainGame::release(void)
{
	GameNode::release();
	SCENEMANAGER->release();

}

void MainGame::render(void)
{
	PatBlt(getMemDc(), 0, 0, WINSIZE_X, WINSIZE_Y, BLACKNESS);

	SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDc());
	
	IMAGEMANAGER->render(getBackBufferKey(), getHdc());
}
