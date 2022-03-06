#include "Stdafx.h"
#include "Map.h"
#include "ObjectManager.h"

void Map::init(float x, float y, float width, float height)
{
	GameObject::Init("Map", x, y, width, height);
	mBgBackImg = IMAGEMANAGER->findImage(IMGCLASS->BgBackImg);
	mBgImg = IMAGEMANAGER->findImage(IMGCLASS->BgImg);
	mBgMiddleImg = IMAGEMANAGER->findImage(IMGCLASS->BgMiddleImg);
	mBgGrassImg = IMAGEMANAGER->findImage(IMGCLASS->BgGrassImg);

	mCocoonImg_03 = mCocoonImg_06 = mCocoonImg_12 = 
	IMAGEMANAGER->findImage(IMGCLASS->Object_Cocoon1);
	mCocoonImg_02 = mCocoonImg_09 = mCocoonImg_11 = mCocoonImg_13 = 
	IMAGEMANAGER->findImage(IMGCLASS->Object_Cocoon3);
	mCocoonImg_05 = mCocoonImg_07 = IMAGEMANAGER->findImage(IMGCLASS->Object_Cocoon4);
	mCocoonImg_01 = mCocoonImg_04 = mCocoonImg_08 = mCocoonImg_10 = mCocoonImg_14 = 
	IMAGEMANAGER->findImage(IMGCLASS->Object_Cocoon6);

	mCocoonHiveImg_01 = mCocoonHiveImg_02 = mCocoonHiveImg_03 = 
	mCocoonHiveImg_04 = mCocoonHiveImg_05 = mCocoonHiveImg_06 = 
	IMAGEMANAGER->findImage(IMGCLASS->Object_CocoonHive);

	mWaterFallImg = IMAGEMANAGER->findImage(IMGCLASS->WaterFallImg);
	mWaterFallMImg = IMAGEMANAGER->findImage(IMGCLASS->WaterFallMImg);
	mWaterFallSImg_01 = IMAGEMANAGER->findImage(IMGCLASS->WaterFallSImg);
	mWaterFallSImg_02 = IMAGEMANAGER->findImage(IMGCLASS->WaterFallSImg);

	mObjects = new  ObjectManager;
	mObjects->init(MAP::POS::MUSHROOM_01_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
}

void Map::release(void)
{
	GameObject::release();

	mObjects->release();
	SAFE_DELETE(mObjects);
}

void Map::draw()
{
	//¹è°æ
	mBgBackImg->render(getMemDc(), 0, -280, CAMERA->getX(), CAMERA->getY(), mWidth, mBgBackImg->getHeight());
	mWaterFallImg->frameRender(getMemDc(), 17684 - CAMERA->getX(), 0 - CAMERA->getY(), mCurrentWaterFrameX, mCurrentWaterFrameY);
	mWaterFallMImg->frameRender(getMemDc(), 17834 - CAMERA->getX(), 0 - CAMERA->getY(), mCurrentWaterMFrameX, mCurrentWaterMFrameY);
	mWaterFallSImg_01->frameRender(getMemDc(), 17654 - CAMERA->getX(), 0 - CAMERA->getY(), mCurrentWaterMFrameX, mCurrentWaterMFrameY);
	mWaterFallSImg_02->frameRender(getMemDc(), 18000 - CAMERA->getX(), 0 - CAMERA->getY(), mCurrentWaterMFrameX, mCurrentWaterMFrameY);
	mBgImg->render(getMemDc(), 0, -280, CAMERA->getX(), CAMERA->getY(), mWidth, mBgImg->getHeight());
	////¹ö¼¸ ¹× ¹ö¼¸³×¹¦
//	mObjects->render();
	//¾Õ¹è°æ
	//mBgGrassImg->render(getMemDc(), 0, GROUND - 20, CAMERA->getX(), CAMERA->getY(), mWidth, mBgGrassImg->getHeight());
}

void Map::animation()
{
	if (mHiveTime + 0.2f < TIMEMANAGER->getWorldTime()) {
		mCurrentFrameHiveX += 1;
		if (mCurrentFrameHiveX > mCocoonHiveImg_01->getMaxFrameX() - 1)
		{
			mCurrentFrameHiveX = 0;
		}
		mHiveTime = TIMEMANAGER->getWorldTime();
	}

	if (mCocoonTime + 0.2f < TIMEMANAGER->getWorldTime()) {
		mCurrentFrameCocoonX += 1;
		if (mCurrentFrameCocoonX > mCocoonImg_01->getMaxFrameX() - 1)
		{
			mCurrentFrameCocoonX = 0;
		}
		mCocoonTime = TIMEMANAGER->getWorldTime();
	}

	if (mWaterTime + 0.1f < TIMEMANAGER->getWorldTime()) {
		mCurrentWaterFrameX += 1;
		if (mCurrentWaterFrameX > mWaterFallImg->getMaxFrameX() - 1)
		{
			mCurrentWaterFrameX = 0;
		}
		mWaterTime = TIMEMANAGER->getWorldTime();
	}

	if (mWaterMTime + 0.1f < TIMEMANAGER->getWorldTime()) {
		mCurrentWaterMFrameX += 1;
		if (mCurrentWaterMFrameX > mWaterFallMImg->getMaxFrameX() - 1)
		{
			mCurrentWaterMFrameX = 0;
		}
		mWaterMTime = TIMEMANAGER->getWorldTime();
	}
}

void Map::move()
{
	mObjects->update();
}

void Map::action()
{
}
