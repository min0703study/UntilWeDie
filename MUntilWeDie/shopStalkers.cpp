#include "Stdafx.h"
#include "ShopStalkers.h"

void ShopStalkers::init(float x, float y, float width, float height)
{
	GameObject::Init("shopStalkers", x, y, width, height);

	mBuildCount = BUILD_BUILDING_TIME;

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off);
	mImg_Tool = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_weapon);

	mBuildType = eBuildingType::off;

	mCreateCount = 0;
	setWeaponCount = 2;

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
	switch (mBuildType)
	{
	case eBuildingType::close:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off_2);
		mImg->render(getMemDc(), getRc().left, getRc().bottom - mImg->getHeight());
		break;
	case eBuildingType::off:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off);
		mImg->render(getMemDc(), getRc().left, getRc().top);
		break;
	case eBuildingType::stand:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_stand);
		mImg->frameRender(getMemDc(), getRc().left, getRc().top);
		break;
	default:

		break;
	}

	mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
}

void ShopStalkers::animation()
{
	if (mAniCount++ % 10 == 0 && (mBuildType == eBuildingType::stand)) {
		mAniCount = 1;
		if (mImg->getFrameX() >= mImg->getMaxFrameX()) {
			mImg->setFrameX(1);
		}
		else {
			mImg->setFrameX(mImg->getFrameX() + 1);
		}
	}
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

	if (KEYMANAGER->isOnceKeyDown('3')) {
		mBuildType = eBuildingType::close;
	}

	if (KEYMANAGER->isOnceKeyDown('4')) {
		mBuildType = eBuildingType::stand;
	}

	if (isStartBuild) {
		mBuildCount--;
		if (mBuildCount == 0) {
			isStartBuild = false;
			mBuildType = eBuildingType::stand;
		}
	}
}

void ShopStalkers::giveWeaponCommand()
{
	if (0 < mCurWeaponCount) {
		mCurWeaponCount--;
		setWeaponCount--;

		mImg_Tool->release();
		SAFE_DELETE(mImg_Tool);
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
		setWeaponCount = 4;
	}

	else {
		mCurWeaponCount++;
		mCreateCount = 0;
		getWeaponCount();
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

void ShopStalkers::startBuild()
{
	isStartBuild = true;
	mBuildType = eBuildingType::close;
}

void ShopStalkers::Monstertrue()
{
	//몬스터 충돌 영역 관리
}

void ShopStalkers::getWeaponCount()
{
	setWeaponCount++;
}