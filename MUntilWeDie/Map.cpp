#include "Stdafx.h"
#include "Map.h"

void Map::init(float x, float y, float width, float height)
{
	GameObject::Init("Map", x, y, width, height);
	mBckImg = IMAGEMANAGER->findImage(IMGCLASS->BkImg);
}

void Map::release(void)
{
}

void Map::draw()
{
	mBckImg->render(getMemDc(), 0, 0, CAMERA->getX(), CAMERA->getY(), mWidth, mBckImg->getHeight());
}

void Map::animation()
{
}

void Map::move()
{
}

void Map::action()
{
}
