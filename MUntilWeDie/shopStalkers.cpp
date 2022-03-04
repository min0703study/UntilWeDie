#include "Stdafx.h"
#include "shopStalkers.h"

void shopStalkers::init(float x, float y, float width, float height)
{
	GameObject::Init("shopStalkers", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off);

	mCreateCount = 0;

	isNpcIn = false;
	mBuildHp = 1;
}

void shopStalkers::release(void)
{
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
	}
}

void shopStalkers::draw()
{
	RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);
}

void shopStalkers::animation()
{
	//Do thing
}

void shopStalkers::move()
{
	//Do Nothing
}

void shopStalkers::action()
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
}

void shopStalkers::giveWeaponCommand()
{
	if (0 < mCurWeaponCount) {
		mCurWeaponCount--;
	}

	else {
		//상호작용 불가능
	}
}

void shopStalkers::autoCreate()
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

void shopStalkers::intoNpc()
{
	if (isNpcIn == true) {
		giveWeaponCommand();
	}

	else {
		isNpcIn = true;
	}
}

void shopStalkers::Monstertrue()
{
	//몬스터 충돌 영역 관리
}