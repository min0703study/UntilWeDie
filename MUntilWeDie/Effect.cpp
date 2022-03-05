#include "Stdafx.h"
#include "Effect.h"

void Effect::init(char* imageKey, float x, float y, int frameY)
{
	mImage = IMAGEMANAGER->findImage(imageKey);
	GameObject::Init("Effect", x, y, mImage->getFrameWidth(), mImage->getFrameHeight());
	mFrameUpdateSec = 1.0f / 10.f;
	mElapsedSec = 0;
	mCurrentFrameX = 0;
	mCurrentFrameY = frameY;
	mbIsEnd = false;
}

void Effect::update(void)
{
	animation();
}

void Effect::release(void)
{
}

void Effect::render(void)
{
	draw();
}

void Effect::draw(void)
{
	mImage->frameRender(getMemDc(), getX() - getHalfWidth(), getY() - getHeight(), mCurrentFrameX, mCurrentFrameY);
}

void Effect::animation(void)
{
	mElapsedSec += TIMEMANAGER->getElapsedTime();

	if (mElapsedSec >= mFrameUpdateSec) {
		mElapsedSec = 0;
		mCurrentFrameX += 1;
		if (mCurrentFrameX > mImage->getMaxFrameX()) {
			mbIsEnd = true;
		}
	}
}