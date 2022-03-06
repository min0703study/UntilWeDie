#include "Stdafx.h"
#include "ShopStalkers.h"

void ShopStalkers::init(float x, float y, float width, float height)
{
	GameObject::Init("shopStalkers", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off);
	mImg_Tool = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_weapon);

	mCreateCount = 0;

	isNpcIn = false;
	mBuildHp = 1;
}

void ShopStalkers::release(void)
{
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
	}
}

void ShopStalkers::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);

	mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
}

void ShopStalkers::animation()
{
	//Do thing
}

void ShopStalkers::move()
{
	//Do Nothing
}

void ShopStalkers::action()
{
	if (isNpcIn) {
		mCreateCount++;

		if (mCreateCount = 100) {
			mCreateCount = 0;
			autoCreate();
		}
	}

	else {
		mCreateCount = 0;
	}

	if (KEYMANAGER->isOnceKeyDown('4')) {
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_open);
	}

	if (KEYMANAGER->isOnceKeyDown('5')) {
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_stand);

		if (mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_stand)) {
			if (mCreateCount = 100 && setWeaponCount < 5) {
				mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('6')) {
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_close);
	}
}

void ShopStalkers::giveWeaponCommand()
{
	if (0 < mCurWeaponCount) {
		mCurWeaponCount--;
	}

	else {
		//상호작용 불가능
	}
}

void ShopStalkers::autoCreate()
{
	if (MAX_WEAPON_COUNT <= mCurWeaponCount) {
		mCreateCount = 100;
		mCurWeaponCount = 4;
	}

	else {
		mCurWeaponCount++;
		mCreateCount = 0;
	}
}

void ShopStalkers::intoNpc()
{
	if (isNpcIn == true) {
		giveWeaponCommand();
	}

	else {
		isNpcIn = true;
	}
}

void ShopStalkers::Monstertrue()
{
	//몬스터 충돌 영역 관리
}

void ShopStalkers::getWeaponCount()
{
	setWeaponCount++;
}