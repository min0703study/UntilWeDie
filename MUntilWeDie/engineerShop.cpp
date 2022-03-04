#include "Stdafx.h"
#include "engineerShop.h"

void engineerShop::init(float x, float y, float width, float height)
{
	GameObject::Init("engineerShop", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_off);

	mCreateCount = 0;

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
	mImg->render(getMemDc(), getRc().left, getRc().top);
	RectangleMake(getMemDc(), getRc());
}

void engineerShop::animation()
{
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
}

//���� �ִ°�
void engineerShop::giveWrenchCommand()
{
	if (0 < mCurWrenchCount) {
		mCurWrenchCount--;
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
	}

	else {
		mCurWrenchCount++;
		mCreateCount = 0;
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

void engineerShop::Monstertrue()
{
	//���� �浹 ���� ����
}