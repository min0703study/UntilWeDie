#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);
	
	mBuildCount = BUILD_BUILDING_TIME;
	
	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
	mImg_Tool = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);

	mBuildType = eBuildingType::off;

	mCreateCount = 0;
	setShovelCount = 2;

	isNpcIn = false;
	mBuildHp = 1;
}

void ShovelShop::release(void)
{
	//생성 되어 있는 삽을 유닛 상호작용시 하나씩 지워준다.
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
	}
}

void ShovelShop::draw()
{
	//RectangleMake(getMemDc(), getRc());
	switch (mBuildType)
	{
	case eBuildingType::close:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off_02);
		mImg->render(getMemDc(), getRc().left, getRc().bottom - mImg->getHeight());
		break;
	case eBuildingType::off:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
		mImg->render(getMemDc(), getRc().left, getRc().top);
		break;
	case eBuildingType::stand:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_stand);
		mImg->frameRender(getMemDc(), getRc().left, getRc().top);
		break;
	default:
		
		break;
	}

	mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
}

void ShovelShop::animation()
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

void ShovelShop::move()
{
	//Do Nothing
}

//update 같은 동작
void ShovelShop::action()
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

	if (KEYMANAGER->isOnceKeyDown('1')) {
		mBuildType = eBuildingType::close;
	}

	if (KEYMANAGER->isOnceKeyDown('2')) {
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

//삽을 주는거
void ShovelShop::giveShovelCommand()
{
	if (0 < mCurShovelCount) {
		mCurShovelCount--;
		setShovelCount--;

		mImg_Tool->release();
		SAFE_DELETE(mImg_Tool);
	}

	else {
		//상호작용 불가능
	}
}

//삽을 생성하는 곳
void ShovelShop::autoCreate()
{
	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		mCreateCount = 100;
		mCurShovelCount = 4;
		setShovelCount = 4;
	}

	else {
		mCurShovelCount++;
		mCreateCount = 0;
		getShovelCount();
	}
}

//유닛 상호작용
void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		giveShovelCommand();
	}

	else {
		isNpcIn = true;
	}
}

void ShovelShop::startBuild()
{
	isStartBuild = true;
	mBuildType = eBuildingType::close;
}

void ShovelShop::Monstertrue()
{
	//몬스터 충돌 영역 관리
}

void ShovelShop::getShovelCount()
{
	setShovelCount++;
}