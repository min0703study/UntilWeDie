#include "Stdafx.h"
#include "engineerShop.h"

void engineerShop::init(float x, float y, float width, float height)
{
	GameObject::Init("engineerShop", x, y, width, height);

	mBuildCount = BUILD_BUILDING_TIME;

	mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_off);
	mImg_Tool = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_wrench);

	mBuildType = eBuildingType::off;

	mCreateCount = 0;
	setWrenchCount = 2;

	isNpcIn = false;
	mBuildHp = 1;
}

void engineerShop::release(void)
{
	if (true)
	{
		//���ͷ� �ϳ��� ������ϴϱ�...
	}
}

void engineerShop::draw()
{
	//RectangleMake(getMemDc(), getRc());
	switch (mBuildType)
	{
	case eBuildingType::close:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_off_2);
		mImg->render(getMemDc(), getRc().left, getRc().bottom - mImg->getHeight());
		break;
	case eBuildingType::off:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_off);
		mImg->render(getMemDc(), getRc().left, getRc().top);
		break;
	case eBuildingType::stand:
		mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_stand);
		mImg->frameRender(getMemDc(), getRc().left, getRc().top);
		break;
	default:

		break;
	}

	mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
}

void engineerShop::animation()
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

void engineerShop::move()
{
	//Do Nothing
}

//update ���� ����
void engineerShop::action()
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

	if (KEYMANAGER->isOnceKeyDown('5')) {
		mBuildType = eBuildingType::close;
	}

	if (KEYMANAGER->isOnceKeyDown('6')) {
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

//���� �ִ°�
void engineerShop::giveWrenchCommand()
{
	if (0 < mCurWrenchCount) {
		mCurWrenchCount--;
		setWrenchCount--;

		mImg_Tool->release();
		SAFE_DELETE(mImg_Tool);
	}

	else {
		//��ȣ�ۿ� �Ұ���
	}
}

//���� �����ϴ� ��
void engineerShop::autoCreate()
{
	if (MAX_WRENCH_COUNT <= mCurWrenchCount) {
		mCreateCount = 100;
		mCurWrenchCount = 4;
		setWrenchCount = 4;
	}

	else {
		mCurWrenchCount++;
		mCreateCount = 0;
		getWrenchCount();
	}
}

//���� ��ȣ�ۿ�
void engineerShop::intoNpc()
{
	if (isNpcIn == true) {
		giveWrenchCommand();
	}

	else {
		isNpcIn = true;
	}
}

void engineerShop::startBuild()
{
	isStartBuild = true;
	mBuildType = eBuildingType::close;
}

void engineerShop::Monstertrue()
{
	//���� �浹 ���� ����
}

void engineerShop::getWrenchCount()
{
	setWrenchCount++;
}