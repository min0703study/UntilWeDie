#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);

	mCreateCount = 0;

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
	mImg->render(getMemDc(), getRc().left, getRc().top);
	RectangleMake(getMemDc(), getRc());
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
}

//���� �ִ°�
void ShovelShop::giveShovelCommand()
{
	if (0 < mCurShovelCount) {
		mCurShovelCount--;
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
	}

	else {
		mCurShovelCount++;
		mCreateCount = 0;
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