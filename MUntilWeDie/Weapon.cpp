#include "Stdafx.h"
#include "Weapon.h"

HRESULT Weapon::init(const char * imageName)
{
	GameObject::Init("¹«±â", 0,  0, 10, 10);
	mIsFire = false;
	mShootSpeed = 7.0f;

	for (int i = 0; i < 5; i++)
	{
		tagBullet bullet;
		ZeroMemory(&bullet, sizeof(tagBullet));

		//mBulletImg = IMAGEMANAGER->findImage(imageName); 
		mVBullet.push_back(bullet);
	}

	return S_OK;
}

void Weapon::release(void)
{
	mVBullet.clear();
}

void Weapon::update(void)
{
	move();
	action();
}

void Weapon::render(void)
{
	draw();
	animation();
}

void Weapon::draw(void)
{
	for (mViBullet = mVBullet.begin(); mViBullet != mVBullet.end(); ++mViBullet) {
		if (!mIsFire) continue;
		RectangleMake(getMemDc(), mViBullet->rc);
		//mBulletImg->render(getMemDc(), mViBullet->x, mViBullet->y);
	}
} 

void Weapon::move(void)
{
	for (mViBullet = mVBullet.begin(); mViBullet != mVBullet.end(); ++mViBullet) {
		if (!mIsFire) continue;

		if (mDirection == eDirection::Left) {
			mViBullet->x -= mShootSpeed;
			mViBullet->y += mViBullet->direction;
			 
			mViBullet->rc = RectMakeCenter(mViBullet->x, mViBullet->y, mWidth, mHeight);

			if (mViBullet->fireX - mViBullet->x > 400) {
				mIsFire = false;
			}
		}
		else {
			mViBullet->x += mShootSpeed;
			mViBullet->y += mViBullet->direction;
			mViBullet->rc = RectMakeCenter(mViBullet->x, mViBullet->y, mWidth, mHeight);

			if (mViBullet->x - mViBullet->fireX > 400) {
				mIsFire = false;
			}
		}

	}
}

void Weapon::shoot(float x, float y, eDirection direction)
{
	if (mIsFire) return;
	mIsFire = true;  

	setAbsX(x);
	setAbsY(y);

	mDirection = direction;
	
	int directionFlag = 1;

	for (mViBullet = mVBullet.begin(); mViBullet != mVBullet.end(); ++mViBullet) {
		mViBullet->fireX = mViBullet->x = getX();
		mViBullet->fireY = mViBullet->y = getY();
		mViBullet->direction = RND->getFromFloatTo(0.3, 0.7) * directionFlag;
		directionFlag *= -1;
	}
}

void Weapon::removeBullet(int arrNum)
{

}
