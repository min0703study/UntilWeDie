#include "Stdafx.h"
#include "Objects.h"

void Mushroom::init(float x, float y, float width, float height)
{
	GameObject::Init("Mushroom", x, y, width, height);

	isStartMushroomGrap = false;
	isEndMushroomGrap = false;
	mCount = GRAB_MUSHROOM_TIME;
}

void Mushroom::release(void)
{
}

void Mushroom::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mShroomAni.GetImage()->frameRender(getMemDc(), getRc().left, getRc().bottom - mShroomAni.GetImage()->getHeight(), mShroomFrameX, mShroomFrameY);
}

void Mushroom::animation()
{
}

void Mushroom::move()
{
}


void Mushroom::action()
{
	if (isStartMushroomGrap&&!isEndMushroomGrap) {
		mCount--;
		if (mCount % 150 == 0) {
			mShroomFrameX += 1;
			if (mShroomFrameX > mShroomAni.GetImage()->getMaxFrameX())
			{
				mShroomFrameX = 0;
			}
		}
		if (mCount <= 0) {
			isEndMushroomGrap = true;
		}
	}
}

void Debris::init(float x, float y, float width, float height)
{
	GameObject::Init("Debris", x, y, width, height);

	isStartDebrisGrap = false;
	isEndDebrisGrap = false;
	mCount = GRAB_MUSHROOM_TIME;
}

void Debris::release(void)
{
}

void Debris::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mDebrisAni.GetImage()->frameRender(getMemDc(), getRc().left, getRc().top, mDebrisFrameX, mDebrisFrameY);
}

void Debris::animation()
{
}

void Debris::move()
{
}

void Debris::action()
{
	if (isStartDebrisGrap && !isEndDebrisGrap) {
		mCount--;
		if (mCount % 150 == 0) {
			mDebrisFrameX += 1;
			if (mDebrisFrameX > mDebrisAni.GetImage()->getMaxFrameX())
			{
				mDebrisFrameX = 0;
			}
		}
		if (mCount <= 0) {
			isEndDebrisGrap = true;
		}
	}
}
