#include "Stdafx.h"
#include "Map.h"
#include "ObjectManager.h"

void Map::init(float x, float y, float width, float height)
{
	GameObject::Init("Map", x, y, width, height);
	mBgImg = IMAGEMANAGER->findImage(IMGCLASS->BgImg);
	mBgGrassImg = IMAGEMANAGER->findImage(IMGCLASS->BgGrassImg);

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
	mBgImg->render(getMemDc(), 0, -280, CAMERA->getX(), CAMERA->getY(), mWidth, mBgImg->getHeight());
	////¹ö¼¸ ¹× ¹ö¼¸³×¹¦
//	mObjects->render();
	//¾Õ¹è°æ
	mBgGrassImg->render(getMemDc(), 0, GROUND - 20, CAMERA->getX(), CAMERA->getY(), mWidth, mBgGrassImg->getHeight());
}

void Map::animation()
{
}

void Map::move()
{
	mObjects->update();
}

void Map::action()
{
}
