#include "Stdafx.h"
#include "Map.h"

void Map::init(float x, float y, float width, float height)
{
	GameObject::Init("Map", x, y, width, height);
	mBgImg = IMAGEMANAGER->findImage(IMGCLASS->BgImg);
	mBgGrassImg = IMAGEMANAGER->findImage(IMGCLASS->BgGrassImg);
	mShroomImg_01 = mShroomImg_02 = mShroomImg_03 = mShroomImg_04 = mShroomImg_05 = mShroomImg_06 = IMAGEMANAGER->findImage(IMGCLASS->Object_Mushroom);

	rcShroom_01 = RectMake(MAP::POS::MUSHROOM_01_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
	rcShroom_02 = RectMake(MAP::POS::MUSHROOM_02_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
	rcShroom_03 = RectMake(MAP::POS::MUSHROOM_03_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
	rcShroom_04 = RectMake(MAP::POS::MUSHROOM_04_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
	rcShroom_05 = RectMake(MAP::POS::MUSHROOM_05_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);
	rcShroom_06 = RectMake(MAP::POS::MUSHROOM_06_X, MAP::POS::OBJECT_GROUND, MAP::SIZE::MUSHROOM_W, MAP::SIZE::MUSHROOM_H);

	count = index = 0;
}

void Map::release(void)
{
}

void Map::draw()
{
	//¹è°æ
	mBgImg->render(getMemDc(), 0, -280, CAMERA->getX(), CAMERA->getY(), mWidth, mBgImg->getHeight());
	//¹ö¼¸³×¹¦
	RectangleMake(getMemDc(), rcShroom_01.left, rcShroom_01.top, rcShroom_01.right, rcShroom_01.bottom);
	RectangleMake(getMemDc(), rcShroom_02.left, rcShroom_02.top, rcShroom_02.right, rcShroom_02.bottom);
	RectangleMake(getMemDc(), rcShroom_03.left, rcShroom_03.top, rcShroom_03.right, rcShroom_03.bottom);
	RectangleMake(getMemDc(), rcShroom_04.left, rcShroom_04.top, rcShroom_04.right, rcShroom_04.bottom);
	RectangleMake(getMemDc(), rcShroom_05.left, rcShroom_05.top, rcShroom_05.right, rcShroom_05.bottom);
	RectangleMake(getMemDc(), rcShroom_06.left, rcShroom_06.top, rcShroom_06.right, rcShroom_06.bottom);
	//¹ö¼¸
	mShroomImg_01->frameRender(getMemDc(), rcShroom_01.left - CAMERA->getX() , rcShroom_01.top - CAMERA->getY(), mShroomImg_01->getFrameX(), mShroomImg_01->getFrameY());
	mShroomImg_02->frameRender(getMemDc(), rcShroom_02.left - CAMERA->getX() , rcShroom_02.top - CAMERA->getY(), mShroomImg_02->getFrameX(), mShroomImg_02->getFrameY());
	mShroomImg_03->frameRender(getMemDc(), rcShroom_03.left - CAMERA->getX() , rcShroom_03.top - CAMERA->getY(), mShroomImg_03->getFrameX(), mShroomImg_03->getFrameY());
	mShroomImg_04->frameRender(getMemDc(), rcShroom_04.left - CAMERA->getX() , rcShroom_04.top - CAMERA->getY(), mShroomImg_04->getFrameX(), mShroomImg_04->getFrameY());
	mShroomImg_05->frameRender(getMemDc(), rcShroom_05.left - CAMERA->getX() , rcShroom_05.top - CAMERA->getY(), mShroomImg_05->getFrameX(), mShroomImg_05->getFrameY());
	mShroomImg_06->frameRender(getMemDc(), rcShroom_06.left - CAMERA->getX() , rcShroom_06.top - CAMERA->getY(), mShroomImg_06->getFrameX(), mShroomImg_06->getFrameY());


	//¹è°æ ¹Ù´Ú
	mBgGrassImg->render(getMemDc(), 0, GROUND + 50, CAMERA->getX(), CAMERA->getY(), mWidth, mBgGrassImg->getHeight());
}

void Map::animation()
{
	/*if ()
	{
		count++;
		if (count % 5 == 0)
		{
			index++;
			if (index > 4)
			{
				index = 0;
			}
		}
		mShroomImg_01->setFrameX(index);
	}*/
}

void Map::move()
{
}

void Map::action()
{
}
