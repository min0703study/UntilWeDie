#pragma once
#include "GameObject.h"
#include "ObjectManager.h"

class Map: public GameObject
{
public:
	void init(float x, float y, float width, float height);
	void release(void);

	void update(void) {
		GameObject::update();

		move();
		action();
	};

	void render(void) {
		GameObject::render();

		draw();
		animation();
	};

	void objectRender(void) {
		GameObject::render();

		////πˆº∏ π◊ πˆº∏≥◊π¶
		mObjects->render();
	}

	void frontRender(void) {
		GameObject::render(); 
		mBgGrassImg->render(getMemDc(), 0, GROUND - 20, CAMERA->getX(), CAMERA->getY(), mWidth, mBgGrassImg->getHeight());

		mCocoonImg_01->frameRender(getMemDc(), 8150 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);
		mCocoonImg_02->frameRender(getMemDc(), 8415 - CAMERA->getX(), 210 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_03->frameRender(getMemDc(), 8901 - CAMERA->getX(), 200 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);	
		mCocoonImg_04->frameRender(getMemDc(), 13835 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_05->frameRender(getMemDc(), 14320 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_06->frameRender(getMemDc(), 14851 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);	
		mCocoonImg_07->frameRender(getMemDc(), 36762 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);	
		mCocoonImg_08->frameRender(getMemDc(), 37016 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);	
		mCocoonImg_09->frameRender(getMemDc(), 37256 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_10->frameRender(getMemDc(), 39759 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_11->frameRender(getMemDc(), 40036 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_12->frameRender(getMemDc(), 40527 - CAMERA->getX(), 180 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_13->frameRender(getMemDc(), 45338 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);		
		mCocoonImg_14->frameRender(getMemDc(), 45853 - CAMERA->getX(), 220 - CAMERA->getY(), mCurrentFrameCocoonX, mCurrentFrameCocoonY);

		mCocoonHiveImg_01->frameRender(getMemDc(), 7499 - CAMERA->getX(), 140 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);		
		mCocoonHiveImg_02->frameRender(getMemDc(), 12165 - CAMERA->getX(), 70 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);	
		mCocoonHiveImg_03->frameRender(getMemDc(), 15533 - CAMERA->getX(), 110 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);	
		mCocoonHiveImg_04->frameRender(getMemDc(), 18875 - CAMERA->getX(), 75 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);	
		mCocoonHiveImg_05->frameRender(getMemDc(), 38640 - CAMERA->getX(),  75 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);	
		mCocoonHiveImg_06->frameRender(getMemDc(), 44089 - CAMERA->getX(), 110 - CAMERA->getY(), mCurrentFrameHiveX, mCurrentFrameHiveY);

		mBgMiddleImg->render(getMemDc(), 0, -280, CAMERA->getX(), CAMERA->getY(), mWidth, mBgMiddleImg->getHeight());

		animation();
	}

	void draw();
	void animation();
	void move();
	void action();

	void setIPlayer(IPlayer* iPlayer) { mObjects->setIPlayer(iPlayer); }

	//float getCenterX() { return CAMERA->getX() + ( / 2.0f); }; //∏ ¿« ∞°øÓµ• x
	//float getGoundY() { return 400.0f; }; //∂•¿« ≥Ù¿Ã

	IObject* getObjectManager() { return (IObject*)mObjects; };


private:
	ImageBase* mBgBackImg;
	ImageBase* mBgImg;
	ImageBase* mBgMiddleImg;
	ImageBase* mBgGrassImg;
	ImageBase* mCocoonImg_01, *mCocoonImg_02, *mCocoonImg_03,
					   *mCocoonImg_04, *mCocoonImg_05, *mCocoonImg_06,
					   *mCocoonImg_07, *mCocoonImg_08, *mCocoonImg_09,
					   *mCocoonImg_10, *mCocoonImg_11, *mCocoonImg_12,
					   *mCocoonImg_13, *mCocoonImg_14;
	ImageBase* mCocoonHiveImg_01, *mCocoonHiveImg_02, *mCocoonHiveImg_03,
					   *mCocoonHiveImg_04, *mCocoonHiveImg_05, *mCocoonHiveImg_06 ;
	ImageBase* mItems;

	ImageBase* mWaterFallImg;
	ImageBase* mWaterFallMImg;
	ImageBase* mWaterFallSImg_01;
	ImageBase* mWaterFallSImg_02;

	ObjectManager* mObjects;

	float mCurrentFrameCocoonX, mCurrentFrameCocoonY;
	float mCurrentFrameHiveX, mCurrentFrameHiveY;
	float mCurrentWaterFrameX, mCurrentWaterFrameY;
	float mCurrentWaterMFrameX, mCurrentWaterMFrameY;

	float mCocoonTime;
	float mHiveTime;
	float mWaterTime;
	float mWaterMTime;
};

