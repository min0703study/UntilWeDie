#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
	mImg_Tool = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);

	mCreateCount = 0;
	setShovelCount = 2;

	isNpcIn = false;
	mBuildHp = 1;
}

void ShovelShop::release(void)
{
	//���� �Ǿ� �ִ� ���� ���� ��ȣ�ۿ�� �ϳ��� �����ش�.
	if (true)
	{
		//���ͷ� �ϳ��� ������ϴϱ�...
	}
}

void ShovelShop::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);

	mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
}

void ShovelShop::animation()
{
	//Do thing
}

void ShovelShop::move()
{
	//Do Nothing
}

//update ���� ����
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
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_open);
	}

	if (KEYMANAGER->isOnceKeyDown('2')) {
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_stand);

		if (mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_stand)) {
			if (mCreateCount = 100 && setShovelCount < 5) {
				mImg_Tool->render(getMemDc(), getRc().left + 350, getRc().top + 100);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('3')) {
		mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_close);
	}
}

//���� �ִ°�
void ShovelShop::giveShovelCommand()
{
	if (0 < mCurShovelCount) {
		mCurShovelCount--;
		setShovelCount--;

		mImg_Tool->release();
		SAFE_DELETE(mImg_Tool);
	}

	else {
		//��ȣ�ۿ� �Ұ���
	}
}

//���� �����ϴ� ��
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

//���� ��ȣ�ۿ�
void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		giveShovelCommand();
	}

	else {
		isNpcIn = true;
	}
}

void ShovelShop::Monstertrue()
{
	//���� �浹 ���� ����
}

void ShovelShop::getShovelCount()
{
	setShovelCount++;
}