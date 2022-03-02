#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);

	//�ʱ�ȭ �� �͵�
	mCreateCount = 0; //--> 0���� �����ؼ� 100�Ǹ� �ϳ��� ����
	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);

	isNpcIn = false;
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
	mImg->render(getMemDc(), getX(), getY());

	//mCurShovelCount ������ �׷��ش�. --->  �������� �������� ä�����ϱ�....
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
			mCreateCount = 0; //--> �ٽ� 0����
			autoCreate(); //----> �� ����
		}
	}

	else {
		//��ȣ�ۿ� �Ұ���
		mCreateCount = 0;
	}
}

//���� �ִ°�
void ShovelShop::giveShovelCommand()
{
	//���� �ֳ� ���Ĵϱ�...
	if (0 < mCurShovelCount) {
		//���� �Ǿ� �־ ��� ������ ������ �� ����
		mCurShovelCount--;
	}

	else
	{
		//��ȣ�ۿ� �Ұ���
	}
}

//���� �����ϴ� ��
void ShovelShop::autoCreate()
{
	if (mCurShovelCount < MAX_SHOVEL_COUNT) {
		//������ �ʴ´�
		//��ġ�� 100���� �ö����� ������ x
		mCreateCount = 100;
		mCurShovelCount = 4;
	}

	else {
		//����� ����
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

