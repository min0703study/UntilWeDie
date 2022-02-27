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
		mShovels; //...?
		IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);
		mImg->release();
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
}

void ShovelShop::giveShovelCommand()
{
	//���� �ֳ� ���Ĵϱ�...
	if (mShoveltrue) {
		//���� ���� �ʾ��� �� ����


	}
	else {
		//���� �Ǿ� �־ ��� ������ ������ �� ����
		mCurShovelCount--;
	}


	switch (mShoveltrue)
	{
	case true:
		//�����Ǿ�����
		//������ ��� �������� �ٲ�� �� �߰�
		mCurShovelCount--;

	case false:
		//����
		//���⿡�� ���� ���� ����ǥ �ؽ��İ� ��µǾ��� 
	}

}

//���� �����ϴ� ��
void ShovelShop::autoCreate()
{
	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		//������ �ʴ´�
		//��ġ�� 100���� �ö����� ������ x
		mCurShovelCount = 100;

	}
	else {
		//����� ����
		IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);
		mCurShovelCount = 0;
	}
}

void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		// �̹� ���� �ֱ� ������ ���� �ִ� ������ ó��
		giveShovelCommand();
	}
	else {
		isNpcIn = true;

		IMAGEMANAGER->findImage("shovelshop_open");
		IMAGEMANAGER->release();
		
		IMAGEMANAGER->findImage("shovelshop_stand");
	}
}

