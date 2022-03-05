#include "Stdafx.h"
#include "Objects.h"

void Mushroom::init(float x, float y, float width, float height)
{
	GameObject::Init("Mushroom", x, y, width, height);

	isStartGrap = false;
	isEndGrap = false;
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
	if (isStartGrap&&!isEndGrap) {
		mCount--;
		if (mCount % 150 == 0) {
			mShroomFrameX += 1;
			if (mShroomFrameX > mShroomAni.GetImage()->getMaxFrameX())
			{
				mShroomFrameX = 0;
			}
		}
		if (mCount <= 0) {
			isEndGrap = true;
		}
	}
}

void Debris::init(float x, float y, float width, float height)
{
	GameObject::Init("Debris", x, y, width, height);
}

void Debris::release(void)
{
}

void Debris::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mDebrisAni.GetImage()->frameRender(getMemDc(), getRc().left, getRc().top);
}

void Debris::animation()
{
}

void Debris::move()
{
}

void Debris::action()
{
}
